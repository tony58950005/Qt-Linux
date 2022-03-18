#-------------------------------------------------
#
# Project created by QtCreator 2021-04-25T10:05:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCan
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animation.cpp \
    qabstractcan.cpp \
    qabstractcanUI.cpp \
    opendialog.cpp

HEADERS  += mainwindow.h \
    animation.h \
    qabstractcan.h \
    opendialog.h

RESOURCES += \
    pic.qrc
