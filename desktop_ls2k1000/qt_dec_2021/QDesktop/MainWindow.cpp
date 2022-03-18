#include "MainWindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QStringList>
#include <QAction>
#include <QDebug>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * @note
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight = QApplication::desktop()->geometry().height();

appPathList         <<"../QCalendar/QCalendar"
                       <<"../QClock/QClock"
                      <<"../QSerial/QSerial"
                     <<"../QRS485/QRS485"
                    <<"../QCan/QCan"
                   <<"../QLed/QLed"
                  <<"../QTemperature/QTemperature"
                 <<"../QWeather/QWeather"
                <<"../QBuzzer/QBuzzer"
                <<"../QBearermonitor/QBearermonitor"
                <<"../QMediaplayer/QMediaplayer"
               <<"../QGps/GPS"
              <<"../QPictureViewer/QPictureViewer/QPictureViewer"
             <<"../QFileView/QFileView"
            <<"../QTetris/QtTetris"
          <<"../QWuzi/QtWuziqi"
	<<"../QSnake/MySnakeGame"
         <<"../QCalculator/QCalculator"
       <<"../QAutotest/QAutotest";


    appNameList     <<"日历"      <<"Time"    <<"串口"
                   <<"RS485"    <<"CAN"     <<"LED灯"
                  <<"温度"     <<"天气"    <<"Buzzer" << "Device Monitor" << "Video"
                 <<"GPS"   <<"Picture"       <<"Files"
                <<"俄罗斯方块"   <<"五子棋"        <<"贪吃蛇"
               <<"计算器" <<"录音"        <<"auto test";



    appInfoList      <<"公历时间"        <<"时钟例程"     <<"功能测试"
                    <<"功能测试"        <<"功能测试"     <<"功能测试"
                   <<"CPU温度"        <<"查看天气"   <<"功能测试"  <<"设备显示器"<<"视频播放器"
                  <<"功能测试"       <<"查看图片"       <<"文件系统"
                 <<"游戏"        <<"游戏"    <<"游戏"
                <<"Calculator"    <<"麦克风"     <<"其他测试";

    loopCount = 0;
    appsPress = new QTimer(this);
    connect(appsPress, SIGNAL(timeout()),this,SLOT(appsPressTimeOutSlot()));

    initMainWindow();
    initAnimation();
    initApps(APP_NUM);
    //initBottom();
    initTop();
}

MainWindow::~MainWindow(){
    qDebug()<<"End~"<<endl;
}

/**
 * @brief MainWindow::initMainWindow
 * @note  初始化主窗体
 */
void MainWindow::initMainWindow()
{
    this->setGeometry(0,0,desktopWidth,desktopHeight);
    this->setWindowFlags(Qt::FramelessWindowHint);

    QPalette palate;
    palate.setBrush(backgroundRole(),QBrush(QPixmap(":/Resource/background/UbuntuStyle.jpg")));
    setPalette(palate);

    mainWidget = new QWidget(this);

    this->setCentralWidget(mainWidget);
    mainWidget->installEventFilter(this);

    appWidgetParent = new QWidget(this);
    appWidgetParent->setGeometry((float)0/1024*this->geometry().width(),(float)62.5/600*this->geometry().height(),(float)this->geometry().width(),(float)500/600*this->geometry().height());

    backgroundApp = new QLabel(appWidgetParent);
    backgroundApp->setGeometry(desktopWidth/18,desktopHeight/5,desktopWidth/60*55,desktopHeight/40*23);
    backgroundApp->setStyleSheet("background-color: rgba(200,179, 165, 10) ; border-radius:15px; border-width: 0px");
    appWidgetParent->setStyleSheet("border-image:transparent");

    appWidget = new QWidget(appWidgetParent);
    //!  设置存放app的窗口大小
    //appWidget->setGeometry(0,0,(float)2*this->geometry().width(),(float)400/480*this->geometry().height());
    appWidget->setGeometry(0,0,(float)this->geometry().width()*2,(float)500/600*this->geometry().height());
    appWidget->setStyleSheet("border-image:transparent");
    appWidget->installEventFilter(this);
}

/**
 * @brief MainWindow::initAnimation
 * @note  绑定动画对象
 */
void MainWindow::initAnimation()
{
    propertyAnimation = new QPropertyAnimation(appWidget,"pos");
    propertyAnimation->setDuration(200);
}

/**
 * @brief MainWindow::initApps
 * @param appNum
 * @note  app按钮初始化和布局
 */
