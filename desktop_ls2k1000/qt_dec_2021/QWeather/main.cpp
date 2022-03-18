/**
 * @projectName   QWeather
 * @brief         从网络获取天气信息，显示到界面上
 * @author        topeet
 * @date          2021-04-19
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
