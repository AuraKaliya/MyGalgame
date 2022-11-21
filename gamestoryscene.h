#ifndef GAMESTORYSCENE_H
#define GAMESTORYSCENE_H

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QList>
#include <QLabel>
#include <QPainter>

#include "cardlabel.h"
#include "talkshowauto.h"
#include "paintlabel.h"
#include "mystyle.h"

#pragma execution_character_set("utf-8")
class gameStoryScene : public QWidget
{
    Q_OBJECT
public:
    //这是剧情对话页面，应该有对话展示和完成相应流程
    /****************************一些想法************************************/
    //纯剧情，不对玩家数据产生任何影响
    //剧情之后的战斗对玩家角色卡产生经验值影响、提供一定量的召唤能量和角色好感度
    //角色好感度获取方式有番外、战斗和互动--番外剧情 --不能跳过但每次都能增加
    /****************************一些想法************************************/
    explicit gameStoryScene(QWidget *parent = nullptr);

    myStyle st;                                                                         //通用style

    gameStoryScene * returnThis();                                                      //返回本体

    /**********************废代码*******************************/
    cardLabel* returnMineImageLabel();                                                  //本来打算做左上角头像和状态的 但是不太合适
    QLabel *returnMyStateLabel();
    /**********************废代码*******************************/

    QLabel *returnHeadLabel();                                                          //返回头像label       --用于加载？
    cardLabel *returnTalkLabel();                                                       //返回对话label

    talkShowAuto* getAutoSwitch();                                                      //自动显示文本开关     --这又是什么玩意 为甚要返回它 自动显示文本不是应该在这个类中吗
    void loadTalkInformation( QList <QList <QString> > str);                            //加载对话文本
    void TalkShowReset();                                                               //对话重置 用于该段剧情结束时
    QPushButton * getReturnBtn();                                                       //返回按钮

private:

    void paintEvent(QPaintEvent *event);

    //返回和跳过按钮 设置在左上角
    QPushButton * returnBtn;
    QPushButton * jumpBtn;

    //先做个界面出来就行了
    //有一个背景的界面--暂时以Label加载，后续替换成paintEvent 同时用QList进行场景的自动替换
    //不替换了 太麻烦了 就这样
    //背景还是用paint画吧

    QRect backgroundRect;
    QLabel *tmpScene;
    QPixmap backgroundPix;

    //上方是一个头像框和状态显示界面       --已废弃
    cardLabel *mineImageLabel;
    paintLabel *mineImageBond;
    QLabel *stateLabel;
    QRect headBondRect;

    //下方是头像和剧情加载界面
    QLabel *buttonLabel;
    QLabel *headImageLabel;
    QPixmap headImagePix;
    QPixmap actor1;
    QRect  actor1Rect;
    QPixmap actor2;
    QRect actor2Rect;
    cardLabel *talkLabel;
    QList <QList <QString> > talkStr;

    talkShowAuto *AutoSwitch;
    int nowIdx;  //用于记录当前对话的进度
private slots:
    void TalkShowBegin();
    void timChanged();
    void returnBtnClicked();
    void jumpBtnClicked();
signals:
    void finished();
    void returnPageMain();

};

#endif // GAMESTORYSCENE_H
