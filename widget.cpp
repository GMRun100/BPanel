#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QFile>
#include <QTimer>
#include <QMessageBox>
#include <QTime>
#include <QDir>
#include <QSettings>
#include <stdio.h>
//#include <QFtp>
#include "stackedwidget.h"
int curCheckNum=0;



//QList<QRadioButton*> listCheckbox;
//配置文件第二列的数字对应ADDRESSOFFSET



Widget::Widget(QWidget *parent) :
    QWidget(parent),runMode(0), pumpMode(0), selectedPumpCount(0),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //  ftp = new QFtp(this);

    //  ui->groupBox_set->setEnabled(false);

    ui->pushButton_cabinet->setText("N.A");
    ui->pushButton_cabinet->setStyleSheet( "background-color: red;  border-width: 2px; border-top-left-radius:30px;border-bottom-right-radius:30px;  border-top-right-radius:30px;border-bottom-left-radius:30px; border-style: double; border-color: yellow;" );

    ui->label_channelA->setText( "A" );
    ui->label_ChannelB->setText( "B" );
    ui->label_ChannelC->setText( "C" );

    ui->label_Title_yxfs->setText( "Operational mode of reactor" );
    ui->label_tile_zsb->setText( "Heavy water pumps" );
    ui->label_title_gldzsd->setText( "Power fixed value setting" );

    ui->label_yxfs->setText( "" );
    ui->label_zsbyxfs->setText( "Mode of OPER" );
    ui->label_gldzfw->setText( "Power Range" );

    ui->label_bkxtms->setText( "Regulating rod" );
    ui->pushButton_back->setText( "Main interface" );
    ui->toolButton_LOCK->setText("Lock");

    ui->pushButton_edit->setText( "Mod" );
    ui->pushButton_cancel->setText( "Cancel" );
    ui->pushButton_confirm->setText( "Confirm" );
    ui->toolButton_Send->setText( "Send" );

    ui->radioButton_d->setText( "D     1*1500rpm or 0  P<=30kW" );

    ui->pushButton_toWidget2->setText("Set K1/K2");



}

Widget::~Widget()
{
    delete ui;
}


void Widget::ConfirmEnable(bool flag)
{
    ui->pushButton_confirm->setEnabled(flag);
}
//bang kong
void Widget::setCabinetStateValue(int manul, int autossig, int cont)
{
    //qDebug()<<"CabinetState++++++++++++++++++++";
    if(manul == 1)
    {
        ui->pushButton_cabinet->setText("MANU");
        //qDebug()<<"CabinetState=MANU\n";
        ui->pushButton_cabinet->setStyleSheet( "background-color: green;  border-width: 2px; border-top-left-radius:30px;border-bottom-right-radius:30px;  border-top-right-radius:30px;border-bottom-left-radius:30px;  color: yellow;" );
        ui->groupBox_set->setEnabled(true);
    }
    if(autossig == 1)
    {
        //qDebug()<<"CabinetState=AUTO\n";
        ui->pushButton_cabinet->setText("AUTO");
        ui->pushButton_cabinet->setStyleSheet( "background-color: red;  border-width: 2px; border-top-left-radius:30px;border-bottom-right-radius:30px;  border-top-right-radius:30px;border-bottom-left-radius:30px;  color: yellow;" );
        ui->groupBox_set->setEnabled(false);

    }
    if(cont == 1)
    {
        //qDebug()<<"CabinetState=CONT\n";
        ui->pushButton_cabinet->setText("CONT");
        ui->pushButton_cabinet->setStyleSheet( "background-color: red;  border-width: 2px; border-top-left-radius:30px;border-bottom-right-radius:30px;  border-top-right-radius:30px;border-bottom-left-radius:30px;  color: yellow;" );

        ui->groupBox_set->setEnabled(false);
    }
    if((manul!=1)&&(autossig!=1)&&(cont != 1))
    {
        //qDebug()<<"CabinetState=N.A\n";
        ui->pushButton_cabinet->setText("N.A");
        ui->pushButton_cabinet->setStyleSheet( "background-color: red;  border-width: 2px; border-top-left-radius:30px;border-bottom-right-radius:30px;  border-top-right-radius:30px;border-bottom-left-radius:30px;  color: yellow;" );
        ui->groupBox_set->setEnabled(true);
    }
    //qDebug()<<"CabinetState-------------------";

}

