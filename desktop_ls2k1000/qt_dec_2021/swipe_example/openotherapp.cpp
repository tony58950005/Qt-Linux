#include "openotherapp.h"
#include <QObject>
#include <QProcess>
#include <QDebug>

OpenOtherApp::OpenOtherApp(QObject *parent)
    :QObject (parent)
{

}

OpenOtherApp::~OpenOtherApp()
{

}

void OpenOtherApp::openClock(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have clock app"<<endl;
    QString program = "../QClock/QClock";
    myProcess->execute(program);
    myProcess->waitForStarted();
    qDebug()<<myProcess->readAllStandardOutput();
    return;
}
