#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //! 设置主窗口
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setObjectName("mainWindow");
    this->setGeometry(0,0,desktopWidth,desktopHeight);
    //this->setStyleSheet("#mainWindow { background-color:  #300a24; outline: none }");

    //! 初始化顶层栏
    initTopWidget();

    //
    initTabWidget();

    //! 设置动画
    enterExitanimation = new Animation(this);
    enterExitanimation->setGeometry(this->geometry().width()-48,0,48,48); //设置位置
    enterExitanimation->setAnimationObject(this);//设置动画对象

}

MainWindow::~MainWindow()
{

}

/**
 * @brief MainWindow::initTopWidget
 * @note  初始化顶层栏
 */
void MainWindow::initTopWidget()
{
    QFont font ( "Microsoft YaHei", 30, 60);
    if(desktopWidth >= desktopHeight)
    {
        font.setPointSize(desktopWidth/70);
    } else {
        font.setPointSize((float)10/800*this->geometry().height());
    }

    topLabel = new QLabel(this);
    topLabel->setGeometry(0,0,(float)this->geometry().width(),40);
    topLabel->setStyleSheet("color:rgba(88,88,88,255);"
                            "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0.988636, y2:0, stop:0 rgba(221, 203, 194, 255), stop:1 rgba(255, 255, 255, 255));"
                            "border:0px;");

    QFont topFont ("Microsoft YaHei", 30, 60);
    topFont.setPointSize(23);
    topLabel->setFont(topFont);
    topLabel->setText(" CAN总线测试系统");
}

/**
 * @brief MainWindow::initTabWidget
 * @note  定义并初始化CAN测试窗口。
 */
void MainWindow::initTabWidget()
{
    //! 初始化tabwidget对象
    tabWidget = new QTabWidget(this);
    tabWidget->setGeometry(0,40,desktopWidth,desktopHeight-40);
    tabWidget->setTabPosition(QTabWidget::West);
    tabWidget->setTabShape(QTabWidget::Rounded);

    //! 定义并初始化can0对象
    can0Object = new QAbstractCan(tabWidget,"can0");
    can0Object->resize(tabWidget->width(),tabWidget->height());

    //! 定义并初始化can1对象
    can1Object = new QAbstractCan(tabWidget,"can1");
    can1Object->resize(tabWidget->width(),tabWidget->height());

    tabWidget->addTab(can0Object,"CAN 0");
    tabWidget->addTab(can1Object,"CAN 1");

}
