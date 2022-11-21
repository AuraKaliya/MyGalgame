#ifndef GAMEGUIDEPAGE_ADVENTURE_H
#define GAMEGUIDEPAGE_ADVENTURE_H

#include <QWidget>
#include<QScrollArea>
#include<QString>
#include<QList>
#include <QLabel>
#include<QPixmap>

#include"cardlabel.h"
#include "gameguidepage_adventure_map.h"

#pragma execution_character_set("utf-8")

class gameGuidePage_Adventure : public QWidget
{
    Q_OBJECT
public:
    //冒险模式----可拖动地图
    /*******************可更新想法*********************************/
        //用List<point>存储地图上可进行跳转的点
        //用函数读取相应的点数据并在初始化过程与相关页面连接   --数据库里没有 需要加上
        //给点添加hover    --可以建QPushButton或者直接用点击事件判断point是否在rect中
    /*******************可更新想法*********************************/
    explicit gameGuidePage_Adventure(QWidget *parent = nullptr);
    void setMapUrl(QString url);
    void updateMap (int w, int h, QString url);                     //设置地图的函数
    void updateMap(int w,int h);
    void updatePoint();
private:
    QPoint offPos;
    //一个充满的Area
    QScrollArea * mainArea;
    gameGuidePage_adventure_map *mapWidegt;
    QString mapUrl=":/images/map/map_0001.png";                     //默认地图
    QPoint starPoint;
    QPoint endPoint;
    // 需要一列list cardlabel和一列 list points 来规范节点位置
    QList<QPoint> labelPoint;
    QList<cardLabel*> sendLabel;
    //需要查一下如何拖动视窗 finished
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:

};

#endif // GAMEGUIDEPAGE_ADVENTURE_H
