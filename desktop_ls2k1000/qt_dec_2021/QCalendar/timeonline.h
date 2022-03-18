#ifndef TIMEONLINE_H
#define TIMEONLINE_H

/**
 * @fileName      timeonline.h
 * @brief         更新系统时间
 * @author        topeet
 * @date          2021-04-23
 */

#include <QObject>
#include <QDateTime>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>

//! 网络时间链接
#define NET_TIME_URL "http://quan.suning.com/getSysTime.do"

class TimeOnline : public QObject
{
    Q_OBJECT
public:
    explicit TimeOnline(QObject *parent = 0);

    int getHour();
    int getMinute();
    int getSecond();

signals:
    void timeUpdated();

public slots:
    void finishedIpQueryReplySlot();
    void finishedTimeReplySlot();

private:
    QNetworkAccessManager *         NAManager;               // 网络请求
    QNetworkReply *                 newReply;
    QNetworkRequest                 ipQueryNRequest;

    QString cmdSetTimeString;                               //更新时间的命令
    QByteArray cmdSetTimeChar;

};

#endif // TIMEONLINE_H
