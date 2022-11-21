#ifndef GAMEGUIDEPAGE_H
#define GAMEGUIDEPAGE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QList>
#include <QString>
#include <QPalette>
#include <QGraphicsDropShadowEffect>
#include<QPushButton>
#include<QMovie>

#include"returnbutton.h"
#include "cardlabel.h"
#include "mystyle.h"
#include "paintlabel.h"
#include "gameguidepage_story.h"
#include "gameguidepage_adventure.h"
#include "gamestoryscene.h"

#pragma execution_character_set("utf-8")



class gameGuidePage : public QWidget
{
    Q_OBJECT
public:
    //这是故事引导页面，囊括了冒险模式、番外模式、剧情模式，并且在页面中提供对卡组的配置和对白玉宫的跳转
    explicit gameGuidePage(QWidget *parent = nullptr);

    /*********不知道有什么用的代码***********/
    gameGuidePage* getThis();                                                //返回自己 但是不知道有什么用=-= 等找到了再加注释
    /*********不知道有什么用的代码***********/

    void initArea();                                                        //初始化视窗   -----并没有实现（好像没用）
    void readStroyInformation(QList<QList<QString>> info);                  //读取的是地图信息
    gameGuidePage_Story* getStoryPage();                                    //剧情界面页
    gameGuidePage_Adventure *getAdvenPage();                                //冒险界面页
    void initThisWidget();                                                  //初始化剧情页等的展示
    returnButton*getReturnButton();                                         //返回按钮
    QPushButton * getBattleTestButton();                                    //测试用战斗页面跳转按钮
private:
    //页面设计：一个返回page 一个视窗Area 一个切换视窗的StackedWidget 一个链接切换的label组带3个子盒子，一个显示卡组和白玉宫的label组
    //三个子盒子是剧情、番外、冒险
    //用excel读取gameInformation的excele内容，根据分类将其插入到各子盒子中。
    //area横向扩展
    QPushButton *batTestBtn;                                                //测试用战斗按钮
    myStyle st;                                                             //通用style

    //背景图片
    QString bkgName=":/images/background/storyGuid_test.png";
    QPixmap *bkpix;
    /******************可修改******************************/
    returnButton * returnLabel;                                             //返回按钮（因为是从label改回button的 名字对不上）
    /******************可修改******************************/

    //动态小人斯蒂卡
    QRect stkRect;
    QMovie *stk;
    QMovie *stk2;
    QString stkn=":/vedios/stk.gif";
    QString stk2n=":/vedios/stk_t.gif";
    QLabel *stkLabel;
    QLabel *stk2Label;

    //动态小人鲨鲨
    QRect ssRect;
    QMovie*ss;
    QString ssn=":/vedios/shasha.gif";
    QLabel *ssLabel[4];


    QStackedWidget *gamesShowWidget;                                         //展示页面 用stacked方便切换 -----但是是在主引导界面内的，而主页面与相关剧情页面同级
    /********************不知道有什么用******************************/
    QList <QString> modeName;                                                //暂时不知道是什么
    /********************不知道有什么用******************************/


    //这里有个新想法，分三种不同方式进行插入，制作三个类
    //剧情用传统Area加滑轮制作，番外用，冒险用地图挪动的方式制作，三个继承自QWidget插入到STackedWidget中。        //已实现
    //底部横条Label 之后用Paint进行划分
    paintLabel*guideLabel;
    cardLabel *storyLabel;
    cardLabel *extraLabel;
    cardLabel *advenLabel;
    cardLabel *cardDeckLabel;
    cardLabel *WhiteStoneLabel;
    QList<cardLabel*> guideLabelList;
//需要一个List来存储剧情页面信息
//【0】ID【1】Name【2】categroy【3】imageUrl【4】mapGrade
    QList<QList<QString> > gameStoryInformation;                           //这是剧情模式地图信息


    gameGuidePage_Story* pageStory;                                        //剧情模式引导页面
    gameGuidePage_Adventure *pageAdventure;                                //冒险模式引导页面




    void paintEvent(QPaintEvent *event) ;
signals:
private slots:

    void ToAdventure();                                                     //跳转槽
    void ToStory();

};

#endif // GAMEGUIDEPAGE_H