void Widget::setLineShowABC(double a, double b, double c)
{
    ui->lineShow_A->setText( QString::number(a) );
    ui->lineShow_B->setText( QString::number(b) );
    ui->lineShow_C->setText( QString::number(c) );

}


void Widget::on_pushButton_back_clicked()
{
    emit goHomeSig();

}

void Widget::on_pushButton_edit_clicked()
{
    ui->lineEdit_A->setEnabled(true);
    ui->lineEdit_B->setEnabled(true);
    ui->lineEdit_C->setEnabled(true);

}

void Widget::on_pushButton_cancel_clicked()
{
    ui->lineEdit_A->setEnabled(false);
    ui->lineEdit_B->setEnabled(false);
    ui->lineEdit_C->setEnabled(false);
}

void Widget::on_pushButton_confirm_clicked()
{

    QString temp0Str = ui->lineEdit_A->text();
    QString temp1Str = ui->lineEdit_B->text();
    QString temp2Str = ui->lineEdit_C->text();



    // check input is same
    if(temp0Str == temp1Str && temp0Str == temp2Str)
    {

        //功率定值下发  PwrA104XU_1xS   PwrB204XU_2xS    PwrC304XU_3xS
//        float temp0 = temp0Str.toFloat();
//        float temp1 = temp1Str.toFloat();
//        float temp2 = temp2Str.toFloat();

        //2019.01.04 GM
        float temp0 = temp0Str.toFloat()*1000;
        float temp1 = temp1Str.toFloat()*1000;
        float temp2 = temp2Str.toFloat()*1000;

        int ret1 = setAnolog( (char*)get8000Point("AREA/powera").toStdString().c_str(), temp0);

        int ret2 =  setAnolog( (char*)get8000Point("AREA/powerb").toStdString().c_str(), temp1);

        int ret3 =  setAnolog( (char*)get8000Point("AREA/powerc").toStdString().c_str(), temp2);

        QString result = getResultInfo(ret1, "A") + getResultInfo(ret2, "B") + getResultInfo(ret3, "C");


        QMessageBox::warning(NULL, "info", result);

    }
    else
        QMessageBox::warning(NULL, tr("warn"), tr("three values must be the same！"));
}


