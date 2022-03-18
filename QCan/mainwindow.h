#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @fileName      mainwindow.h
 * @brief         主窗口
 * @author        topeet
 * @date          2021-04-30
 */

#include <QMainWindow>
#include <QTabWidget>

#include "animation.h"
#include "qabstractcan.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initTopWidget();
    void initTabWidget();

private:
    Animation               *           enterExitanimation;     //进场和出场动画
    QLabel                  *           topLabel;               //顶层栏
    int                                 desktopWidth;           //屏幕长度
    int                                 desktopHeight;          //屏幕宽度
    QTabWidget              *           tabWidget;              //用于窗口切换
    QAbstractCan            *           can0Object;             //can0测试窗口
    QAbstractCan            *           can1Object;             //can1测试窗口
};

#endif // MAINWINDOW_H
