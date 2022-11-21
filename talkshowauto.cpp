#include "talkshowauto.h"



void talkShowAuto::load(QString st, cardLabel *lb)
{
    str=st;
    lab=lb;
}

void talkShowAuto::load(QString st, QLabel *lb)
{
    str=st;
    lab=lb;
}

void talkShowAuto::timeStar()
{
    tim->start(speed);
}

void talkShowAuto::timeStar(int sp)
{
    tim->start(sp);
    speed=sp;
}

void talkShowAuto::setSpeed(int sp)
{
    speed=sp;
    tim->setInterval(speed);
}

void talkShowAuto::timChanged()
{
    if(inc>str.size())
        tim->stop();
    else
        lab->setText(str.left(inc));
    inc++;
}

void talkShowAuto::reset()
{
    inc=0;
}

QTimer *talkShowAuto::getTimer()
{
    return tim;
}

QString talkShowAuto::getLineStr()
{
    return str;
}

QString talkShowAuto::getLabelStr()
{
    return lab->text();
}
