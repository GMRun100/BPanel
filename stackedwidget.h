#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QStackedWidget>
#include "widget.h"
#include "widget2.h"
#include "ParameterAdjust.h"


namespace Ui {
class StackedWidget;
}

extern QMap<QString, QString> BPanelMapValue;
extern QMap<QString, QString> BPanelMapWidget1Points;
extern QMap<QString, QString> BPanelMapWidget0Points;

static QString getDispalyPoint(QString key) {    return  BPanelMapWidget1Points.value(key).split("#").first(); }
//static QString get8000Point(QString key) {    return  BPanelMapWidget1Points.value(key).split("#").last();  }
//2019.1.1 GM
static QString get8000Point(QString key) {    return  BPanelMapWidget0Points.value(key).split("#").last();  }
static QString get8000Point2(QString key) {    return  BPanelMapWidget1Points.value(key).split("#").last();  }
static QString getValueByName(QString name)  { return BPanelMapValue.value(name); }

void delaymsecs( int msecs);
int setAnolog(const char *paramterName, float parameterValue);
int setDigital(const char *paramterName, BYTE variableValue);
QString getResultInfo(int flag, QString name);


char *get1000PointNameByIndex(int index);
void setValueByIndex(int index, float value);


class StackedWidget : public QStackedWidget
{
    Q_OBJECT
    
public:
     StackedWidget(QWidget *parent = 0);
    ~StackedWidget();



    Widget *widget1;
    Widget2 *widget2;

     void (*myFun)();
     void setMyFun( void(*pfun)() ) {  myFun = pfun; }


     char Temp[64];
     char* getFirstPoint(QString name);
     char* getLastPoint(QString name);



    
private slots:
    void changeWidget2Slot();
    void changeWidget1Slot();

    void goHome();

private:
    Ui::StackedWidget *ui;
};

#endif // STACKEDWIDGET_H
