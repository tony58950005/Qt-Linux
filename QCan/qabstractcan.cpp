#include "qabstractcan.h"

QAbstractCan::QAbstractCan(QWidget *parent) : QWidget(parent){Q_UNUSED(parent)}

/**
 * @brief QAbstractCan::QAbstractCan
 * @param parent    父窗口
 * @param m_name    设备节点名字
 */
QAbstractCan::QAbstractCan(QWidget *parent, QString m_name)
    : QWidget(parent), name(m_name)
{
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();

    fd = -1;

    initLable();
    initPushButton();
    //initComBox();
    initEdit();
    initLayout();
    openDialog = new OpenDialog;


    connect(dialogBtn, SIGNAL(clicked()), this, SLOT(dialogBtnClickedSlot()));
    connect(sendBtn,SIGNAL(clicked()),this,SLOT(sendBtnClickedSlot()));
    connect(settingBtn,SIGNAL(clicked()),this,SLOT(settingBtnClickedSlot()));
    connect(this,SIGNAL(updateInfoLabSignal(QString)),this,SLOT(infoLabUpdate(QString)));
}

/**
 * @brief QAbstractCan::~QAbstractCan
 * @note  结束程序时将can0和can1关闭
 */
QAbstractCan::~QAbstractCan()
{
    if (notifier) {
        delete notifier;
        notifier = 0;
    }
    if (fd >= 0) {
        ::close(fd);
        fd = -1;
    }

    QString canDownCmdString = "ifconfig " + name + " down";
    QByteArray canDownCmdByteArry = canDownCmdString.toLatin1();
    char * canDownCmdChar = canDownCmdByteArry.data();
    system(canDownCmdChar);
}

/**
 * @brief QAbstractCan::settingBtnClickedSlot
 * @note  "打开/设置"按钮槽函数,can节点初始化：
 *          1.调用system命令初始化can属性
 *          2.创建套接字文件描述符
 *          3.设置接收的过滤id
 *          4.监听套接字
 */
void QAbstractCan::settingBtnClickedSlot()
{

    if (fd >= 0) {
        ::close(fd);
        fd = -1;
    }

    bool ok = false;
    QString recvIdEditData;

    //! 设置can属性
    setCanAttribute();

    //! 创建文件描述符fd，打开CAN网络
    bool ret = openCanDevice();
    if(!ret)
    {
        return;
    }

    //! 设置过滤规则,只读取指定id标识符的数据,
    recvIdEditData = recvIdEdit->text();
    if(recvIdEditData.isEmpty())// 输入为空
    {
        // 不设置过滤器，接收所有id的消息

#if 0
        //设置过滤器,禁止接收所有消息(没有使用)
        if((setsockopt(fd, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0)) < 0)
        {
            QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
            return;
        }
#endif
    }else{
        // 设置过滤器,接收指定id的消息
        struct can_filter rfilter[1];
        rfilter[0].can_id = recvIdEditData.toInt(&ok,16);/* 获取界面设置的id */
        rfilter[0].can_mask = CAN_SFF_MASK;
        if(setsockopt(fd, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter)) < 0)
        {
            QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
            return;
        }
    }

    //! 监听可读事件
    notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
    connect (notifier, SIGNAL(activated(int)), this, SLOT(recvDataIsComeSlot()));
    emit updateInfoLabSignal("设置成功并打开");
}


/**
 * @brief QAbstractCan::sendBtnClickedSlot
 * @note  发送按钮槽函数，实现数据发送功能
 */
void QAbstractCan::sendBtnClickedSlot()
{
    bool ok = false;
    int ret = -1;
    char sendBuffChar[8] = {0,0,0,0,0,0,0,0};
    struct can_frame frame;

    //! 设置要发送的id
    QString idString = sendIdEdit->text();
    int idDec = idString.toInt(&ok,16);
    if(!ok)
    {
        QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
        return;
    }
    frame.can_id = idDec;

    //! 从界面获取要发送的数据
    QString dataString = sendDataEdit->text();
    QStringList dataStrArray = dataString.split(".");

    //! 设置发送的数据长度
    frame.can_dlc = dataStrArray.length();

    //! 发送数据
    QString temp;
    for( int i=0; i<dataStrArray.length(); i++ )
    {
        temp = dataStrArray.at(i);
        sendBuffChar[i] = temp.toInt(&ok,16);
        if(!ok)
        {
            QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
            return;
        }
    }
    memcpy(frame.data, sendBuffChar, frame.can_dlc);
    ret = write(fd, &frame, sizeof(struct can_frame));
    if(ret < 0)
    {
        QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
        return;
    }
    emit updateInfoLabSignal("发送成功");
}


