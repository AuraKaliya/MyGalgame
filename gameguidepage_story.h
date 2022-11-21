#ifndef GAMEGUIDEPAGE_STORY_H
#define GAMEGUIDEPAGE_STORY_H

#include <QWidget>
#include<QScrollArea>
#include<QString>
#include<QList>
#include <QLabel>
#include<QPixmap>
#include "mystyle.h"

#include"cardlabel.h"

#pragma execution_character_set("utf-8")

class gameGuidePage_Story : public QWidget
{
    Q_OBJECT
public:
    explicit gameGuidePage_Story(QWidget *parent = nullptr);
    void addPage(QString imageUrl,QString storyName);
    cardLabel * getStoryLabel(int);
    void explorPage(QWidget* wid,int w);
private:
    //一个充满的Area
    QScrollArea * mainArea;
    QWidget *showWidget;
    myStyle st;
    int count;
    QList <cardLabel*> stories;
    //一个显示16：9场景图片的引导
    //一个显示剧情名字的label
signals:

};

#endif // GAMEGUIDEPAGE_STORY_H
