#include "MainWindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QDir>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


#ifdef __arm__   //在ARM触摸屏设备上运行时不显示鼠标箭头
    //QApplication::setOverrideCursor(Qt::BlankCursor);
#endif
    //! 设置编码格式为utf-8 默认的情况下 无法识别中文路径 所以这里必须要设置为utf-8
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    //! 设置程序的工作目录为可执行文件所在目录
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    MainWindow w;
    w.show();
    return a.exec();
}
