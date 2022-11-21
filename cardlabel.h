#ifndef CARDLABEL_H
#define CARDLABEL_H

#include <QObject>
#include <QLabel>
#include <QWheelEvent>
#include<QPainter>
#include "cardshowwigdet.h"


#pragma execution_character_set("utf-8")

class cardLabel:public QLabel
{
    Q_OBJECT
public:
    explicit cardLabel(QWidget *parent=0,Qt::WindowFlags f=Qt::WindowFlags());
    ~cardLabel(){}

        /*********************这里的“卡牌”是抽象的卡牌，可以应用在任何有需求的情况*******************************/

    void setIdx(int i);                              //设置“卡牌”的序列，应用在需要通过创建carldLabel前后顺序记录的情况

    void setLabelName(QString);                      //设置“卡牌”的名字，应用在需要通过名字检索相应卡牌的情况
    QString getLabelName();

    void setPointCard(cardShowWigdet * point);       //设置连接的卡牌界面，是对从白玉宫的展示到卡牌详细页面的特化功能设计
    cardShowWigdet *  getPoint();

    /*************废功能***********************/
    void setPaint(bool p,QString url);                //这算是个废代码，因为paintevent会影响纯加载图片的情况，所以需要另一个paintLabel类来特化这种情况
    /*************废功能***********************/

private:
    /*************废功能***********************/
    QPixmap background;
    bool painting=false;
    /*************废功能***********************/

    int cardIdx;                                        //“卡牌”的序列
    cardShowWigdet * pointTo;                           //卡牌的指向界面
    QString labelName;                                  //“卡牌”的名字

protected:
    void mouseReleaseEvent(QMouseEvent *ev) override;   //添加点击事件

signals:
    //点击发送的相关信号    ----广播多种信号，根据需要设计槽进行接收
    void clickedCard3();
    void clicked(cardLabel*);
    void clickedCard(int i);
    void clickedCard2( cardShowWigdet * p);

    //鼠标放在卡牌上时会显示的  待添加该功能                  --添加时可以参考QPushButton的hover的styleSheet 或者鼠标移动进该box时的事件
    //void hover();


};

#endif // CARDLABEL_H
