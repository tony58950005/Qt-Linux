#include "mainwindow.h"
#include <QApplication>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();

    //初始化主窗口
    this->setGeometry(0,0,desktopWidth,desktopHeight);
    setStyleSheet("background-color: #300a24; outline: none");

    //初始化顶层栏
    topLabel = new QLabel(this);
    topLabel->setGeometry(0,0,(float)this->geometry().width(),40);
    topLabel->setStyleSheet("color:rgba(88,88,88,255);"
                            "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0.988636, y2:0, stop:0 rgba(221, 203, 194, 255), stop:1 rgba(255, 255, 255, 255));"
                            "border:0px;");
    topLabel->setText("  Buzzer控制系统");

    //创建多界面切换窗口并初始化
    tabWidget = new QTabWidget(this);
    if(desktopWidth > desktopHeight)
    {

        tabWidget->setGeometry(desktopWidth/20, 40+desktopHeight/20,desktopWidth/20*18,desktopHeight/10*9-40);
    } else {
        tabWidget->setGeometry(desktopWidth/20, 40+desktopHeight/20,desktopWidth/20*18,desktopHeight/10*9-40);
    }


    tabWidget->setStyleSheet("background-color: rgb(255, 255, 255);");


    //tabWidget->setStyleSheet(" background-color: #FFFAF0  ");

    tabWidget->setTabShape(QTabWidget:: Rounded);
    tabWidget->setFocusPolicy(Qt::NoFocus);

    //创建led和buzzer，并添加到QTabWidget
    //led  = new Led(tabWidget,"/sys/class/leds/sys-led",":/Resource/led/led");
    buzzer = new Led(tabWidget,"/sys/class/leds/beep",":/Resource/buzzer/buzzer");
    //tabWidget->addTab(led,   "LED灯");
    tabWidget->addTab(buzzer,"蜂鸣器");
    tabWidget->setCurrentIndex(0);

    //创建动画
    enterExitanimation = new Animation(this);
    enterExitanimation->setGeometry(this->geometry().width()-40,0,40,40); //设置位置
    enterExitanimation->setAnimationObject(this);//设置动画对象

    //设置鼠标位置
    QCursor cursor;
    cursor.setPos(desktopWidth,desktopHeight);

}

MainWindow::~MainWindow()
{
}

