#include "ikunfly.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPainter>
#include<QRandomGenerator>
IkunFly::IkunFly(QWidget *parent) : QWidget(parent)
{
    m_pixmap.load(":/1");
    setFixedSize(m_pixmap.size());

    startTimer(150);
}

void IkunFly::fly(int min, int max)
{
    m_index++;
    if(m_index > 2){
        m_index=1;
    }
    QString name=QString (":/%1").arg(m_index);
    m_pixmap.load(name);
    update();

    int stepX = QRandomGenerator::global()->bounded(min,max);
    int stepY = QRandomGenerator::global()->bounded(min,max);

    int curX = this->geometry().topLeft().x() + stepX;
    int curY = this->geometry().topLeft().y() + stepY;

    QDesktopWidget  *desk = QApplication::desktop();
    if(curX >= desk->screenGeometry().right() ){
        curX = desk->screenGeometry().left();
    }
    if(curY >= desk->screenGeometry().bottom() ){
        curY = desk->screenGeometry().top();
    }

    move(curX , curY);
}

void IkunFly::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawPixmap(rect(),m_pixmap);
}

void IkunFly::timerEvent(QTimerEvent *ev)
{
    fly(10,30);
}

void IkunFly::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() ==Qt::LeftButton ){
        m_pt = ev->globalPos() - this->geometry().topLeft();
    }
}

void IkunFly::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton ){
        this->move(ev->globalPos() - m_pt);
    }
}

void IkunFly::enterEvent(QEvent *ev)
{
    fly(-300,300);
}
