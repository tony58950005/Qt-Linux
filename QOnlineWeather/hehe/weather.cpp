#include "weather.h"

Weather::Weather(QObject *parent) : QObject(parent)
{
    // 网络请求
    NAManager = new QNetworkAccessManager;
    /* 获取ip地址 发送请求 */
    QNetworkRequest  ipQueryNRequest;
    ipQueryNRequest.setUrl(QUrl(IP_QUERY_API_URL));
    QNetworkReply *newReply = NAManager->get(ipQueryNRequest);
    connect(newReply, SIGNAL(finished()), this, SLOT(slotFinishedIpQueryReply()));

}

/**
 * @brief Widget::slotFinishedIpQueryReply
 * @note  获取当前所在城市后，请求此城市的天气数据
 */
void Weather::slotFinishedIpQueryReply()
{
    //qDebug()<<__LINE__;
    QNetworkReply *reply =  qobject_cast<QNetworkReply *>(sender());
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QString temp = codec->toUnicode(reply->readAll());

    reply->deleteLater();

    /* 判断字符串是否为空 */
    if (temp.isEmpty() || temp.isNull()) {
        return;
    }

    /* 提取city字段 */
    int length = temp.length(); // 得到字符串长度
    int startIndex = temp.indexOf("city:") + 6;  // city:广州市,
    int endIndex = -1;

    if (5 == startIndex) { // 表示不存在city字段 -1，定位失败
        return;
    }

    for (int i = startIndex; i < length; i++) {

        if (',' == temp.at(i)) {
            endIndex = i;
            break;
        }
    }

    if (-1 == endIndex) {//定位失败
        return;
    }
    /* 获取城市名 发送请求 */
    QString cityName = temp.mid(startIndex, endIndex - startIndex - 1);
    QNetworkRequest  weatherGetNRequest;
    weatherGetNRequest.setUrl(QUrl(WEATHER_GET_API_URL + cityName));
    QNetworkReply *newReply = NAManager->get(weatherGetNRequest);
    connect(newReply, SIGNAL(finished()), this, SLOT(slotFinishedWeatherGetReply()));
}

/**
 * @brief Widget::slotFinishedWeatherGetReply
 * @note  根据城市获取天气信息并保存
 */
void Weather::slotFinishedWeatherGetReply()
{
    QNetworkReply *reply =  qobject_cast<QNetworkReply *>(sender());
    QString temp = reply->readAll();
    reply->deleteLater();

    if (temp.isEmpty() || temp.isNull() ) {//定位失败
        return;
    }

    /* 创建Json相关对象 */
    QJsonParseError error;
    QJsonObject jsonObj;
    QJsonDocument jsonDocument;
    QString data;

    /* 解析Jason字符串 获取天气预告信息 */
    jsonDocument = QJsonDocument::fromJson(temp.toUtf8(), &error);
    if(error.error == QJsonParseError::NoError)
    {
        if(jsonDocument.isNull() || jsonDocument.isEmpty())
        {
            return;
        }else{
            if(jsonDocument.isObject())
            {
                jsonObj = jsonDocument.object();
                jsonObj = jsonObj.value("data").toObject();
                /* 当前城市数据 */
                data = jsonObj.value("city").toString();
                currentCity = data;

                /* 当前温度数据 */
                data = jsonObj.value("wendu").toString() + "℃ ";
                currentTemp = data;

                /* 当前风力 */
                data = jsonObj.value("fengli").toString();
                currentWindPower = data;

                /* 当前风向 */
                data = jsonObj.value("fengxiang").toString();
                currentWindDirection = data;

                QJsonArray forecast = jsonObj.value("forecast").toArray();

                /* 解析未来五天内天气数据，保存到数组中 */
                for(int i=0; i < 5; i++)
                {
                    QJsonObject objectDate = forecast.at(i).toObject();

                    /* 日期信息 */
                    if(objectDate.value("date").toString().length() == 6)
                    {
                        data = objectDate.value("date").toString().mid(3, 3) + "\n"+ objectDate.value("date").toString().mid(0, 3);
                    }else {
                        data = objectDate.value("date").toString().mid(2, 3) + "\n"+ objectDate.value("date").toString().mid(0, 2);
                    }
                    week[i].futureDate = data;

                    //qDebug()<<"Week day future Data: "<<week[i].futureDate;
                    /* 最高温度与最低温度 */
                    QJsonObject object = forecast.at(i).toObject();
                    data = object.value("low").toString().mid(3, 3) + "~";
                    data += object.value("high").toString().mid(3, 3);
                    week[i].lowHigh = data;

                    /* 天气类型:如大雨等 */
                    data = object.value("type").toString();
                    week[i].type = data;
                    if(i == 0)//当前天气类型
                    {
                        currentType = data;
                    }

                    /* 风向 */
                    data = object.value("fengxiang").toString();
                    week[i].WindDirection = data;

                    /* 风力 */
                    data = object.value("fengli").toString().mid(9,2);
                    week[i].WindPower = data;

                    data.clear();

                }
            }//! [ for END ]
        }
    }else {
        return;
    }
    emit weekDataReady();
}

/**
 * @brief Weather::getCurrentCity
 * @return
 */
QString Weather::getCurrentCity()
{

    if(currentCity.isEmpty())
        return "NotReady";
    return currentCity;
}

/**
 * @brief Weather::getCurrentDate
 * @return
 */
QString Weather::getCurrentDate()
{
    QString str;
    if(week[0].futureDate.isEmpty())
    {
        return "NotReady";

    }
    str = week[0].futureDate;

    return str.mid(4,6);

}

/**
 * @brief Weather::getCurrentTemp
 * @return
 */
QString Weather::getCurrentTemp()
{
    if(currentTemp.isEmpty())
        return "NotReady";
    return currentTemp;
}

/**
 * @brief Weather::getCurrentType
 * @return
 */
QString Weather::getCurrentType()
{
    if(currentType.isEmpty())
        return "NotReady";
    return currentType;
}

/**
 * @brief Weather::getWeekDayName
 * @param index
 * @return
 */
QString Weather::getWeekDayName(int index)
{
    if(week[index].futureDate.isEmpty())
        return "NotReady";
    return week[index].futureDate;
}

/**
 * @brief Weather::getWeekDayLowHigh
 * @param index
 * @return
 */
QString Weather::getWeekDayLowHigh(int index)
{
    if(week[index].lowHigh.isEmpty())
        return "NotReady";
    return week[index].lowHigh;
}

/**
 * @brief Weather::getWeekDayType
 * @param index
 * @return
 */
QString Weather::getWeekDayType(int index)
{
    if(week[index].type.isEmpty())
        return "NotReady";
    return week[index].type;
}

/**
 * @brief Weather::getWeekDayWindDirection
 * @param index
 * @return
 */
QString Weather::getWeekDayWindDirection(int index)
{
    if(week[index].WindDirection.isEmpty())
       return "NotReady";
    return week[index].WindDirection;

}

/**
 * @brief Weather::getWeekDayWindPower
 * @param index
 * @return
 */
QString Weather::getWeekDayWindPower(int index)
{
   if(week[index].WindPower.isEmpty())
        return "NotReady";
    return week[index].WindPower;

}
