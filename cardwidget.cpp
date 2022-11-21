#include "cardwidget.h"


cardWidget::cardWidget(QWidget *parent):QWidget(parent)
{
    setWindowTitle(tr("cardWidget"));
    resize(1600,900);


        /******************界面的数据初始化*****************************/
    myCardId=0;
    cardCate<<"角色卡"<<"道具卡"<<"装备卡";


    //初始化各界面卡牌数量为0
    for(int i=0;i<4;i++)
    {
        countCard[i]=0;
    }

    //实例化主显示堆窗口
    mainShowWidget=new QStackedWidget(this);
    mainShowWidget->setGeometry(0,0,1600,900);

    //主显示界面
    FirstShowWiget=new QWidget(this);
    mainShowWidget->addWidget(FirstShowWiget);
    FirstShowWiget->setGeometry(0,0,1600,900);

    /*设置按钮布局*/

    //实例化按钮
    charactorCardBtn=new QPushButton(cardCate[0],FirstShowWiget);
    propCardBtn=new QPushButton(cardCate[1],FirstShowWiget);
    equipmentCardBtn=new QPushButton(cardCate[2],FirstShowWiget);
    cardDeckBtn=new QPushButton(tr(" 卡组 "),FirstShowWiget);
    returnBtn=new QPushButton(tr(" 返回 "),FirstShowWiget);
    buttonList<<charactorCardBtn<<propCardBtn<<equipmentCardBtn<<cardDeckBtn<<returnBtn;

      for(int i=0;i<buttonList.size();i++)                                                  //设置通用style
      {
          buttonList[i]->setStyleSheet(st.style_buttonLabel());
      }
    //布局
    charactorCardBtn->setGeometry(150,100,200,80);
    propCardBtn->setGeometry(charactorCardBtn->width()+charactorCardBtn->x()+20,100,200,80);
    equipmentCardBtn->setGeometry( propCardBtn->width()+propCardBtn->x()+20,100,200,80);
    cardDeckBtn->setGeometry(equipmentCardBtn->width()+equipmentCardBtn->x()+20,100,200,80);
    returnBtn->setGeometry(cardDeckBtn->width()+cardDeckBtn->x()+300,100,200,80);

    /*搭建牌库显示界面*/
    //查询&卡组用图来组建卡牌信息id区分
    cardShowWidget=new QStackedWidget(FirstShowWiget);                                      //建立在白玉宫的主显示窗体上
    cardShowWidget->setGeometry(100,charactorCardBtn->height()+charactorCardBtn->y()+50,1400,600);
    cardShowWidget->setWindowFlags(Qt::FramelessWindowHint);                                //设置窗体属性：没有边框
    cardShowWidget->setAttribute(Qt::WA_TranslucentBackground,true);                        //设置透明

    //四个界面的初始化
    charactorArea=new QScrollArea(this);
    propArea=new QScrollArea(this);
    equipmentArea=new QScrollArea(this);
    cardDeckArea=new QScrollArea(this);
    Area<<charactorArea<<propArea<<equipmentArea<<cardDeckArea;

     for(int i= 0;i<Area.size();i++)
     {
        cardShowWidget->addWidget(Area[i]);
        cardShowWidget->setWindowFlags(Qt::FramelessWindowHint);
        cardShowWidget->setAttribute(Qt::WA_TranslucentBackground,true);
        //初始化视窗大小
        Area[i]->setGeometry(0,0,1400,600);
        QWidget *tempArea=new QWidget(this);            //每个界面显示由Area控制视口，由widget提供视图

        tempArea->setAutoFillBackground(true);
        QPalette pal;
        pal.setColor(QPalette::Background,QColor(240,255-i*10,255-i*10,240));
        tempArea->setPalette(pal);
        Area[i]->setWidget(tempArea);
        //初始化窗口大小
        tempArea->setGeometry(0,0,Area[i]->width()-20,600);
        Area[i]->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Area[i]->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     }

    //背景搭建
    re=new QRect();
    re->setRect(0,0,1600,900);
    bkpic.load(":/images/background/cardHubBackground.png");

    connect(charactorCardBtn,SIGNAL(clicked()),this,SLOT(To_cardShowPageC()));      //这里建了四个槽来跳转页面 太蠢了
    connect(propCardBtn,SIGNAL(clicked()),this,SLOT(To_cardShowPageP()));
    connect(equipmentCardBtn,SIGNAL(clicked()),this,SLOT(To_cardShowPageE()));
    connect(cardDeckBtn,SIGNAL(clicked()),this,SLOT(To_cardShowPageD()));
}

