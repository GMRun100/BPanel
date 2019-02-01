/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mylineedit.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_Title_yxfs;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_yxfs;
    QLabel *label_zsbyxfs;
    QLabel *label_gldzfw;
    QRadioButton *radioButton_a;
    QRadioButton *radioButton_b;
    QRadioButton *radioButton_c;
    QRadioButton *radioButton_d;
    QLabel *label_bkxtms;
    QPushButton *pushButton_cabinet;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_tile_zsb;
    QGroupBox *groupBox_pump;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton_pumpD;
    QToolButton *toolButton_Send;
    QToolButton *toolButton_pumpA;
    QToolButton *toolButton_pumpB;
    QToolButton *toolButton_pumpC;
    QLabel *label_lastPump;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_title_gldzsd;
    QGroupBox *groupBox_set;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_channelA;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_ChannelB;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_ChannelC;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_edit;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_confirm;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    MyLineEdit *lineEdit_A;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_12;
    MyLineEdit *lineEdit_B;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_18;
    MyLineEdit *lineEdit_C;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *lineShow_A;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_19;
    QLineEdit *lineShow_B;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_20;
    QLineEdit *lineShow_C;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pushButton_back;
    QToolButton *toolButton_LOCK;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *pushButton_toWidget2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1224, 556);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(192, 192, 192, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Widget->setPalette(palette);
        gridLayout_4 = new QGridLayout(Widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Title_yxfs = new QLabel(Widget);
        label_Title_yxfs->setObjectName(QStringLiteral("label_Title_yxfs"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_Title_yxfs->sizePolicy().hasHeightForWidth());
        label_Title_yxfs->setSizePolicy(sizePolicy);
        label_Title_yxfs->setMinimumSize(QSize(460, 60));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_Title_yxfs->setFont(font);
        label_Title_yxfs->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Title_yxfs);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_yxfs = new QLabel(groupBox);
        label_yxfs->setObjectName(QStringLiteral("label_yxfs"));
        sizePolicy.setHeightForWidth(label_yxfs->sizePolicy().hasHeightForWidth());
        label_yxfs->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(16);
        label_yxfs->setFont(font1);

        gridLayout->addWidget(label_yxfs, 0, 0, 1, 1);

        label_zsbyxfs = new QLabel(groupBox);
        label_zsbyxfs->setObjectName(QStringLiteral("label_zsbyxfs"));
        sizePolicy.setHeightForWidth(label_zsbyxfs->sizePolicy().hasHeightForWidth());
        label_zsbyxfs->setSizePolicy(sizePolicy);
        label_zsbyxfs->setFont(font1);

        gridLayout->addWidget(label_zsbyxfs, 0, 1, 1, 1);

        label_gldzfw = new QLabel(groupBox);
        label_gldzfw->setObjectName(QStringLiteral("label_gldzfw"));
        sizePolicy.setHeightForWidth(label_gldzfw->sizePolicy().hasHeightForWidth());
        label_gldzfw->setSizePolicy(sizePolicy);
        label_gldzfw->setFont(font1);

        gridLayout->addWidget(label_gldzfw, 0, 2, 1, 2);

        radioButton_a = new QRadioButton(groupBox);
        radioButton_a->setObjectName(QStringLiteral("radioButton_a"));
        radioButton_a->setEnabled(true);
        QFont font2;
        font2.setPointSize(18);
        radioButton_a->setFont(font2);
        radioButton_a->setStyleSheet(QLatin1String("QRadioButton::indicator::unchecked{   border-width: 2px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: white;\n"
"width:30px; height:30px;\n"
"border-top-left-radius:16px;border-bottom-right-radius:16px;  border-top-right-radius:16px;border-bottom-left-radius:16px;\n"
" }\n"
"QRadioButton::indicator::checked{ \n"
" border-width: 2px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: green;\n"
"width:30px; height:30px;\n"
"border-top-left-radius:16px;border-bottom-right-radius:16px;  border-top-right-radius:16px;border-bottom-left-radius:16px;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(radioButton_a, 1, 0, 1, 4);

        radioButton_b = new QRadioButton(groupBox);
        radioButton_b->setObjectName(QStringLiteral("radioButton_b"));
        radioButton_b->setFont(font2);
        radioButton_b->setStyleSheet(QLatin1String("QRadioButton::indicator::unchecked{   border-width: 2px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: white;\n"
"width:30px; height:30px;\n"
"border-top-left-radius:16px;border-bottom-right-radius:16px;  border-top-right-radius:16px;border-bottom-left-radius:16px;\n"
" }\n"
"QRadioButton::indicator::checked{ \n"
" border-width: 2px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: green;\n"
"width:30px; height:30px;\n"
"border-top-left-radius:16px;border-bottom-right-radius:16px;  border-top-right-radius:16px;border-bottom-left-radius:16px;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(radioButton_b, 2, 0, 1, 4);

        radioButton_c = new QRadioButton(groupBox);
        radioButton_c->setObjectName(QStringLiteral("radioButton_c"));
        radioButton_c->setFont(font2);
        radioButton_c->setStyleSheet(QLatin1String("QRadioButton::indicator::unchecked{   border-width: 2px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: white;\n"
"width:30px; height:30px;\n"
"border-top-left-radius:16px;border-bottom-right-radius:16px;  border-top-right-radius:16px;border-bottom-left-radius:16px;\n"
" }\n"
"QRadioButton::indicator::checked{ \n"
" border-width: 2px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: green;\n"
"width:30px; height:30px;\n"
"border-top-left-radius:16px;border-bottom-right-radius:16px;  border-top-right-radius:16px;border-bottom-left-radius:16px;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(radioButton_c, 3, 0, 1, 4);

        radioButton_d = new QRadioButton(groupBox);
        radioButton_d->setObjectName(QStringLiteral("radioButton_d"));
        radioButton_d->setFont(font2);
        radioButton_d->setStyleSheet(QLatin1String("QRadioButton::indicator::unchecked{   border-width: 2px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: white;\n"
"width:30px; height:30px;\n"
"border-top-left-radius:16px;border-bottom-right-radius:16px;  border-top-right-radius:16px;border-bottom-left-radius:16px;\n"
" }\n"
"QRadioButton::indicator::checked{ \n"
" border-width: 2px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: green;\n"
"width:30px; height:30px;\n"
"border-top-left-radius:16px;border-bottom-right-radius:16px;  border-top-right-radius:16px;border-bottom-left-radius:16px;\n"
" }\n"
""));

        gridLayout->addWidget(radioButton_d, 4, 0, 1, 4);

        label_bkxtms = new QLabel(groupBox);
        label_bkxtms->setObjectName(QStringLiteral("label_bkxtms"));
        QFont font3;
        font3.setPointSize(24);
        label_bkxtms->setFont(font3);
        label_bkxtms->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_bkxtms, 5, 0, 1, 2);

        pushButton_cabinet = new QPushButton(groupBox);
        pushButton_cabinet->setObjectName(QStringLiteral("pushButton_cabinet"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_cabinet->sizePolicy().hasHeightForWidth());
        pushButton_cabinet->setSizePolicy(sizePolicy2);
        pushButton_cabinet->setMinimumSize(QSize(60, 60));
        QFont font4;
        font4.setPointSize(17);
        pushButton_cabinet->setFont(font4);
        pushButton_cabinet->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pushButton_cabinet, 5, 2, 1, 1);


        verticalLayout->addWidget(groupBox);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_tile_zsb = new QLabel(Widget);
        label_tile_zsb->setObjectName(QStringLiteral("label_tile_zsb"));
        sizePolicy.setHeightForWidth(label_tile_zsb->sizePolicy().hasHeightForWidth());
        label_tile_zsb->setSizePolicy(sizePolicy);
        label_tile_zsb->setMinimumSize(QSize(0, 60));
        label_tile_zsb->setFont(font);
        label_tile_zsb->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_tile_zsb);

        groupBox_pump = new QGroupBox(Widget);
        groupBox_pump->setObjectName(QStringLiteral("groupBox_pump"));
        sizePolicy1.setHeightForWidth(groupBox_pump->sizePolicy().hasHeightForWidth());
        groupBox_pump->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(groupBox_pump);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        toolButton_pumpD = new QToolButton(groupBox_pump);
        toolButton_pumpD->setObjectName(QStringLiteral("toolButton_pumpD"));
        sizePolicy2.setHeightForWidth(toolButton_pumpD->sizePolicy().hasHeightForWidth());
        toolButton_pumpD->setSizePolicy(sizePolicy2);
        toolButton_pumpD->setMinimumSize(QSize(95, 60));
        QFont font5;
        font5.setPointSize(19);
        font5.setBold(true);
        font5.setWeight(75);
        toolButton_pumpD->setFont(font5);
        toolButton_pumpD->setStyleSheet(QLatin1String("QToolButton{   border-width: 6px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: gray;\n"
" }\n"
" QToolButton:checked{ background-color: yellow;   border-color: yellow; }"));
        toolButton_pumpD->setCheckable(true);

        gridLayout_2->addWidget(toolButton_pumpD, 4, 0, 1, 1);

        toolButton_Send = new QToolButton(groupBox_pump);
        toolButton_Send->setObjectName(QStringLiteral("toolButton_Send"));
        sizePolicy2.setHeightForWidth(toolButton_Send->sizePolicy().hasHeightForWidth());
        toolButton_Send->setSizePolicy(sizePolicy2);
        toolButton_Send->setMinimumSize(QSize(95, 60));
        toolButton_Send->setFont(font5);
        toolButton_Send->setStyleSheet(QLatin1String("QToolButton{   border-width: 6px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: gray;\n"
" }\n"
" QToolButton:pressed{ background-color: yellow;   border-color: yellow; }"));
        toolButton_Send->setCheckable(true);

        gridLayout_2->addWidget(toolButton_Send, 5, 0, 1, 1);

        toolButton_pumpA = new QToolButton(groupBox_pump);
        toolButton_pumpA->setObjectName(QStringLiteral("toolButton_pumpA"));
        sizePolicy2.setHeightForWidth(toolButton_pumpA->sizePolicy().hasHeightForWidth());
        toolButton_pumpA->setSizePolicy(sizePolicy2);
        toolButton_pumpA->setMinimumSize(QSize(95, 60));
        toolButton_pumpA->setFont(font5);
        toolButton_pumpA->setStyleSheet(QLatin1String("QToolButton{   border-width: 6px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: gray;\n"
" }\n"
" QToolButton:checked{ background-color: yellow;   border-color: yellow; }"));
        toolButton_pumpA->setCheckable(true);
        toolButton_pumpA->setPopupMode(QToolButton::DelayedPopup);

        gridLayout_2->addWidget(toolButton_pumpA, 1, 0, 1, 1);

        toolButton_pumpB = new QToolButton(groupBox_pump);
        toolButton_pumpB->setObjectName(QStringLiteral("toolButton_pumpB"));
        sizePolicy2.setHeightForWidth(toolButton_pumpB->sizePolicy().hasHeightForWidth());
        toolButton_pumpB->setSizePolicy(sizePolicy2);
        toolButton_pumpB->setMinimumSize(QSize(95, 60));
        toolButton_pumpB->setFont(font5);
        toolButton_pumpB->setStyleSheet(QLatin1String("QToolButton{   border-width: 6px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: gray;\n"
" }\n"
" QToolButton:checked{ background-color: yellow;   border-color: yellow; }"));
        toolButton_pumpB->setCheckable(true);

        gridLayout_2->addWidget(toolButton_pumpB, 2, 0, 1, 1);

        toolButton_pumpC = new QToolButton(groupBox_pump);
        toolButton_pumpC->setObjectName(QStringLiteral("toolButton_pumpC"));
        sizePolicy2.setHeightForWidth(toolButton_pumpC->sizePolicy().hasHeightForWidth());
        toolButton_pumpC->setSizePolicy(sizePolicy2);
        toolButton_pumpC->setMinimumSize(QSize(95, 60));
        toolButton_pumpC->setFont(font5);
        toolButton_pumpC->setStyleSheet(QLatin1String("QToolButton{   border-width: 6px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: gray;\n"
" }\n"
" QToolButton:checked{ background-color: yellow;   border-color: yellow; }"));
        toolButton_pumpC->setCheckable(true);

        gridLayout_2->addWidget(toolButton_pumpC, 3, 0, 1, 1);

        label_lastPump = new QLabel(groupBox_pump);
        label_lastPump->setObjectName(QStringLiteral("label_lastPump"));
        sizePolicy.setHeightForWidth(label_lastPump->sizePolicy().hasHeightForWidth());
        label_lastPump->setSizePolicy(sizePolicy);
        label_lastPump->setFont(font1);
        label_lastPump->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_lastPump, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_pump);


        gridLayout_4->addLayout(verticalLayout_2, 0, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_title_gldzsd = new QLabel(Widget);
        label_title_gldzsd->setObjectName(QStringLiteral("label_title_gldzsd"));
        sizePolicy.setHeightForWidth(label_title_gldzsd->sizePolicy().hasHeightForWidth());
        label_title_gldzsd->setSizePolicy(sizePolicy);
        label_title_gldzsd->setMinimumSize(QSize(0, 60));
        label_title_gldzsd->setFont(font);
        label_title_gldzsd->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_title_gldzsd);

        groupBox_set = new QGroupBox(Widget);
        groupBox_set->setObjectName(QStringLiteral("groupBox_set"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_set->sizePolicy().hasHeightForWidth());
        groupBox_set->setSizePolicy(sizePolicy3);
        gridLayout_3 = new QGridLayout(groupBox_set);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);

        label_channelA = new QLabel(groupBox_set);
        label_channelA->setObjectName(QStringLiteral("label_channelA"));
        sizePolicy.setHeightForWidth(label_channelA->sizePolicy().hasHeightForWidth());
        label_channelA->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setFamily(QStringLiteral("Times New Roman"));
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setWeight(75);
        label_channelA->setFont(font6);
        label_channelA->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_channelA);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        label_ChannelB = new QLabel(groupBox_set);
        label_ChannelB->setObjectName(QStringLiteral("label_ChannelB"));
        sizePolicy.setHeightForWidth(label_ChannelB->sizePolicy().hasHeightForWidth());
        label_ChannelB->setSizePolicy(sizePolicy);
        label_ChannelB->setFont(font6);
        label_ChannelB->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_ChannelB);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_15);

        label_ChannelC = new QLabel(groupBox_set);
        label_ChannelC->setObjectName(QStringLiteral("label_ChannelC"));
        sizePolicy.setHeightForWidth(label_ChannelC->sizePolicy().hasHeightForWidth());
        label_ChannelC->setSizePolicy(sizePolicy);
        label_ChannelC->setFont(font6);
        label_ChannelC->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_ChannelC);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_16);


        gridLayout_3->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButton_edit = new QPushButton(groupBox_set);
        pushButton_edit->setObjectName(QStringLiteral("pushButton_edit"));
        sizePolicy2.setHeightForWidth(pushButton_edit->sizePolicy().hasHeightForWidth());
        pushButton_edit->setSizePolicy(sizePolicy2);
        pushButton_edit->setMinimumSize(QSize(75, 60));
        QFont font7;
        font7.setFamily(QStringLiteral("Times New Roman"));
        pushButton_edit->setFont(font7);
        pushButton_edit->setAutoFillBackground(false);
        pushButton_edit->setStyleSheet(QLatin1String(" QPushButton{   border-width: 6px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: gray;\n"
" }\n"
" QPushButton:hover{ background-color: yellow;   border-color: yellow; }"));
        pushButton_edit->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_edit);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        pushButton_cancel = new QPushButton(groupBox_set);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        sizePolicy2.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy2);
        pushButton_cancel->setMinimumSize(QSize(75, 60));
        pushButton_cancel->setFont(font7);
        pushButton_cancel->setAutoFillBackground(false);
        pushButton_cancel->setStyleSheet(QLatin1String(" QPushButton{   border-width: 6px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: gray;\n"
" }\n"
" QPushButton:hover{ background-color: yellow;   border-color: yellow; }"));
        pushButton_cancel->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_cancel);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        pushButton_confirm = new QPushButton(groupBox_set);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        sizePolicy2.setHeightForWidth(pushButton_confirm->sizePolicy().hasHeightForWidth());
        pushButton_confirm->setSizePolicy(sizePolicy2);
        pushButton_confirm->setMinimumSize(QSize(75, 60));
        pushButton_confirm->setFont(font7);
        pushButton_confirm->setAutoFillBackground(false);
        pushButton_confirm->setStyleSheet(QLatin1String(" QPushButton{   border-width: 6px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: gray;\n"
" }\n"
" QPushButton:hover{ background-color: yellow;   border-color: yellow; }"));
        pushButton_confirm->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_confirm);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout_3->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(13, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        lineEdit_A = new MyLineEdit(groupBox_set);
        lineEdit_A->setObjectName(QStringLiteral("lineEdit_A"));
        lineEdit_A->setEnabled(false);
        sizePolicy2.setHeightForWidth(lineEdit_A->sizePolicy().hasHeightForWidth());
        lineEdit_A->setSizePolicy(sizePolicy2);
        lineEdit_A->setMinimumSize(QSize(120, 0));
        lineEdit_A->setMaxLength(10);
        lineEdit_A->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_A);

        label_5 = new QLabel(groupBox_set);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_12 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        lineEdit_B = new MyLineEdit(groupBox_set);
        lineEdit_B->setObjectName(QStringLiteral("lineEdit_B"));
        lineEdit_B->setEnabled(false);
        sizePolicy2.setHeightForWidth(lineEdit_B->sizePolicy().hasHeightForWidth());
        lineEdit_B->setSizePolicy(sizePolicy2);
        lineEdit_B->setMinimumSize(QSize(120, 0));
        lineEdit_B->setMaximumSize(QSize(80, 16777215));
        lineEdit_B->setMaxLength(10);
        lineEdit_B->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_B);

        label_6 = new QLabel(groupBox_set);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);

        horizontalLayout_5->addWidget(label_6);

        horizontalSpacer_18 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_18);

        lineEdit_C = new MyLineEdit(groupBox_set);
        lineEdit_C->setObjectName(QStringLiteral("lineEdit_C"));
        lineEdit_C->setEnabled(false);
        sizePolicy2.setHeightForWidth(lineEdit_C->sizePolicy().hasHeightForWidth());
        lineEdit_C->setSizePolicy(sizePolicy2);
        lineEdit_C->setMaxLength(10);
        lineEdit_C->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_C);

        label = new QLabel(groupBox_set);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        lineShow_A = new QLineEdit(groupBox_set);
        lineShow_A->setObjectName(QStringLiteral("lineShow_A"));
        lineShow_A->setEnabled(false);
        sizePolicy2.setHeightForWidth(lineShow_A->sizePolicy().hasHeightForWidth());
        lineShow_A->setSizePolicy(sizePolicy2);
        lineShow_A->setMinimumSize(QSize(120, 0));
        lineShow_A->setMaximumSize(QSize(80, 16777215));
        QFont font8;
        font8.setFamily(QStringLiteral("Times New Roman"));
        font8.setPointSize(14);
        lineShow_A->setFont(font8);
        lineShow_A->setStyleSheet(QStringLiteral("QLineEdit{ background-color: rgb(192,192,192);  border-width: 2px;border-style: double; border-color: blue;}"));
        lineShow_A->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineShow_A);

        label_2 = new QLabel(groupBox_set);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_19 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_19);

        lineShow_B = new QLineEdit(groupBox_set);
        lineShow_B->setObjectName(QStringLiteral("lineShow_B"));
        lineShow_B->setEnabled(false);
        sizePolicy2.setHeightForWidth(lineShow_B->sizePolicy().hasHeightForWidth());
        lineShow_B->setSizePolicy(sizePolicy2);
        lineShow_B->setMinimumSize(QSize(120, 0));
        lineShow_B->setMaximumSize(QSize(80, 16777215));
        lineShow_B->setFont(font8);
        lineShow_B->setStyleSheet(QStringLiteral("QLineEdit{ background-color: rgb(192,192,192);  border-width: 2px;border-style: double; border-color: blue;}"));
        lineShow_B->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineShow_B);

        label_3 = new QLabel(groupBox_set);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_20);

        lineShow_C = new QLineEdit(groupBox_set);
        lineShow_C->setObjectName(QStringLiteral("lineShow_C"));
        lineShow_C->setEnabled(false);
        sizePolicy2.setHeightForWidth(lineShow_C->sizePolicy().hasHeightForWidth());
        lineShow_C->setSizePolicy(sizePolicy2);
        lineShow_C->setMinimumSize(QSize(120, 0));
        lineShow_C->setMaximumSize(QSize(80, 16777215));
        lineShow_C->setFont(font8);
        lineShow_C->setStyleSheet(QStringLiteral("QLineEdit{ background-color: rgb(192,192,192);  border-width: 2px;border-style: double; border-color: blue;}"));
        lineShow_C->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineShow_C);

        label_4 = new QLabel(groupBox_set);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_17);


        gridLayout_3->addLayout(horizontalLayout_4, 2, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_set);


        gridLayout_4->addLayout(verticalLayout_3, 0, 3, 1, 1);

        pushButton_back = new QPushButton(Widget);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        sizePolicy2.setHeightForWidth(pushButton_back->sizePolicy().hasHeightForWidth());
        pushButton_back->setSizePolicy(sizePolicy2);
        pushButton_back->setMinimumSize(QSize(0, 60));
        QFont font9;
        font9.setFamily(QStringLiteral("Times New Roman"));
        font9.setPointSize(20);
        font9.setBold(true);
        font9.setWeight(75);
        pushButton_back->setFont(font9);
        pushButton_back->setStyleSheet(QStringLiteral(""));

        gridLayout_4->addWidget(pushButton_back, 1, 0, 1, 1);

        toolButton_LOCK = new QToolButton(Widget);
        toolButton_LOCK->setObjectName(QStringLiteral("toolButton_LOCK"));
        sizePolicy2.setHeightForWidth(toolButton_LOCK->sizePolicy().hasHeightForWidth());
        toolButton_LOCK->setSizePolicy(sizePolicy2);
        toolButton_LOCK->setMinimumSize(QSize(80, 60));
        toolButton_LOCK->setFont(font9);
        toolButton_LOCK->setStyleSheet(QLatin1String("QToolButton{   border-width: 6px;\n"
"     border-style: solid;\n"
"     border-color: gray;\n"
"	background-color: gray;\n"
" }\n"
" QToolButton:checked{ background-color: yellow;   border-color: yellow; }"));
        toolButton_LOCK->setCheckable(true);

        gridLayout_4->addWidget(toolButton_LOCK, 1, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_21);

        pushButton_toWidget2 = new QPushButton(Widget);
        pushButton_toWidget2->setObjectName(QStringLiteral("pushButton_toWidget2"));
        sizePolicy4.setHeightForWidth(pushButton_toWidget2->sizePolicy().hasHeightForWidth());
        pushButton_toWidget2->setSizePolicy(sizePolicy4);
        pushButton_toWidget2->setFont(font9);

        horizontalLayout_7->addWidget(pushButton_toWidget2);


        gridLayout_4->addLayout(horizontalLayout_7, 1, 3, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_Title_yxfs->setText(QApplication::translate("Widget", "\345\217\215\345\272\224\345\240\206\350\277\220\350\241\214\346\226\271\345\274\217", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_yxfs->setText(QApplication::translate("Widget", "\350\277\220\350\241\214\346\226\271\345\274\217", Q_NULLPTR));
        label_zsbyxfs->setText(QApplication::translate("Widget", "\351\207\215\346\260\264\346\263\265\350\277\220\350\241\214\346\226\271\345\274\217", Q_NULLPTR));
        label_gldzfw->setText(QApplication::translate("Widget", "\345\205\201\350\256\270\345\212\237\347\216\207\345\256\232\345\200\274\350\214\203\345\233\264", Q_NULLPTR));
        radioButton_a->setText(QApplication::translate("Widget", "A     3*3000rpm     P<=15MW", Q_NULLPTR));
        radioButton_b->setText(QApplication::translate("Widget", "B     2*3000rpm     P<=10MW", Q_NULLPTR));
        radioButton_c->setText(QApplication::translate("Widget", "C     2*1500rpm     P<=3MW", Q_NULLPTR));
        radioButton_d->setText(QApplication::translate("Widget", "D     1*1500rpm\346\210\2260\345\217\260  P<=30kW", Q_NULLPTR));
        label_bkxtms->setText(QApplication::translate("Widget", "\346\243\222\346\216\247\347\263\273\347\273\237\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_cabinet->setText(QApplication::translate("Widget", "AUTO", Q_NULLPTR));
        label_tile_zsb->setText(QApplication::translate("Widget", "\351\207\215\346\260\264\346\263\265", Q_NULLPTR));
        groupBox_pump->setTitle(QString());
        toolButton_pumpD->setText(QApplication::translate("Widget", "D", Q_NULLPTR));
        toolButton_Send->setText(QApplication::translate("Widget", "\344\270\213\345\217\221", Q_NULLPTR));
        toolButton_pumpA->setText(QApplication::translate("Widget", "A", Q_NULLPTR));
        toolButton_pumpB->setText(QApplication::translate("Widget", "B", Q_NULLPTR));
        toolButton_pumpC->setText(QApplication::translate("Widget", "C", Q_NULLPTR));
        label_lastPump->setText(QString());
        label_title_gldzsd->setText(QApplication::translate("Widget", "\345\212\237\347\216\207\345\256\232\345\200\274\350\256\276\345\256\232", Q_NULLPTR));
        groupBox_set->setTitle(QString());
        label_channelA->setText(QApplication::translate("Widget", "A\351\200\232\351\201\223", Q_NULLPTR));
        label_ChannelB->setText(QApplication::translate("Widget", "B\351\200\232\351\201\223", Q_NULLPTR));
        label_ChannelC->setText(QApplication::translate("Widget", "C\351\200\232\351\201\223", Q_NULLPTR));
        pushButton_edit->setText(QApplication::translate("Widget", "\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_confirm->setText(QApplication::translate("Widget", "\347\241\256\350\256\244", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "kW", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "kW", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "kW", Q_NULLPTR));
        lineShow_A->setText(QApplication::translate("Widget", "777", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "kW", Q_NULLPTR));
        lineShow_B->setText(QApplication::translate("Widget", "888", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "kW", Q_NULLPTR));
        lineShow_C->setText(QApplication::translate("Widget", "999", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "kW", Q_NULLPTR));
        pushButton_back->setText(QApplication::translate("Widget", "\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        toolButton_LOCK->setText(QApplication::translate("Widget", "\351\224\201\345\256\232", Q_NULLPTR));
        pushButton_toWidget2->setText(QApplication::translate("Widget", "\347\224\265\346\265\201\350\275\254\345\212\237\347\216\207\347\263\273\346\225\260\350\256\276\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
