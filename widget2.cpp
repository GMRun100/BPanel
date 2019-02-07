#include "widget2.h"
#include "ui_widget2.h"
#include <QMessageBox>
#include <QDebug>
#include "stackedwidget.h"

Widget2::Widget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget2)
{
    ui->setupUi(this);
}


Widget2::~Widget2()
{
    delete ui;
}

void Widget2::on_pushButton_changeWidget1_clicked()
{
    emit changeWidget1();
}

void Widget2::on_pushButton_back_clicked()
{
    emit goHomeSig();
}

void Widget2::updateValue()
{

    ui->label_d1_p->setText( QString::number(getValueByName("D1/power").toFloat()/1000,'e',3));
    //QMessageBox::warning(NULL,"test",ui->label_d1_p->text());
    ui->label_d2_p->setText(QString::number( getValueByName("D2/power").toFloat()/1000,'e',3));
    ui->label_d4_p->setText( QString::number(getValueByName("D4/power").toFloat()/1000,'e',3));
    ui->label_d5_p->setText( QString::number(getValueByName("D5/power").toFloat()/1000,'e',3));
    ui->label_d6_p->setText(QString::number( getValueByName("D6/power").toFloat()/1000,'e',3));
    ui->label_d7_p->setText( QString::number(getValueByName("D7/power").toFloat()/1000,'e',3));
    ui->label_d8_p->setText( QString::number(getValueByName("D8/power").toFloat()/1000,'e',3));
    ui->label_d14_p->setText( QString::number(getValueByName("D14/power").toFloat()/1000,'e',3));

    ui->label_d1_k1->setText( getValueByName("D1/k1") );
    ui->label_d2_k1->setText( getValueByName("D2/k1") );
    ui->label_d4_k1->setText( getValueByName("D4/k1") );
    ui->label_d5_k1->setText( getValueByName("D5/k1") );
    ui->label_d6_k1->setText( getValueByName("D6/k1") );
    ui->label_d7_k1->setText( getValueByName("D7/k1") );
    ui->label_d8_k1->setText( getValueByName("D8/k1") );
    ui->label_d14_k1->setText( getValueByName("D14/k1") );

    ui->label_d1_k2->setText( getValueByName("D1/k2") );
    ui->label_d2_k2->setText( getValueByName("D2/k2") );
    ui->label_d4_k2->setText( getValueByName("D4/k2") );
    ui->label_d5_k2->setText( getValueByName("D5/k2") );
    ui->label_d6_k2->setText( getValueByName("D6/k2") );
    ui->label_d7_k2->setText( getValueByName("D7/k2") );
    ui->label_d8_k2->setText( getValueByName("D8/k2") );
    ui->label_d14_k2->setText( getValueByName("D14/k2") );

    //2019.01.04 GM 画面显示的功率为KW，需要将1000收到的数值除以1000
    float tempsp;
    tempsp=getValueByName("SP/setpoint").toFloat()/1000;

    ui->label_sp_val->setText(QString::number(tempsp));


//    ui->label_d1_k3->setText( getValueByName("D1/k3") );
//    ui->label_d7_k3->setText( getValueByName("D7/k3") );
//    ui->label_d8_k3->setText( getValueByName("D8/k3") );
//    ui->label_d14_k3->setText( getValueByName("D14/k3") );


//    ui->label_d1_k4->setText( getValueByName("D1/k4") );
//    ui->label_d7_k4->setText( getValueByName("D7/k4") );
//    ui->label_d8_k4->setText( getValueByName("D8/k4") );
//    ui->label_d14_k4->setText( getValueByName("D14/k4") );



}

/*
MyButton::MyButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(myButtonClicked()) );
}

void MyButton::myButtonClicked()
{
    if(QMessageBox::Ok == QMessageBox::question(this, "info", "Are you sure to send this value?", QMessageBox::Ok, QMessageBox::Cancel) )
    {

        QObjectList objList = this->parent()->children();

        QStringList lineEditList;

        foreach (QObject *temp, objList)
        {
            QString LineEditName = temp->objectName();
            if( LineEditName.startsWith("lineEdit") )
            {
                QString inputText = ((QLineEdit*)temp)->text();

                lineEditList<< inputText;


            }


        }
        qDebug()<<lineEditList;


        //定值下发

        qDebug()<<lineEditList<<this->objectName();


    }



    //check lineedit is null
     QObjectList objList = this->parent()->children();
        bool isNUll = false;
        QStringList lineEditList;

        foreach (QObject *temp, objList)
        {
            QString LineEditName = temp->objectName();
            if( LineEditName.startsWith("lineEdit") )
            {
                QString inputText = ((QLineEdit*)temp)->text();
                if( !(inputText.length()) )
                {
                    isNUll = true;
                    break;
                }
                else
                {
                    lineEditList<< ((QLineEdit*)temp)->text();
                }

            }


        }
        qDebug()<<lineEditList;

        if(isNUll)
            QMessageBox::warning(NULL, "warnning", "lineedit is empty!");
        else  //定值下发
        {
            qDebug()<<lineEditList<<this->objectName();






            //清空定值
            foreach (QObject *temp, objList)
            {
                QString LineEditName = temp->objectName();
                if( LineEditName.startsWith("lineEdit") )
                {

                    ((QLineEdit*)temp)->clear();
                }


            }
        }


}
*/


