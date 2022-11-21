#ifndef GAMEGUIDEPAGE_ADVENTURE_MAP_H
#define GAMEGUIDEPAGE_ADVENTURE_MAP_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QDialog>
#include <QPainter>
#include <QRect>
#include <QPixmap>
#include <QString>
#include <QLabel>
#include <QImage>
#include <QPalette>


#pragma execution_character_set("utf-8")

#include <QDebug>

class gameGuidePage_adventure_map : public QWidget
{
    Q_OBJECT
public:
    //用于加载地图界面的widget  ----说实话有点冗余
    explicit gameGuidePage_adventure_map(QWidget *parent = nullptr);
    void loadMap(int w,int h,QString url);
private:
    bool isPress;
    bool isInit;
    QPoint offPos;
    QString imgUrl;
    QLabel * loadLabel;
    QImage img;
    QPalette pal;
    int whiths;
    int heights;
signals:

};

#endif // GAMEGUIDEPAGE_ADVENTURE_MAP_H
