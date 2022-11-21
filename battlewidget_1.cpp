#include "battlewidget_1.h"

battleWidget_1::battleWidget_1(QWidget *parent) : QWidget(parent)
{
    resize(1600,900);
    setStyleSheet("border-radius:3px;color:rgb(255,255,255); background:transparent;");                     //这啥玩意


    bkRect.setRect(0,0,1600,900);                                                                           //战斗背景加载
    bkImage.load(backgroundUrl);

    HPRect_M.setRect(30,50,550,50);                                                                         //血条初始化
    HPMAXRect_M.setRect(30,50,550,50);
    HPRect_O.setRect(1020,50,550,50);
    HPMAXRect_O.setRect(1020,50,550,50);
    HPList<<HPRect_M<<HPRect_O;



    vsLabel=new QLabel(this);                                                                               //成计时器Label啦
    vsLabel->setGeometry(700,20,200,110);
    vsLabel->setText(" 30 ");
    vsLabel->setAlignment(Qt::AlignCenter);
    vsLabel->setStyleSheet("font:50 50pt;background-color:argb(255,47,17,109);color:rgb(255,255,255);");


    runLabel=new cardLabel(this);                                                                           //没实装~没有撤退可言~
    runLabel->setGeometry(620,50,50,50);

    //肯定小了 需要调整  --可以在之后心情好的时候优化下
    charactorRect_M.setRect(150,100,282,500);
    charactorLabel_M=new paintLabel(this);
    charactorLabel_M->setGeometry(charactorRect_M);
    charactorLabel_M->setAttribute (Qt::WA_TranslucentBackground);
    charactorLabel_M->setIDX(0);

    charactorRect_O.setRect(1168,100,282,500);
    charactorLabel_O=new paintLabel(this);
    charactorLabel_O->setGeometry(charactorRect_O);
    charactorLabel_O->setIDX(1);
    charactorLabel_O->setAttribute (Qt::WA_TranslucentBackground);
    charactorRectList<<charactorRect_M<<charactorRect_O;


    lowLabel=new paintLabel(this);                                                                          //底部区域
    lowLabel->setGeometry(0,600,1600,300);
    lowLabel->setStyleSheet("background-color:argb(255,47,17,109);");


    headLabel=new QLabel(this);                                                                             //头像
    headLabel->setGeometry(50,625,250,250);
    headRect.setRect(50,625,250,250);

    cardRect.setRect(350,600,880,300);

    //初始化手卡rect
    for(int i=0;i<5;i++)
    {
        handCardRect[i].setRect(350+20+i*(152+20),615,152,270);
    }

    stateRect.setRect(1230,600,350,300);                                                                   //这啥玩意

    ATKLabel_M=new QLabel(this);
    ATKLabel_M->setGeometry(1250,615,300,50);

    DEFLabel_M=new QLabel(this);
    DEFLabel_M->setGeometry(1250,680,300,50);

    ADShowList<<ATKLabel_M<<DEFLabel_M;

    for(int i=0;i<ADShowList.size();i++)
    {
        ADShowList[i]->setAlignment(Qt::AlignVCenter);
        ADShowList[i]->setStyleSheet("font:30 20pt;background-color:argb(160,188,143,246);");
    }


    buffRect_M.setRect(1250,750,300,125);

    //初始化常参数
    playerM=new player();
    playerO=new player();

    playerM->setOPPO(playerO);
    playerO->setOPPO(playerM);

    playerM->setNPC(false);
    playerO->setNPC(true);



    connect(&mainStepTimer,SIGNAL(timeout()),this,SLOT(timChanged()));                              //主要阶段倒计时
    connect(charactorLabel_M,SIGNAL(clicked(int)),this,SLOT(usingCard(int)));                       //对人物使用卡牌
    connect(charactorLabel_O,SIGNAL(clicked(int)),this,SLOT(usingCard(int)));

}

void battleWidget_1::loadNPCInformation(QList<QList<QString> > NPCStr)
{

    QList<QString> tmplist;
    int tmpidx=(rand()%(NPCStr.size()-1))+1;

    for(int i=0;i<NPCStr[0].size();i++)
    {
        tmplist.append(NPCStr[tmpidx][i]);
    }

    staticInformation<<tmplist;
}