static int num = 0;
void Widget::CreateLedFile()
{

    QFile file("./led.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << QString("a%1 ").arg( num++ )<< "\n";
    file.close();
    //qDebug()<<"file create"<<num;


//    ftp->connectToHost("ftp.qt.nokia.com");   // id == 1
//    ftp->login();                             // id == 2
//    ftp->cd("qt");                            // id == 3
//    ftp->put(&file, "led.txt", QFtp::Ascii);
//    ftp->close();
}

void Widget::on_pushButton_Chinese_clicked()
{
    ui->label_channelA->setText( tr("A通道") );
    ui->label_ChannelB->setText( tr("B通道") );
    ui->label_ChannelC->setText( tr("C通道") );

    ui->label_Title_yxfs->setText( tr("反应堆运行方式") );
    ui->label_tile_zsb->setText( tr("重水泵") );
    ui->label_title_gldzsd->setText( tr("功率定制设定") );

    ui->label_yxfs->setText( tr("运行方式") );
    ui->label_zsbyxfs->setText( tr("重水泵运行方式") );
    ui->label_gldzfw->setText( tr("允许功率定值范围") );

    ui->label_bkxtms->setText( tr("棒控系统模式") );
    ui->pushButton_back->setText( tr("主界面") );
    ui->toolButton_LOCK->setText( tr("锁定") );

    ui->pushButton_edit->setText( tr("修改") );
    ui->pushButton_cancel->setText( tr("取消") );
    ui->pushButton_confirm->setText( tr("确认") );
    ui->toolButton_Send->setText( tr("下发") );

    ui->radioButton_d->setText( tr("D     1*1500rpm或0台  P<=30kW") );
}

void Widget::on_pushButton_English_clicked()
{
    ui->label_channelA->setText( "Gallery A" );
    ui->label_ChannelB->setText( "Gallery B" );
    ui->label_ChannelC->setText( "Gallery C" );

    ui->label_Title_yxfs->setText( "Operational mode of reactor" );
    ui->label_tile_zsb->setText( "Heavy water pumps" );
    ui->label_title_gldzsd->setText( "Power fixed value setting" );

    ui->label_yxfs->setText( "" );
    ui->label_zsbyxfs->setText( "Mode of OPER" );
    ui->label_gldzfw->setText( "Power Range" );

    ui->label_bkxtms->setText( "Regulating rod" );
    ui->pushButton_back->setText( "Main interface" );
    ui->toolButton_LOCK->setText("LOCK");

    ui->pushButton_edit->setText( "MOD" );
    ui->pushButton_cancel->setText( "Cancel" );
    ui->pushButton_confirm->setText( "Confirm" );
    ui->toolButton_Send->setText( "Send" );

    ui->radioButton_d->setText( "D     1*1500rpm or 0  P<=30kW" );

    ui->pushButton_toWidget2->setText("Setting");

}
//锁定时发送 运行方式 和 重水泵  自动模式下发送
void Widget::on_toolButton_LOCK_clicked()
{

    if(ui->toolButton_LOCK->isChecked())
    {
        ui->groupBox->setEnabled(false);
        ui->groupBox_pump->setEnabled(false);
        ui->groupBox_set->setEnabled(false);
        ui->toolButton_LOCK->setText("Unlock");

    }
    else
    {
        ui->groupBox->setEnabled(true);
        ui->groupBox_pump->setEnabled(true);
        ui->groupBox_set->setEnabled(true);
        ui->toolButton_LOCK->setText("Lock");
    }

}



void Widget::on_toolButton_pumpA_clicked(bool checked)
{
    if(checked)
    {

        if(runMode == 1 && selectedPumpCount == 3)
        {
            ui->toolButton_pumpA->setChecked(false);
            return;
        }

        if(runMode == 2 || runMode == 3)
        {
            if(selectedPumpCount >= 2 || ui->toolButton_pumpB->isChecked())
            {

                ui->toolButton_pumpA->setChecked(false);
                return;
            }
        }

        if(runMode == 4)
        {
            ui->toolButton_pumpA->setChecked(true);
            ui->toolButton_pumpB->setChecked(false);
            ui->toolButton_pumpC->setChecked(false);
            ui->toolButton_pumpD->setChecked(false);
            return;
        }

        selectedPumpCount++;
    }
    else
        selectedPumpCount--;
}

void Widget::on_toolButton_pumpB_clicked(bool checked)
{
    if(checked)
    {
        if(runMode == 1 && selectedPumpCount == 3)
        {
            ui->toolButton_pumpB->setChecked(false);
            return;
        }

        if(runMode == 2 || runMode == 3)
        {
            if(selectedPumpCount >= 2 || ui->toolButton_pumpA->isChecked())
            {

                ui->toolButton_pumpB->setChecked(false);
                return;
            }
        }

        if(runMode == 4)
        {
            ui->toolButton_pumpA->setChecked(false);
            ui->toolButton_pumpB->setChecked(true);
            ui->toolButton_pumpC->setChecked(false);
            ui->toolButton_pumpD->setChecked(false);
            return;
        }

        selectedPumpCount++;


    }
    else
        selectedPumpCount--;
}

void Widget::on_toolButton_pumpC_clicked(bool checked)
{
    if(checked)
    {
        if(runMode == 1 && selectedPumpCount == 3)
        {
            ui->toolButton_pumpC->setChecked(false);
            return;
        }

        if(runMode == 2 || runMode == 3)
        {
            if(selectedPumpCount >= 2 || ui->toolButton_pumpD->isChecked())
            {
                ui->toolButton_pumpC->setChecked(false);
                return;
            }
        }

        if(runMode == 4)
        {
            ui->toolButton_pumpA->setChecked(false);
            ui->toolButton_pumpB->setChecked(false);
            ui->toolButton_pumpC->setChecked(true);
            ui->toolButton_pumpD->setChecked(false);
            return;
        }

        selectedPumpCount++;


    }
    else
        selectedPumpCount--;
}

void Widget::on_toolButton_pumpD_clicked(bool checked)
{
    if(checked)
    {

        if(runMode == 1 && selectedPumpCount == 3)
        {
            ui->toolButton_pumpD->setChecked(false);
            return;
        }

        if(runMode == 2 || runMode == 3)
        {
            if(selectedPumpCount >= 2 || ui->toolButton_pumpC->isChecked())
            {

                ui->toolButton_pumpD->setChecked(false);
                return;
            }
        }

        if(runMode == 4)
        {
            ui->toolButton_pumpA->setChecked(false);
            ui->toolButton_pumpB->setChecked(false);
            ui->toolButton_pumpC->setChecked(false);
            ui->toolButton_pumpD->setChecked(true);
            return;
        }

        selectedPumpCount++;


    }
    else
        selectedPumpCount--;
}


//命令下发
void Widget::on_toolButton_Send_clicked()
{

    if(1 == runMode && selectedPumpCount != 3)
    {   QMessageBox::warning(NULL, tr("Warn"), tr("Must selected 3 pumps！"));  return; }

    if(2 == runMode || 3 == runMode)
    {
        if(selectedPumpCount != 2)
        {  QMessageBox::warning(NULL, tr("Warn"), tr("Must selected 2 pumps！"));  return; }
    }

    if(4 == runMode )   //最多一个
    {
        if(selectedPumpCount > 1)
        {  QMessageBox::warning(NULL, tr("Warn"), tr("Select 1 pump at most！"));  return; }
    }



    //run mode
    switch (runMode) {
    case 1:

        qDebug()<< setDigital( "POM_A_1", 1)<<"run mode a 1";
        qDebug()<< setDigital( "POM_B_1", 0)<<"run mode b 0";
        qDebug()<< setDigital( "POM_C_1", 0)<<"run mode c 0";
        qDebug()<< setDigital( "POM_D_1", 0)<<"run mode d 0";


        qDebug()<< setDigital( "POM_A_2", 1);
        qDebug()<< setDigital( "POM_B_2", 0);
        qDebug()<< setDigital( "POM_C_2", 0);
        qDebug()<< setDigital( "POM_D_2", 0);

        qDebug()<< setDigital( "POM_A_3", 1);
        qDebug()<< setDigital( "POM_B_3", 0);
        qDebug()<< setDigital( "POM_C_3", 0);
        qDebug()<< setDigital( "POM_D_3", 0);

        sendPumpSelect();

        break;
    case 2:

        qDebug()<< setDigital( "POM_A_1", 0);
        qDebug()<< setDigital( "POM_B_1", 1);
        qDebug()<< setDigital( "POM_C_1", 0);
        qDebug()<< setDigital( "POM_D_1", 0);

        qDebug()<< setDigital( "POM_A_2", 0);
        qDebug()<< setDigital( "POM_B_2", 1);
        qDebug()<< setDigital( "POM_C_2", 0);
        qDebug()<< setDigital( "POM_D_2", 0);

        qDebug()<< setDigital( "POM_A_3", 0);
        qDebug()<< setDigital( "POM_B_3", 1);
        qDebug()<< setDigital( "POM_C_3", 0);
        qDebug()<< setDigital( "POM_D_3", 0);


        sendPumpSelect();

        break;
    case 3:

        qDebug()<< setDigital( "POM_A_1", 0);
        qDebug()<< setDigital( "POM_B_1", 0);
        qDebug()<< setDigital( "POM_C_1", 1);
        qDebug()<< setDigital( "POM_D_1", 0);

        qDebug()<< setDigital( "POM_A_2", 0);
        qDebug()<< setDigital( "POM_B_2", 0);
        qDebug()<< setDigital( "POM_C_2", 1);
        qDebug()<< setDigital( "POM_D_2", 0);

        qDebug()<< setDigital( "POM_A_3", 0);
        qDebug()<< setDigital( "POM_B_3", 0);
        qDebug()<< setDigital( "POM_C_3", 1);
        qDebug()<< setDigital( "POM_D_3", 0);


        sendPumpSelect();

        break;
    case 4:

        qDebug()<< setDigital( "POM_A_1", 0);
        qDebug()<< setDigital( "POM_B_1", 0);
        qDebug()<< setDigital( "POM_C_1", 0);
        qDebug()<< setDigital( "POM_D_1", 1);

        qDebug()<< setDigital( "POM_A_2", 0);
        qDebug()<< setDigital( "POM_B_2", 0);
        qDebug()<< setDigital( "POM_C_2", 0);
        qDebug()<< setDigital( "POM_D_2", 1);

        qDebug()<< setDigital( "POM_A_3", 0);
        qDebug()<< setDigital( "POM_B_3", 0);
        qDebug()<< setDigital( "POM_C_3", 0);
        qDebug()<< setDigital( "POM_D_3", 1);


        sendPumpSelect();

        break;
    default:
        break;
    }

}

void Widget::on_radioButton_a_toggled(bool checked)
{
    if(checked)
    {   runMode = 1;  curCheckNum = 1; }
}

void Widget::on_radioButton_b_toggled(bool checked)
{
    if(checked)
    {  runMode = 2;  curCheckNum = 2; }
}

void Widget::on_radioButton_c_toggled(bool checked)
{
    if(checked)
    {   runMode = 3; curCheckNum = 3; }
}

void Widget::on_radioButton_d_toggled(bool checked)
{
    if(checked)
    {   runMode = 4; curCheckNum = 4; }
}

void Widget::sendPumpSelect()
{
    char pumpa[32]={'\0'};
    char pumpb[32]={'\0'};
    char pumpc[32]={'\0'};
    //char pumpd[32]={'\0'};   //GM

    // qDebug()<<get8000Point("AREA/pumpa")<<get8000Point("AREA/pumpb")<<get8000Point("AREA/pumpc");

//    memcpy(pumpa,get8000Point("AREA/pumpa").toStdString().c_str(), 32 );
//    memcpy(pumpb,get8000Point("AREA/pumpb").toStdString().c_str(), 32 );
//    memcpy(pumpc,get8000Point("AREA/pumpc").toStdString().c_str(), 32 );
    //memcpy(pumpd,get8000Point("AREA/pumpd").toStdString().c_str(), 32 );


    ui->label_lastPump->setText("");

    if(ui->toolButton_pumpA->isChecked())
    {
//        qDebug()<< setDigital( pumpa, 1)<<"PUMA 1<<1";

//        qDebug()<< setDigital( pumpb, 1)<<"PUMA 2<<1";

//        qDebug()<< setDigital( pumpc, 1)<<"PUMA 3<<1";

        setDigital( "PumA_op_1", 1);
        setDigital( "PumA_op_2", 1);
        setDigital( "PumA_op_3", 1);

        ui->toolButton_pumpA->setChecked(false);
        ui->label_lastPump->setText( "A " );
    }
    else
    {
//        qDebug()<< setDigital( pumpa, 0)<<"PUMA 1<<0";

//        qDebug()<< setDigital( pumpb, 0)<<"PUMA 2<<0";

//        qDebug()<< setDigital( pumpc, 0)<<"PUMA 3<<0";
        setDigital( "PumA_op_1", 0);
        setDigital( "PumA_op_2", 0);
        setDigital( "PumA_op_3", 0);


    }

    if(ui->toolButton_pumpB->isChecked())
    {
//        qDebug()<< setDigital( pumpa, 1)<<"PUMB 1<<1";

//        qDebug()<< setDigital( pumpb, 1)<<"PUMB 2<<1";

//       qDebug()<< setDigital( pumpc, 1)<<"PUMB 3<<1";
        setDigital( "PumB_op_1", 1);
        setDigital( "PumB_op_2", 1);
        setDigital( "PumB_op_3", 1);

        ui->toolButton_pumpB->setChecked(false);
        ui->label_lastPump->setText( ui->label_lastPump->text() + "B " );
    }
    else
    {
//        qDebug()<< setDigital( pumpa, 0)<<"PUMB 1<<0";

//        qDebug()<< setDigital( pumpb, 0)<<"PUMB 2<<0";

//        qDebug()<< setDigital( pumpc, 0)<<"PUMB 3<<0";
        setDigital( "PumB_op_1", 0);
        setDigital( "PumB_op_2", 0);
        setDigital( "PumB_op_3", 0);
        ui->toolButton_pumpB->setChecked(false);
    }

    if(ui->toolButton_pumpC->isChecked())
    {
       // qDebug()<< setDigital( pumpa, 1)<<"PUMC 1<<1";

      //  qDebug()<< setDigital( pumpb, 1)<<"PUMC 2<<1";

       // qDebug()<< setDigital( pumpc, 1)<<"PUMC 3<<1";
        setDigital( "PumC_op_1", 1);
        setDigital( "PumC_op_2", 1);
        setDigital( "PumC_op_3", 1);

        ui->toolButton_pumpC->setChecked(false);
        ui->label_lastPump->setText( ui->label_lastPump->text() + "C " );
    }
    else
    {
       // qDebug()<< setDigital( pumpa, 0)<<"PUMC 1<<0";

      //  qDebug()<< setDigital( pumpb, 0)<<"PUMC 2<<0";

       // qDebug()<< setDigital( pumpc, 0)<<"PUMC 3<<0";

        setDigital( "PumC_op_1", 0);
        setDigital( "PumC_op_2", 0);
        setDigital( "PumC_op_3", 0);

        ui->toolButton_pumpC->setChecked(false);
    }

    if(ui->toolButton_pumpD->isChecked())
    {
       // qDebug()<< setDigital( pumpa, 1)<<"PUMD 1<<1";

      //  qDebug()<< setDigital( pumpb, 1)<<"PUMD 2<<1";

       // qDebug()<< setDigital( pumpc, 1)<<"PUMD 3<<1";
        setDigital( "PumD_op_1", 1);
        setDigital( "PumD_op_2", 1);
        setDigital( "PumD_op_3", 1);

        ui->toolButton_pumpD->setChecked(false);
        ui->label_lastPump->setText( ui->label_lastPump->text() + "D " );
    }
    else
    {
//        qDebug()<< setDigital( pumpa, 0)<<"PUMD 1<<0";

//        qDebug()<< setDigital( pumpb, 0)<<"PUMD 2<<0";

//        qDebug()<< setDigital( pumpc, 0)<<"PUMD 3<<0";

        setDigital( "PumD_op_1", 0);
        setDigital( "PumD_op_2", 0);
        setDigital( "PumD_op_3", 0);

        ui->toolButton_pumpD->setChecked(false);
    }

    selectedPumpCount = 0;
    QMessageBox::warning(NULL, "info", "command sended!");

}


void Widget::on_pushButton_k2_A_clicked()
{
    float oldpower, oldk2;
    this->getCurK2('a', oldpower, oldk2);

    if( oldpower >= -0.00001 && oldpower <= 0.00001 )
    {
        QMessageBox::warning(NULL, "warning", "old power is zero!");
        return;
    }

    float curPower = ui->lineShow_A->text().toFloat();
    float newK2 = oldk2*curPower/oldpower;

    int ret =  setAnolog( (char*)get8000Point("AREA/k2a").toStdString().c_str(), newK2);

    QString result = getResultInfo(ret, "A");

    QMessageBox::warning(NULL, "info", result + QString("Value:%1").arg(newK2));
}

void Widget::on_pushButton_k2_B_clicked()
{
    float oldpower, oldk2;
    this->getCurK2('b', oldpower, oldk2);

    if( oldpower >= -0.00001 && oldpower <= 0.00001 )
    {
        QMessageBox::warning(NULL, "warning", "old power is zero!");
        return;
    }

    float curPower = ui->lineShow_A->text().toFloat();
    float newK2 = oldk2*curPower/oldpower;

    int ret =  setAnolog( (char*)get8000Point("AREA/k2b").toStdString().c_str(), newK2);

    QString result = getResultInfo(ret, "B");

    QMessageBox::warning(NULL, "info", result + QString("Value:%1").arg(newK2));
}

void Widget::on_pushButton_k2_C_clicked()
{
    float oldpower, oldk2;
    this->getCurK2('c', oldpower, oldk2);

    if( oldpower >= -0.00001 && oldpower <= 0.00001 )
    {
        QMessageBox::warning(NULL, "warning", "old power is zero!");
        return;
    }

    float curPower = ui->lineShow_A->text().toFloat();
    float newK2 = oldk2*curPower/oldpower;

    int ret =  setAnolog( (char*)get8000Point("AREA/k2c").toStdString().c_str(), newK2);

    QString result = getResultInfo(ret, "C");

    QMessageBox::warning(NULL, "info", result + QString("Value:%1").arg(newK2));
}

void Widget::on_pushButton_toWidget2_clicked()
{
    emit changeWidget2();
}
