#include "scenelabel.h"


sceneLabel::sceneLabel(QWidget *parent, Qt::WindowFlags f)
{

}

void sceneLabel::setPointStoryPage(gameStoryScene *point)
{
    pointStory=point;
}



void sceneLabel::mouseReleaseEvent(QMouseEvent *ev)
{
      emit clicked(pointStory);
}