void MainWindow::initApps(int appNum)
{

    gridPage1 = new QGridLayout;
    gridPage2 = new QGridLayout;
    appWidgetLayout = new QHBoxLayout(appWidget);

    gridPage1->setContentsMargins(desktopWidth/10,desktopHeight/5,desktopWidth/10,desktopHeight/10);
    gridPage2->setContentsMargins(desktopWidth/10,desktopHeight/5,desktopWidth/10,desktopHeight/10);

    QFont nameFont("PangMenZhengDao", 20, 40);
    QFont infoFont("PangMenZhengDao", 20, 40);

    for(int i = 0; i < appNum; i++) //!遍历app数组设置位置及尺寸
    {
        appBtn[i] = new APPButton( appWidget, i, appNameList[i], appPathList[i], appInfoList[i]);

        if(desktopWidth < 500 ){//调整RGB_4.3寸屏按钮大小
            appBtn[i]->setMinimumSize(desktopWidth/4,desktopHeight/5);
            appBtn[i]->setMaximumSize(desktopWidth/4,desktopHeight/5);
        }else {                 //其他屏幕按钮大小
            appBtn[i]->setMinimumSize(desktopWidth/50*12,desktopHeight/6);
            appBtn[i]->setMaximumSize(desktopWidth/50*12,desktopHeight/6);
        }

        if(desktopWidth < desktopHeight){//竖屏 { i.MX6ULL-[ LVDS 7.0 ] }
            appBtn[i]->iconLabel->setFixedSize(desktopHeight/20,desktopHeight/20);
            nameFont.setPixelSize(20);
            infoFont.setPixelSize(18);

        }else {//横屏
            appBtn[i]->iconLabel->setFixedSize(desktopHeight/9,desktopHeight/9);
            nameFont.setPixelSize(desktopWidth/50);
            infoFont.setPixelSize(desktopWidth/60);
        }

        appBtn[i]->nameLabel->setFont(nameFont);
        appBtn[i]->infoLabel->setFont(infoFont);

        if(i < 9)//对第一页APP进行布局
        {
            if(i%3 == 0){
                gridPage1 ->addWidget(appBtn[i],i/3,1,2,2);
            }else if (i%3 == 1) {
                gridPage1 ->addWidget(appBtn[i],i/3,4,2,2);
            }else if (i%3 == 2) {
                gridPage1 ->addWidget(appBtn[i],i/3,7,2,2);
            }

            if(i != 2 && i != 5 && i != 8)//设置app按钮左右间隔
            {
                gridPage1->setSpacing(desktopWidth/10);
            }
        }
        else if ( i >= 9 && i < 18 ) {//对第二页APP进行布局
            if((i-9)%3 == 0){
                gridPage2 ->addWidget(appBtn[i],(i-9)/3,1,2,2);
            }else if ((i-9)%3 == 1) {
                gridPage2 ->addWidget(appBtn[i],(i-9)/3,4,2,2);
            }else if ((i-9)%3 == 2) {
                gridPage2 ->addWidget(appBtn[i],(i-9)/3,7,2,2);
            }

            if(i != 11 && i != 14 && i != 17)//设置app按钮左右间隔
            {
                gridPage2->setSpacing(desktopWidth/10);
            }
        }
        
        connect(appBtn[i],SIGNAL(appFinished()),this,SLOT(showMainWindow()));
        connect(appBtn[i],SIGNAL(appBacked()),this,SLOT(appMoveBackwardSlot()));
        connect(appBtn[i],SIGNAL(appFored()),this,SLOT(appMoveForwardSlot()));
        connect(appBtn[i],SIGNAL(appMoved(int)),this,SLOT(appMoveWin(int)));
    }//!

    appWidgetLayout->addLayout(gridPage1);
    appWidgetLayout->addLayout(gridPage2);
}

/**
 * @brief MainWindow::initTop
 * @note  初始化顶层栏的时间的显示
 */