//好家伙 这么多废案
void battleWidget_1::loadNPCStrategy(QList<QList<QString> > strategyStr)
{
    qDebug()<<"未使用";
}

void battleWidget_1::loadPlayerInformation(QList<QList<QString> > PlayerStr)
{
    qDebug()<<"未使用2";
}

void battleWidget_1::loadPlayerInformation(QList<QString> PlayerStr)
{
     qDebug()<<"未使用3";
}


void battleWidget_1::loadBuffInformation(QList<QList<QString> > BuffStr)
{

     for(int i=0;i<BuffStr.size();i++)
     {
          QList<QString> tmplist;
         for(int j=0;j<BuffStr[0].size();j++)
         {
             tmplist.append(BuffStr[i][j]);
         }
         buffInformationList.append(tmplist);
     }

}

void battleWidget_1::loadCardHub(QList<QList<QString> > cardStr)
{
    for(int i=1;i<cardStr.size();i++)
    {
         QList<QString> tmplist;
        for(int j=0;j<cardStr[0].size();j++)
        {
            tmplist.append(cardStr[i][j]);
            //qDebug()<<tmplist;
        }
        cardHub.append(tmplist);
    }
}

void battleWidget_1::initCardDeck()
{
     qDebug()<<"未使用5";
}

void battleWidget_1::initCardNPC(int type, int difficulty)
{

    int tmpCount=100;
    int tmpRrate;
    int tmpSRrate;
    int tmpSSRrate;

    if(difficulty>30)
    {
        tmpRrate=10;
        tmpSRrate=3;
        tmpSSRrate=10;
    }else if(difficulty>10)
    {
        tmpRrate=5;
        tmpSRrate=5;
        tmpSSRrate=10;
    }else
    {
        tmpRrate=3;
        tmpSRrate=5;
        tmpSSRrate=10;
    }



    while(tmpCount>=0)
    {
        if(NPCtype[type]==NPCtype[0])
        {

            for(int i=0;i<cardHub.size();i++)
            {
                if(cardHub[i][3]=="攻增益"||cardHub[i][3]=="防减益")
                   {
                        if(qrand()%2==1)
                        {
                            QList<QString> tmpCard;
                                for(int j=0;j<10;j++)
                                   { tmpCard.append(cardHub[i][j]);}
                            handCardNPC.append(tmpCard);
                            tmpCount--;
                        }
                    }else if(cardHub[i][3]=="装备"&&cardHub[i][5].toInt()>0)
                    {
                             if(qrand()%3==1)
                             {
                                 QList<QString> tmpCard;
                                     for(int j=0;j<10;j++)
                                        { tmpCard.append(cardHub[i][j]);}
                                 handCardNPC.append(tmpCard);
                                 tmpCount--;
                             }


                     }else if(cardHub[i][4]=="R")
                    {
                            if(qrand()%tmpRrate==1)
                            {
                                QList<QString> tmpCard;
                                    for(int j=0;j<10;j++)
                                       { tmpCard.append(cardHub[i][j]);}
                                handCardNPC.append(tmpCard);
                                tmpCount--;
                            }

                     }   else if(cardHub[i][4]=="SR")
                {
                    if(qrand()%tmpSRrate==1)
                    {
                        QList<QString> tmpCard;
                            for(int j=0;j<10;j++)
                               { tmpCard.append(cardHub[i][j]);}
                        handCardNPC.append(tmpCard);
                        tmpCount--;
                    }

                }else if(cardHub[i][4]=="SSR")
                {
                    if(qrand()%tmpSSRrate==1)
                    {
                        QList<QString> tmpCard;
                            for(int j=0;j<10;j++)
                               { tmpCard.append(cardHub[i][j]);}
                        handCardNPC.append(tmpCard);
                        tmpCount--;
                    }

                }

            }

        }


        if(NPCtype[type]==NPCtype[1])
        {

            for(int i=0;i<cardHub.size();i++)
            {
                if(cardHub[i][3]=="防增益"||cardHub[i][3]=="攻减益")
                   {
                        if(qrand()%2==1)
                        {
                            QList<QString> tmpCard;
                                for(int j=0;j<10;j++)
                                   { tmpCard.append(cardHub[i][j]);}
                            handCardNPC.append(tmpCard);
                            tmpCount--;
                        }
                    }else if(cardHub[i][3]=="装备"&&cardHub[i][6].toInt()>0)
                    {
                             if(qrand()%3==1)
                             {
                                 QList<QString> tmpCard;
                                     for(int j=0;j<10;j++)
                                        { tmpCard.append(cardHub[i][j]);}
                                 handCardNPC.append(tmpCard);
                                 tmpCount--;
                             }


                     }else if(cardHub[i][4]=="R")
                    {
                            if(qrand()%tmpRrate==1)
                            {
                                QList<QString> tmpCard;
                                    for(int j=0;j<10;j++)
                                       { tmpCard.append(cardHub[i][j]);}
                                handCardNPC.append(tmpCard);
                                tmpCount--;
                            }

                     }   else if(cardHub[i][4]=="SR")
                {
                    if(qrand()%tmpSRrate==1)
                    {
                        QList<QString> tmpCard;
                            for(int j=0;j<10;j++)
                               { tmpCard.append(cardHub[i][j]);}
                        handCardNPC.append(tmpCard);
                        tmpCount--;
                    }

                }else if(cardHub[i][4]=="SSR")
                {
                    if(qrand()%tmpSSRrate==1)
                    {
                        QList<QString> tmpCard;
                            for(int j=0;j<10;j++)
                               { tmpCard.append(cardHub[i][j]);}
                        handCardNPC.append(tmpCard);
                        tmpCount--;
                    }

                }

            }

        }



        if(NPCtype[type]==NPCtype[2])
        {

            for(int i=0;i<cardHub.size();i++)
            {
                if(cardHub[i][4]=="R")
                    {
                            if(qrand()%tmpRrate==1)
                            {
                                QList<QString> tmpCard;
                                    for(int j=0;j<10;j++)
                                       { tmpCard.append(cardHub[i][j]);}
                                handCardNPC.append(tmpCard);
                                tmpCount--;
                            }

                     }   else if(cardHub[i][4]=="SR")
                {
                    if(qrand()%tmpSRrate==1)
                    {
                        QList<QString> tmpCard;
                            for(int j=0;j<10;j++)
                               { tmpCard.append(cardHub[i][j]);}
                        handCardNPC.append(tmpCard);
                        tmpCount--;
                    }

                }else if(cardHub[i][4]=="SSR")
                {
                    if(qrand()%tmpSSRrate==1)
                    {
                        QList<QString> tmpCard;
                            for(int j=0;j<10;j++)
                               { tmpCard.append(cardHub[i][j]);}
                        handCardNPC.append(tmpCard);
                        tmpCount--;
                    }

                }

            }

        }
        tmpCount--;
    }

    //下标为10的属性列 为等级列
    for(int s=0;s<handCardNPC.size();s++)
    {
        handCardNPC[s].append(QString::number(difficulty+qrand()%(50-difficulty+1)-1));
    }


}

