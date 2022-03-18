#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include "animation.h"
#include "led.h"
#include "buzzer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Animation               *           enterExitanimation;
    QLabel                  *           topLabel;
    QTabWidget              *           tabWidget;
    Led                     *           led;
    Led                     *           buzzer;
    int                                 desktopWidth;
    int                                 desktopHeight;





};
#endif // MAINWINDOW_H
