#-------------------------------------------------
#
# Project created by QtCreator 2021-04-16T14:57:04
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QWeather
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animation.cpp \
    weather.cpp \
    weekweatherlabel.cpp

HEADERS  += mainwindow.h \
    animation.h \
    weather.h \
    weekweatherlabel.h

RESOURCES += \
    pic.qrc
