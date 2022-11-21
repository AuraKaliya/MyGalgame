#include "gameguidepage_adventure_map.h"

gameGuidePage_adventure_map::gameGuidePage_adventure_map(QWidget *parent) : QWidget(parent)
{
    isPress=false;
    isInit=false;
}

void gameGuidePage_adventure_map::loadMap(int w, int h, QString url)
{
    imgUrl=url;
    whiths=w;
    heights=h;
    isInit=false;
    this->setAutoFillBackground(true);
    img.load(url);
    pal.setBrush(this->backgroundRole(),QBrush(img));
    this->setPalette(pal);
}
