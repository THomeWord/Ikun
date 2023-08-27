#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QMediaPlayer *player;
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