void battleWidget_1::initCardPlayer()
{

    cardDeckInformaiton *tmpCardDeck=whiteStone->getCardDeck();

//【0】ID【1】Name【2】种类【3】副类【4】稀有度【5】ATK【6】DEF【7】DHP【8】BUFF（暂定最多一个buff）【9】持续回合【10】等级 NPC的卡牌等级随NPC等级，Player自获取[11]url
  for(int i=0;i<tmpCardDeck->cardInformationInWhiteStone.size();i++)
  {
      QList<QString> tmpStr;
      tmpStr.append(QString::number(tmpCardDeck->cardInformationInWhiteStone[i]->getCardId()));
       tmpStr.append(tmpCardDeck->cardInformationInWhiteStone[i]->getCardName());
        tmpStr.append(tmpCardDeck->cardInformationInWhiteStone[i]->getCardCate());
         tmpStr.append(tmpCardDeck->cardInformationInWhiteStone[i]->getCardCate2());
          tmpStr.append(tmpCardDeck->cardInformationInWhiteStone[i]->getCardRarity());
           tmpStr.append(QString::number(tmpCardDeck->cardInformationInWhiteStone[i]->getCardATK()));
            tmpStr.append(QString::number(tmpCardDeck->cardInformationInWhiteStone[i]->getCardDEF()));
             tmpStr.append(QString::number(tmpCardDeck->cardInformationInWhiteStone[i]->getCardDHP()));
              tmpStr.append(QString::number(tmpCardDeck->cardInformationInWhiteStone[i]->getCardBuffId()));
               tmpStr.append(cardHub[findCardInHub(tmpCardDeck->cardInformationInWhiteStone[i]->getCardId())]);
                tmpStr.append(QString::number(tmpCardDeck->cardInformationInWhiteStone[i]->getCardGrade()));
                 tmpStr.append(tmpCardDeck->cardInformationInWhiteStone[i]->getCardPic());

        cardDeck.append(tmpStr);

  }

}