void MainWindow::initTop()
{
    QFont font;
    font.setPixelSize((float)desktopHeight/20);

    topLabel = new TopLabel(this);
    QFont timeFont("PangMenZhengDao", 10, 10);
    topLabel->setGeometry(0,0,(float)this->geometry().width(),25);
    topLabel->dateLabel->setGeometry((float)(this->geometry().width()-150),0,(float)(150),25);

    timeLabel = new QLabel(this);
    if(desktopWidth == 600 && desktopHeight == 1024){
        timeLabel->setFixedSize(desktopWidth/2,desktopHeight/4);
        timeLabel->move(desktopWidth/4,desktopHeight/10);
        timeFont.setPixelSize((float)desktopWidth/9);
    }else {
        timeLabel->setFixedSize(desktopWidth/3,desktopHeight/6);
        timeLabel->move(desktopWidth/3,desktopHeight/10);
        timeFont.setPixelSize((float)desktopWidth/13);
    }

    timeLabel->setStyleSheet("border-image:transparent; color: #E0FFFF");
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setFont(timeFont);
    timeLabel->setText("系统时间");

    connect(topLabel->timer,SIGNAL(timeout()),this,SLOT(updateTime()));
}

/**
 * @brief MainWindow::initBottom
 * @note  初始化页面小圆点翻页图标
 */
void MainWindow::initBottom()
{
    pageWidget[0] = new QWidget(mainWidget);
    pageWidget[0]->setStyleSheet("border-image:url(Resource/icon/page2)");
    pageWidget[0]->setGeometry((float)370/800*this->geometry().width(),(float)450/480*this->geometry().height(),
                               (float)15/800*this->geometry().width(),(float)15/800*this->geometry().width());
    pageWidget[1] = new QWidget(mainWidget);
    pageWidget[1]->setStyleSheet("border-image:url(Resource/icon/page1)");
    pageWidget[1]->setGeometry((float)410/800*this->geometry().width(),(float)450/480*this->geometry().height(),
                               (float)15/800*this->geometry().width(),(float)15/800*this->geometry().width());
}

/**
 * @brief MainWindow:   eventFilter
 * @param obj       :   触发事件的对象
 * @param event     :   事件类型
 * @return          :
 * @note            :   根据appWidget事件，进行滑动翻页
 */
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{

    int offsetX;
    int moveOffset;

    // event on appWidget
    if(obj == appWidget)
    {
         switch (event->type()) {

         case QEvent::MouseButtonPress:
             pointStartA.setX(cursor().pos().x());
             pointStartB.setX(cursor().pos().x());
             break;

         case QEvent::MouseButtonRelease:
             offsetX = cursor().pos().x()-pointStartA.x();
             position = loopCount*appWidgetParent->geometry().width();
             if(qAbs(offsetX) >= 10)//the threshold 20->10
             {
                 if(offsetX > 0)
                 {
                    //! 向后滚动
                    if(loopCount>0){
                        //backward();
                        //qDebug()<<"loopCount(B):  "<<loopCount<<endl; 
		    }
                 }else {
                    //! 向前滚动
                    if(loopCount<=0){
                        //forward();
			//qDebug()<<"loopCount(F):  "<<loopCount<<endl;
                    //  backward();
		    }
                 }
             }else {
              //      mainWinMove();
             }
             break;

         case QEvent::MouseMove:
             //! 移动窗口
             moveOffset = cursor().pos().x() - pointStartB.x();
	     //wmk add
	     /*if(moveOffset > 20)
		moveOffset=20;*/
	     //end wmk
             if(loopCount <=0 && moveOffset >=0){
                if(moveOffset>=50){appWidget->move(50,0);mainWinMove();loopCount=0;}
                //else{appWidget->move(appWidget->pos().x()+moveOffset,0);}
             }else if(loopCount >0 && moveOffset <0){
                if(moveOffset<=-50){appWidget->move(-50-desktopWidth,0);mainWinMove();loopCount=1;}
                //else{appWidget->move(appWidget->pos().x()+moveOffset,0);}

             }else{


                //appWidget->move(appWidget->pos().x()+moveOffset,0);
             }
             //appWidget->move(appWidget->pos().x()+moveOffset,0);

             pointStartB.setX(cursor().pos().x());
             break;

         default:
             break;
         }

    }else if (obj == mainWidget) {
        switch ( event->type() ) {
        case QEvent::MouseButtonPress:

            break;
        default:
            break;
        }

    }else {
        qDebug()<<obj->objectName();
    }

    return QWidget::eventFilter(obj, event);//将事件传递给父类
}

/**
 * @brief MainWindow::backward
 * @note  向后滚动
 */
