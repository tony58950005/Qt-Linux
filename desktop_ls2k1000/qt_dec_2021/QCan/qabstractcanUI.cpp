#include "qabstractcan.h"

/**
 * @brief QAbstractCan::initLable
 * @note  初始化窗口的lab标签
 */
void QAbstractCan::initLable()
{
    sendIdLab       = new QLabel(this);
    sendIdLab->setAlignment(Qt::AlignCenter);
    sendIdLab->setText  (" ID:");

    sendDataLab     = new QLabel(this);
    sendDataLab->setAlignment(Qt::AlignCenter);
    sendDataLab->setText("数据:");
/*
    baudrateLab     = new QLabel(this);
    baudrateLab->setAlignment(Qt::AlignCenter);
    baudrateLab->setText("波特率:");
*/
    recvIdLab       = new QLabel(this);
    recvIdLab->setAlignment(Qt::AlignCenter);
    recvIdLab->setText("接收ID");

    if(desktopWidth >= 800)
    {
        infoLab         = new QLabel(this);
        infoLab->setAlignment(Qt::AlignCenter);
        QString info = "请打开" + name;
        infoLab->setText(info);
    }

}

/**
 * @brief QAbstractCan::initPushButton
 * @note  初始化窗口的按钮
 */
void QAbstractCan::initPushButton()
{
    settingBtn     = new QPushButton(this);
    settingBtn->setText("打开can节点");

    sendBtn        = new QPushButton(this);
    sendBtn->setText("发送");

    dialogBtn = new QPushButton(this);
    dialogBtn->setText("打开can网络");
}

/**
 * @brief QAbstractCan::initComBox
 * @note  初始化窗口的下拉框
 */
void QAbstractCan::initComBox()
{
   // baudrateComBox  = new QComboBox(this);
    //QStringList baudrateList;
    //baudrateList << "20000"<<"50000"<<"125000"<<"250000"<<"500000"<<"800000"<<"1000000";

    //baudrateComBox->addItems(baudrateList);
}

/**
 * @brief QAbstractCan::initEdit
 * @note  初始化窗口的编辑器
 */
void QAbstractCan::initEdit()
{
    sendIdEdit = new QLineEdit(this);
    sendIdEdit->setToolTip("请输入一个16进制数");
    if(name == "can0")
    {
        sendIdEdit->setText("1F");
    }else if(name == "can1"){
        sendIdEdit->setText("A1");
    }

    sendDataEdit = new QLineEdit(this);
    sendDataEdit->setText("11.22.33.44.55.66.77.88");
    sendDataEdit->setToolTip("请输入八个16进制数\n并用小数点隔开");

    recvIdEdit = new QLineEdit(this);
    //recvIdEdit->setText("2F");
    recvIdEdit->setToolTip("请输入一个16进制数");

    recvEdit = new QPlainTextEdit(this);
    //recvEdit->setReadOnly(true);
}

/**
 * @brief QAbstractCan::initUI
 * @note  窗口布局
 */
void QAbstractCan::initLayout()
{
    sendLayout = new QHBoxLayout;
    sendLayout->addWidget(sendIdLab,1);
    sendLayout->addWidget(sendIdEdit,2);
    sendLayout->addStretch(desktopWidth/300);
    sendLayout->addWidget(sendDataLab,1);
    sendLayout->addWidget(sendDataEdit,18);
    sendLayout->addStretch(desktopWidth/300);
    sendLayout->addWidget(sendBtn,3);
    sendLayout->addStretch(desktopWidth/400);

    attriLayout = new QGridLayout;
    //attriLayout->addWidget(baudrateLab,0,1,1,2);
   // attriLayout->addWidget(baudrateComBox,0,3,1,3);
    attriLayout->addWidget(recvIdLab,1,1,1,2);
    attriLayout->addWidget(recvIdEdit,1,3,1,1);
    attriLayout->addWidget(settingBtn,2,3,1,2);
    attriLayout->addWidget(dialogBtn,3,3,1,2);
    settingLayout = new QVBoxLayout;
    if(desktopWidth >= 800)
    {
        settingLayout->addLayout(attriLayout,1);
        settingLayout->addWidget(infoLab,2);
    }else {
        settingLayout->addLayout(attriLayout);
    }
    recvLayout = new QHBoxLayout;
    recvLayout->addWidget(recvEdit);

    sendGroup = new QGroupBox;
    sendGroup->setTitle("发送");
    sendGroup->setLayout(sendLayout);

    recvGroup = new QGroupBox;
    recvGroup->setTitle("接收");
    recvGroup->setLayout(recvLayout);

    settingGroup = new QGroupBox;
    settingGroup->setTitle("打开");
    settingGroup->setLayout(settingLayout);

    recvSetLayout = new QHBoxLayout;
    recvSetLayout->addWidget(recvGroup,2);
    recvSetLayout->addWidget(settingGroup,1);

    canWidgetLayout = new QVBoxLayout(this);
    canWidgetLayout->addWidget(sendGroup);
    canWidgetLayout->addLayout(recvSetLayout);
}
