#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @fileName      mainwindow.h
 * @brief         应用程序主窗口
 * @author        topeet
 * @date          2021-04-19
 */

#include <QMainWindow>
#include <QDesktopWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QGroupBox>
#include <QTimer>

#include "animation.h"
#include "weather.h"
#include "weekweatherlabel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initWidgetUI();


protected slots:
    void updateWeekLabelSlot();                                 //刷新界面天气数据

private:
    Weather                 *           weather;                //天气信息
    Animation               *           enterExitanimation;     //进场和出场动画
    QLabel                  *           topLabel;               //顶层栏
    QWidget                 *           widget;                 //显示天气信息的窗口
    QLabel                  *           currentDateLabel;       //当前日期
    QLabel                  *           currentCityLabel;       //当前城市
    QLabel                  *           currentTemperLabel;     //当前温度
    QLabel                  *           currentWeatherLabel;    //当前天气
    WeekWeatherLabel        *           weatherLabelArr[5];     //显示未来几天天气信息的label
    QHBoxLayout             *           currentHLayout;         //当前天气模块水平布局
    QHBoxLayout             *           arrHLayout;             //未来天气模块水平布局
    QVBoxLayout             *           widgetVLayout;          //显示天气信息的窗口widget的垂直布局
    QGroupBox                           currentGroupBox;        //当前天气模块窗口
    QGroupBox                           arrGroupBox;            //未来天气窗口
    QTimer                  *           timer;                  //定时器
    int                                 desktopWidth;           //屏幕长度
    int                                 desktopHeight;          //屏幕宽度
};

#endif // MAINWINDOW_H
