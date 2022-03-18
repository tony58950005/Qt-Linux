#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();

    weather = new Weather;
    connect(weather,SIGNAL(weekDataReady()), this, SLOT(updateWeekLabelSlot()));

    //初始化主窗口
    this->setGeometry(0,0,desktopWidth,desktopHeight);
    setStyleSheet("background-color: #FFFFF0; outline: none");

    QFont font ( "Microsoft YaHei", 30, 60);
    if(desktopWidth >= desktopHeight)
    {
        font.setPointSize(desktopWidth/70);
    }else {
        font.setPointSize((float)10/800*this->geometry().height());
    }
    //初始化顶层栏
    topLabel = new QLabel(this);
    topLabel->setGeometry(0,0,(float)this->geometry().width(),40);
    topLabel->setStyleSheet("color:rgba(88,88,88,255);"
                            "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0.988636, y2:0, stop:0 rgba(221, 203, 194, 255), stop:1 rgba(255, 255, 255, 255));"
                            "border:0px;");

    QFont topFont ( "Microsoft YaHei", 30, 60);
    topFont.setPointSize(23);
    topLabel->setFont(topFont);
    topLabel->setText(" 实时气象监测系统");

    widget = new QWidget(this);
    widget->setGeometry(1,1+40,desktopWidth-2,desktopHeight-44);

    //widget->setStyleSheet("background: white");

    initWidgetUI();

    //qDebug()<<__FILE__<<__func__<<__LINE__;
    //创建动画
    enterExitanimation = new Animation(this);
    enterExitanimation->setGeometry(this->geometry().width()-40,0,40,40); //设置位置
    enterExitanimation->setAnimationObject(this);//设置动画对象

    //设置鼠标位置
    QCursor cursor;
    cursor.setPos(desktopWidth,desktopHeight);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateWeekLabelSlot()));
    timer->start(1000);

}

MainWindow::~MainWindow()
{

}

/**
 * @brief MainWindow::initUI
 */
void MainWindow::initWidgetUI()
{
    QString labelStyle = "color:rgba(255,255,255,255); background-color: #086A87 ; border-radius:15px; border-width: 0px";
    QFont font ( "Microsoft YaHei", 30, 60);
    if(desktopWidth >= desktopHeight)
    {
        font.setPointSize(desktopWidth/70);
    }else {
        font.setPointSize((float)10/800*this->geometry().height());
    }
    //!当前天气模块控件设置
    currentCityLabel        = new QLabel(widget);
    currentTemperLabel      = new QLabel(widget);
    currentWeatherLabel     = new QLabel(widget);
    currentDateLabel        = new QLabel(widget);

    //设置字体
    currentDateLabel        ->setFont(font);
    currentCityLabel        ->setFont(font);
    currentTemperLabel      ->setFont(font);
    currentWeatherLabel     ->setFont(font);

    //设置label样式
    currentDateLabel        ->setStyleSheet(labelStyle);
    currentCityLabel        ->setStyleSheet(labelStyle);
    currentTemperLabel      ->setStyleSheet(labelStyle);
    currentWeatherLabel     ->setStyleSheet(labelStyle);

    //设置文字居中
    currentDateLabel        ->setAlignment(Qt::AlignCenter);
    currentCityLabel        ->setAlignment(Qt::AlignCenter);
    currentTemperLabel      ->setAlignment(Qt::AlignCenter);
    currentWeatherLabel     ->setAlignment(Qt::AlignCenter);

    //当前天气模块控件布局
    currentHLayout          = new QHBoxLayout;
    currentHLayout->addWidget(currentDateLabel);
    currentHLayout->addWidget(currentCityLabel);
    currentHLayout->addWidget(currentTemperLabel);
    currentHLayout->addWidget(currentWeatherLabel);

    currentGroupBox.setLayout(currentHLayout);
    currentGroupBox.setTitle("当前天气");

    //未来天气模块控件设置及布局
    arrHLayout = new QHBoxLayout;
    for(int i = 0; i < 5; i++)
    {
        //显示未来几天的天气信息
        weatherLabelArr[i] = new WeekWeatherLabel(widget);
        weatherLabelArr[i]->dateLabel           ->setText(weather->getWeekDayName(i));
        weatherLabelArr[i]->typeLabel           ->setText(weather->getWeekDayType(i));
        weatherLabelArr[i]->lowHighTempLabel    ->setText(weather->getWeekDayLowHigh(i));
        weatherLabelArr[i]->windDirectionLabel  ->setText(weather->getWeekDayWindDirection(i));
        weatherLabelArr[i]->windPowerLabel      ->setText(weather->getWeekDayWindPower(i));
        arrHLayout->addWidget(weatherLabelArr[i]);

    }
    //arrGroupBox.setAlignment(Qt::AlignCenter);
    arrGroupBox.setLayout(arrHLayout);
    arrGroupBox.setTitle("天气预测");

    //天气显示窗口widget布局
    widgetVLayout = new QVBoxLayout(widget);
    if(desktopWidth < desktopHeight){
        widgetVLayout->setContentsMargins(10,10,10,desktopHeight/10*5);
    }
    widgetVLayout->addWidget(&currentGroupBox,1);
    widgetVLayout->addWidget(&arrGroupBox,5);
}

/**
 * @brief MainWindow::updateWeekLabelSlot
 * @note  槽函数，刷新界面天气数据
 */
void MainWindow::updateWeekLabelSlot()
{
    for(int i = 0; i < 5; i++)
    {
        //刷新未来几天内天气数据（文字）
        weatherLabelArr[i]->dateLabel           ->setText(weather->getWeekDayName(i));
        weatherLabelArr[i]->typeLabel           ->setText(weather->getWeekDayType(i));
        weatherLabelArr[i]->lowHighTempLabel    ->setText(weather->getWeekDayLowHigh(i));
        weatherLabelArr[i]->windDirectionLabel  ->setText(weather->getWeekDayWindDirection(i));
        weatherLabelArr[i]->windPowerLabel      ->setText(weather->getWeekDayWindPower(i));

        //刷新未来几天天气图片，4.3寸屏不显示图片
        if(weatherLabelArr[i]->typeIcon != NULL)
        {
            weatherLabelArr[i]->typeIcon->setStyleSheet("QLabel{border-image:url(:/Resource/weather/"+ weather->getWeekDayType(i) +".png)};");
        }
    }

    //刷新当前天气数据
    currentDateLabel        ->setText(weather->getCurrentDate());
    currentCityLabel        ->setText(weather->getCurrentCity());
    currentTemperLabel      ->setText(weather->getCurrentTemp());
    currentWeatherLabel     ->setText(weather->getCurrentType());
}