/**
 * @brief QAbstractCan::recvDataIsComeSlot
 * @note  读取数据槽函数，QSocketNotifier监听到可读事件后执行此函数
 */
void QAbstractCan::recvDataIsComeSlot()
{
    char showBuff[20]={0,0,0,0,0,0,0,0};
    struct can_frame frame;

    //! 读取数据
    if(read(fd, &frame, sizeof(struct can_frame)) <= 0 ){
        perror("read");
        QMessageBox::critical(this, tr("Error"), strerror(errno), QMessageBox::Yes);
        return;
    }
    /**
     * @brief sprintf
     * @param id    发送方ID
     * @param dlc   接收到的数据长度
     * @note        将数据保存到showBuff[8]中,显示到界面
     */
    sprintf(showBuff, "id:%03X@dlc:%d~$ %02X %02X %02X %02X %02X %02X %02X %02X", \
                        frame.can_id,\
                        frame.can_dlc,\
                        frame.data[0],\
                        frame.data[1],\
                        frame.data[2],\
                        frame.data[3],\
                        frame.data[4],\
                        frame.data[5],\
                        frame.data[6],\
                        frame.data[7]);

    QString data = QString(QLatin1String(showBuff));
    recvEdit->appendPlainText(data.mid(0,(15+frame.can_dlc*3)));
    emit updateInfoLabSignal("接收成功");
}



/**
 * @brief QAbstractCan::openCanDevice
 * @note  创建套接字，绑定can节点
 */
bool QAbstractCan::openCanDevice()
{
    if (fd >= 0) {
        ::close(fd);
        fd = -1;
    }

    int ret = -1;
    char * canName = name.toLatin1().data();

    //! 创建socket套接字
    fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(fd < 0)
    {
        QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
        return false;
    }

    //! 指定网卡名称
    strcpy(ifr.ifr_name, canName);
    ret = ioctl(fd, SIOCGIFINDEX, &ifr);
    if(ret < 0){
        QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
        ::close(fd);
        return false;
    }

    //! 设置网络类型和接口
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex; /* CAN网络接口索引 */

    //! 绑定
    ret = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    if(ret < 0){
        QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
        ::close(fd);
        return false;
    }

    return true;
}

/**
 * @brief QAbstractCan::setCanAttribute
 * @note  设置can的波特率和工作模式（本例程为triple-sampling）
 *        改为在超级终端使用命令设置
 */
void QAbstractCan::setCanAttribute()
{
#if 0
    QString baudrateString = baudrateComBox->currentText();

    QString canParamsCmdString = "ip link set " + name + " up type can bitrate " + baudrateString + " triple-sampling on ";
    QByteArray canParamsCmdByteArry = canParamsCmdString.toLatin1();
    char * canParamsCmdChar = canParamsCmdByteArry.data();

    QString canUpCmdString = "ifconfig " + name + " up";
    QByteArray canUpByteArry = canUpCmdString.toLatin1();
    char * canUpCmdChar = canUpByteArry.data();

    QString canDownCmdString = "ifconfig " + name + " down";
    QByteArray canDownCmdByteArry = canDownCmdString.toLatin1();
    char * canDownCmdChar = canDownCmdByteArry.data();


    system(canDownCmdChar);
    system(canParamsCmdChar);
    system(canUpCmdChar);
#endif
}

/**
 * @brief QAbstractCan::infoLabUpdate
 * @param info 更新设置栏的infoLab显示内容
 */
void QAbstractCan::infoLabUpdate(QString info)
{
    infoLab->setText(info);
}

/**
 * @brief QAbstractCan::dialogBtnClickedSlot
 */
void QAbstractCan::dialogBtnClickedSlot()
{
    openDialog->setParent(this);
    openDialog->show();
}


