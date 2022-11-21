#include "gameguidepage_story.h"

gameGuidePage_Story::gameGuidePage_Story(QWidget *parent) : QWidget(parent)
{
    resize(1200,600);

    mainArea=new QScrollArea(this);
    mainArea->setGeometry(0,0,1200,600);

    showWidget=new QWidget();
    mainArea->setWidget(showWidget);
    showWidget->setGeometry(0,0,1200,mainArea->height()-20);

    mainArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    count =0;


}

void gameGuidePage_Story::addPage(QString imageUrl, QString storyName)
{

    //先判断是否要扩展窗体
    //712*400  712*50
    //50 Spacing

   if((50+(count+1)*762)>=showWidget->width()) explorPage(showWidget,800);

   //建立part
   cardLabel * storyImageLabel=new cardLabel(showWidget);
   QLabel *storyNameLabel=new QLabel(showWidget);

   storyImageLabel->setGeometry(50+count*762,50,712,400);
   storyImageLabel->setMaximumSize(712,400);
   storyNameLabel->setGeometry(storyImageLabel->x(),storyImageLabel->y()+storyImageLabel->height()+50,storyImageLabel->width(),50);

   QPixmap tempPix;
   tempPix.load(imageUrl);
   storyImageLabel->setPixmap(tempPix);
   storyImageLabel->setScaledContents(true);
   //storyImageLabel->setStyleSheet("border-radius:10%;");
   storyNameLabel->setText(storyName);
   storyNameLabel->setAlignment(Qt::AlignCenter);
   storyNameLabel->setStyleSheet(st.style_longLabel());

    stories<<storyImageLabel;
    storyImageLabel->setIdx(stories.size()-1);
    //在外层进行label与widget的跳转的链接
    count++;

}

cardLabel *gameGuidePage_Story::getStoryLabel(int i)
{
    return stories[i];
}

void gameGuidePage_Story::explorPage(QWidget *wid, int Dw)
{
    wid->resize(wid->width()+Dw,wid->height());

}


