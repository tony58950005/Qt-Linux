#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QDesktopWidget>
#include <QLabel>
#include <QPropertyAnimation>

class Animation : public QWidget
{
    Q_OBJECT
public:
    explicit Animation(QWidget *parent = nullptr);
    ~Animation();

    void setAnimationObject(QMainWindow *obj);


signals:

public slots:
    void closeAnimationSlot();
    void exitAppAnimationSlot();
    void updateAnimationSlot();

private:
    QPushButton * exitBtn;
    QMainWindow * animationObject;
    QPropertyAnimation * startAnimation;
    QPropertyAnimation * exitAnimation;
    int desktopWidth;
    int desktopHeight;
};

#endif // ANIMATION_H
