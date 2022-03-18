#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QDir>

/**
 * @fileName      main.cpp
 * @brief         程序入口，本程序使用了第三方图标库QCustomplot，实现了用曲线图显示CPU温度变化
 * @author        topeet
 * @date          2021-04-21
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /* 设置编码格式为utf-8 默认的情况下 无法识别中文路径 所以这里必须要设置为utf-8 */
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    /* 设置程序的工作目录为可执行文件所在目录 */
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    w.show();

    return a.exec();
}
