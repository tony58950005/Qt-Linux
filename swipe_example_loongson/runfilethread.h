#ifndef RUNFILETHREAD_H
#define RUNFILETHREAD_H

//#include <QMainWindow>
#include <QObject>
#include "openotherapp.h"
#include <QThread>
//#include <QWidget>

class RunFIleThread:public QThread
{
    Q_OBJECT
    Q_PROPERTY(void best NOTIFY bestChanged)
public:
    RunFIleThread(QObject *parent = 0);
    Q_INVOKABLE void run() override;
    ~RunFIleThread();
signals:
    void bestChanged();
public slots:


protected:

};

#endif // RUNFILETHREAD_H
