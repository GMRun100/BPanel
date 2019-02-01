#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H
#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit(QWidget *parent);

private slots:
    void checkInputValue(QString temp);
};

#endif // MYLINEEDIT_H