void battleWidget_1::initCardPlayerTest()
{
    int count=100;

    while(count>=0)
    {
            for(int i=0;i<cardHub.size();i++)
            {
                if(qrand()%4==1)
                {
                    QList<QString>tmpCard;
                    for(int j=0;j<12;j++)   tmpCard.append(cardHub[i][j]);
                    cardDeck.append(tmpCard);
                    count--;
                }
            }


        count--;

    }



}

void battleWidget_1::inStep()
{
           update();  //血条更新
           pdrawChardStep(playerO);     //对手抽卡
           pdrawChardStep(playerM);     //我方抽卡
           pmainStep(playerO);          //对手主要阶段
           pmainStep(playerM);          //我方主要阶段
}

void battleWidget_1::drawCardPlayer()
{
}

void battleWidget_1::initCardInformation()
{
            //重置结束flag
            hasEnd=false;
            playerM->initState();
            playerO->initState();

            //暂定最高等级为20，但目前等级没有实装
            initCardNPC(qrand()%3,qrand()%20);

            //测试环节--玩家卡组从牌库中抽取
            initCardPlayerTest();

            //玩家抽三张卡
            pdrawChardStep(playerM);
            pdrawChardStep(playerM);
            pdrawChardStep(playerM);

}

void battleWidget_1::linkWhiteStone(cardWidget *w)
{
    whiteStone=w;
}


int battleWidget_1::findCardInHub(int cardId)
{
    for(int i=0;i<cardHub.size();i++)
    {
        if(cardId==cardHub[i][0].toInt())
        {
            return i;
        }
    }
    return 0;
}

int battleWidget_1::findCardData(int cardId, QList<QList<QString> > &database)
{
    for(int i=0;i<database.size();i++)
        if(cardId==database[i][0].toInt())
            return i;
    return 0;

}

bool battleWidget_1::settleOutBuff(player *p)
{
    //结算buff 返回是否进入主要阶段
    bool tmpFlag=true;
    QList<QList<QString>> ptmpBuff=p->getBuffNow();

    for(int i=0;i<ptmpBuff.size();i++)
    {
        int tmpidx=findCardData(ptmpBuff[i][0].toInt(),buffInformationList);
        if(isJumpBuff(buffInformationList[tmpidx][1])) tmpFlag=false;
        //buff中的ATK等都是对该player而言的。
        p->settleOutBuff(buffInformationList[tmpidx][4].toInt(),buffInformationList[tmpidx][5].toInt(),buffInformationList[tmpidx][6].toInt());
    }
    if(p->getEquipBuff()!="")
    {
         int tmpidx=findCardData(p->getEquipBuff().toInt(),buffInformationList);
        p->settleOutBuff(buffInformationList[tmpidx][4].toInt(),buffInformationList[tmpidx][5].toInt(),buffInformationList[tmpidx][6].toInt());
    }

    //结算之后能否进入主要阶段
    //要等所有buff都结算了才返回
return tmpFlag;

}

bool battleWidget_1::isJumpBuff(QString buffName)
{
    //判断是否为特殊的buff
    for(int i=0;i<jumpBuffCount;i++)
    {
        if(buffName==jumpBuff[i]) return true;
    }
    return false;
}

void battleWidget_1::initTimeCount()
{
    mainStepTime=31;
}

void battleWidget_1::mainStepStar()
{
    mainStepTimer.setInterval(1000);
    mainStepTimer.start();
}

void battleWidget_1::returnPage()
{
}

void battleWidget_1::timChanged()
{
    if(mainStepTime<=0) {
        mainStepTimer.stop();
        pbattleStep();
    }
    else   mainStepTime--;

}

