#include "stackedwidget.h"
#include <QApplication>
#include <QTextCodec>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
  //  QTextCodec::setCodecForLocale(QTextCodec::codecForName("gbk"));
   // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gbk"));


//    Widget w;
//    w.show();
    StackedWidget sw;
    sw.show();
    
    return a.exec();
}
