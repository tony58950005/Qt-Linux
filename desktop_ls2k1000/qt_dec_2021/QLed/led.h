#ifndef LED_H
#define LED_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QProcess>

class Led : public QWidget
{
    Q_OBJECT
public:
    explicit Led(QWidget *parent = nullptr);
    Led(QWidget *parent = nullptr, QString path = nullptr, QString image = nullptr);
    ~Led();

    void ledNone();
    void ledOn();
    void ledOff();
    void ledHeartbeat();

signals:

public slots:
    void offBtnClickedSlot();
    void onBtnClickedSlot();
    void heartBtnClickedSlot();

    void heartImageTimerOutSlot();

private:
    QPushButton             *       onBtn;
    QPushButton             *       offBtn;
    QPushButton             *       heartbeatBtn;

    QLabel                  *       stateLabel;

    QVBoxLayout             *       vBoxLayout;
    QHBoxLayout             *       hBoxLayout;

    QTimer                  *       heartImageTimer;

    QPixmap                 *       onPix;
    QPixmap                 *       offPix;
    QPixmap                 *       heartPix;

    QString                         devPath;
    QString                         devImage;
    int                             statusFlag;
    char                    *       charCmdNone;
    char                    *       charCmdOff;
    char                    *       charCmdOn;
    char                    *       charCmdHeartbeat;
};

#endif // LED_H
