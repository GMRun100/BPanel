#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include  <QtCore/QTextStream>

extern int curCheckNum;
namespace Ui {
class Widget;
}

//class QFtp;

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


    void ConfirmEnable(bool flag);


    void (*getCurK2)(char flag, float &oldpower, float &oldk2);


    void setK2Fun( void(*K2fun)(char, float&, float&) )  { getCurK2 = K2fun;  }

    void setCabinetStateValue(int manul, int autossig, int cont );
    void setLineShowABC(double a, double b, double c);

    
private slots:

    void on_pushButton_back_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_confirm_clicked();

    void CreateLedFile();

    void on_pushButton_Chinese_clicked();

    void on_pushButton_English_clicked();

    void on_toolButton_LOCK_clicked();



    void on_toolButton_pumpA_clicked(bool checked);

    void on_toolButton_pumpB_clicked(bool checked);

    void on_toolButton_pumpC_clicked(bool checked);

    void on_toolButton_pumpD_clicked(bool checked);



    void on_toolButton_Send_clicked();

    void on_radioButton_a_toggled(bool checked);

    void on_radioButton_b_toggled(bool checked);

    void on_radioButton_c_toggled(bool checked);

    void on_radioButton_d_toggled(bool checked);

    void on_pushButton_k2_A_clicked();

    void on_pushButton_k2_B_clicked();

    void on_pushButton_k2_C_clicked();

    void on_pushButton_toWidget2_clicked();

private:
    Ui::Widget *ui;
    int runMode, pumpMode, selectedPumpCount;

    void sendPumpSelect();

    //QFtp *ftp;

signals:
    void changeWidget2();
    void goHomeSig();
};

#endif // WIDGET_H
