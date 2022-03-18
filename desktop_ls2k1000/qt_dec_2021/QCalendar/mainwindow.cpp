#include "mainwindow.h"
#include <QPalette>
#include <QFont>
#include <QToolButton>
#include <QTableWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //设置主窗口
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setObjectName("mainWindow");
    this->setGeometry(0,0,desktopWidth,desktopHeight);
    this->setStyleSheet("#mainWindow { background-color: #C1CDCD }");

    dateWidget = new QWidget(this);
    dateWidget->setGeometry(0,40,desktopWidth,desktopHeight-40);

    //初始化顶层栏
    initTopWidget();

    //初始化日历窗口
    initCalenddeWidget();

    //初始化当前日期窗口
    initCurrentView();

    //初始化显示日期的主窗口, 并布局
    dateLayout = new QHBoxLayout(dateWidget);
    dateLayout->setContentsMargins(0,0,0,0);
    dateLayout->addWidget(calendar,7);
    dateLayout->setSpacing(0);
    dateLayout->addLayout(todayLayout ,3);

    //更新系统时间
    currenTime = new TimeOnline(this);

    //设置动画
    enterExitanimation = new Animation(this);
    enterExitanimation->setGeometry(this->geometry().width()-48,0,48,48); //设置位置
    enterExitanimation->setAnimationObject(this);//设置动画对象

    //刷新界面显示
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerOutSlot()));
    connect(currenTime, SIGNAL(timeUpdated()), this, SLOT(timerOutSlot()));
    timer->start(1000);

    connect(calendar,SIGNAL(selectionChanged()),this,SLOT(selectDateSlot()));

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
    topLabel->setText(" 日历");
}

/**
 * @brief MainWindow::initCalenddeWidget
 */
void MainWindow::initCalenddeWidget()
{
    calendar = new QCalendarWidget(this);

    //! 不显示最左边的周期统计列表
    calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    //! 将周日显示在第一列
    calendar->setFirstDayOfWeek(Qt::Sunday);

    //! 去除虚线框（焦点框）
    calendar->setFocusPolicy(Qt::NoFocus);

    //! 设置日历上的字体大小
    QFont calendarFont;
    calendarFont.setPixelSize((float)20/800*this->geometry().width());
    calendar->setFont(calendarFont);

    //! 设置切换上个月的按钮图标
    QToolButton * preMonthBth =  calendar->findChild<QToolButton*>(QLatin1String("qt_calendar_prevmonth"));
    preMonthBth->setIconSize(QSize(desktopWidth/20, desktopWidth/20));
    preMonthBth->setIcon(QIcon(":/Resource/calendarIcon/prevmonth.png"));

    //! 设置切换下个月的按钮图标
    QToolButton * nextMonthBth =  calendar->findChild<QToolButton*>(QLatin1String("qt_calendar_nextmonth"));
    nextMonthBth->setIconSize(QSize(desktopWidth/20, desktopWidth/20));
    nextMonthBth->setIcon(QIcon(":/Resource/calendarIcon/nextmonth.png"));

    //! 设置月月份年号窗口背景色
    QWidget * naviWidget = calendar->findChild<QWidget *>(QLatin1String("qt_calendar_navigationbar"));
    naviWidget->setStyleSheet("background-color: #EECFA1;");

    //! 设置月份年号字体
    QString monyerStyleSheet = "QToolButton {color:#60619c;"
                               "} "
                               "QToolButton :pressed{ "
                               "color: #9ACD32;"
                               "}";
    QToolButton * monthBtn = calendar->findChild<QToolButton *>(QLatin1String("qt_calendar_monthbutton"));
    monthBtn->setStyleSheet(monyerStyleSheet);
    QToolButton * yearBtn = calendar->findChild<QToolButton *>(QLatin1String("qt_calendar_yearbutton"));
    yearBtn->setStyleSheet(monyerStyleSheet);
}

/**
 * @brief MainWindow::initTodayView
 */
void MainWindow::initCurrentView()
{
    todayLayout = new QVBoxLayout;
    todayLab = new QLabel(this);
    currentMonthDayLab  = new QLabel(this);
    currentWeekLab = new QLabel(this);
    selectDateLab = new QLabel(this);

    todayLayout->addWidget(todayLab,1);
    todayLayout->addWidget(currentMonthDayLab,1);
    todayLayout->addWidget(currentWeekLab,1);
    todayLayout->addSpacing((desktopHeight-40)/3);
    todayLayout->addWidget(selectDateLab,1);
    todayLayout->addSpacing((desktopHeight-40)/6);

    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::white);

    QFont todayLabFont;
    todayLabFont.setPixelSize((float)40/800*this->geometry().width());
    todayLab->setFont(todayLabFont);
    todayLab->setPalette(pal);
    todayLab->setAlignment(Qt::AlignCenter);
    todayLab->setText("Today");

    QFont currentLabFont;
    currentLabFont.setPixelSize((float)30/800*this->geometry().width());

    currentMonthDayLab->setFont(currentLabFont);
    currentMonthDayLab->setPalette(pal);
    currentMonthDayLab->setAlignment(Qt::AlignCenter);


    currentWeekLab->setFont(currentLabFont);
    currentWeekLab->setPalette(pal);
    currentWeekLab->setAlignment(Qt::AlignCenter);

    selectDateLab->setFont(currentLabFont);
    selectDateLab->setPalette(pal);
    selectDateLab->setAlignment(Qt::AlignCenter);

    currentMonthDayLab->setText("12月31日");
    currentWeekLab->setText("星期日");
}

/**
 * @brief MainWindow::selectDateSlot
 */
void MainWindow::selectDateSlot()
{
    QString selectStr = calendar->selectedDate().toString("yyyy-MM-dd");
    selectDateLab->setText(selectStr);
}

/**
 * @brief MainWindow::timerOutSlot
 */
void MainWindow::timerOutSlot()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString monthDay = currentTime.toString("MM-dd");
    QString week = currentTime.toString("dddd");
    currentMonthDayLab->setText(monthDay);
    currentWeekLab->setText(week);

}

