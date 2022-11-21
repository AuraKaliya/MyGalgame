#ifndef MYSTYLE_H
#define MYSTYLE_H

#include <QString>
#include <QGraphicsDropShadowEffect>
#include "cardlabel.h"


class myStyle
{
public:
    //本项目的通用style；
    myStyle();
    QString bkGrey(int);
    QString bkGreyH(int);
    QString style_buttonLabel();
    QString style_buttonLabelChoose();
    QString style_returnButtonLabelLeft();
    QString style_longLabel();
    QString style_hover();
    QString style_roLabel();
    void style_shadowButton(cardLabel*);
private:



};

#endif // MYSTYLE_H