void battleWidget_1::selectCard(int idx)
{
    if(mainStepTimer.isActive())
    {
        if(cardChoose==idx) cardChoose=-1;
         else  cardChoose=idx;
    }
    if(cardChoose!=-1) qDebug()<<"选中："<<handCardLabel[cardChoose]->getLabelName();

}

void battleWidget_1::usingCard(int idx)
{
    if(idx==0)
    {
        if(cardChoose>=0)
        {
            updateMsgBox(handCard[cardChoose],playerM);
        }
    }else  if(idx==1)
    {
        if(cardChoose>=0)
        {
            updateMsgBox(handCard[cardChoose],playerO);
        }

    }

}

void battleWidget_1::hpChangedM()
{
    HPRect_M.setWidth((HPMAXRect_M.width()*playerM->getHP())/playerM->getHPMax());
}

void battleWidget_1::hpChangedO()
{
    HPRect_O.setWidth((HPMAXRect_O.width()*playerO->getHP())/playerO->getHPMax());

}

void battleWidget_1::resetBattleRole()
{
    //仅清除，做测试；  -- 在外部进行重新加载
    staticInformation.clear();
}

void battleWidget_1::updateMsgBox(QList<QString> hc, player *p)
{
    QString tmpTEXT="";

    //真的要对“····”使用“····”吗？
    //Name 副类 ATK DEF DHP BUFF
    //后续换成描述，把具体数值信息显示放到hover中
    tmpTEXT="真的要对"+p->getName()+"使用"+hc[1]+"吗？";
    cardChooseBox.setText(tmpTEXT);
    tmpTEXT=hc[1]+" "+hc[3]+" ATK:"+hc[5]+" DEF:"+hc[6]+" DHP:"+hc[7]+" BUFF:"+buffInformationList[findCardData(hc[8].toInt(),buffInformationList)][2];

    cardChooseBox.setInformativeText(tmpTEXT);
    cardChooseBox.setStandardButtons(QMessageBox::Ok|QMessageBox::No);
    cardChooseBox.setDefaultButton(QMessageBox::No);

    int ret=cardChooseBox.exec();

    switch(ret)
    {
        case QMessageBox::Ok:
                puseCard(p,cardChoose);
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }
}

void battleWidget_1::initBattle()
{
     qDebug()<<"未使用initBattle";
}

void battleWidget_1::initBattleTest()
{
    //作为test
    QPixmap headpic(headImageUrl);
    headLabel->setPixmap(headpic);
    headLabel->setScaledContents(true);
    headLabel->setVisible(true);
    //初始化双方角色
    qDebug()<<staticInformation[0];
    playerM->loadPlayerInformation(staticInformation[0]); 
     charactorLabel_M->setPaintUrl(staticInformation[0][6]);
    playerO->loadPlayerInformation(staticInformation[1]);
     charactorLabel_O->setPaintUrl(staticInformation[1][6]);
    //进入抽卡阶段，这里有个循环? 还是用函数自调好些感觉
    inStep();

}



void battleWidget_1::mouseReleaseEvent(QMouseEvent *event)
{
    //点击事件不太行，改成QLbabel的点击
    //对立绘应该用Paintlabel；
    //当点击事件发生时，如果是在主要阶段中，即timer处于active状态。
    if(mainStepTimer.isActive())
    {      //获取鼠标位置
             QPoint tmpPos=event->pos();

        if(headRect.contains(tmpPos)){      //直接结束回合
            mainStepTimer.stop();
            pbattleStep();
        }
    }
}

void battleWidget_1::paintEvent(QPaintEvent *event)
{
    //对各阶段实时变化的状态量进行展示
    vsLabel->setText(QString::number(mainStepTime));

    QPainter *painter= new QPainter(this);
    painter->drawPixmap(bkRect,bkImage);

    QPen pen;
    pen.setColor(Qt::darkRed);
    pen.setWidth(3);
    painter->setPen(pen);
    for(int i=0;i<handCardLabel.size();i++)
    {
      handCardLabel[i]->move(handCardRect[i].x(),handCardRect[i].y());
      painter->drawRect(handCardRect[i]);
      handCardLabel[i]->setPixmap(*handCardPic[i]);
      handCardLabel[i] ->setScaledContents(true);
    }

    ATKLabel_M->setText(" ATK:"+QString::number(playerM->getOATK()));
    DEFLabel_M->setText(" DEF:"+QString::number(playerM->getODEF()));

    painter->drawRect(headRect);
    painter->drawRect(HPMAXRect_M);
    painter->drawRect(HPMAXRect_O);
    painter->drawRect(buffRect_M);

    painter->setBrush(QBrush(Qt::red,Qt::SolidPattern));
    painter->drawRect(HPRect_M);
    painter->drawRect(HPRect_O);



    painter->end();
}


