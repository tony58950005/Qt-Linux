#include "timeonline.h"

TimeOnline::TimeOnline(QObject *parent) : QObject(parent)
{
    //发送网络请求
    NAManager = new QNetworkAccessManager(this);
    ipQueryNRequest.setUrl(QUrl(NET_TIME_URL));
    newReply = NAManager->get(ipQueryNRequest);
    connect(newReply, SIGNAL(finished()), this, SLOT(finishedTimeReplySlot()));
}

/**
 * @brief TimeOnline::finishedIpQueryReplySlot
 */
void TimeOnline::finishedIpQueryReplySlot()
{

    newReply = NAManager->get(ipQueryNRequest);
    connect(newReply, SIGNAL(finished()), this, SLOT(finishedTimeReplySlot()));
}

/**
 * @brief TimeOnline::finishedTimeReplySlot
 * @note  解析获取到的网络时间，并更新到系统
 */
void TimeOnline::finishedTimeReplySlot()
{

    QNetworkReply * timeReplay = qobject_cast< QNetworkReply * > (sender());
    QString dataReplay = timeReplay->readAll();
    if(dataReplay.isEmpty() || dataReplay.isNull())
    {
        qDebug()<<" replay time failed ";
        return;
    }
    timeReplay->deleteLater();

    // 创建Json相关对象
    QJsonParseError error;
    QJsonObject jsonObj;
    QJsonDocument jsonDocument;
    QString data;

    // 解析Jason字符串
     jsonDocument = QJsonDocument::fromJson(dataReplay.toUtf8(), &error);
     if(error.error == QJsonParseError::NoError)
     {
        if(jsonDocument.isEmpty() || jsonDocument.isNull())
        {
            return;
        }else{
            if(jsonDocument.isObject())
            {
                jsonObj = jsonDocument.object();
                data = jsonObj.value("sysTime2").toString();
                cmdSetTimeString = "date -s \"" + data + "\"";
                cmdSetTimeChar = cmdSetTimeString.toUtf8();
                std::system(cmdSetTimeChar);
                emit timeUpdated();
            }
        }
     }else {// Jason error
        return;
     }
}

