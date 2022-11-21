#ifndef TALKSHOWAUTO_H
#define TALKSHOWAUTO_H

#include <QObject>
#include <QTimer>
#include <QString>
#include <QLabel>
#include <QFile>
#include <QDebug>

#include "cardlabel.h"

#pragma execution_character_set("utf-8")
class talkShowAuto:public QObject
{
    //自动显示文本的类  00使用方法00   在相应的页面进行显示速度设置和时钟控制（槽和信号及active），需要时一行一行读取并显示
public:
    talkShowAuto()
    {
        inc=0;
        speed=100;
        tim= new QTimer(this);
    }
    void load(QString st,QLabel *lb); //载入
    void load(QString st, cardLabel *lb);
    void timeStar ();
    void timeStar (int sp);
    void setSpeed(int sp);
    void timChanged();
    void reset();
    QTimer* getTimer();
    QString getLineStr();
    QString getLabelStr();
    //返回文本数据
private:
    QString str; //需要显示的文本
    QLabel *lab; //承载文本的label
    QTimer *tim;//时间计数器
    int inc;  //对于一段文字的指针，用于逐字显示
    int speed; //用于显示文字的速度 即时间间隔
private slots:
};

#endif // TALKSHOWAUTO_H