void battleWidget_1::pdrawChardStep(player *p)
{ 
  bool canContinue=true;
  canContinue=settleOutBuff(p);                                                     //结算buff
  hpChangedO();
  hpChangedM();
  //结算后对角色血量进行判定是否存活。
  if(p->isSurvival()){}
  else
  {
        //  这里试想不通过emit进行 仅通过内部函数调用把流程进行完毕，
        //  emit 感觉用作类之间的传递信号更好些。
        //  比如发送胜利者是否是玩家/胜利者的idx/用作排行榜结算更好些
        //  当前角色血量见底，获胜者是其对手
        pendStep(p->getOPPO());
  }

  update();

  if(canContinue)  //状态正常，可以进入抽卡阶段
   {
     if(p->isNPC()){ }
     else    //是玩家 抽一张到手卡里
     {
       if(!cardDeck.empty()) //卡组里还有卡
        {

                        int tmpIdx=rand()%cardDeck.size();
                        QList<QString> tmpCard;
                        for(int i=0;i<cardDeck[tmpIdx].size();i++)  {tmpCard.append(cardDeck[tmpIdx][i]);}

                        //卡组中去除该卡
                        cardDeck.swap(tmpIdx,cardDeck.size()-1);
                        cardDeck.pop_back();

                        //手卡没满就加入手卡，满了就爆掉
                        //使用手牌需要考虑 handCard pop,handCardLabel pop +删除 handCardImage swap;注意一个是指针一个是实例

                        if(handCard.size()<5)
                        {
                            handCard.insert(handCard.size(),tmpCard);

                            cardLabel * tmpCardLabel=new cardLabel(this);
                            tmpCardLabel->resize(152,270);
                            //是否有必要存在 或者用tmpUrl来获取更好
                          // handCardImageUrl[handCard.size()-1]=cardDeck[findCardInHub(tmpCard[0].toInt())][11];
                            //常驻5个pixmap 每次改变只用改变对应的手卡idx的image的load。
                           QString  tmpUrl=cardDeck[findCardInHub(tmpCard[0].toInt())][11];
                           QPixmap *tmpImg=new QPixmap();
                           tmpImg->load(tmpUrl);
                           handCardPic.insert(handCardPic.size(),tmpImg);
                           tmpCardLabel->setPixmap(*tmpImg);
                           tmpCardLabel->setScaledContents(true);
                           //要保证handcard和handcardlabel数量一致
                           tmpCardLabel->setIdx(handCardLabel.size());
                           connect(tmpCardLabel,SIGNAL(clickedCard(int)),this,SLOT(selectCard(int)));
                           tmpCardLabel->setLabelName(tmpCard[1]);
                           tmpCardLabel->setVisible(true);

                           handCardLabel.insert(handCardLabel.size(),tmpCardLabel);

                           updateHandCardImage();
                           update();
                        }
                    }else       //卡组没卡了 对手胜利
                    {
                        pendStep(p->getOPPO());
                        return;
                    }
                }
        }
}

