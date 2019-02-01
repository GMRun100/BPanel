#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Widget2;
}
/*
class MyButton : public QPushButton
{
    Q_OBJECT

public:
    MyButton(QWidget *parent);

private slots:
    void myButtonClicked();

};*/

class Widget2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget2(QWidget *parent = 0);
    ~Widget2();

    //2018.12.31 GM
    void calc(float current, float K1, float K2, int *num1, float *num2);


public slots:
    void updateValue();
    void sendk3k4();

    
private slots:
    void on_pushButton_changeWidget1_clicked();

    void on_pushButton_back_clicked();



    //void on_pushButton_d3_clicked();

   // void on_pushButton_d10_clicked();

   // void on_pushButton_d12_clicked();

    void on_pushButton_d2_clicked();

    void on_pushButton_d6_clicked();

    void on_pushButton_d4_clicked();

    void on_pushButton_d5_clicked();

    void on_pushButton_d1_clicked();

    void on_pushButton_d8_clicked();

    void on_pushButton_d7_clicked();

    void on_pushButton_d14_clicked();
    //2019.01.04 GM
    void on_pushButton_D2D9_cal_k2_clicked();
    void on_pushButton_D6D13_CAL_K2_clicked();
    void on_pushButton_D4_D11_CAL_K2_clicked();
    void on_pushButton_D5_CAL_k2_clicked();
    void on_pushButton_D1_CAL_K2_clicked();
    void on_pushButton_D8_CAL_K2_clicked();
    void on_pushButton_D7_CAL_K2_clicked();
    void on_pushButton_D14_CAL_K2_clicked();




signals:
    void changeWidget1();
    void goHomeSig();

private:
    Ui::Widget2 *ui;

};

#endif // WIDGET2_H
