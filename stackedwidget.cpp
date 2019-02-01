#include "stackedwidget.h"
#include "ui_stackedwidget.h"
#include "widget.h"
#include "widget2.h"
#include <QDebug>
#include <QSettings>
#include <QDir>
#include <QMap>
#include <QTime>
#include <QTimer>
#include <string.h>
#include <QMessageBox>


QMap<QString, QString> BPanelMapValue;
QMap<QString, QString> BPanelMapWidget1Points;
QMap<QString, QString> BPanelMapWidget0Points;

StackedWidget::StackedWidget(QWidget *parent) :
    QStackedWidget(parent), myFun(NULL),
    ui(new Ui::StackedWidget)
{
    ui->setupUi(this);

    //初始化ini文件
    QString curDir = QDir::currentPath();
    //QMessageBox::information(NULL,"dir",curDir.toStdString().c_str());

    QSettings myset(curDir + "/config/nodeinfo.ini", QSettings::IniFormat);
    myset.setIniCodec("system");
    QStringList keyList = myset.allKeys();

    int start = 0;
//    foreach (QString key, keyList) {
//       // qDebug()<<key<<myset.value(key).toString();
//        if( key.startsWith("LED") || key.startsWith("PROJECT") || key.startsWith("AREA") )
//        {
//            qDebug()<<"key="<<key<<"BPanelMapWidget0Points="<<myset.value(key).toString();
//             BPanelMapWidget0Points.insert( key, myset.value(key).toString());
//            //QMessageBox::information(NULL,"BPanelMapWidget0Points",myset.value(key).toString());
//            //BPanelMapWidget1Points.insert( key, myset.value(key).toString());  //2018.12.31 GM
//        }
//        else
//            qDebug()<<"key="<<key<<"BPanelMapWidget1Points="<<myset.value(key).toString();
//            BPanelMapWidget1Points.insert( key, myset.value(key).toString() );
//           //QMessageBox::information(NULL,"BPanelMapWidget1Points",myset.value(key).toString());

//    }
    foreach (QString key, keyList) {
             BPanelMapWidget0Points.insert( key, myset.value(key).toString());
    }

    //2018.12.31 GM
    QSettings myset2(curDir + "/config/nodeinfo2.ini", QSettings::IniFormat);
    myset2.setIniCodec("system");
    QStringList keyList2 = myset2.allKeys();

    foreach (QString key2, keyList2) {
             BPanelMapWidget1Points.insert( key2, myset2.value(key2).toString());
    }

    //Debug  GM  2018.12.31
//    for(int i=0;i<BPanelMapWidget1Points.count();i++)
//    {
//        qDebug()<<"i="<<i<<"value="<<BPanelMapWidget1Points.keys().at(i);
//    }
    //Debug END


    QWidget *temp = this->widget(0);
    this->removeWidget(temp);
    delete temp;

    temp = this->widget(0);
    this->removeWidget(temp);
    delete temp;

    widget1 = new Widget(this);
    connect(widget1, SIGNAL(changeWidget2()), this, SLOT(changeWidget2Slot()));
    connect(widget1, SIGNAL(goHomeSig()), this, SLOT(goHome()));

    this->addWidget(widget1);

    widget2 = new Widget2(this);
    connect(widget2, SIGNAL(changeWidget1()), this, SLOT(changeWidget1Slot()));
    connect(widget2, SIGNAL(goHomeSig()), this, SLOT(goHome()));

    this->addWidget(widget2);



    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), widget2, SLOT(updateValue()));
    int period = BPanelMapWidget0Points.value("LED/period","1000").toInt();
    timer->start(period);

    //2019.1.1 GM
    QTimer *timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), widget2, SLOT(sendk3k4()));
    //timer1->start(300);
}

StackedWidget::~StackedWidget()
{
    delete ui;
}

char *StackedWidget::getFirstPoint(QString name)
{
       // QString tt = BPanelMapWidget1Points.value(name).split("#").first();
        QString tt = BPanelMapWidget0Points.value(name).split("#").first();
        //qDebug()<<tt<<"\n";

        memset(Temp, '\0', 64);

        memcpy(Temp, tt.toStdString().c_str(), tt.length());

    return Temp;

}

char *StackedWidget::getLastPoint(QString name)
{
        //QString str = BPanelMapWidget1Points.value(name).split("#").last();
        QString str = BPanelMapWidget0Points.value(name).split("#").last();
        //qDebug()<<str<<"\n";
        //QMessageBox::warning(NULL,"#",BPanelMapWidget1Points.value(name).split("#").begin().);
        //QMessageBox::information(NULL,"str",str.toStdString().c_str());
        memset(Temp, '\0', 64);

        memcpy(Temp, str.toStdString().c_str(), str.length());
        //QMessageBox::warning(NULL,"GM",str.toStdString().c_str());

    return Temp;
}

void StackedWidget::changeWidget2Slot()
{
    this->setCurrentIndex(1);
}

void StackedWidget::changeWidget1Slot()
{
    this->setCurrentIndex(0);
}

void StackedWidget::goHome()
{
    if(NULL != myFun)
        this->myFun();
}


void delaymsecs( int msecs)
{
    QTime curTime = QTime::currentTime();
    QTime NowTime;

    do{
        NowTime = QTime::currentTime();
    }while( curTime.msecsTo(NowTime) <= msecs );
}


int setAnolog( const char *paramterName, float parameterValue)
{
    int num = parameterAdjust(   (char*)paramterName, parameterValue);
    delaymsecs(200);
    return num;
    return 0;

}

int setDigital( const char *paramterName, BYTE variableValue)
{
    int num = variableForce(  (char*)paramterName,  variableValue);
    delaymsecs(200);
    return num;
    return 0;
}


QString getResultInfo(int flag, QString name)
{
    name.append("  ");
    QString reStr;
    switch(flag)
    {
    case 0:
        //reStr = name + tr("参数整定成功\n");
        reStr = name + QObject::tr("send success!\n");
        break;

    case -1:
        //reStr = name + tr("维护网络未连接\n");
        reStr = name + QObject::tr("net not connected!\n");
        break;

    case -2:
        //reStr = name + tr("控制站的模式不是维护模式\n");
        reStr = name + QObject::tr("not serv mode!\n");
        break;

    case -3:
        //reStr = name + tr("主控制器（0槽）参数整定未成功\n");
        reStr = name + QObject::tr("main controller send failed!\n");
        break;

    case -4:
        //reStr = name + tr("从控制器（1槽）参数整定未成功\n");
        reStr = name + QObject::tr("secondary controller send failed!\n");
        break;

    default:
        break;

    }

    return reStr;
}

char myTemp[64];
char *get1000PointNameByIndex(int index)
{
    QString tt = BPanelMapWidget1Points.keys().at(index);
    QString tt2 = BPanelMapWidget1Points.value(tt).split("#").first();  //2018.12.31 GM
    //qDebug()<<"get1000PointNameByIndex"<<"index="<<index<<"name="<<tt;
    memset(myTemp, '\0', 64);

    memcpy(myTemp, tt2.toStdString().c_str(), tt2.length());
    return myTemp;

}



void setValueByIndex(int index, float value)
{
    if(index < BPanelMapWidget1Points.count())
    {
        QString key = BPanelMapWidget1Points.keys().at(index);
        //qDebug()<<index<<key<<BPanelMapWidget1Points.value(key);

        BPanelMapValue.insert(key, QString::number(value));
        //qDebug()<<"GMGM~~";
       // qDebug()<<BPanelMapValue;
    }
}
