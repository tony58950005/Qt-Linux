#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H
/**
 * @fileName      timewidget.h
 * @brief         时间显示窗口
 * @author        topeet
 * @date          2021-04-23
 */
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>

#include <QPushButton>
#include "timeonline.h"

//下面三个数组用来定义表针的三个顶点，以便后面的填充
static const QPoint hourHand[3] = {
    QPoint(3, 8),
    QPoint(-3, 8),
    QPoint(0, -40)
};
static const QPoint minuteHand[3] = {
    QPoint(3, 8),
    QPoint(-3, 8),
    QPoint(0, -70)
};
static const QPoint secondHand[3] = {
    QPoint(3, 8),
    QPoint(-3, 8),
    QPoint(0, -90)
};

class TimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimeWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:

private:
    TimeOnline  * currenTime;       //更新系统时间
    QTime     time;                 //系统时间
};

#endif // TIMEWIDGET_H
