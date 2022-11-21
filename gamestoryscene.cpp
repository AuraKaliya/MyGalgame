#include "gamestoryscene.h"

gameStoryScene::gameStoryScene(QWidget *parent) : QWidget(parent)
{
    resize(1600,900);

    tmpScene= new QLabel(this);

    QPixmap tmpPic;                                                                 //初始场景是一片黑
    tmpPic.load(":/images/background/dark.png");
    backgroundPix=tmpPic;

    buttonLabel=new QLabel(this);                                                   //这啥玩意
    buttonLabel->setGeometry(0,700,1600,200);

    headImageLabel =new QLabel(this);                                               //头像
    headImageLabel->setGeometry(50,725,150,150);
    headImageLabel ->setScaledContents(true);

    headBondRect.setRect(45,720,170,170);                                           //头像框
    mineImageBond=new paintLabel(this);
    mineImageBond->setGeometry(headBondRect);
    mineImageBond->setPaintUrl(":/images/headBond/bond1.png");

    talkLabel =new cardLabel(this);                                                 //对话label
    talkLabel->setGeometry(250,725,1000,150);
    talkLabel->setAlignment(Qt::AlignLeft);
    talkLabel->setAlignment(Qt::AlignTop);
    talkLabel->setStyleSheet("font: 30 23pt 'Microsoft YaHei';color:rgb(255,255,255);border-radius:10%; background-color:rgba(135,135,135,200);");
    talkLabel->setPaint(true,":/images/background/o_0.7_grey.png");                  //后续如果可以就把这个进行style化了
    talkLabel->setWordWrap(true);


    //后面的留白是为了添加背包、卡组系统--需要联动即时选取和使用道具的信号的发送与接收

     AutoSwitch=new talkShowAuto();
     nowIdx=1;                                                                      //因为要去掉读取时读入的列名字
     /****************此处代码重构**************************/
     //素材更新了 这地方也要更新一下
    //初始化所有image 和Rect 用临时素材替代
     headImagePix.load(":/card/images/card/charactor/h_李韶奏.png");
    /****************此处代码重构**************************/

     /*********************人物的立绘放置区域***********************************/
     //310*550 太小了
     //不太满意 有空了调整一下
     backgroundRect.setRect(0,0,1600,900);
     actor1Rect.setRect(150,250,600,1067);
     actor2Rect.setRect(600,250,600,1067);
    /*********************人物的立绘放置区域***********************************/



     returnBtn=new QPushButton(this);
     returnBtn->setText("返回");
     returnBtn->setGeometry(20,20,150,75);
     returnBtn->setStyleSheet(st.style_buttonLabel());

     jumpBtn=new QPushButton(this);
     jumpBtn->setText("跳过");
     jumpBtn->setGeometry(20,100,150,75);
     jumpBtn->setStyleSheet(st.style_buttonLabel());

//链接
     connect(returnBtn,SIGNAL(clicked()),this,SLOT(returnBtnClicked()));
     connect(jumpBtn,SIGNAL(clicked()),this,SLOT(jumpBtnClicked()));
     connect(talkLabel,SIGNAL(clickedCard3()),this,SLOT(TalkShowBegin()));                                    //对话系统核心
     connect(AutoSwitch->getTimer(),SIGNAL(timeout()),this,SLOT(timChanged()));                               //自动显示系统核心
}

gameStoryScene *gameStoryScene::returnThis()
{
    return this;
}

cardLabel *gameStoryScene::returnMineImageLabel()
{
    return mineImageLabel;
}

QLabel *gameStoryScene::returnMyStateLabel()
{
    return stateLabel;

}

QLabel *gameStoryScene::returnHeadLabel()
{
    return headImageLabel;

}

cardLabel *gameStoryScene::returnTalkLabel()
{
    return talkLabel;

}

talkShowAuto *gameStoryScene::getAutoSwitch()
{
    return AutoSwitch;

}

void gameStoryScene::loadTalkInformation(QList<QList<QString> > str)
{
    for (int i=0;i<str.size();i++)
    {
        QList<QString> temp;
        for(int j=0;j<str[0].size();j++)
        {
            temp.append(str[i][j]);
        }
            talkStr.append(temp);
    }
}

void gameStoryScene::TalkShowBegin()
{
    //这个函数是为了label点击设立的

    //当未加载完时，需要加快显示
    if(AutoSwitch->getTimer()->isActive()) {AutoSwitch->setSpeed(10);}
    else if(nowIdx<talkStr.size())                                                      //当加载完一段，但剧情没加载完时，需要跳到下一段文本
    {
        AutoSwitch->reset();
        AutoSwitch->setSpeed(200);
        AutoSwitch->load(talkStr[nowIdx][0],talkLabel);
        //切换主要对话人物  -重新加载pixmap 然后update
        if(talkStr[nowIdx][1].toInt()==1)  {   headImagePix.load(talkStr[nowIdx][4]);}  //切换头像
        if(talkStr[nowIdx][7].toInt()==1)  {   backgroundPix.load(talkStr[nowIdx][8]);} //切换场景
        if(talkStr[nowIdx][2]!="0")  { actor1.load(talkStr[nowIdx][5]);}                //切换主要对话人
        else {actor1.load("");}
        if(talkStr[nowIdx][3]!="0")  {actor2.load(talkStr[nowIdx][6]);}                 //切换次要对话人
        else {actor2.load("");}
        update();
        AutoSwitch->timeStar();
        AutoSwitch->getTimer()->start();
        nowIdx++;                                                                       //下一段 idx++
    }
    else                                                                                //整段剧情加载完时，将发送一个信号，跳转到Story引导页面（因为是同级页面，需要在上级页面中进行跳转）
    {
        TalkShowReset();
        emit finished();
    }
}


void gameStoryScene:: timChanged()
{
    AutoSwitch->timChanged();
}

void gameStoryScene::returnBtnClicked()
{
    AutoSwitch->getTimer()->stop();
    TalkShowReset();
    emit returnPageMain();
}

void gameStoryScene::jumpBtnClicked()
{
    AutoSwitch->getTimer()->stop();
    TalkShowReset();
    emit finished();
}

void gameStoryScene::TalkShowReset()
{
    nowIdx=1;
    talkLabel->setText("");
}

QPushButton *gameStoryScene::getReturnBtn()
{
    return returnBtn;
}



void gameStoryScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    headImageLabel->setPixmap(headImagePix);
    painter.drawPixmap(backgroundRect,backgroundPix);
    //绘制立绘
    if(!actor1.isNull())
    {
        actor1.scaled(actor1Rect.size(),Qt::KeepAspectRatioByExpanding);
        painter.drawPixmap(actor1Rect,actor1);
    }
    if(!actor2.isNull())
    {
        actor2.scaled(actor2Rect.size(),Qt::KeepAspectRatioByExpanding);
        painter.drawPixmap(actor2Rect,actor2);
    }
    painter.end();

}
