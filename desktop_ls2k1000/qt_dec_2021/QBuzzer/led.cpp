#include "led.h"
#include <QDateTime>
#include <QByteArray>
#include <QDebug>
#include <stdlib.h>

Led::Led(QWidget *parent){ Q_UNUSED(parent) }

/**
 * @brief Led::Led
 * @param parent
 * @param path LED路径
 * @note  初始化成员变量，界面布局,初始化定时器
 */
Led::Led(QWidget *parent, QString path, QString image)
    : QWidget(parent),
      devPath(path),
      devImage(image)
{
    //初始化按钮
    offBtn = new QPushButton(this);
    onBtn  = new QPushButton(this);
    heartbeatBtn = new QPushButton(this);

    offBtn->setText("OFF");
    onBtn->setText("ON");
    heartbeatBtn->setText("heart");

    QString btnStyle = "QPushButton{background: #300a24; color: white; border-radius: 20px; } QPushButton:hover{ background: #A4A4A4; color: #300a24 ;border-radius: 15px;}";

    offBtn->setStyleSheet(btnStyle);
    onBtn->setStyleSheet(btnStyle);
    heartbeatBtn->setStyleSheet(btnStyle);

    connect(offBtn,SIGNAL(clicked()),this,SLOT(offBtnClickedSlot()));
    connect(onBtn,SIGNAL(clicked()),this,SLOT(onBtnClickedSlot()));
    connect(heartbeatBtn,SIGNAL(clicked()),this,SLOT(heartBtnClickedSlot()));

    //初始化显示led状态图片的Label
    stateLabel = new QLabel(this);
    stateLabel->setScaledContents(true);

    //布局
    vBoxLayout = new QVBoxLayout;
    vBoxLayout->addWidget(offBtn);
    vBoxLayout->addWidget(onBtn);
    vBoxLayout->addWidget(heartbeatBtn);

    if(parent->width() < parent->height())
    {
        offBtn->setFixedSize(parent->height()/7,parent->width()/10);
        onBtn->setFixedSize(parent->height()/7,parent->width()/10);
        heartbeatBtn->setFixedSize(parent->height()/7,parent->width()/10);
        stateLabel->setFixedSize(parent->width()/2,parent->width()/2);
    }else {
        offBtn->setFixedSize(parent->width()/9,parent->height()/10);
        onBtn->setFixedSize(parent->width()/9,parent->height()/10);
        heartbeatBtn->setFixedSize(parent->width()/9,parent->height()/10);
        stateLabel->setFixedSize(parent->height()/2,parent->height()/2);
    }



    //stateLabel->setPixmap(QPixmap(devImage + "off.png"));
    hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(stateLabel);

    if(parent->width() < parent->height())
    {
        hBoxLayout->addSpacing(parent->width()/10);
    }else {
        hBoxLayout->addSpacing(parent->width()/5);
    }
    hBoxLayout->addLayout(vBoxLayout);

    heartImageTimer = new QTimer(this);
    connect(heartImageTimer,SIGNAL(timeout()),this,SLOT(heartImageTimerOutSlot()));


    //初始化状态图片
    offPix = new QPixmap(image +"off.png");
    onPix = new QPixmap(image +"on.png");
    offPix->scaled(stateLabel->size(),Qt::KeepAspectRatio);
    onPix->scaled(stateLabel->size(),Qt::KeepAspectRatio);

    //设置LED初始状态
    stateLabel->setPixmap(*offPix);
    ledNone();
}

Led::~Led()
{
    ledOff();
    qDebug()<<"EXIT";
}

/**
 * @brief Led::ledNone 无状态
 */
void Led::ledNone()
{
    /* 无状态 */
    QString cmd_none = "echo none>"+ devPath +"/trigger";
    QByteArray cmdby_none = cmd_none.toLatin1();
    char* charCmd_none = cmdby_none.data();
    if(heartImageTimer->isActive())
        heartImageTimer->stop();

    ::system(charCmd_none);
}

/**
 * @brief Led::ledOn 灯亮
 */
void Led::ledOn()
{
    /* 开 */
    /*QString cmd_on = "echo 1 >"+ devPath +"/brightness";
    QByteArray cmdby_on = cmd_on.toLatin1();
    char* charCmd_on = cmdby_on.data();
    if(heartImageTimer->isActive())
        heartImageTimer->stop();
    ::system(charCmd_on);*/
    system("echo 0 > /sys/class/pwm/pwmchip3/export");
    system("echo 366300 > /sys/class/pwm/pwmchip3/pwm0/period");
    system("echo 260000 > /sys/class/pwm/pwmchip3/pwm0/duty_cycle");
    system("echo 1 > /sys/class/pwm/pwmchip3/pwm0/enable");

}

/**
 * @brief Led::ledOff 灯灭
 */
void Led::ledOff()
{
    /*QString cmd_off = "echo 0 >"+ devPath +"/brightness";
    QByteArray cmdby_off = cmd_off.toLatin1();
    char* Cmd_off = cmdby_off.data();

    if(heartImageTimer->isActive())
        heartImageTimer->stop();
    ::system(Cmd_off);*/
    system("echo 0 > /sys/class/pwm/pwmchip3/pwm0/enable");

}

/**
 * @brief Led::ledHeartbeat 心跳
 */
void Led::ledHeartbeat()
{
    /* 心跳 */
    /*QString cmd_heartbeat = "echo heartbeat>"+ devPath +"/trigger";
    QByteArray cmdby_heartbeat = cmd_heartbeat.toLatin1();
    char* charCmd_heartbeat = cmdby_heartbeat.data();
    ::system(charCmd_heartbeat);*/
    for(int x=0;x<3;x++){
        system("echo 1 > /sys/class/pwm/pwmchip3/pwm0/enable");
        system("sleep 1s ");
        system("echo 0 > /sys/class/pwm/pwmchip3/pwm0/enable");
        system("sleep 1s");
    }

}



/**
 * @brief Led::offBtnClickedSlot
 */
void Led::offBtnClickedSlot()
{
    stateLabel->setPixmap(*offPix);
    ledOff();
}

/**
 * @brief Led::onBtnClickedSlot
 */
void Led::onBtnClickedSlot()
{
    stateLabel->setPixmap(*onPix);
    ledOn();
}

/**
 * @brief Led::heartBtnClickedSlot
 */
void Led::heartBtnClickedSlot()
{
    statusFlag=0;
    ledHeartbeat();
    heartImageTimer->start(200);

}

/**
 * @brief Led::heartImageTimerOutSlot
 */
void Led::heartImageTimerOutSlot()
{
    if(statusFlag == 0)
    {
        stateLabel->setPixmap(*onPix);
        statusFlag = 1;
    }else {
        stateLabel->setPixmap(*offPix);
        statusFlag = 0;
    }
}

