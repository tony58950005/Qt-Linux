#ifndef OPENOTHERAPP_H
#define OPENOTHERAPP_H

#include <QObject>
#include <QQuickItem>
#include <QVariant>
#include <QDebug>
#include <QTimer>
#include <QProcess>

class OpenOtherApp:public QObject
{
    Q_OBJECT
    Q_PROPERTY(void best NOTIFY bestChanged)
public:
    OpenOtherApp(QObject *parent=0);
    ~OpenOtherApp();
signals:
    void bestChanged();

public slots:
    void openClock();

private:
    void best();
    void setBest(double value);
    QTimer m_timer;

};

#endif // OPENOTHERAPP_H
