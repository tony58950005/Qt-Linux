#include "TopLabel.h"
#include <QDebug>

/**
 * @brief TopLabel::TopLabel
 * @param parent
 * @note  初始化顶层栏
 */
TopLabel::TopLabel(QWidget *parent)
    : QLabel(parent)
{
    setStyleSheet("QLabel { color:rgba(88,88,88,255); "
                  //"background-color: qlineargradient(spread:pad, x1:0.977273, y1:1, x2:1, y2:0, stop:0 rgba(207, 196, 187, 255), stop:1 rgba(255, 255, 255, 255));"
                  "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(247, 177, 177, 255), stop:1 rgba(255, 255, 255, 255));"
                  "border:0px;};");
    setText("  iTOP-LOONGSON 2K Qt5 Desktop ");

    timer = new QTimer(this);
    dateLabel = new QLabel(this);
    dateLabel->setStyleSheet("QLabel { color:rgba(88,88,88,255);border:0px;border-radius:500px };");
    dateLabel->setText("系统日期");

    connect(timer,SIGNAL(timeout()),this,SLOT(updateDateTimeSlot()));
    timer->start(1000);
}

/**
 * @brief TopLabel::updateDataTime
 * @note  定时刷新时间
 */
void TopLabel::updateDateTimeSlot()
{
    currentTime = QDateTime::currentDateTime();
    timerStr = currentTime.toString("yyyy-MM-dd ddd");
    t = currentTime.toString("hh:mm:ss");
    dateLabel->setText(" "+timerStr);
}
