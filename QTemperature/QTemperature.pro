#-------------------------------------------------
#
# Project created by QtCreator 2021-04-20T10:33:14
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTemperature
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animation.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    animation.h \
    qcustomplot.h

RESOURCES += \
    pic.qrc
