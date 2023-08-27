#ifndef IKUNFLY_H
#define IKUNFLY_H

#include <QWidget>

class IkunFly : public QWidget
{
    Q_OBJECT
public:
    explicit IkunFly(QWidget *parent = nullptr);

    void fly(int min, int max);
protected:
    void paintEvent(QPaintEvent *ev);
    void timerEvent(QTimerEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void enterEvent(QEvent *ev);
signals:

private:
    QPixmap m_pixmap;
    int m_index=1;

    QPoint m_pt;


};

#endif // IKUNFLY_H
