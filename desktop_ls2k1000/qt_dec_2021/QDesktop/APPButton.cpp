#include "APPButton.h"
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QString>
#include <QMessageBox>

APPButton::APPButton(QWidget *parent) { Q_UNUSED(parent) }

/**
 * @brief APPButton::APPButton
 * @param ind       : APP索引编号
 * @param name      : APP名字
 * @param path      : APP路径
 * @param info      : APP信息
 * @note  初始化图标，文字显示label，并进行布局
 */
APPButton::APPButton(QWidget *parent, int ind, QString name, QString path, QString info)
    : QPushButton(parent),
      index(ind),
      appName(name),
      appPath(path),
      appInfo(info)
{
    setAttribute(Qt::WA_AcceptTouchEvents);

    appFlagTimer = new QTimer(this);
    appExecTimer = new QTimer(this);
    vLayout = new QVBoxLayout;
    hLayout = new QHBoxLayout(this);

    //! 初始化APP图标
    iconLabel = new QLabel;
    QPixmap pix;
    pix.load("Resource/icon/"+QString::number(ind+1)+".png");
    pix.scaled(iconLabel->size(),Qt::KeepAspectRatio);
    iconLabel->setScaledContents(true);
    iconLabel->setPixmap(pix);

    //! 初始化APP名字显示
    nameLabel = new QLabel(this);
    nameLabel->setAlignment(Qt::AlignBottom);
    nameLabel->setStyleSheet("QLabel{color:#FFFFFF;}");
    nameLabel->setText("   "+appName);

    //! 初始化APP其他信息显示
    infoLabel = new QLabel(this);
    infoLabel->setAlignment(Qt::AlignTop);
    infoLabel->setStyleSheet("QLabel{color:#F8F8FF;}");
    infoLabel->setText("   "+appInfo);

    //! 布局
    vLayout->addWidget(nameLabel);
    vLayout->addWidget(infoLabel);
    hLayout->addWidget(iconLabel);
    hLayout->addLayout(vLayout);
    this->setLayout(hLayout);

    //! 设置按钮样式
    setStyleSheet(""
                  //! 正常状态
                  "QPushButton{"
                                "background: transparent;"
                                "border:0px transparent; "
                                "color:rgba(88,88,88,255)}"
                  //! 悬浮状态
                  "QPushButton:hover{"
                                "border:2px solid rgba(38,135,200,255);"
                                "}"
                  );

    connect(appFlagTimer,SIGNAL(timeout()),this,SLOT(appFlagTimerOutSlot()));
    connect(appExecTimer,SIGNAL(timeout()),this,SLOT(appExecTimerOutSlot()));

    installEventFilter(this);
    appPressFlage = 0;
}


/**
 * @brief APPButton::appFlagTimerOutSlot
 */
void APPButton::appFlagTimerOutSlot()
{
    appFlagTimer->stop();
    appPressFlage = 0;
}

/**
 * @brief APPButton::appExecTimerOutSlot
 * @note  时间到后执行应用程序
 */
void APPButton::appExecTimerOutSlot()
{
    appExecTimer->stop();

    QFile file(appPath);
    if(!file.exists())
    {
        QMessageBox::information(this,"Info","该功能暂未上线,努力优化中...",QMessageBox::Ok);
    }
    appProcess.setParent(this);

    appProcess.start(appPath);
    appProcess.waitForFinished(-1);

    QCursor cursor;
    cursor.setPos(0,0);
    //qDebug()<<"app[i] = "<<index;

    appPressFlage = 1;
    emit appFinished();
    appFlagTimer->start(20);

}

/**
 * @brief APPButton::eventFilter
 * @param obj
 * @param event
 * @return
 * @note  判断是否点击，滑动应用程序，并作出相应操作
 */
bool APPButton::eventFilter(QObject *obj, QEvent *event)
{

    switch (event->type()) {

    case QEvent::MouseButtonPress:

        pointStartA.setX(cursor().pos().x());
        pointStartB.setX(cursor().pos().x());

        break;

    case QEvent::MouseButtonRelease:

        offsetX = cursor().pos().x() - pointStartA.x();


        if(qAbs(offsetX) >= 10)
        { //! 绝对值，求滑动的距离

            if(offsetX > 0)
            {
                //! 向后滚动
                emit appBacked();
            }else{
                //! 向前滚动
                emit appFored();
		qDebug()<<"wmk emit forward wmk"<<endl;
                //emit appBacked();
            }
        } else  if(appPressFlage == 0 )
        {   //! 开启APP
            appExecTimer->start(20);
        }
        break;

    case QEvent::MouseMove:

        emit appMoved(index);
        break;

    default:
        break;
    }

    return QWidget::eventFilter(obj,event);
}



