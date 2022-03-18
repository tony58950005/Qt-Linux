#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QEvent>
#include <QTimer>
#include <QLabel>
#include <QPropertyAnimation>

#include "APPButton.h"
#include "TopLabel.h"

#define APP_NUM 18  // APP个数

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void initMainWindow();                                  // 主窗体布局初始化
    void initAnimation();                                   // 滑动动画初始化
    void initApps(int appNum);                              // APP初始化
    void initTop();                                         // 顶层栏初始化
    void initBottom();                                      // 底部页面圆点初始化

protected:
    bool eventFilter(QObject *obj,QEvent *event) override;

private:
    void backward();                                        // 滑向下一页
    void forward();                                         // 滑向前一页
    void mainWinMove();                                     // 不翻页并恢复滑动前的位置

protected slots:
    void showMainWindow();
    void updateTime();
    void appMoveBackwardSlot();
    void appMoveForwardSlot();
    void appMoveWin(int appIndex);
    void appsPressTimeOutSlot();


private:
    QWidget             *       mainWidget;                 // 主Widget
    QWidget             *       appWidgetParent;            // 存放app的父窗口
    QWidget             *       appWidget;                  // 存放app的区域
    QWidget             *       pageWidget[2];              // 页面小圆点
    TopLabel            *       topLabel;                   // 顶层栏
    QLabel              *       timeLabel;                  // 显示时间
    QLabel              *       backgroundApp;              // APP背景
    APPButton           *       appBtn[APP_NUM];            // APP按钮
    QStringList                 appPathList;                // 存放APP路径
    QStringList                 appNameList;                // 存放APP名字
    QStringList                 appInfoList;                // 存放APP信息
    QGridLayout         *       gridPage1;                  // 第一页栅格布局
    QGridLayout         *       gridPage2;                  // 第二页栅格布局
    QHBoxLayout         *       appWidgetLayout;            // appWidget布局
    QPropertyAnimation  *       propertyAnimation;          // 页面切换动画
    QPoint                      pointStartA;                // 记录按下点的x坐标
    QPoint                      pointStartB;                // 记录按下点的x坐标
    QTimer              *       appsPress;
    int                         desktopWidth;               // 屏幕长度
    int                         desktopHeight;              // 屏幕宽度
    int                         loopCount;                  // 当前页号
    int                         position;                   // 界面移动前所在的页号
};
#endif // MAINWINDOW_H