void battleWidget_1::pmainStep(player *p)
{
    //对npc来说，抽的卡是使用的卡，需要确定使用卡数量、使用何种卡牌;
    //确定使用卡数量--这段放在主阶段中
    if(p->isNPC())
    {
        if(handCardNPC.empty()){
            pendStep(p->getOPPO());
            return;
        }
        //确定使用卡数量
          int tmpCardUseCount=qrand()%3+1;

          //策略
          while(tmpCardUseCount>0)
          {
              if((p->getHP()+p->getDHP())<=p->getHPMax()*0.4)
              {
                  bool isUseFlag=false;
                  for(int i=0;i<handCardNPC.size();i++)
                  {
                      if(cardHub[i][3]=="恢复")
                      {
                          puseCardNPC(p,i);
                          isUseFlag=true;
                          tmpCardUseCount--;
                          break;
                      }
                  }
                  if(isUseFlag) continue;
              }

              int tmpIDX=qrand()%handCardNPC.size();

              if(handCardNPC[tmpIDX][3]=="防减益"||handCardNPC[tmpIDX][3]=="攻减益")
              {
                  //emit useCardNPC(p->getOPPO(),tmpIDX);

                  puseCardNPC(p->getOPPO(),tmpIDX);
                  tmpCardUseCount--;
              }
              else
              {
                 // emit useCardNPC(p,tmpIDX);
                  puseCardNPC(p,tmpIDX);
                  tmpCardUseCount--;
              }
          }
    }else
    {
        //玩家进入主要阶段
        initTimeCount();
        mainStepStar();
    }
}

void battleWidget_1::pbattleStep()
{
    //进入战斗回合，双方结算共一次

    bool flag=false;      //--结束标志

    flag=playerM->battle();
    hpChangedO();

    if(flag) {
          pendStep(playerM);
    }
    else
    {
        flag=playerO->battle();
         hpChangedM();
        if(flag) {
            pendStep(playerO);
         }
    }

    //一回合结束，需要对双方的临时属性进行清除
    playerM->nextTurn();
    playerO->nextTurn();

    inStep();                                                   //进入下一回合
}

void battleWidget_1::pendStep(player *winner)
{
    if(hasEnd)      //已结算过，其余流程所有进入此处就此返回结束
    {
       return;
    }

    //设置一个cardLabel或弹窗（完成这个页面后更迭成这个） 描述获胜方和获得的物品（暂无）、经验（写到白玉宫内）
    QString tmpStr="";
    endBox.setStandardButtons(QMessageBox::Ok);
    endBox.setDefaultButton(QMessageBox::Ok);
    endBox.setWindowTitle("战斗结果速递~");
    endBox.setWindowIcon(QIcon(":/images/icon/widgetIcon.ico"));

    if(winner->isNPC())
    {
       tmpStr="很遗憾,本次战斗获胜者是:"+winner->getName();

       endBox.setText(tmpStr);
    }else
    {
        tmpStr="恭喜你获得本次战斗的胜利！"+winner->getName()+"感到很高兴~";
        endBox.setText(tmpStr);
    }

    int ret=endBox.exec();

    switch (ret) {
            case QMessageBox::Ok:
                emit win(winner);
                emit returnGuidePage();
        break;
    default:
        emit returnGuidePage();
        break;
    }
    hasEnd=true;
}

void battleWidget_1::puseCard(player *p, int hcidx)
{

    //卡牌使用-然后从手卡中去掉
    p->beusedCard(handCard[hcidx]);
    handCard[hcidx].clear();
    handCard.removeOne(handCard[hcidx]);

    cardLabel* pp=handCardLabel[hcidx];                                    //对使用过的卡，应该在结算后“删去”
    handCardLabel.removeOne(handCardLabel[hcidx]);
    delete pp;
    pp=nullptr;

    QPixmap * ppp=handCardPic[hcidx];
    handCardPic.removeOne(handCardPic[hcidx]);
    delete ppp;
    ppp=nullptr;

    for(int i=0;i<handCardLabel.size();i++)
    {
        handCardLabel[i]->setIdx(i);
    }

    cardChoose=-1;                                                          //然后重置选择状态
    update();
}

void battleWidget_1::puseCardNPC(player *p, int cIdx)
{
    p->beusedCard(handCardNPC[cIdx]);
    handCardNPC.removeOne(handCardNPC[cIdx]);
}

void battleWidget_1::updateHandCardImage()
{
    for(int i=0;i<handCardLabel.size();i++)                     //这个函数用来确保卡牌画面和实际信息一致
    {
        handCardImageUrl[i]=handCard[i][11];
        handCardPic[i]->load(handCardImageUrl[i]);
        handCardLabel[i]->setPixmap(*handCardPic[i]);
        handCardLabel[i]->move(handCardRect[i].x(),handCardRect[i].y());
        handCardLabel[i]->setIdx(i);
    }
}

void battleWidget_1::setHeadImageUrl(QString s)
{
    headImageUrl=s;
}
