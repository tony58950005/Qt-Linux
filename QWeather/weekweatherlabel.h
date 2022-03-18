#ifndef WEEKWEATHERLABEL_H
#define WEEKWEATHERLABEL_H

/**
 * @fileName      weekweatherlabel.h
 * @brief         显示未来某天的label
 * @author        topeet
 * @date          2021-04-19
 */

#include <QObject>
#include <QLabel>
#include <QVBoxLayout>

class WeekWeatherLabel : public QLabel
{
public:
    WeekWeatherLabel(QWidget * parent = nullptr);

    QLabel          *   dateLabel;          //显示日期
    QLabel          *   typeIcon;           //显示天气图标
    QLabel          *   lowHighTempLabel;   //显示最高最低温
    QLabel          *   typeLabel;          //显示天气类型
    QLabel          *   windDirectionLabel; //显示风向
    QLabel          *   windPowerLabel;     //显示风力

    QVBoxLayout     *   vBoxWeekLayout;     //天气信息label垂直布局
    QHBoxLayout     *   hBoxLayoutIcon;     //天气图标水平布局
};

#endif // WEEKWEATHERLABEL_H
