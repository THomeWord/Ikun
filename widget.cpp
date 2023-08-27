#include "widget.h"
#include "ui_widget.h"
#include"ikunfly.h"
#include<QRandomGenerator>
#include<QMessageBox>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置无边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置窗口背景透明
    setAttribute(Qt::WA_TranslucentBackground, true);
    //窗口最大化
    showMaximized();
    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/3"));
    player->setVolume(100);
    player->play();
    for(int i=0;i<75;i++){
        IkunFly *win =new IkunFly(this);
        win->move(QRandomGenerator::global()->bounded(this->width()),
                  QRandomGenerator::global()->bounded(this->height()));
        win->show();
        //状态的显示
        connect(player,&QMediaPlayer::stateChanged,[=]()
        {
            switch(player->state())
            {
            case QMediaPlayer::StoppedState:
                win->close();//图片关闭
                this->close();
                break;
            default:
                break;
            }
        });

    }
}

Widget::~Widget()
{
    delete ui;
}

