#include "gameguidepage_adventure.h"

gameGuidePage_Adventure::gameGuidePage_Adventure(QWidget *parent) : QWidget(parent)
{
     resize(1200,600);
     //一个充满的area
     mainArea =new QScrollArea(this);
     mainArea->setGeometry(0,0,1200,600);
     //一个初始在左上角边界的map
     mapWidegt=new gameGuidePage_adventure_map();
     mainArea->setWidget(mapWidegt);
     mapWidegt->setGeometry(0,0,4000,4000);
     //地图的视窗不需要滑动块
     mainArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     mainArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

     updateMap(4000,4000);                                                  //初始提供默认地图
}


void gameGuidePage_Adventure::mousePressEvent(QMouseEvent *event)
{

    setMouseTracking(true);                                                 //开启鼠标追踪
    QPoint starPos=event->globalPos();                                      //计算起始点坐标（窗体内）
    starPoint=starPos-mapWidegt->pos();

    QWidget::mousePressEvent(event);                                        //这一行是事件传递功能   --目前可有可无
}

void gameGuidePage_Adventure::mouseMoveEvent(QMouseEvent *event)
{
    QPoint endPos=event->globalPos();                                       //鼠标移动过程中不断追踪并更新
    mapWidegt->move(endPos-starPoint);                                      //同时地图跟随鼠标移动
    QWidget::mouseMoveEvent(event);
}

void gameGuidePage_Adventure::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint endPos=event->globalPos();                                       //结束时把记录点更新了
    offPos =endPos-geometry().topLeft();
    setMouseTracking(false);
    QWidget::mouseReleaseEvent(event);


        endPoint=mapWidegt->pos();                                          //对地图边界判断，自动对对齐（防止出现空白）
        if(mapWidegt->x()>=0)                                            {endPoint.setX(0);}
        if(mapWidegt->y()>=0)                                            {endPoint.setY(0);}
        if(mapWidegt->x()+mapWidegt->width()<=mainArea->width())         {endPoint.setX(-(mapWidegt->width()-mainArea->width()));}
        if(mapWidegt->y()+mapWidegt->height()<=mainArea->height())       {endPoint.setY(-(mapWidegt->height()-mainArea->height()));}
        if(mapWidegt->x()>=0)                                            {endPoint.setX(0);}
        if(mapWidegt->y()>=0)                                            {endPoint.setY(0);}
        mapWidegt->move(endPoint);
}

void gameGuidePage_Adventure::setMapUrl(QString url)
{
    mapUrl=url;
}

void gameGuidePage_Adventure::updateMap(int w, int h, QString url)
{
    mapWidegt->loadMap(w,h,url);
}

void gameGuidePage_Adventure::updateMap(int w, int h)
{
    mapWidegt->loadMap(w,h,mapUrl);
}

void gameGuidePage_Adventure::updatePoint()
{
    starPoint.setX(mapWidegt->x()) ;
    starPoint.setY(mapWidegt->y());
}


