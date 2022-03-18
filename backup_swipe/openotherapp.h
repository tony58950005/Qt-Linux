#ifndef OPENOTHERAPP_H
#define OPENOTHERAPP_H

#include <QObject>
#include <QQuickItem>
#include <QVariant>
#include <QDebug>
#include <QTimer>
#include <QProcess>
#include <QQmlEngine>
#include <QProcess>
#include <QQuickWindow>
#include <QtQml>
#include <QQuickView>
#include <QEvent>
#include <QTimer>

#include <QPropertyAnimation>

class OpenOtherApp:public QObject
{
    Q_OBJECT
    Q_PROPERTY(void best NOTIFY bestChanged)
public:
    OpenOtherApp(QObject *parent=0);
    ~OpenOtherApp();
    QObject QApp;
signals:
    void bestChanged();

public slots:
    void openCalendar();
    void openClock();
    void openSerial();
    void openRs485();
    void openCan();
    void openLed();
    void openTemperature();
    void openWeather();
    void openBuzzer();
    void openBearmonitor();
    void openMediaplayer();
    void openGps();
    void openPictureviewer();
    void openFileview();
    void openTetris();
    void openWuziqi();
    void openSnake();

private:
    void best();
    void setBest(double value);
    QTimer m_timer;


};

#endif // OPENOTHERAPP_H
