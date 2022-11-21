#include "cardlabel.h"



cardLabel::cardLabel(QWidget *parent,Qt::WindowFlags):QLabel(parent)
{

    cardIdx=0;
    painting=false;

}

void cardLabel::setIdx(int i)
{
    cardIdx=i;
}

void cardLabel::setLabelName(QString str)
{
    labelName=str;
}

QString cardLabel::getLabelName()
{
    return labelName;
}

void cardLabel::setPointCard(cardShowWigdet *point)
{
    pointTo=point;
}

cardShowWigdet *cardLabel::getPoint()
{
    return pointTo;
}

void cardLabel::setPaint(bool p, QString url)
{
    /*******废代码*******/
    painting=p;
    background.load(url);
    /*******废代码*******/

}



void cardLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit clickedCard(cardIdx);
    emit clickedCard2(pointTo);
    emit clicked(this);
    emit clickedCard3();

}

