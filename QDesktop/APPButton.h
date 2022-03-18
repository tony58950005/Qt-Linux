#ifndef APPBUTTON_H
#define APPBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QMouseEvent>
#include <QTouchEvent>
#include <QProcess>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QString>

class APPButton : public QPushButton
{
    Q_OBJECT
public:
    explicit APPButton(QWidget *parent = nullptr);
    APPButton(QWidget *parent = nullptr, int ind = -1, QString name="", QString path="", QString info="");

protected:
    bool eventFilter(QObject * obj, QEvent *event) override;

protected slots:
    void appFlagTimerOutSlot();
    void appExecTimerOutSlot();

signals:
    void appFinished();
    void appBacked();
    void appFored();
    void appMoved(int appIndex);

public:
    QLabel              *       iconLabel;                  // 显示APP图标
    QLabel              *       nameLabel;                  // 显示APP名字
    QLabel              *       infoLabel;                  // 显示APP信息
    QPoint                      pointStartA;                // 记录按下点的x坐标
    QPoint                      pointStartB;                // 记录按下点的x坐标
    QTimer              *       appFlagTimer;               // 标记
    QTimer              *       appExecTimer;               // 用于延时执行应用程序
    int                         offsetX;                    // 滑动距离,判断能否翻页
    int                         moveOffset;                 // 滑动距离
    int                         position;                   // 界面移动前所在的页号
    unsigned int                appPressFlage;              // 0: 可以按下; >0 不可以按下
    int                         index;                      // APP索引

private:
    QString                     appName;                    // APP名字
    QString                     appPath;                    // APP路径
    QString                     appInfo;                    // APP信息
    QProcess                    appProcess;                 // 应用程序进程
    QHBoxLayout         *       hLayout;                    // 文字label布局
    QVBoxLayout         *       vLayout;                    // 文字图标label布局
    int                         appWinWidth;
    int                         appWinHeight;
};

#endif // APPBUTTON_H
