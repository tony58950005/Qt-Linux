#include "opendialog.h"

OpenDialog::OpenDialog(QWidget *parent)
    :QWidget(parent)
{
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();

    move(desktopWidth/2-230,desktopHeight/2-150);

    if(desktopWidth < 500)
    {
        resize(468,200);
    }else {
        resize(460,300);
    }
    infoText = new QPlainTextEdit(this);
    infoText->move(10,10);
    infoText->resize(this->width()-20, this->height()-60);
    infoText->setReadOnly(true);
    infoText->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    infoText->setStyleSheet("background-color:#EDEDED;");
    infoText->appendPlainText("以can0为例,在串口终端执行以下命令：\n");
    infoText->appendPlainText("1) 关闭ifconfig can0 down");
    infoText->appendPlainText("2) 设置ip link set can0 up type can bitrate 125000 triple-sampling on");
    infoText->appendPlainText("3) 开启ifconfig can0 up");
    infoText->appendPlainText("4) 点击“打开can节点”按钮");

    closeBtn = new QPushButton(this);
    if(desktopWidth < 500)
    {
        closeBtn->move(desktopWidth/2,desktopHeight-100);
    }else {
        closeBtn->move(200,260);
    }

    closeBtn->resize(60,30);
    closeBtn->setText("完成");
    connect(closeBtn, SIGNAL(clicked()), this, SLOT(closeDialog()));

}

void OpenDialog::closeDialog()
{
    this->close();
}
