#ifndef TOPLABEL_H
#define TOPLABEL_H

#include <QObject>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QVBoxLayout>

class TopLabel : public QLabel
{
    Q_OBJECT
public:
    TopLabel(QWidget *parent = nullptr);

protected slots:
    void updateDateTimeSlot();

public:
    QLabel              *       nameLabel;
    QLabel              *       dateLabel;
    QString                     t;
    QTimer              *       timer;

private:
    QDateTime                   currentTime;
    QString                     timerStr;

};

#endif // TOPLABEL_H
