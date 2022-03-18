#ifndef QABSTRACTCAN_H
#define QABSTRACTCAN_H

/**
 * @fileName      qabstractcan.h
 * @brief         can测试窗口，定义并初始化各组件，实现can设备的打开，
 *                接收，发送功能。
 * @author        topeet
 * @date          2021-04-30
 */

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QGroupBox>
#include <QMessageBox>
#include <QDebug>
#include <QSocketNotifier>
#include <QStringList>

//! Linux platform header files
#if defined __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/fs.h>
#include <errno.h>
#include <termio.h>
#include <ctype.h>
#if defined __cplusplus
}
#endif

#include "opendialog.h"

class QAbstractCan : public QWidget
{
    Q_OBJECT
public:
    explicit QAbstractCan(QWidget *parent = 0);
    QAbstractCan(QWidget *parent = 0, QString m_name = NULL);
    ~QAbstractCan();

    void initLable();
    void initPushButton();
    void initComBox();
    void initEdit();
    void initLayout();

private:
    bool openCanDevice();
    void setCanAttribute();

signals:
    void updateInfoLabSignal(QString info);

public slots:
    void settingBtnClickedSlot();
    void sendBtnClickedSlot();
    void recvDataIsComeSlot();
    void infoLabUpdate(QString info);
    void dialogBtnClickedSlot();

public:

private:
    QLabel                      *           sendIdLab;                      //发送栏id标签
    QLabel                      *           sendDataLab;                    //发送栏数据标签
    //QLabel                      *           baudrateLab;                    //设置栏波特率标签
    QLabel                      *           infoLab;                        //设置栏信息标签
    QLabel                      *           recvIdLab;                      //设置栏id过滤标签
    QPushButton                 *           sendBtn;                        //发送栏发送按钮
    QPushButton                 *           settingBtn;                     //设置栏"打开/设置"按钮
    QPushButton                 *           dialogBtn;
    //QComboBox                   *           baudrateComBox;                 //波特率选择下拉框
    QLineEdit                   *           sendIdEdit;                     //发送报文中的标识符ID编辑框
    QLineEdit                   *           sendDataEdit;                   //发送报文中的数据编辑框
    QLineEdit                   *           recvIdEdit;                     //设置栏id编辑窗
    QPlainTextEdit              *           recvEdit;                       //接收栏接收数据显示框
    QGroupBox                   *           sendGroup;
    QGroupBox                   *           recvGroup;
    QGroupBox                   *           settingGroup;
    QHBoxLayout                 *           sendLayout;
    QGridLayout                 *           attriLayout;
    QVBoxLayout                 *           settingLayout;
    QHBoxLayout                 *           recvLayout;
    QHBoxLayout                 *           recvSetLayout;
    QVBoxLayout                 *           canWidgetLayout;
    OpenDialog                  *           openDialog;
    int                                     fd;                             //socket文件描述符
    QString                                 name;                           //can名字
    QString                                 sendFilterId;                   //发送时数据中的id标识符
    QSocketNotifier             *           notifier;                       //用于监听套接字的可读事件
    struct ifreq                            ifr;                            //网络接口地址
    struct sockaddr_can                     addr;                           //设置can网络接口
    int                                     desktopWidth;                   //屏幕长度
    int                                     desktopHeight;                  //屏幕宽度
};

#endif // QABSTRACTCAN_H


#if 0
//! 设置回环模式，自发自收，用于测试单路can硬件是否正常
ip link set can0 up type can bitrate 125000  loopback on
#endif
