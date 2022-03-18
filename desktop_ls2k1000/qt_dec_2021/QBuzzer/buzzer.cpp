#include "buzzer.h"

Buzzer::Buzzer(QWidget *parent) : QWidget(parent)
{
    QString cmd_none = "echo none>"+ devPath +"/trigger";
    QByteArray cmdby_none = cmd_none.toLatin1();
    charCmdNone = cmdby_none.data();

    QString cmd_off = "echo 0 >"+ devPath +"/brightness";
    QByteArray cmdby_off = cmd_off.toLatin1();
    charCmdOff = cmdby_off.data();

    QString cmd_on = "echo 1 >"+ devPath +"/brightness";
    QByteArray cmdby_on = cmd_on.toLatin1();
    charCmdOn = cmdby_on.data();

    QString cmd_heartbeat = "echo heartbeat>"+ devPath +"/trigger";
    QByteArray cmdby_heartbeat = cmd_heartbeat.toLatin1();
    charCmdHeartbeat = cmdby_heartbeat.data();

}

/**
 * @brief Buzzer::buzzerNone 无状态
 */
void Buzzer::buzzerNone()
{
    system(charCmdNone);
}

/**
 * @brief Buzzer::buzzerOff 关
 */
void Buzzer::buzzerOff()
{
    //system(charCmdNone);
    //system(charCmdOn);
    system("echo 0 > /sys/class/pwm/pwmchip3/pwm0/enable");
}

/**
 * @brief Buzzer::buzzerOn 开
 */
void Buzzer::buzzerOn()
{
    //system(charCmdNone);
    //system(charCmdOff);
    system("echo 0 > /sys/class/pwm/pwmchip3/export");
    system("echo 366300 > /sys/class/pwm/pwmchip3/pwm0/period");
    system("echo 260000 > /sys/class/pwm/pwmchip3/pwm0/duty_cycle");
    system("echo 1 > /sys/class/pwm/pwmchip3/pwm0/enable");
}

/**
 * @brief Buzzer::buzzerHearbeat 心跳
 */
void Buzzer::buzzerHearbeat()
{
    //system(charCmdHeartbeat);
    for (int x=0;x<3;x++){
        system("echo 1 > /sys/class/pwm/pwmchip3/pwm0/enable");
        system("sleep 1s ");
        system("echo 0 > /sys/class/pwm/pwmchip3/pwm0/enable");
        system("sleep 1s ");
    }
}
