#include "runfilethread.h"
#include "openotherapp.h"
#include <QObject>

RunFIleThread::RunFIleThread(QObject *parent)

{

}

void RunFIleThread::run()
{
    OpenOtherApp o1;
    o1.openCalendar();
}

RunFIleThread::~RunFIleThread()
{
    qDebug()<< "RunFIleThread has been destructed"<<endl;
}
