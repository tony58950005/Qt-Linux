#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QPen>
#include <QString>
#include <QFont>
#include <QPalette>
#include "animation.h"
#include "qcustomplot.h"

//! CPU温度节点
#define TEMP_INPUT_PATH "/sys/class/hwmon/hwmon0/temp1_input"

#define AXIS_X_MIN   0
#define AXIS_X_MAX   50
#define AXIS_Y_MIN   40
#define AXIS_Y_MAX   110
#define COUNT_MAX    500000

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initTopWidget();
    void initChartWidget();
    void initButton();


protected slots:
    void readTemperatureSlot();
    void pauseBtnClickedSlot();
    void resetBtnClickedSlot();

private:
    Animation               *           enterExitanimation;     //进场和出场动画
    QLabel                  *           topLabel;               //顶层栏
    QWidget                 *           chartWidget;            //折线图显示窗口
    QCustomPlot             *           customPlot;             //曲线图窗口
    QTimer                  *           timer;                  //定时器
    QFile                               tempDevice;             //设备节点
    QString                 *           temperature;            //温度
    QPushButton             *           pauseBtn;
    QPushButton             *           resetBtn;
    int                                 desktopWidth;           //屏幕长度
    int                                 desktopHeight;          //屏幕宽度
    unsigned int                        count;                  //计数器，用于计算监测总时间
};

#endif // MAINWINDOW_H
