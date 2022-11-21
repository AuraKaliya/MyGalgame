#ifndef BATTLEWIDGET_1_H
#define BATTLEWIDGET_1_H

#include  <QWidget>
#include  <QRect>
#include  <QList>
#include  <QLabel>
#include  <QString>
#include <QPainter>
#include <QPen>
#include <QSlider>

#include  "cardlabel.h"
#include  "paintlabel.h"
#include "player.h"
#include "cardwidget.h"

#include  <QDebug>
#pragma execution_character_set("utf-8")


class battleWidget_1 : public QWidget
{
    Q_OBJECT
public:
    //战斗用界面，应该实现的功能是导入卡牌信息、对对战角色进行初始化、导入buff信息、完整的战斗流程及战斗结果的信号发送
    /*******************************战斗流程设计*************************************/
    // 战斗开始前，导入双方角色卡信息  --NPC：随机初始化                                Player：调取默认卡组中角色卡进行初始化
    // 战斗开始前，导入双方卡组       --NPC：随机初始化                                Player：调取默认卡组
    // 战斗开始，玩家抽三张牌作为初始手牌
    // 进入抽卡阶段    ---结算buff                 --判断是否结算和能否抽卡（卡组是否为空、buff是否为jumpBUFF（眩晕、睡眠等状态））
    //               ---可以抽卡   --NPC：跳过                                     Player：从卡组中抽取一张
    //               ---玩家手卡超过五张则该张卡牌爆掉
    // 进入主要阶段                 --NPC：随机使用1-3张卡牌，使用原则依据行为树或决策树  Player：任意使用|使用上限为三张（能量点暂未实装）
    // 使用卡牌时，依照卡牌信息给使用对象添加临时属性和buff
    // 主要阶段为30s 玩家也可以通过点击特定区域（暂定头像）进行手动结束回合
    // 进入战斗阶段                 --双方各自调用类中函数，计算对手的DEF和自己的ATK以及DHP作为血量增减的数据
    // 当战斗阶段结束，双方血条均未见底时，回到抽卡阶段，即进入下一回合
    /*******************************战斗流程设计*************************************/


    explicit battleWidget_1(QWidget *parent = nullptr);

    /***************************想法*********************************************/

    //这个界面专为NPC对战玩家设计，相关细节调整一下便可，需要单独做出玩家类来，在测试对战成功后考虑将这俩合并成一个类的继承树，采用虚函数等优化结构
    //因为每次对战都需要初始化卡牌，并且后续可能不止一个对战界面，所以应该将卡牌信息和buff信息作为static导入
    //目前导入的数据有重复，所以在设计连接数据库时进行去重设计  这里也需要改变一下结构
    //建新属性全部替换后删除老属性和函数（注释、测试、删除）

    /***************************想法*********************************************/

   //传入一个二维序列，随机选取其中一个导入。
   void loadNPCInformation(QList<QList <QString> > NPCStr);
   //暂且不用，后续考虑加入
   void loadNPCStrategy(QList<QList <QString> > strategyStr);
   //或许导入一维list更好
   void loadPlayerInformation(QList<QList <QString> > PlayerStr);
   void loadPlayerInformation(QList<QString> PlayerStr);
   //buff总信息-buffInformationList
   void loadBuffInformation(QList<QList <QString> > BuffStr);
   //导入牌库信息
   void loadCardHub(QList<QList <QString> > cardStr);
    //npc的类型：激进（多攻击类增益和装备偏好 多防御减益类） 保守（多防御类增益和装备偏好 多攻击减益类） 普通（纯随机）
    //抽卡难度影响SR和SSR的概率
     void initCardDeck();
   //这俩应该是初始化阶段的 初始化双方卡组  --待转移代码--已完成
    void initCardNPC(int type, int  difficulty);
    void initCardPlayer();
    void initCardPlayerTest();
    void inStep();
    void drawCardNPC();
    void drawCardPlayer();
    void initCardInformation();
    void linkWhiteStone(cardWidget *);
    int findCardInHub(int cardId);
    int findCardData(int cardId,QList<QList<QString> > &database);
    //判断异常状态
    int getStateNow(player *p);
    //判断血量状况
    int getStateToUseCardNow(player * p);
    //对buff进行结算，存在于抽卡阶段开始时 返回是否继续的标志;
    bool settleOutBuff(player*p);
    bool isJumpBuff(QString buffName);
    void initTimeCount();
    void mainStepStar();
    int getClickedCardIdx(QPoint );
    void returnPage();
    void updateMsgBox(QList<QString> hc,player *);


