#-------------------------------------------------
#
# Project created by QtCreator 2021-04-23T09:20:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCalendar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animation.cpp \
    timeonline.cpp

HEADERS  += mainwindow.h \
    animation.h \
    timeonline.h

RESOURCES += \
    pic.qrc
