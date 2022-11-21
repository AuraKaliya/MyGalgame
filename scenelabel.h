#ifndef SCENELABEL_H
#define SCENELABEL_H

#include <QObject>
#include <QLabel>

#include "gamestoryscene.h"

#pragma execution_character_set("utf-8")

//废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃废弃
class sceneLabel : public QLabel
{
    Q_OBJECT
public:
     explicit  sceneLabel(QWidget *parent=0,Qt::WindowFlags f=Qt::WindowFlags());
     ~sceneLabel(){};
    void setPointStoryPage(gameStoryScene* point);
private:
    gameStoryScene * pointStory;
protected:
    void mouseReleaseEvent(QMouseEvent *ev) override;
signals:
    void clicked(gameStoryScene*);
};

#endif // SCENELABEL_H
