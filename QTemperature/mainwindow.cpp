#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //设置主窗口
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setGeometry(0,0,desktopWidth,desktopHeight);
    this->setStyleSheet("background-color: #300A24; outline: none");

    //设置要检测的设备( 本例程为CPU温度 )
    tempDevice.setFileName(TEMP_INPUT_PATH);

    initTopWidget();
    initChartWidget();

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(readTemperatureSlot()));

    timer->start(1000);

    initButton();
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



/**
 * @brief MainWindow::initTopWidget
 * @note  初始化顶层框
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
    //初始化顶层栏
    topLabel = new QLabel(this);
    topLabel->setGeometry(0,0,(float)this->geometry().width(),40);
    topLabel->setStyleSheet("color:rgba(88,88,88,255);"
                            "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0.988636, y2:0, stop:0 rgba(221, 203, 194, 255), stop:1 rgba(255, 255, 255, 255));"
                            "border:0px;");

    QFont topFont ("Microsoft YaHei", 30, 60);
    topFont.setPointSize(23);
    topLabel->setFont(topFont);
    topLabel->setText(" CPU温度检测系统");
}

/**
 * @brief MainWindow::initChartWidget
 * @note  实例化QCustomplot，并设置样式和基本参数
 */
void MainWindow::initChartWidget()
{
    //设置背景色
    QBrush brushBackground(QColor(255,255,255));
    customPlot = new QCustomPlot(this);
    customPlot->setBackground(brushBackground);

    //位置大小
    if(desktopWidth > 800)
    {
        customPlot->setGeometry((float)50/800*this->geometry().width(), (float)70/480*this->geometry().height(),
                           (float)700/800*this->geometry().width(), (float)300/480*this->geometry().height());
    }else {
        customPlot->setGeometry((float)50/800*this->geometry().width(), (float)80/480*this->geometry().height(),
                           (float)700/800*this->geometry().width(), (float)295/480*this->geometry().height());
    }
    //设置x y坐标轴颜色,宽度
    QPen tickPen(QColor("#300A24"));
    tickPen.setWidth(desktopHeight/200);
    customPlot->xAxis->setTickPen(tickPen);
    customPlot->xAxis->setBasePen(tickPen);
    customPlot->yAxis->setTickPen(tickPen);
    customPlot->yAxis->setBasePen(tickPen);

    //设置xy轴数据范围
    customPlot->xAxis->setRange(AXIS_X_MIN, AXIS_X_MAX);
    customPlot->yAxis->setRange(AXIS_Y_MIN, AXIS_Y_MAX);

    //根据不同屏幕设置刻度数量
    if(desktopWidth >= desktopHeight)
    {
        customPlot->xAxis->ticker()->setTickCount(10);
    }else {
        customPlot->yAxis->ticker()->setTickCount(12);
        customPlot->xAxis->ticker()->setTickCount(10);
    }

    //设置xy轴标签文字
    customPlot->xAxis->setLabel("时间: 0.0s");
    customPlot->yAxis->setLabel("温度/摄氏度");

    QFont font;
    font.setPointSize((float)16/800*this->geometry().width());
    customPlot->xAxis->setLabelColor(QColor(Qt::blue)); // X轴上标识label字体颜色
    customPlot->yAxis->setLabelColor(QColor(Qt::blue));

    //设置曲线的颜色宽度
    QPen graphPen(QColor("#EE9A00"));
    graphPen.setWidth(3);

    //增加曲线图
    customPlot->addGraph();
    customPlot->graph(0)->setPen(graphPen);
    customPlot->graph(0)->setName("Temp"); // 设置曲线的名字
    customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);   // 设置连接线的类型 两点直线连接
    //刷新显示
    customPlot->replot();
}

/**
 * @brief MainWindow::initButton
 * @note  初始化按钮
 */
void MainWindow::initButton()
{
    QString fontSize;
    if(desktopWidth > desktopHeight)
    {
        fontSize = QString::number( desktopHeight/20 );
    }else {
        fontSize = QString::number( desktopWidth/20 );
    }
    QString btnStyleSheet = ""
            //正常状态样式
            "QPushButton{"
            "color: #300A24;"
            "background-color: #CDC9C9;"            //背景色
            "border-style:outset;"                  //边框样式（inset/outset）
            "border-radius:10px;"                   //边框圆角半径像素
            "padding:6px;"
            "font: " + fontSize + "px ;"
            "}"
            //鼠标按下样式
            "QPushButton:pressed{"
            "background-color: #C6E2FF;"
            "border-style:outset;"                  //边框样式（inset/outset）
            "border-radius:10px;"                   //边框圆角半径像素
            "border-style:inset;"
            "color:rgba(0,0,0,100);"
            "}";

    pauseBtn = new QPushButton(this);
    pauseBtn->setGeometry((float)this->geometry().width()/4,(float)400/480*this->geometry().height(),
                          (float)this->geometry().width()/800*100,(float)this->geometry().width()/800*50);
    pauseBtn->setText("暂停");
    pauseBtn->setStyleSheet(btnStyleSheet);
    connect(pauseBtn, SIGNAL(clicked()), this, SLOT(pauseBtnClickedSlot()));

    resetBtn = new QPushButton(this);
    resetBtn->setGeometry((float)this->geometry().width()/8*5,(float)400/480*this->geometry().height(),
                          (float)this->geometry().width()/800*100,(float)this->geometry().width()/800*50);
    resetBtn->setText("重置");
    resetBtn->setStyleSheet(btnStyleSheet);
    connect(resetBtn,SIGNAL(clicked()),this,SLOT(resetBtnClickedSlot()));
}

/**
 * @brief MainWindow::readTemperatureSlot
 * @note  槽函数，时间到后读取温度值
 */
void MainWindow::readTemperatureSlot()
{
    // count计数判断 */
    if (COUNT_MAX < count)
        count = 0;

    tempDevice.open(QIODevice::ReadOnly);

    QString temperature = tempDevice.readAll().mid(0,5);
    tempDevice.close();
    double temp = temperature.toDouble() / 1000;
    //qDebug()<<temperature<<"  "<<temp;
    // 更新X轴
    if (count > AXIS_X_MAX)
        customPlot->xAxis->setRange(count - AXIS_X_MAX, count);

    // 添加数据
    customPlot->graph(0)->addData(count, temp);
    customPlot->yAxis->setLabel("温度:  " + QString::number(temp)+ " ℃");
    customPlot->xAxis->setLabel("时间:  " + QString::number(count) + " s");
    customPlot->replot();
    temp = -1;

    // 更新计数
    count++;
}

/**
 * @brief MainWindow::pauseBtnClickedSlot
 * @note  暂停按钮槽函数
 */
void MainWindow::pauseBtnClickedSlot()
{
    if (timer->isActive()) {
        timer->stop();
    }
    else {
        timer->start(1000);
    }
}

/**
 * @brief MainWindow::resetBtnClickedSlot
 * @note  重置按钮槽函数,数据清零，重新开始计时
 */
void MainWindow::resetBtnClickedSlot()
{

    if (timer->isActive()) {
        timer->stop();
    }
    count = 0;
    customPlot->graph(0)->data().data()->clear();
    customPlot->xAxis->setRange(0, AXIS_X_MAX);
    customPlot->replot();
    customPlot->yAxis->setLabel("温度:  * ℃");
    customPlot->xAxis->setLabel("时间:  0s");
    timer->start(1000);
}
