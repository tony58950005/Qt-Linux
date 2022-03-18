#ifndef BUZZER_H
#define BUZZER_H

#include <QObject>
#include <QWidget>

class Buzzer : public QWidget
{
    Q_OBJECT
public:
    explicit Buzzer(QWidget *parent = nullptr);

    void buzzerNone();
    void buzzerOff();
    void buzzerOn();
    void buzzerHearbeat();

signals:

public slots:

private:
    const QString                   devPath             ="/sys/class/leds/beep";
    int                             statusFlag;
    char *                          charCmdNone;
    char *                          charCmdOff;
    char *                          charCmdOn;
    char *                          charCmdHeartbeat;
};

#endif // BUZZER_H
