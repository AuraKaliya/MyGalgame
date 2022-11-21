#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>
#include <QStackedWidget>
#include <QPalette>
#include <QWidget>
#include <QList>
#include <QString>

#include <QDebug>


#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>









#include "readexcel.h"
#include  "cardwidget.h"
#include "cardshowwigdet.h"
#include "callcardwidget.h"
#include "gameguidepage.h"
#include "gamestoryscene.h"
#include "scenelabel.h"
#include "battlewidget_1.h"
#include "mystyle.h"
#pragma execution_character_set("utf-8")


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void linkStoryScene(cardLabel* cl);


private:
    Ui::MainWindow *ui;

    //最底层界面stac
    QStackedWidget * gameShowWidget;

    //该项目通用style，用于统一ui风格
    myStyle  st;


/************************主界面建立*****************************************/
    //主界面widget
    QWidget * mainShowWidget;

    //主界面-标题的承载label
    paintLabel * titleLabel;

    //作为承载背景图片的label
    QLabel * mainBackgroundLabel;

    //为主界面添加一个组五个按钮
    //虽然不知道当时设计这个是想怎么样，但是也许以后会有用呢
    QGroupBox *mainPageBtnGroup;

    QPushButton *mainNewStoryBtn;   //新篇章
    QPushButton *mainCallBtn;       //召唤
    QPushButton *mainSettingBtn;    //设置
    QPushButton *mainCardHomeBtn;   //白玉宫
    QPushButton *mainEndBtn;        //归隐

    //用一个QList将这五个按钮组织起来，便于统一设置Style、Size和Location
    QList<QPushButton *> buttonList;


    //添加子界面的承载页-StackedWidget
    QStackedWidget *pageWidget;

    //添加游戏子页面承载页-story
    QStackedWidget *storyWidget;

    //添加白玉宫界面
    cardWidget *whiteStone;


    //在没学数据库连接之前采用的是通过TXT（V1.0）、Excel（V2.0）来读取数据信息。
    //数据读取&初始化           /*****************这段在之后准备废弃，但不删除**********************/
    readExcel* readCardData;
    readExcel* readStoryData;
    readExcel* readStoryCharactorData;
    readExcel* readStoryTalkData;
    readExcel* readBuff;
    readExcel* readCardHub;
    readExcel* readStoryNPC;

    //card数据读取              /*****************这段在之后准备废弃，但不删除**********************/
    QString cardInformationName="cardInformation.xlsx";
    //story数据读取
    QString storyInformationName="gameStoryInformation.xlsx";
    //剧情角色信息读取
    QString storyCharactorInformationName="story_charactorInformation.xlsx";
    //战斗页面buff信息读取
    QString battleBuffInformationName="battleBuffInformation.xlsx";
    //战斗页面NPC卡组读取
    QString battleCardHubName="battleCardHub.xlsx";
    //剧情人物NPC数据读取
    QString storyNPCInformationName = "storyNPCInformation.xlsx";
    //剧情文本读取【0】文本【1】人物切换【2】主要对话人【3】次要对话人【4】主要对话人headURL【5】主要对话人立绘URL【6】次要对话人立绘URL【7】场景切换【8】场景切换URL
    QString story_1_name="story_1.xlsx";


     //用于初始化时读取的数据存储        /*****************这段在之后准备废弃，但不删除**********************/
     QList<QList <QString> >storyInformaitonList;
     QList<QList <QString> > cardInformationList;
     QList<QList<QString> > storyTalkStr;
     QList<QList<QString> > battleBuffStr;
     QList<QList<QString> > cardHubStr;
     QList<QList<QString> > storyCharactorStr;



    //添加抽卡页面
    callCardWidget * callStar;
    //添加game引导页面
    gameGuidePage *gameMainPage;
    //gamestory
    int StoryCount;     //用于记录storySCcene的idx和数量
    gameStoryScene* storyScene1;  //剧情对话页面

    //战斗界面
    battleWidget_1* battleWidgetForest;


private slots:
    //白玉宫按钮点击
    void On_mainCardHomeBtn();
    void On_mainCallBtn();
    void On_returnBtn();
    void To_storyScene(int);
    void To_newPages();
    void storyEnd();
    void storyBattle();

};
#endif // MAINWINDOW_H
