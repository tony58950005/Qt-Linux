#include "openotherapp.h"
#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QtWidgets/QProgressDialog>


OpenOtherApp::OpenOtherApp(QObject *parent)
    :QObject (parent)
{

}

OpenOtherApp::~OpenOtherApp()
{
    qDebug()<< "openOtherApp has been destructed"<<endl;
}
//void OpenOtherApp::on_modalButton_clicked()
//{
//    int numTasks = 100000;
//    QWidget wmk;
//    QProgressDialog progress("Task in progress...", "Cancel", 0, numTasks, &wmk);
//    progress.setWindowModality(Qt::WindowModal);

//    for (int i = 0; i < numTasks; i++) {
//        progress.setValue(i);

//        if (progress.wasCanceled())
//            break;
//    }
//    progress.setValue(numTasks);
//}

void OpenOtherApp::updateUI()
{

    QCoreApplication::processEvents();
}


void OpenOtherApp::openCalendar(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);


    qDebug()<< "Have Calendar app"<<endl;
    QString program = "../QCalendar/QCalendar";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openClock(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Clock app"<<endl;
    QString program = "../QClock/QClock";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openSerial(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Serial app"<<endl;
    QString program = "../QSerial/QSerial";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openRs485(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have RS485 app"<<endl;
    QString program = "../QRS485/QRS485";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openCan(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Can app"<<endl;
    QString program = "../QCan/QCan";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openLed(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Led app"<<endl;
    QString program = "../QLed/QLed";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openTemperature(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Temperature app"<<endl;
    QString program = "../QTemperature/QTemperature";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openWeather(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Weather app"<<endl;
    QString program = "../QWeather/QWeather";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openBuzzer(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Buzzer app"<<endl;
    QString program = "../QBuzzer/QBuzzer";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openBearmonitor(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Bearmonitor app"<<endl;
    QString program = "../QBearermonitor/QBearermonitor";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openMediaplayer(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Mediaplayer app"<<endl;
    QString program = "../QMediaplayer/QMediaplayer";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openGps(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Gps app"<<endl;
    QString program = "../QGps/GPS";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openPictureviewer(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Pictureviewer app"<<endl;
    QString program = "../QPictureViewer/QPictureViewer/QPictureViewer";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}


void OpenOtherApp::openFileview(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Fileview app"<<endl;
    QString program = "../QFileView/QFileView";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openTetris(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Tetris app"<<endl;
    QString program = "../QTetris/QTetris";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openWuziqi(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Wuziqi app"<<endl;
    QString program = "../QWuzi/QtWuziqi";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}

void OpenOtherApp::openSnake(){
    QProcess *parent=new QProcess();
    QProcess *myProcess = new QProcess(parent);
    qDebug()<< "Have Snake app"<<endl;
    QString program = "../QSnake/MySnakeGame";
    myProcess->execute(program);
    myProcess->waitForFinished();
    //qDebug()<<myProcess->readAllStandardOutput();
    return;
}





