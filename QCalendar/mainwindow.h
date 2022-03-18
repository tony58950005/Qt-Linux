#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QDateTime>

#include "animation.h"
#include "timeonline.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initTopWidget();
    void initCalenddeWidget();
    void initCurrentView();

protected slots:
    void selectDateSlot();
    void timerOutSlot();

private:
    Animation               *           enterExitanimation;     //进场和出场动画
    QLabel                  *           topLabel;               //顶层栏
    QWidget                 *           dateWidget;             //日历窗口
    QCalendarWidget         *           calendar;               //日历

    QWidget                 *           currentWidget;          //当前日期窗口
    QVBoxLayout             *           todayLayout;            //当前日期模块的垂直布局
    QLabel                  *           todayLab;
    QLabel                  *           currentMonthDayLab;
    QLabel                  *           currentWeekLab;
    QLabel                  *           selectDateLab;
    QPushButton             *           currentResetBtn;        //

    QHBoxLayout             *           dateLayout;             //日期主界面布局
    TimeOnline              *           currenTime;
    QTimer                  *           timer;
    int                                 desktopWidth;           //屏幕长度
    int                                 desktopHeight;          //屏幕宽度
};

#endif // MAINWINDOW_H