void cardWidget::readCardInformation(QList<QList<QString> > information)
{   //用于读取相关信息
    for (int i=1;i<information.size();i++)
    {
        QList<QString> temp;
        for(int j=0;j<information[0].size();j++)
        {
            temp.append(information[i][j]);

        }
            cardInformation.append(temp);
    }

}

void cardWidget::addCard(int inCardId)
{   //添加卡牌的方法
    //先创建详细界面，再把卡放在白玉宫中  奶奶的这个类名字拼错了
    cardShowWigdet *aNewCardWidget=new cardShowWigdet(this);

    aNewCardWidget->initCard(inCardId,cardInformation);
    mainShowWidget->addWidget(aNewCardWidget);

    //判断卡牌种类
    int tempId=0;
    if(aNewCardWidget->getCardCate()==tr("角色卡")) tempId=0;
    else if(aNewCardWidget->getCardCate()==tr("道具卡")) tempId=1;
    else if(aNewCardWidget->getCardCate()==tr("装备卡")) tempId=2;


    //建组   /***********************可优化显示**************************/   //这个组可以大一圈或者设计一个卡框然后把边框去掉
        QGroupBox *tempBox=new QGroupBox(Area[tempId]->widget());
        cardLabel *tempCard=new cardLabel(tempBox);
        tempCard->setGeometry(0,0,254,450);
        cardLabel *tempNameLabel=new cardLabel(tempBox);
        tempNameLabel->setGeometry(0,470,254,50);
        tempCard->setPointCard(aNewCardWidget);
        tempNameLabel->setPointCard(aNewCardWidget);
    /***********************后续更新*******************************/
        //采用读取指针的方式进行，这样不必每次添加都建一个image 需要减少空间使用
        QImage  tempPic;
        tempPic.load(aNewCardWidget->getCardPic());
        tempCard->setPixmap(QPixmap::fromImage(tempPic));
        tempCard->setScaledContents(true);
        tempNameLabel->setText(aNewCardWidget->getCardName());
        tempNameLabel ->setAlignment(Qt::AlignCenter);
        tempNameLabel ->setStyleSheet(st.style_buttonLabel()+"border-radius:0%");

  /***********************后续更新*******************************/

        //判断是否增加widget高度
        if((countCard[tempId]/4+1)*550>=Area[tempId]->widget()->height()) // 会超
                 explorPage(Area[tempId]->widget(),600);    //写了一个函数来扩展widget

        tempBox->setGeometry(countCard[tempId]%4*(64+254)+64,(countCard[tempId]/4)*550+40,254,520);
        countCard[tempId]+=1;
            //将其入玩家总牌库中，方便卡组模式
        myCard<<aNewCardWidget;
        myCardId++;

        connect(tempCard,SIGNAL(clickedCard2(cardShowWigdet *)),this,SLOT(To_charactorShow(cardShowWigdet *)));     //指向关联界面
        connect( aNewCardWidget->getBtn(),SIGNAL(clicked()),this,SLOT(To_charactorMainPage()));                     //返回按钮的connect
}

void cardWidget::explorPage(QWidget *wid, int dh)
{
    wid->resize(wid->width(),wid->height()+dh);
}

QList<QList<QString> > cardWidget::showInformation()
{
    return cardInformation;
}

QPushButton *cardWidget::getReturnBtn()
{
    return returnBtn;
}

int cardWidget::getDefaultCardDeck()
{
    return defaultCardDeck;
}

cardDeckInformaiton *cardWidget::getCardDeck()
{
    return cardDeckList[defaultCardDeck];
}

cardDeckInformaiton *cardWidget::getCardDeck(int idx)
{
    return cardDeckList[idx];
}

void cardWidget::paintEvent(QPaintEvent *event)
{
    QPainter  paint(this);  //采用paintevent来绘制背景
    paint.drawPixmap(*re,bkpic);
    paint.end();

}

void cardWidget::To_charactorShow(cardShowWigdet * p)
{
    mainShowWidget->setCurrentWidget(p);
}

void cardWidget::To_charactorMainPage()
{
    mainShowWidget->setCurrentIndex(0);
}

void cardWidget::To_cardShowPageC()
{
    cardShowWidget->setCurrentIndex(0);
}

void cardWidget::To_cardShowPageP()
{
    cardShowWidget->setCurrentIndex(1);
}

void cardWidget::To_cardShowPageE()
{
    cardShowWidget->setCurrentIndex(2);
}

void cardWidget::To_cardShowPageD()
{
    cardShowWidget->setCurrentIndex(3);
}



