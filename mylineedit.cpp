#include "mylineedit.h"
#include <QDebug>
#include <QMessageBox>
#include "widget.h"
MyLineEdit::MyLineEdit(QWidget *parent)
    : QLineEdit(parent)
{

    connect(this, SIGNAL(textChanged(QString)), this, SLOT(checkInputValue(QString )));
}

void MyLineEdit::checkInputValue(QString temp)
{
    int num = temp.toInt();
   // if(num>curCheckNum)
    //    this->setText( temp.remove( temp.length()-1, 1 ) );

    switch (curCheckNum) {
    case 1:

        if(num>15000)
        {
            ((Widget*)parent()->parent())->ConfirmEnable(false);
            //QMessageBox::warning(NULL, tr("Warning"), tr("输入值必须小于15000！"));
            QMessageBox::warning(NULL, tr("Warning"), tr("Value should not be more than 15000!"));
        }
        else
            ((Widget*)parent()->parent())->ConfirmEnable(true);


        break;
    case 2:

        if(num>10000)
        {
            ((Widget*)parent()->parent())->ConfirmEnable(false);
             QMessageBox::warning(NULL, tr("Warning"), tr("Value should not be more than 10000!"));
        }
        else
            ((Widget*)parent()->parent())->ConfirmEnable(true);


        break;
    case 3:

        if(num>3000)
        {
            ((Widget*)parent()->parent())->ConfirmEnable(false);
             QMessageBox::warning(NULL, tr("Warning"), tr("Value should not be more than 3000!"));
        }
        else
            ((Widget*)parent()->parent())->ConfirmEnable(true);

        break;
    case 4:

        if(num>30)
        {
            ((Widget*)parent()->parent())->ConfirmEnable(false);
             QMessageBox::warning(NULL, tr("Warning"), tr("Value should not be more than 30!"));
        }
        else
            ((Widget*)parent()->parent())->ConfirmEnable(true);


        break;
    default:
        break;
    }

}