void MainWindow::backward()
{
    propertyAnimation->stop();
    if(loopCount<=0){
        propertyAnimation->setStartValue(QPoint(50,0));
    }else{
        propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));
    }
    //propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));

    propertyAnimation->setEndValue(QPoint(0,0));//the original 0,0->?,0
    propertyAnimation->start();
    loopCount--;

    if(loopCount <= 0)
        loopCount=0;
     for(int i=0;i<2;i++)
     {
         /*
        if(i==qAbs(loopCount))
            pageWidget[i]->setStyleSheet("border-image:url(Resource/icon/page2)");
        else
            pageWidget[i]->setStyleSheet("border-image:url(Resource/icon/page1)");
            */
     }
}

/**
 * @brief MainWindow::forward
 * @note  向前滚动
 */
void MainWindow::forward()
{
    static int widthValue = appWidgetParent->geometry().width();
    
    propertyAnimation->stop();
    if(loopCount>0){
        propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));
        propertyAnimation->setEndValue(QPoint(0,0));
    }else{
        propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));
        propertyAnimation->setEndValue(QPoint(-widthValue*1,0));
    }

//    propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));
//    propertyAnimation->setEndValue(QPoint(-widthValue*1,0));
    propertyAnimation->start();

    loopCount++;

    if(loopCount >= 1)
        loopCount=1;

    for(int i=0;i<2;i++){
        /*
        if(i==qAbs(loopCount))
            pageWidget[i]->setStyleSheet("border-image:url(Resource/icon/page2)");
        else
            pageWidget[i]->setStyleSheet("border-image:url(Resource/icon/page1)");
            */
    }

}

/**
 * @brief MainWindow::mainWinMove
 * @note  回到当前页
 */
void MainWindow::mainWinMove()
{
    propertyAnimation->stop();
    propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));
    propertyAnimation->setEndValue(QPoint(-position,0));
    propertyAnimation->start();
}


void MainWindow::updateTime()
{
    timeLabel->setText(topLabel->t);
}

/**
 * @brief MainWindow::appMoveBackwardSlot
 * @note  向后滑动APP按钮后，切换主界面
 */
void MainWindow::appMoveBackwardSlot()
{
    if(loopCount>0)
        backward();
}

/**
 * @brief MainWindow::appMoveForwardSlot
 * @note  向前滑动APP按钮后，切换主界面
 */
void MainWindow::appMoveForwardSlot()
{
    qDebug()<<"loopCount:"<<loopCount<<endl;
    if(loopCount<=0){
        forward();
    }
}

/**
 * @brief MainWindow::appMoveWin
 * @param appIndex  APP编号
 * @note  滑动APP按钮时主界面跟随移动
 */
void MainWindow::appMoveWin(int appIndex)
{
    appBtn[appIndex]->moveOffset = cursor().pos().x() - appBtn[appIndex]->pointStartB.x();
    qDebug()<<"appButton->offsetX:"<<appBtn[appIndex]->offsetX<<endl;
    //appWidget->move(appWidget->pos().x() + appBtn[appIndex]->moveOffset,0);

    if(loopCount <=0 && appBtn[appIndex]->moveOffset >=0){appBtn[appIndex]->moveOffset=0;}
    if(loopCount >0 && appBtn[appIndex]->moveOffset <0){appBtn[appIndex]->moveOffset=0;}

    qDebug()<<"wmk moveOffset:"<<appBtn[appIndex]->moveOffset<<endl;

    appWidget->move(appWidget->pos().x() + appBtn[appIndex]->moveOffset,0);
    appBtn[appIndex]->pointStartB.setX(cursor().pos().x());
    appBtn[appIndex]->appPressFlage=1;
    appBtn[appIndex]->appFlagTimer->start(200);
}

/**
 * @brief MainWindow::appsPressTimeOutSlot
 */
void MainWindow::appsPressTimeOutSlot()
{
    //过滤触摸事件
    for(int i = 0 ; i < APP_NUM ; i++)
    {
        appBtn[i]->appPressFlage = 0;
    }
    appsPress->stop();
}
/**
 * @brief MainWindow::showMainWindow
 * @note  刷新界面
 */
void MainWindow::showMainWindow()
{
    //过滤触摸事件
    for(int i = 0 ; i < APP_NUM ; i++)
    {
        appBtn[i]->appPressFlage = 1;
        if(appBtn[i]->appFlagTimer->isActive())
        {
            appBtn[i]->appFlagTimer->stop();
        }
    }
    QCursor cursor;
    cursor.setPos(desktopWidth,desktopHeight);
    this->show();
    repaint(0,0,desktopWidth,desktopHeight);
    appsPress->start(100);//threshold 200->100
}



