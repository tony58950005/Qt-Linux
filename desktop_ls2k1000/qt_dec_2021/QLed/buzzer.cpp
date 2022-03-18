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
    system(charCmdNone);
    system(charCmdOn);
}

/**
 * @brief Buzzer::buzzerOn 开
 */
void Buzzer::buzzerOn()
{
    system(charCmdNone);
    system(charCmdOff);
}

/**
 * @brief Buzzer::buzzerHearbeat 心跳
 */
void Buzzer::buzzerHearbeat()
{
    system(charCmdHeartbeat);
}