    //初始化战斗双方角色-是整个流程的开始
    void initBattle();
    void initBattleTest();
    void pdrawChardStep(player*);
    void pmainStep(player*);
    void pbattleStep();
    void pendStep(player* winner);
    void puseCard(player*,int hcidx);
    void puseCardNPC(player *p,int cIdx);
    void updateHandCardImage();
    //测试-用定信息加载玩家
    void testInformationLoading();
    void setHeadImageUrl(QString );
    void  hpChangedM();
    void  hpChangedO();
    void resetBattleRole();
private:

        bool hasEnd=false;
        cardWidget * whiteStone; //用于连接白玉宫          --为后续卡组读取做准备

        /*暂时废弃、如果有做外挂需要可以用这个来可视化控制*/
        QSlider *HPSliderM;
        QSlider *HPSliderO;
        /*暂时废弃、如果有做外挂需要可以用这个来可视化控制*/

        QPixmap bkImage;                                                                 //背景图片
        QRect bkRect;
        QString backgroundUrl=":/images/background/story_dream_shop1.png";



        QString headImageUrl=":/card/images/card/charactor/h_李韶奏.png";                 //战斗时主角头像

        //一个玩家类，两个对象                --该类中包含了对是否是NPC的判断
        player *playerM;
        player *playerO;

        //NPC策略
        const int NPCTypeCount=3;
        QString NPCtype[3]={"激进","保守","普通"};
        const int jumpBuffCount=2;
        QString jumpBuff[4]={"睡眠","眩晕","",""};


        //手卡信息框
        QString handCardImageUrl[5]={"","","","",""};
        QPixmap handCardImage[5];                                                         //这为什么会有俩
        QList<QPixmap*> handCardPic;                                                      //对啊为什么



        //需要初始化它
        QRect  handCardRect[5];                                                           //手卡区域，后续可以添加选中时候的提示（框框） 以及卡框

        int cardChoose=-1;                                                                //选择的手卡序号  -1代表未选择
        bool cardUseIsMe=true;                                                            //这又是什么

        QMessageBox cardChooseBox;                                                        //对角色使用卡牌时会跳出该提示框
        QMessageBox endBox;                                                               //战斗结束会弹出胜利方


        /***********************************后续需要重新设计************************************************/
         //对NPC来说，抽卡是从卡库里把固定“费用”的卡牌按照设定的卡牌数随机挑选进牌库
         //目前开发不用考虑卡牌的费用，只需要实现随机挑选入库即可，这个跟卡池挑卡同理。
         //需要一个手牌池子，连接总卡池，设定道具卡和装备卡比例，按比例入库后需要区分为攻防增益减益道具、特殊道具、恢复道具、装备。
        //道具区分可以在源excel中添加
         //对于总牌库信息设计    【0】ID【1】Name【2】种类【3】副类【4】稀有度【5】ATK【6】DEF【7】DHP【8】BUFF（暂定最多一个buff）【9】持续回合【10】等级(这个根据NPC等级变化)【11】imageUrl
        QList<QList<QString>> cardHub;

        QList<QList<QString>> handCardNPC;

        //对于玩家而言，这个界面的卡组信息来源于白玉宫中的卡组，主键为ID;
        //需要有选择卡组的阶段，和根据卡组导入到cardDeck信息的阶段
        //试改成以传入卡组类来进行
        QList<QList<QString>> cardDeck;  //信息来自卡组
        //玩家的手卡，同时配置能够显示的label
        QList<QList<QString>> handCard;
        QList<cardLabel*> handCardLabel;
        //抽卡就append 使用就pop 然后delete  都需要函数来进行封装
        /***********************************后续需要重新设计************************************************/

