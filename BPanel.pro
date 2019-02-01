#-------------------------------------------------
#
# Project created by QtCreator 2017-08-16T09:58:41
#
#-------------------------------------------------

QT += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BPanel

#TEMPLATE = lib
TEMPLATE = lib
#DESTDIR = F:/NicBuilder_Source/bin/Release/
#DESTDIR = F:/NicBuilder_Source/bin/Debug/
DESTDIR = D:/CNCS/NicSys1000/NicSys1000_dev/trunk/02.Software/02.DB/branches/english_version/bin/Release
#DESTDIR = D:/CNCS/NicSys1000/NicSys1000_dev/trunk/02.Software/02.DB/branches/english_version/bin/Debug
CONFIG += staticlib



#TEMPLATE = lib
#DESTDIR = E:/english_version/bin/Release/
#CONFIG += staticlib

#DEFINES += MYSHAREDLIB_LIBRARY

LIBS += -lParameterAdjust

SOURCES += main.cpp\
        widget.cpp \
    mylineedit.cpp \
    stackedwidget.cpp \
    widget2.cpp

HEADERS  += widget.h \
    ParameterAdjust.h \
    mylineedit.h \
    widget2.h \
    stackedwidget.h

FORMS    += widget.ui \
    stackedwidget.ui \
    widget2.ui
