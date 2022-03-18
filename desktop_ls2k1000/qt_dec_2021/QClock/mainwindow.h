#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFont>
#include <QEvent>
#include <QPalette>

#include "animation.h"
#include "timewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void initTopWidget();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Animation               *           enterExitanimation;     //进场和出场动画
    QLabel                  *           topLabel;               //顶层栏
    TimeWidget              *           timeWidget;             //时钟显示窗口
    int                                 desktopWidth;           //屏幕长度
    int                                 desktopHeight;          //屏幕宽度
};

#endif // MAINWINDOW_H