    //需要一个QWidget类来存放
    //顶部血条用QRect和QPainter绘制
    //VS用paintlabel绘制
    //逃跑按钮由cardlabel填充
    //立绘用paint和rect绘制
    //下方一个背景板label 头像label由qlabel填充 加一个头像框rect 一个卡牌区域，一个战斗信息区域

    //HP
    QRect HPRect_M;
    QRect HPMAXRect_M;
    QRect HPRect_O;
    QRect HPMAXRect_O;
    QList <QRect> HPList;

    //战斗能量点：每回合最多使用三张卡牌，每回合恢复为3点     --未实装
    int energy=3;
    const  int energyMax=3;

    //VS 逃跑部件                                      --成倒计时区域了
    QLabel *vsLabel;
    cardLabel *runLabel;

    //立绘区域
    QRect charactorRect_M;
    paintLabel *charactorLabel_M;
    QRect charactorRect_O;
    paintLabel *charactorLabel_O;
    QList <QRect> charactorRectList;

    //底部界面
    paintLabel *lowLabel;
    QLabel *headLabel;
    QRect headRect;
    QRect cardRect;
    QRect stateRect;
    QLabel *ATKLabel_M;
    QLabel *DEFLabel_M;
    QList <QLabel*> ADShowList;

    /***************************更新内容*************************************/
    //在使用卡牌、buff结算后需要更新buff区域的图标，对图标的hover会显示消息框提示buff信息
    QRect buffRect_M;
    //buff显示暂且不做
    QList <QLabel*> buffList;
    /***************************更新内容*************************************/

    //用于存储战斗信息的属性
    //一个list用来存立绘url（或战斗用动图url）、战斗动画url
    //一个list存入战斗双方人物的初始属性 二维 【0】ID【1】Name【3】等级【4】星阶【5】ATK【6】DEF
    //以上两个合并 因为有共同属性：俩人，静态
    //最终决定   【0】ID【1】Name【2】等级【3】星阶【4】ATK【5】DEF【6】立绘url（后续改为战斗姿态1url-站立）【7】战斗姿态2url-攻击      --要改~~~~~~~

    //做成list可以给后续扩展车轮战做铺垫
    QList <QList<QString> > staticInformation;
    //一个list用来存储星阶和自带buff的信息表 【0】id 【1】3阶buff 【2】5阶buff
    QList <QList<QString> >starBuffInformationList;
    //一个list用于存储所有buff信息表，用于查找
    //BUFF信息标准：【0】ID【1】Name【2】持续时间【3】buff种类（增益/减益）【4】ATK【5】DEF【6】DHP【7】iconUrl
     QList <QList<QString> >buffInformationList;
    //一个list用于存入战斗双方每回合的属性变化（装备卡带来）和buff  【0】ATK【1】DEF
    //一个list用于记录我方buff；
       QList <QString>buff_M;                                                                               //--暂时没用上
    //一个list用于记录对方buff；
     QList <QString>buff_O;                                                                                 //--暂时没用上
     //设置一个timer，进入主要阶段时timer启动，每次启动时有个倒计时，倒数暂定30s。
     //timer启动时对于鼠标在屏幕上的点击激活对应区域卡牌的选取、取消选取两个行为，设置两个按钮进行结束和使用卡牌。


     QTimer mainStepTimer;                                                                                  //主要阶段的计时器
    int mainStepTime=31;

    void mouseReleaseEvent(QMouseEvent *event) ;
    void paintEvent(QPaintEvent *event) ;
signals:

    /**************************阶段跳跃目前用函数来做，玩家对战可以考虑用这个给服务端传输信号*****************************/

     //进入抽卡阶段，NPC和玩家有不同表现
    void drawCardStep( player *);
    //进入主要阶段，NPC和玩家具有不同表现
    void mainStep(player*);
    //进入战斗阶段，对buff和装备进行结算，同时对血量进行扣除
    void battleStep();
    //进入战斗完成阶段
    void endStep(player*);
    void useCardNPC(player *,int);
    void useCard(player *,int);
    void win(player*);
    void returnGuidePage();



private slots:

    void timChanged();
    void selectCard(int);
    void usingCard(int);

};

#endif // BATTLEWIDGET_1_H
