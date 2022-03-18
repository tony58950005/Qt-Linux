#-------------------------------------------------
#
# Project created by QtCreator 2021-04-22T10:09:11
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QClock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animation.cpp \
    timeonline.cpp \
    timewidget.cpp

HEADERS  += mainwindow.h \
    animation.h \
    timeonline.h \
    timewidget.h

RESOURCES += \
    pic.qrc
