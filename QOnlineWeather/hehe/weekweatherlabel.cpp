#include "weekweatherlabel.h"
#include <QDesktopWidget>
#include <QApplication>

WeekWeatherLabel::WeekWeatherLabel(QWidget * parent)
    : QLabel(parent)
{
    int desktopWidth = QApplication::desktop()->geometry().width();
    int desktopHeight=QApplication::desktop()->geometry().height();

    this->setStyleSheet("color:rgba(255,255,255,255); background-color: #086A87 ; border-radius:15px; border-width: 0px");
    this->setAlignment(Qt::AlignCenter);

    //设置未来几天天气信息label内的字体
    QFont font ( "Microsoft YaHei", 30, 60);
    if(desktopWidth >= desktopHeight)
    {
        font.setPointSize(desktopWidth/70);
    }else {
        font.setPointSize(desktopWidth/50);
    }

    QString labelStyle = "color:rgba(255,255,255,255); background-color: #086A87 ; border-radius:15px; border-width: 0px";

    dateLabel            = new QLabel(this);
    typeIcon             = new QLabel(this);
    lowHighTempLabel     = new QLabel(this);
    typeLabel            = new QLabel(this);
    windDirectionLabel   = new QLabel(this);
    windPowerLabel       = new QLabel(this);

    //设置文字居中
    dateLabel           ->setAlignment(Qt::AlignCenter);
    typeIcon            ->setAlignment(Qt::AlignCenter);
    lowHighTempLabel    ->setAlignment(Qt::AlignCenter);
    typeLabel           ->setAlignment(Qt::AlignCenter);
    windDirectionLabel  ->setAlignment(Qt::AlignCenter);
    windPowerLabel      ->setAlignment(Qt::AlignCenter);

    //设置字体
    dateLabel           ->setFont(font);
    lowHighTempLabel    ->setFont(font);
    typeLabel           ->setFont(font);
    windDirectionLabel  ->setFont(font);
    windPowerLabel      ->setFont(font);

    //设置天气图标
    dateLabel           ->setStyleSheet(labelStyle);
    typeIcon            ->setStyleSheet("QLabel{border-image:url(:/Resource/weather/未定义.png)};");

    //设置各kabel样式
    lowHighTempLabel    ->setStyleSheet(labelStyle);
    typeLabel           ->setStyleSheet(labelStyle);
    windDirectionLabel  ->setStyleSheet(labelStyle);
    windPowerLabel      ->setStyleSheet(labelStyle);

    //设置显示天气图标的label
    typeIcon->setFixedWidth(dateLabel->height()*4);
    hBoxLayoutIcon = new QHBoxLayout;
    hBoxLayoutIcon->addStretch();
    hBoxLayoutIcon->addWidget(typeIcon);
    hBoxLayoutIcon->addStretch();

    //天气信息label布局
    vBoxWeekLayout      = new QVBoxLayout(this);
    vBoxWeekLayout      ->addWidget(dateLabel);
    if(desktopWidth >= 800)
    {
        vBoxWeekLayout      ->addLayout(hBoxLayoutIcon);
    }else {//4.3寸屏幕不显示天气图片·
        typeIcon->setFixedWidth(0);
    }
    vBoxWeekLayout      ->addWidget(lowHighTempLabel);
    vBoxWeekLayout      ->addWidget(typeLabel);
    vBoxWeekLayout      ->addWidget(windDirectionLabel);
    vBoxWeekLayout      ->addWidget(windPowerLabel);

}
