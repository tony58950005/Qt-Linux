#ifndef VSCROLL_H
#define VSCROLL_H
#include <QScrollBar>
#include <QPropertyAnimation>
#include <QDateTime>
#include <QTimer>
#include <QEvent>
#include <QWidget>

class Vscroll : public QWidget
{
    Q_OBJECT
public:
    explicit Vscroll(QWidget *parent = 0);
    void setObjectList(QWidget *obj);
    void setObjectScrollBar(QScrollBar *obj);

signals:

public slots:
private:
    QScrollBar *m_scrollBarV;
protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // VSCROLL_H
