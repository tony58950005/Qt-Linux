#-------------------------------------------------
#
# Project created by QtCreator 2021-04-25T10:29:25
#
#-------------------------------------------------

QT       += core gui serialport
QT       += widgets
QT	+= serialport

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport
#requires(qtConfig(combobox))

#greaterThan(QT_MAJOR_VERSION, 4) {
#    QT       += widgets serialport
#    requires(qtConfig(combobox))
#} else {
#    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
#}

TARGET = QSerial
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animation.cpp \
    serialwidget.cpp \
    settingwidget.cpp

HEADERS  += mainwindow.h \
    animation.h \
    serialwidget.h \
    settingwidget.h

RESOURCES += \
    pic.qrc
