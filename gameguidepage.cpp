#include "gameguidepage.h"

gameGuidePage::gameGuidePage(QWidget *parent) : QWidget(parent)
{
    resize(1600,900);

    returnLabel=new returnButton(this);                                                             //实例化返回按钮
    returnLabel->setGeometry(0,0,200,100);
    returnLabel->setText(" 返 回 ");
    returnLabel->setStyleSheet(st.style_returnButtonLabelLeft());

    gamesShowWidget =new QStackedWidget(this);                                                      //建立一个stackedWidget mainWidget是引导页面 后续剧情和战斗添加在之后
    gamesShowWidget->setGeometry(200,125,1200,600);


    QPalette palTest(gamesShowWidget->palette());                                                   //给视窗内添加纯色背景--虽然抽象了点
    palTest.setColor(QPalette::Background,QColor(140,140,140,200));
    gamesShowWidget->setAutoFillBackground(true);
    gamesShowWidget->setPalette(palTest);



    guideLabel=new paintLabel(this);                                                                //底部横栏页面，采用paintlabel直接画图
    guideLabel->setGeometry(0,750,1600,150);
    guideLabel->setPaintUrl(":/images/background/lowLabel_test2.png");

    //底部按钮组
    storyLabel=new cardLabel(this);
    storyLabel->setGeometry(50,775,200,100);
    storyLabel->setText(" 故事模式 ");

    extraLabel=new cardLabel(this);
    extraLabel->setGeometry(300,775,200,100);
    extraLabel->setText(" 番外模式 ");

    advenLabel=new cardLabel(this);
    advenLabel->setGeometry(550,775,200,100);
    advenLabel->setText(" 冒险模式 ");

    cardDeckLabel=new cardLabel(this);
    cardDeckLabel->setGeometry(1150,775,200,100);
    cardDeckLabel->setText(" 卡 组 ");

    WhiteStoneLabel=new cardLabel(this);
    WhiteStoneLabel->setGeometry(1375,775,200,100);
    WhiteStoneLabel->setText(" 白玉宫 ");

    guideLabelList<<storyLabel<<extraLabel<<advenLabel<<cardDeckLabel<<WhiteStoneLabel;
    for(int i=0;i<guideLabelList.size();i++)                                                          //风格设置采用循环进行统一
    {
        guideLabelList[i]->setAlignment(Qt::AlignCenter);
        guideLabelList[i]->setStyleSheet(st.style_buttonLabel());
    }


    batTestBtn=new QPushButton(this);                                                                 //战斗测试按钮
    batTestBtn->setGeometry(20,150,150,80);
    batTestBtn->setText("战斗测试");
    batTestBtn->setStyleSheet(st.style_buttonLabel());
    batTestBtn->setVisible(false);                                                                    //只有切换到冒险页面才能可见




    //添加剧情页面
    //在main中进行信息载入 这个页面提供了一个返回指针的接口             //好像并不是必须，因为本来就是在main中进行创建的对象
    pageStory=new gameGuidePage_Story(this);                                                          //剧情引导页面，也就是视窗显示的那块（代替了相应的widget）
    gamesShowWidget->addWidget(pageStory);
    pageStory->setGeometry(0,0,1200,600);

    pageAdventure=new gameGuidePage_Adventure(this);                                                  //冒险引导页面，代替了相应的widget
    gamesShowWidget->addWidget(pageAdventure);
    pageAdventure->setGeometry(0,0,1200,600);

    /****************************！动态小人！***********************************/
    stkRect.setRect(20,550,160,200);
    stkLabel=new QLabel(this);
    stkLabel->setGeometry(stkRect);
    stk = new QMovie;
    stk->setFileName(stkn);
    QSize si(stkRect.size());

    stk->setScaledSize(si);
    stk->start();
    stkLabel->setMovie(stk);

    stk2Label=new QLabel(this);
    stkRect.setRect(1420,550,160,200);
    stk2Label->setGeometry(stkRect);
    stk2=new QMovie;
    stk2->setFileName(stk2n);
    stk2->setScaledSize(si);
    stk2->start();
    stk2Label->setMovie(stk2);

    ssLabel[0]=new QLabel(this);
    ssLabel[0]->setGeometry(200,25,100,100);

    ssLabel[1]=new QLabel(this);
    ssLabel[1]->setGeometry(600,25,100,100);

    ssLabel[2]=new QLabel(this);
    ssLabel[2]->setGeometry(900,25,100,100);

    ssLabel[3]=new QLabel(this);
    ssLabel[3]->setGeometry(1300,25,100,100);


    ss=new QMovie;
    ss->setFileName(ssn);
    QSize sr(100,100);
    ss->setScaledSize(sr);
    ss->start();
    for(int i=0;i<4;i++)
    {
        ssLabel[i]->setMovie(ss);

    }

    /****************************！动态小人！***********************************/
     bkpix=new QPixmap();
     bkpix->load(bkgName);

    storyLabel->setStyleSheet(st.style_buttonLabelChoose());                                        //初始化时默认展示剧情引导页面
    st.style_shadowButton(storyLabel);                                                              //不知道这个类能不能这么玩，没仔细看效果
    gamesShowWidget->setCurrentIndex(0);                                                            //初始为主引导页面

    connect(storyLabel,SIGNAL(clickedCard3()),this,SLOT(ToStory()));                                //页面内跳转到剧情模式
    connect(advenLabel,SIGNAL(clickedCard3()),this,SLOT(ToAdventure()));                            //页面内跳转到冒险模式

}






gameGuidePage *gameGuidePage::getThis()
{
    return this;

}

void gameGuidePage::readStroyInformation(QList<QList<QString> > info)
{
    for (int i=0;i<info.size();i++)
    {
        QList<QString> temp;
        for(int j=0;j<info[0].size();j++)
        {
            temp.append(info[i][j]);

        }
            gameStoryInformation.append(temp);
    }
}

gameGuidePage_Story *gameGuidePage::getStoryPage()
{
    return pageStory;
}

gameGuidePage_Adventure *gameGuidePage::getAdvenPage()
{
    return pageAdventure;
}

void gameGuidePage::initThisWidget()
{

    for(int i=0;i<gameStoryInformation.size();i++)      //对剧情界面的加载
    {
        if(gameStoryInformation[i][2]=="剧情")
            pageStory->addPage(gameStoryInformation[i][3],gameStoryInformation[i][1]);
    }





}

returnButton *gameGuidePage::getReturnButton()
{
    return returnLabel;

}

QPushButton *gameGuidePage::getBattleTestButton()
{
        return batTestBtn;
}

void gameGuidePage::paintEvent(QPaintEvent *event)
{
    QPainter *paint=new QPainter(this);

    paint->drawPixmap(QRect(0,0,1600,900),*bkpix);
    paint->end();
}

void gameGuidePage::ToAdventure()
{
    //在跳转到冒险页面时，需要改变按钮的选择状态和视窗的相应页面展示 ----冒险页面独有的战斗测试按钮也要显示

    batTestBtn->setVisible(true);
    storyLabel->setStyleSheet(st.style_buttonLabel());
    advenLabel->setStyleSheet(st.style_buttonLabelChoose());
    st.style_shadowButton(advenLabel);
    gamesShowWidget->setCurrentWidget(pageAdventure);
}

void gameGuidePage::ToStory()
{

    batTestBtn->setVisible(false);
    advenLabel->setStyleSheet(st.style_buttonLabel());
    storyLabel->setStyleSheet(st.style_buttonLabelChoose());
    st.style_shadowButton(storyLabel);
    gamesShowWidget->setCurrentWidget(pageStory);

}
