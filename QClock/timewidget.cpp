#include "timewidget.h"


TimeWidget::TimeWidget(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->setStyleSheet("background-color:rgb(24, 24, 255);");

    //获取网络时间，更新到系统
    currenTime = new TimeOnline(this);
    connect(currenTime, SIGNAL(timeUpdated()), this, SLOT(update()));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

}
/**
 * @brief TimeWidget::paintEvent
 * @param event
 * @note  画出表盘和指针
 */
void TimeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    //填充表针的颜色
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(127, 127,0,120);
    //绘制的范围
    int side = qMin(width(), height());
    //获取当前的时间
    time = QTime::currentTime();
    //声明用来绘图用的“画家”
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    //重新定位坐标起始点点
    painter.translate(width() / 2, height() / 2);
    //设定画布的边界
    painter.scale(side / 200.0, side / 200.0);
    //填充时针，不需要边线所以NoPen
    painter.setPen(Qt::NoPen);
    //画刷颜色设定
    painter.setBrush(hourColor);
    //保存“画家”的状态
    painter.save();
    //将“画家”（的”视角“）根据时间参数转移
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    //填充时针的区域
    painter.drawConvexPolygon(hourHand, 3);
    //恢复填充前“画家”的状态
    painter.restore();
    //下面画表示小时的刻度，此时要用到画笔（因为要划线）
    painter.setPen(hourColor);
    //十二个刻度，循环下就好了
    for (int i = 0; i < 12; ++i) {
        //先画跳线，再转角
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    //和绘制时针类似，绘制了分针和秒针，及相应的刻度
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);
    painter.save();
    painter.rotate(6.0*time.second());
    painter.drawConvexPolygon(secondHand,3);
    painter.restore();

}
