#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QLabel>
#include <QStackedWidget>
#include <QGridLayout>
#include <QList>
#include <QPushButton>
#include <QPalette>
#include <QString>
#include <QList>
#include<QScrollArea>
#include<QGridLayout>
#include<QGroupBox>

#include "mystyle.h"
#include "cardlabel.h"
#include "cardshowwigdet.h"

#include <QDebug>
#pragma execution_character_set("utf-8")

class cardDeckInformaiton;

class cardWidget :public QWidget
{
    Q_OBJECT
public:
    cardWidget(QWidget * parent=0);

    //这是白玉宫的界面，应该实现的功能有卡牌自动添加和排列、卡组添加和设计、卡牌展示
    //后续可以添加卡牌仓库的查找功能、好友功能、个人信息功能

    /***************************更新添加卡组功能***************************************/
    //因为有卡组的设计，需要设置Static存储静态的卡牌信息方便读取    --但是好像就这一个页面，可以直接传并不用static
    void readCardInformation(QList<QList<QString>> information);            //读取牌库信息 进行本地化
    void addCard(int inCardId);                                             //添加卡牌--需要进行判断种类
    void explorPage(QWidget*wid,int dh);                                    //添加卡牌时需要扩大Area的widget
    QList<QList<QString>> showInformation();                                //返回/传递 卡牌信息
    QPushButton * getReturnBtn();
    int getDefaultCardDeck();                                               //后续想通过此来进入战斗初始化卡组和手牌
    /******************************************************************************************/
    //选取卡牌进入卡组，流程为：展示所有卡牌-选取卡牌-点击确定-判断可否加入-加入更新。  需要通过信号来进行断点等待
    void selectCardPushInCardDeck();
    cardDeckInformaiton* getCardDeck();
    cardDeckInformaiton* getCardDeck(int );
    /***************************更新添加卡组功能***************************************/

private:
    myStyle st;                                                     //添加风格

    QList<QList<QString>> cardInformation;                         //用于记录读取的所有卡牌信息

    QRect *re;                                                      // 什么区域的rect
    QPixmap bkpic;                                                  //背景图片

    int myCardId;
    QList<cardShowWigdet *> myCard;


    QList<QString> cardCate;                                        //对应button进行判断


    int defaultCardDeck=0;                                          //用于记录默认卡组
    QList<cardDeckInformaiton*> cardDeckList;                       //卡组的 组




    //添加角色-道具-装备-卡组-返回按钮
    QPushButton *charactorCardBtn;
    QPushButton *propCardBtn;
    QPushButton *equipmentCardBtn;
    QPushButton *cardDeckBtn;
    QPushButton *returnBtn;
    QList<QPushButton*> buttonList;                                 //切换卡牌种类显示按钮的组


    QStackedWidget * mainShowWidget;                                //添加一个等窗体大小的stacedWidget 后续插入卡牌的详细界面

    QWidget *FirstShowWiget;                                        //添加首页面显示Widget用于承载按钮和卡牌显示界面

    //添加内显示卡牌StackedWidget 窗体
    QStackedWidget *cardShowWidget;
    //添加角色-道具-装备-卡组界面
    QScrollArea *charactorArea;
    QScrollArea *propArea;
    QScrollArea *equipmentArea;
    QScrollArea *cardDeckArea;
    QList< QScrollArea*> Area;

    int countCard[4];   //用于记录每个界面的卡牌数量

    void paintEvent(QPaintEvent *event);
public slots:
    void To_charactorShow(cardShowWigdet * p);
    void To_charactorMainPage();
    void To_cardShowPageC();
    void To_cardShowPageP();
    void To_cardShowPageE();
    void To_cardShowPageD();
};








class cardDeckInformaiton
{
    //卡组类，用于实现卡组功能，暂时还没有什么想法
public:
    QList<int> cardIdInWhiteStone;
    QList<cardShowWigdet *> cardInformationInWhiteStone;
    int charactorIDInCardDeck;
    const  int charactorMax=1;
    const int cardCount=40;
    void pushInCardDeck()
    {
    }
    void popOutCardDeck(int idx)
    {
    }








};




#endif // CARDWIDGET_H
