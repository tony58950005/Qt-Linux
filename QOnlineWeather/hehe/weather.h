#ifndef WEATHER_H
#define WEATHER_H

/**
 * @fileName      weather.h
 * @brief         通过网络获取天气信息数据并存储
 * @author        topeet
 * @date          2021-04-19
 */

#include <QObject>
#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QTextCodec>
#include <QFileInfo>
#include <QPushButton>

//获取天气
#define   WEATHER_GET_API_URL  "http://wthrcdn.etouch.cn/weather_mini?city="

//获取所在城市
#define   IP_QUERY_API_URL    "http://ip.ws.126.net/ipquery"

class Weather : public QObject
{
    Q_OBJECT
public:
    explicit Weather(QObject *parent = 0);

    //! 存放未来天气信息
    typedef struct futureWeather {
        QString futureDate;         //日期
        QString lowHigh;            //最高最低气温
        QString type;               //天气类型
        QString WindDirection;      //风向
        QString WindPower;          //风力

    } QWeekdate ;

    QString getCurrentCity();
    QString getCurrentDate();
    QString getCurrentTemp();
    QString getCurrentType();

    QString getWeekDayName(int index);
    QString getWeekDayLowHigh(int index);
    QString getWeekDayType(int index);
    QString getWeekDayWindDirection(int index);
    QString getWeekDayWindPower(int index);

signals:
    void weekDataReady();                                   //天气信息朱安备好

public slots:
    void slotFinishedIpQueryReply();
    void slotFinishedWeatherGetReply();

private:
    QNetworkAccessManager       *   NAManager;
    QNetworkReply               *   newReply;
    QWeekdate                       week[5];                //未来天气

    QString                         currentCity;            //当前城市
    QString                         currentDate;            //当前日期
    QString                         currentTemp;            //当前温度
    QString                         currentWindDirection;   //当前风向
    QString                         currentWindPower;       //当前风力
    QString                         currentType;            //当前天气

};

#endif // WEATHER_H
