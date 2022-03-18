#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QDir>
#include <QSharedMemory>
#include <QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSharedMemory shared_memory;
    shared_memory.setKey(QString("555555"));

    if(shared_memory.attach()){
        return 0;
    }
    /* 设置编码格式为utf-8 默认的情况下 无法识别中文路径 所以这里必须要设置为utf-8 */
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    /* 设置程序的工作目录为可执行文件所在目录 */
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    if(shared_memory.create(1)){
        MainWindow w;
        w.show();
        return a.exec();

    }
    //MainWindow w;
    //w.show();
    //return a.exec();
}
