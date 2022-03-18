#ifndef OPENDIALOG_H
#define OPENDIALOG_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>

class OpenDialog : public QWidget
{
    Q_OBJECT
public:
    explicit  OpenDialog(QWidget *parent = 0);
    QPlainTextEdit * infoText;
    QPushButton * closeBtn;
    int                                     desktopWidth;                   //屏幕长度
    int                                     desktopHeight;                  //屏幕宽度

public slots:
    void closeDialog();
};

#endif // OPENDIALOG_H