void Widget2::on_pushButton_d2_clicked()
{
    //2019.01.04 GM 增加对要发送的K2值的判断，K2值需大于等1小于10
    QString str;
    if((ui->lineEdit_d2_k1->text()!=NULL)||(ui->lineEdit_d2_k2->text()!=NULL))
    {      
        if((ui->lineEdit_d2_k1->text()!=NULL)&&(ui->lineEdit_d2_k2->text()==NULL))
        {
            str.append("Are you sure to send this value?\n");
            str.append("k1=");
            str.append(ui->lineEdit_d2_k1->text());
            if(QMessageBox::Ok == QMessageBox::question(this, "info",str , QMessageBox::Ok, QMessageBox::Cancel) )
            {
                 QStringList lineEditList;
                 lineEditList<<ui->lineEdit_d2_k1->text();

                 QStringList pointList;
                 pointList<<get8000Point2("D2/k1");
                 qDebug()<<pointList;

                 QString result;
                 for(int i=0; i<lineEditList.count(); i++)
                 {
                     int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                     result += getResultInfo(ret, pointList.at(i))+"\n";
                 }

                 QMessageBox::warning(NULL, "info", result);

            }
        }
        else if((ui->lineEdit_d2_k1->text()==NULL)&&(ui->lineEdit_d2_k2->text()!=NULL))
        {
            if((ui->lineEdit_d2_k2->text().toFloat()>=1)&&(ui->lineEdit_d2_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k2=");
                str.append(ui->lineEdit_d2_k2->text());
                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d2_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D2/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
        else
        {
            if((ui->lineEdit_d2_k2->text().toFloat()>=1)&&(ui->lineEdit_d2_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k1=");
                str.append(ui->lineEdit_d2_k1->text());
                str.append("\n");
                str.append("k2=");
                str.append(ui->lineEdit_d2_k2->text());

                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d2_k1->text()<<ui->lineEdit_d2_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D2/k1")<<get8000Point2("D2/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, "info", "please input the k1 or k2 value");
    }

}

void Widget2::on_pushButton_d6_clicked()
{
//    if(QMessageBox::Ok == QMessageBox::question(this, "info", "Are you sure to send this value?", QMessageBox::Ok, QMessageBox::Cancel) )
//    {
//         QStringList lineEditList;
//         lineEditList<<ui->lineEdit_d6_k1->text()<<ui->lineEdit_d6_k2->text();

//         QStringList pointList;
//         pointList<<get8000Point2("D6/k1")<<get8000Point2("D6/k2");
//         qDebug()<<pointList;

//         QString result;
//         for(int i=0; i<lineEditList.count(); i++)
//         {
//             int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
//             result += getResultInfo(ret, pointList.at(i))+"\n";
//         }


//         QMessageBox::warning(NULL, "info", result);

//    }

    //2019.01.04 GM
    QString str;
    if((ui->lineEdit_d6_k1->text()!=NULL)||(ui->lineEdit_d6_k2->text()!=NULL))
    {
        if((ui->lineEdit_d6_k1->text()!=NULL)&&(ui->lineEdit_d6_k2->text()==NULL))
        {
            str.append("Are you sure to send this value?\n");
            str.append("k1=");
            str.append(ui->lineEdit_d6_k1->text());
            if(QMessageBox::Ok == QMessageBox::question(this, "info",str , QMessageBox::Ok, QMessageBox::Cancel) )
            {
                 QStringList lineEditList;
                 lineEditList<<ui->lineEdit_d6_k1->text();

                 QStringList pointList;
                 pointList<<get8000Point2("D6/k1");
                 qDebug()<<pointList;

                 QString result;
                 for(int i=0; i<lineEditList.count(); i++)
                 {
                     int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                     result += getResultInfo(ret, pointList.at(i))+"\n";
                 }

                 QMessageBox::warning(NULL, "info", result);

            }
        }
        else if((ui->lineEdit_d6_k1->text()==NULL)&&(ui->lineEdit_d6_k2->text()!=NULL))
        {
            if((ui->lineEdit_d6_k2->text().toFloat()>=1)&&(ui->lineEdit_d6_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k2=");
                str.append(ui->lineEdit_d6_k2->text());
                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d6_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D6/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
        else
        {
            if((ui->lineEdit_d6_k2->text().toFloat()>=1)&&(ui->lineEdit_d6_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k1=");
                str.append(ui->lineEdit_d6_k1->text());
                str.append("\n");
                str.append("k2=");
                str.append(ui->lineEdit_d6_k2->text());

                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d6_k1->text()<<ui->lineEdit_d6_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D6/k1")<<get8000Point2("D6/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, "info", "please input the k1 or k2 value");
    }
}

void Widget2::on_pushButton_d4_clicked()
{
//    if(QMessageBox::Ok == QMessageBox::question(this, "info", "Are you sure to send this value?", QMessageBox::Ok, QMessageBox::Cancel) )
//    {
//         QStringList lineEditList;
//         lineEditList<<ui->lineEdit_d4_k1->text()<<ui->lineEdit_d4_k2->text();

//         QStringList pointList;
//         pointList<<get8000Point2("D4/k1")<<get8000Point2("D4/k2");
//         qDebug()<<pointList;

//         QString result;
//         for(int i=0; i<lineEditList.count(); i++)
//         {
//             int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
//             result += getResultInfo(ret, pointList.at(i))+"\n";
//         }
//         QMessageBox::warning(NULL, "info", result);

//    }

    //2019.01.04 GM
    QString str;
    if((ui->lineEdit_d4_k1->text()!=NULL)||(ui->lineEdit_d4_k2->text()!=NULL))
    {
        if((ui->lineEdit_d4_k1->text()!=NULL)&&(ui->lineEdit_d4_k2->text()==NULL))
        {
            str.append("Are you sure to send this value?\n");
            str.append("k1=");
            str.append(ui->lineEdit_d4_k1->text());
            if(QMessageBox::Ok == QMessageBox::question(this, "info",str , QMessageBox::Ok, QMessageBox::Cancel) )
            {
                 QStringList lineEditList;
                 lineEditList<<ui->lineEdit_d4_k1->text();

                 QStringList pointList;
                 pointList<<get8000Point2("D4/k1");
                 qDebug()<<pointList;

                 QString result;
                 for(int i=0; i<lineEditList.count(); i++)
                 {
                     int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                     result += getResultInfo(ret, pointList.at(i))+"\n";
                 }

                 QMessageBox::warning(NULL, "info", result);

            }
        }
        else if((ui->lineEdit_d4_k1->text()==NULL)&&(ui->lineEdit_d4_k2->text()!=NULL))
        {
            if((ui->lineEdit_d4_k2->text().toFloat()>=1)&&(ui->lineEdit_d4_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k2=");
                str.append(ui->lineEdit_d4_k2->text());
                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d4_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D4/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
        else
        {
            if((ui->lineEdit_d4_k2->text().toFloat()>=1)&&(ui->lineEdit_d4_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k1=");
                str.append(ui->lineEdit_d4_k1->text());
                str.append("\n");
                str.append("k2=");
                str.append(ui->lineEdit_d4_k2->text());

                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d4_k1->text()<<ui->lineEdit_d4_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D4/k1")<<get8000Point2("D4/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, "info", "please input the k1 or k2 value");
    }


}

void Widget2::on_pushButton_d5_clicked()
{
//    if(QMessageBox::Ok == QMessageBox::question(this, "info", "Are you sure to send this value?", QMessageBox::Ok, QMessageBox::Cancel) )
//    {
//         QStringList lineEditList;
//         lineEditList<<ui->lineEdit_d5_k1->text()<<ui->lineEdit_d5_k2->text();

//         QStringList pointList;
//         pointList<<get8000Point2("D5/k1")<<get8000Point2("D5/k2");
//         qDebug()<<pointList;

//         QString result;
//         for(int i=0; i<lineEditList.count(); i++)
//         {
//             int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
//             result += getResultInfo(ret, pointList.at(i))+"\n";
//         }


//         QMessageBox::warning(NULL, "info", result);

//    }

    //2019.01.04 GM
    QString str;
    if((ui->lineEdit_d5_k1->text()!=NULL)||(ui->lineEdit_d5_k2->text()!=NULL))
    {
        if((ui->lineEdit_d5_k1->text()!=NULL)&&(ui->lineEdit_d5_k2->text()==NULL))
        {
            str.append("Are you sure to send this value?\n");
            str.append("k1=");
            str.append(ui->lineEdit_d5_k1->text());
            if(QMessageBox::Ok == QMessageBox::question(this, "info",str , QMessageBox::Ok, QMessageBox::Cancel) )
            {
                 QStringList lineEditList;
                 lineEditList<<ui->lineEdit_d5_k1->text();

                 QStringList pointList;
                 pointList<<get8000Point2("D5/k1");
                 qDebug()<<pointList;

                 QString result;
                 for(int i=0; i<lineEditList.count(); i++)
                 {
                     int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                     result += getResultInfo(ret, pointList.at(i))+"\n";
                 }

                 QMessageBox::warning(NULL, "info", result);

            }
        }
        else if((ui->lineEdit_d5_k1->text()==NULL)&&(ui->lineEdit_d5_k2->text()!=NULL))
        {
            if((ui->lineEdit_d5_k2->text().toFloat()>=1)&&(ui->lineEdit_d5_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k2=");
                str.append(ui->lineEdit_d5_k2->text());
                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d5_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D5/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
        else
        {
            if((ui->lineEdit_d5_k2->text().toFloat()>=1)&&(ui->lineEdit_d5_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k1=");
                str.append(ui->lineEdit_d5_k1->text());
                str.append("\n");
                str.append("k2=");
                str.append(ui->lineEdit_d5_k2->text());

                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d5_k1->text()<<ui->lineEdit_d5_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D5/k1")<<get8000Point2("D5/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, "info", "please input the k1 or k2 value");
    }


}

void Widget2::on_pushButton_d1_clicked()
{
//    if(QMessageBox::Ok == QMessageBox::question(this, "info", "Are you sure to send this value?", QMessageBox::Ok, QMessageBox::Cancel) )
//    {
//         QStringList lineEditList;
//        // lineEditList<<ui->lineEdit_d3_k1->text()<<ui->lineEdit_d3_k2->text()<<ui->lineEdit_d1_k3->text()<<ui->lineEdit_d1_k4->text();
//         lineEditList<<ui->lineEdit_d1_k1->text()<<ui->lineEdit_d1_k2->text();

//         QStringList pointList;
//         //pointList<<get8000Point("D1/k1")<<get8000Point("D1/k2")<<get8000Point("D1/k3")<<get8000Point("D1/k4");
//         pointList<<get8000Point2("D1/k1")<<get8000Point2("D1/k2");
//         qDebug()<<pointList;

//         QString result;
//         for(int i=0; i<lineEditList.count(); i++)
//         {
//             int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
//             result += getResultInfo(ret, pointList.at(i))+"\n";
//         }

//         QMessageBox::warning(NULL, "info", result);
//    }


    //2019.01.04 GM
    QString str;
    if((ui->lineEdit_d1_k1->text()!=NULL)||(ui->lineEdit_d1_k2->text()!=NULL))
    {
        if((ui->lineEdit_d1_k1->text()!=NULL)&&(ui->lineEdit_d1_k2->text()==NULL))
        {
            str.append("Are you sure to send this value?\n");
            str.append("k1=");
            str.append(ui->lineEdit_d1_k1->text());
            if(QMessageBox::Ok == QMessageBox::question(this, "info",str , QMessageBox::Ok, QMessageBox::Cancel) )
            {
                 QStringList lineEditList;
                 lineEditList<<ui->lineEdit_d1_k1->text();

                 QStringList pointList;
                 pointList<<get8000Point2("D1/k1");
                 qDebug()<<pointList;

                 QString result;
                 for(int i=0; i<lineEditList.count(); i++)
                 {
                     int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                     result += getResultInfo(ret, pointList.at(i))+"\n";
                 }

                 QMessageBox::warning(NULL, "info", result);

            }
        }
        else if((ui->lineEdit_d1_k1->text()==NULL)&&(ui->lineEdit_d1_k2->text()!=NULL))
        {
            if((ui->lineEdit_d1_k2->text().toFloat()>=1)&&(ui->lineEdit_d1_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k2=");
                str.append(ui->lineEdit_d1_k2->text());
                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d1_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D1/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
        else
        {
            if((ui->lineEdit_d1_k2->text().toFloat()>=1)&&(ui->lineEdit_d1_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k1=");
                str.append(ui->lineEdit_d1_k1->text());
                str.append("\n");
                str.append("k2=");
                str.append(ui->lineEdit_d1_k2->text());

                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d1_k1->text()<<ui->lineEdit_d1_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D1/k1")<<get8000Point2("D1/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, "info", "please input the k1 or k2 value");
    }

}

void Widget2::on_pushButton_d8_clicked()
{
//    if(QMessageBox::Ok == QMessageBox::question(this, "info", "Are you sure to send this value?", QMessageBox::Ok, QMessageBox::Cancel) )
//    {
//         QStringList lineEditList;
//         //lineEditList<<ui->lineEdit_d8_k1->text()<<ui->lineEdit_d8_k2->text()<<ui->lineEdit_d8_k3->text()<<ui->lineEdit_d8_k4->text();
//         lineEditList<<ui->lineEdit_d8_k1->text()<<ui->lineEdit_d8_k2->text();
//         QStringList pointList;
//         //pointList<<get8000Point("D8/k1")<<get8000Point("D8/k2")<<get8000Point("D8/k3")<<get8000Point("D8/k4");
//         pointList<<get8000Point2("D8/k1")<<get8000Point2("D8/k2");
//         //qDebug()<<pointList;

//         QString result;
//         for(int i=0; i<lineEditList.count(); i++)
//         {
//             int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
//             result += getResultInfo(ret, pointList.at(i))+"\n";
//         }
//         QMessageBox::warning(NULL, "info", result);

//    }

    //2019.01.04 GM
    QString str;
    if((ui->lineEdit_d8_k1->text()!=NULL)||(ui->lineEdit_d8_k2->text()!=NULL))
    {
        if((ui->lineEdit_d8_k1->text()!=NULL)&&(ui->lineEdit_d8_k2->text()==NULL))
        {
            str.append("Are you sure to send this value?\n");
            str.append("k1=");
            str.append(ui->lineEdit_d8_k1->text());
            if(QMessageBox::Ok == QMessageBox::question(this, "info",str , QMessageBox::Ok, QMessageBox::Cancel) )
            {
                 QStringList lineEditList;
                 lineEditList<<ui->lineEdit_d8_k1->text();

                 QStringList pointList;
                 pointList<<get8000Point2("D8/k1");
                 qDebug()<<pointList;

                 QString result;
                 for(int i=0; i<lineEditList.count(); i++)
                 {
                     int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                     result += getResultInfo(ret, pointList.at(i))+"\n";
                 }

                 QMessageBox::warning(NULL, "info", result);

            }
        }
        else if((ui->lineEdit_d8_k1->text()==NULL)&&(ui->lineEdit_d8_k2->text()!=NULL))
        {
            if((ui->lineEdit_d8_k2->text().toFloat()>=1)&&(ui->lineEdit_d8_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k2=");
                str.append(ui->lineEdit_d8_k2->text());
                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d8_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D8/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
        else
        {
            if((ui->lineEdit_d8_k2->text().toFloat()>=1)&&(ui->lineEdit_d8_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k1=");
                str.append(ui->lineEdit_d8_k1->text());
                str.append("\n");
                str.append("k2=");
                str.append(ui->lineEdit_d8_k2->text());

                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d8_k1->text()<<ui->lineEdit_d8_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D8/k1")<<get8000Point2("D8/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, "info", "please input the k1 or k2 value");
    }


}

void Widget2::on_pushButton_d7_clicked()
{
//    if(QMessageBox::Ok == QMessageBox::question(this, "info", "Are you sure to send this value?", QMessageBox::Ok, QMessageBox::Cancel) )
//    {
//         QStringList lineEditList;
//         //lineEditList<<ui->lineEdit_d7_k1->text()<<ui->lineEdit_d7_k2->text()<<ui->lineEdit_d7_k3->text()<<ui->lineEdit_d7_k4->text();
//         lineEditList<<ui->lineEdit_d7_k1->text()<<ui->lineEdit_d7_k2->text();
//         QStringList pointList;
//         //pointList<<get8000Point("D7/k1")<<get8000Point("D7/k2")<<get8000Point("D7/k3")<<get8000Point("D7/k4");
//         pointList<<get8000Point2("D7/k1")<<get8000Point2("D7/k2");
//         //qDebug()<<pointList;

//         QString result;
//         for(int i=0; i<lineEditList.count(); i++)
//         {
//             int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
//             result += getResultInfo(ret, pointList.at(i))+"\n";
//         }


//         QMessageBox::warning(NULL, "info", result);

//    }

    //2019.01.04 GM
    QString str;
    if((ui->lineEdit_d7_k1->text()!=NULL)||(ui->lineEdit_d7_k2->text()!=NULL))
    {
        if((ui->lineEdit_d7_k1->text()!=NULL)&&(ui->lineEdit_d7_k2->text()==NULL))
        {
            str.append("Are you sure to send this value?\n");
            str.append("k1=");
            str.append(ui->lineEdit_d7_k1->text());
            if(QMessageBox::Ok == QMessageBox::question(this, "info",str , QMessageBox::Ok, QMessageBox::Cancel) )
            {
                 QStringList lineEditList;
                 lineEditList<<ui->lineEdit_d7_k1->text();

                 QStringList pointList;
                 pointList<<get8000Point2("D7/k1");
                 qDebug()<<pointList;

                 QString result;
                 for(int i=0; i<lineEditList.count(); i++)
                 {
                     int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                     result += getResultInfo(ret, pointList.at(i))+"\n";
                 }

                 QMessageBox::warning(NULL, "info", result);

            }
        }
        else if((ui->lineEdit_d7_k1->text()==NULL)&&(ui->lineEdit_d7_k2->text()!=NULL))
        {
            if((ui->lineEdit_d7_k2->text().toFloat()>=1)&&(ui->lineEdit_d7_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k2=");
                str.append(ui->lineEdit_d7_k2->text());
                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d7_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D7/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
        else
        {
            if((ui->lineEdit_d7_k2->text().toFloat()>=1)&&(ui->lineEdit_d7_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k1=");
                str.append(ui->lineEdit_d7_k1->text());
                str.append("\n");
                str.append("k2=");
                str.append(ui->lineEdit_d7_k2->text());

                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d7_k1->text()<<ui->lineEdit_d7_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D7/k1")<<get8000Point2("D7/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, "info", "please input the k1 or k2 value");
    }


}

void Widget2::on_pushButton_d14_clicked()
{
//    if(QMessageBox::Ok == QMessageBox::question(this, "info", "Are you sure to send this value?", QMessageBox::Ok, QMessageBox::Cancel) )
//    {
//         QStringList lineEditList;
//         //lineEditList<<ui->lineEdit_d14_k1->text()<<ui->lineEdit_d14_k2->text()<<ui->lineEdit_d14_k3->text()<<ui->lineEdit_d14_k4->text();
//         lineEditList<<ui->lineEdit_d14_k1->text()<<ui->lineEdit_d14_k2->text();
//         QStringList pointList;
//         //pointList<<get8000Point("D14/k1")<<get8000Point("D14/k2")<<get8000Point("D14/k3")<<get8000Point("D14/k4");
//         pointList<<get8000Point2("D14/k1")<<get8000Point2("D14/k2");
//         //qDebug()<<pointList;

//         QString result;
//         for(int i=0; i<lineEditList.count(); i++)
//         {
//             int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
//             result += getResultInfo(ret, pointList.at(i))+"\n";
//         }


//         QMessageBox::warning(NULL, "info", result);

//    }

    //2019.01.04 GM
    QString str;
    if((ui->lineEdit_d14_k1->text()!=NULL)||(ui->lineEdit_d14_k2->text()!=NULL))
    {
        if((ui->lineEdit_d14_k1->text()!=NULL)&&(ui->lineEdit_d14_k2->text()==NULL))
        {
            str.append("Are you sure to send this value?\n");
            str.append("k1=");
            str.append(ui->lineEdit_d14_k1->text());
            if(QMessageBox::Ok == QMessageBox::question(this, "info",str , QMessageBox::Ok, QMessageBox::Cancel) )
            {
                 QStringList lineEditList;
                 lineEditList<<ui->lineEdit_d14_k1->text();

                 QStringList pointList;
                 pointList<<get8000Point2("D14/k1");
                 qDebug()<<pointList;

                 QString result;
                 for(int i=0; i<lineEditList.count(); i++)
                 {
                     int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                     result += getResultInfo(ret, pointList.at(i))+"\n";
                 }

                 QMessageBox::warning(NULL, "info", result);

            }
        }
        else if((ui->lineEdit_d14_k1->text()==NULL)&&(ui->lineEdit_d14_k2->text()!=NULL))
        {
            if((ui->lineEdit_d14_k2->text().toFloat()>=1)&&(ui->lineEdit_d14_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k2=");
                str.append(ui->lineEdit_d14_k2->text());
                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d14_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D14/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
        else
        {
            if((ui->lineEdit_d14_k2->text().toFloat()>=1)&&(ui->lineEdit_d14_k2->text().toFloat()<10))
            {
                str.append("Are you sure to send this value?\n");
                str.append("k1=");
                str.append(ui->lineEdit_d14_k1->text());
                str.append("\n");
                str.append("k2=");
                str.append(ui->lineEdit_d14_k2->text());

                if(QMessageBox::Ok == QMessageBox::question(this, "info", str, QMessageBox::Ok, QMessageBox::Cancel) )
                {
                     QStringList lineEditList;
                     lineEditList<<ui->lineEdit_d14_k1->text()<<ui->lineEdit_d14_k2->text();

                     QStringList pointList;
                     pointList<<get8000Point2("D14/k1")<<get8000Point2("D14/k2");
                     qDebug()<<pointList;

                     QString result;
                     for(int i=0; i<lineEditList.count(); i++)
                     {
                         int ret =  setAnolog( (char*)pointList.at(i).toStdString().c_str(), lineEditList.at(i).toFloat());
                         result += getResultInfo(ret, pointList.at(i))+"\n";
                     }

                     QMessageBox::warning(NULL, "info", result);

                }

            }
            else
            {

                QMessageBox::warning(NULL, "info", "K2 Value is out of range.K2 value:1≤k2<10");
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, "info", "please input the k1 or k2 value");
    }


}
//2019.1.1 GM
//函数功能：提取功率的量程和量值
void Widget2::calc(float current, float K1, float K2, int *num1, float *num2)
{
    float tmp,tmp1,tmp2;
    tmp = current*K1*K2;
    tmp1 = log10(tmp);
    *num1 = (int)tmp1;
    tmp2 = tmp1 - *num1;
    *num2 = pow(10, tmp2);
}

void Widget2::on_pushButton_D2D9_cal_k2_clicked()
{
    //qDebug()<<"GMGMGGM";
    float f1,f2,f3,f4;
    f1=getValueByName("SP/setpoint").toFloat();
    //qDebug()<<"setpoint="<<f1<<"\n";
    f2=getValueByName("D2/k1").toFloat();
    //qDebug()<<"k1="<<f2<<"\n";
    f3=getValueByName("D2/Current").toFloat();
    //qDebug()<<"Current="<<f3<<"\n";
    if(f2*f3!=0)
    {
        f4=f1/(f2*f3);
        //qDebug()<<"K2="<<f4<<"\n";
        ui->lineEdit_d2_k2->setText(QString::number(f4));
    }
    else
    {
         QMessageBox::warning(NULL, "info", "the current or K1 value is 0!");
    }
}

void Widget2::on_pushButton_D6D13_CAL_K2_clicked()
{
    //qDebug()<<"GMGMGGM";
    float f1,f2,f3,f4;
    f1=getValueByName("SP/setpoint").toFloat();
    f2=getValueByName("D6/k1").toFloat();
    f3=getValueByName("D6/Current").toFloat();
    if(f2*f3!=0)
    {
        f4=f1/(f2*f3);
        ui->lineEdit_d6_k2->setText(QString::number(f4));
    }
    else
    {
         QMessageBox::warning(NULL, "info", "the current or K1 value is 0!");
    }
}

void Widget2::on_pushButton_D4_D11_CAL_K2_clicked()
{
    //qDebug()<<"GMGMGGM";
    float f1,f2,f3,f4;
    f1=getValueByName("SP/setpoint").toFloat();
    f2=getValueByName("D4/k1").toFloat();
    f3=getValueByName("D4/Current").toFloat();
    if(f2*f3!=0)
    {
        f4=f1/(f2*f3);
        ui->lineEdit_d4_k2->setText(QString::number(f4));
    }
    else
    {
         QMessageBox::warning(NULL, "info", "the current or K1 value is 0!");
    }
}

void Widget2::on_pushButton_D5_CAL_k2_clicked()
{
    //qDebug()<<"GMGMGGM";
    float f1,f2,f3,f4;
    f1=getValueByName("SP/setpoint").toFloat();
    f2=getValueByName("D5/k1").toFloat();
    f3=getValueByName("D5/Current").toFloat();
    if(f2*f3!=0)
    {
        f4=f1/(f2*f3);
        ui->lineEdit_d5_k2->setText(QString::number(f4));
    }
    else
    {
         QMessageBox::warning(NULL, "info", "the current or K1 value is 0!");
    }
}

void Widget2::on_pushButton_D1_CAL_K2_clicked()
{
    //qDebug()<<"GMGMGGM";
    float f1,f2,f3,f4;
    f1=getValueByName("SP/setpoint").toFloat();
    f2=getValueByName("D1/k1").toFloat();
    f3=getValueByName("D1/Current").toFloat();
    if(f2*f3!=0)
    {
        f4=f1/(f2*f3);
        ui->lineEdit_d1_k2->setText(QString::number(f4));
    }
    else
    {
         QMessageBox::warning(NULL, "info", "the current or K1 value is 0!");
    }
}


void Widget2::on_pushButton_D8_CAL_K2_clicked()
{
    //qDebug()<<"GMGMGGM";
    float f1,f2,f3,f4;
    f1=getValueByName("SP/setpoint").toFloat();
    f2=getValueByName("D8/k1").toFloat();
    f3=getValueByName("D8/Current").toFloat();
    if(f2*f3!=0)
    {
        f4=f1/(f2*f3);
        ui->lineEdit_d8_k2->setText(QString::number(f4));
    }
    else
    {
         QMessageBox::warning(NULL, "info", "the current or K1 value is 0!");
    }
}

void Widget2::on_pushButton_D7_CAL_K2_clicked()
{
    //qDebug()<<"GMGMGGM";
    float f1,f2,f3,f4;
    f1=getValueByName("SP/setpoint").toFloat();
    f2=getValueByName("D7/k1").toFloat();
    f3=getValueByName("D7/Current").toFloat();
    if(f2*f3!=0)
    {
        f4=f1/(f2*f3);
        ui->lineEdit_d7_k2->setText(QString::number(f4));
    }
    else
    {
         QMessageBox::warning(NULL, "info", "the current or K1 value is 0!");
    }
}

void Widget2::on_pushButton_D14_CAL_K2_clicked()
{
    //qDebug()<<"GMGMGGM";
    float f1,f2,f3,f4;
    f1=getValueByName("SP/setpoint").toFloat();
    f2=getValueByName("D14/k1").toFloat();
    f3=getValueByName("D14/Current").toFloat();
    if(f2*f3!=0)
    {
        f4=f1/(f2*f3);
        ui->lineEdit_d14_k2->setText(QString::number(f4));
    }
    else
    {
         QMessageBox::warning(NULL, "info", "the current or K1 value is 0!");
    }
}


//2019.1.1 GM
//函数功能：自动计算K3,K4并下发
void Widget2::sendk3k4()
{
//    //string tmpstr1,tmpstr2,tmpstr3;
//    //计算D1_K3K4
//    float d1_f1,d1_f2,d1_f3;
//    int d1_k4;
//    float d1_k3;
//    d1_f1=getValueByName("D1/Current").toFloat();
//    d1_f2=getValueByName("D1/k1").toFloat();
//    d1_f3=getValueByName("D1/k2").toFloat();
//    calc(d1_f1,d1_f2,d1_f3,&d1_k4,&d1_k3);
//    ui->label_d1_k3->setText(QString::number(d1_k3));
//    ui->label_d1_k4->setText(QString::number(d1_k4));
//    ui->label_d1_I->setText(QString::number(d1_f1));

//    //计算D7_K3K4
//    float d7_f1,d7_f2,d7_f3;
//    int d7_k4;
//    float d7_k3;
//    d7_f1=getValueByName("D7/Current").toFloat();
//    d7_f2=getValueByName("D7/k1").toFloat();
//    d7_f3=getValueByName("D7/k2").toFloat();
//    calc(d7_f1,d7_f2,d7_f3,&d7_k4,&d7_k3);
//    //qDebug()<<"d7_f1="<<d7_f1<<"d7_f2="<<d7_f2<<"d7_f3="<<d7_f3<<"d7_k4="<<d7_k4<<"d7_k3="<<d7_k3;
//    ui->label_d7_k3->setText(QString::number(d7_k3));
//    ui->label_d7_k4->setText(QString::number(d7_k4));
//    ui->label_d7_I->setText(QString::number(d7_f1));

//    //计算D8_K3K4
//    float d8_f1,d8_f2,d8_f3;
//    int d8_k4;
//    float d8_k3;
//    d8_f1=getValueByName("D8/Current").toFloat();
//    d8_f2=getValueByName("D8/k1").toFloat();
//    d8_f3=getValueByName("D8/k2").toFloat();
//    calc(d8_f1,d8_f2,d8_f3,&d8_k4,&d8_k3);
//    ui->label_d8_k3->setText(QString::number(d8_k3));
//    ui->label_d8_k4->setText(QString::number(d8_k4));
//    ui->label_d8_I->setText(QString::number(d8_f1));

//    //计算D14_K3K4
//    float d14_f1,d14_f2,d14_f3;
//    int d14_k4;
//    float d14_k3;
//    d14_f1=getValueByName("D14/Current").toFloat();
//    d14_f2=getValueByName("D14/k1").toFloat();
//    d14_f3=getValueByName("D14/k2").toFloat();
//    calc(d14_f1,d14_f2,d14_f3,&d14_k4,&d14_k3);
//    ui->label_d14_k3->setText(QString::number(d14_k3));
//    ui->label_d14_k4->setText(QString::number(d14_k4));
//    ui->label_d14_I->setText(QString::number(d14_f1));

//    //qDebug()<<"tmpf1="<<tmpf1<<"tmpf2="<<tmpf2<<"tmpf3="<<tmpf3<<"numk3="<<numk3<<"numk4="<<numk4;
//    //进行下发操作
//    QStringList list1,list2;
//    list1.clear();
//    list2.clear();
//    list1<<QString::number(d1_k3)<<QString::number(d1_k4)<<QString::number(d7_k3)<<QString::number(d7_k4)<<QString::number(d8_k3)<<QString::number(d8_k4)<<QString::number(d14_k3)<<QString::number(d14_k4);

//    list2<<get8000Point2("D1/k3")<<get8000Point2("D1/k4")<<get8000Point2("D7/k3")<<get8000Point2("D7/k4")<<get8000Point2("D8/k3")<<get8000Point2("D8/k4")<<get8000Point2("D14/k3")<<get8000Point2("D14/k4");

//    QString result;
//    for(int i=0; i<list1.count(); i++)
//    {
//        int ret =  setAnolog( (char*)list2.at(i).toStdString().c_str(), list1.at(i).toFloat());
//        result += getResultInfo(ret, list2.at(i))+"\n";
//    }
}

