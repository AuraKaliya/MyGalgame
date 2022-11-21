#ifndef CALLCARDWIDGET_H
#define CALLCARDWIDGET_H

#include <QWidget>
#include<QStackedWidget>

#include <QGroupBox>
#include <QList>
#include <QPixmap>
#include<QMovie>
#include <QString>
#include<QTime>
#include<QtGlobal>
#include <QIcon>


#include "cardlabel.h"
#include "iconlabel.h"
#include "paintlabel.h"
#include "readexcel.h"
#include "cardwidget.h"
#include "mystyle.h"

#pragma execution_character_set("utf-8")


class callCardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit callCardWidget(QWidget *parent = nullptr);

    //这个自建类是抽卡页面，实现功能应该有更新卡池、
    //为降低类之间的耦合度，应该通过发送信号方式进行传递抽中卡的信息
    /*******************************需要进行的代码重构******************************************/
      void linkCardHome(cardWidget*);
     cardWidget * whiteStone;                    //链接白玉宫
     //还有槽函数中的对其添加卡的过程--放在mainWidget中进行
    /*******************************需要进行的代码重构******************************************/

    void initCardPool();                    //初始化卡池
    void updatePage();                      //更新能量
    cardLabel * getReturnLabel();




private:

   /**********************静态信息，后续优化要放进mainwindow中处理****************************/

    QString movieName=":/vedios/callcard_0.gif";
    QMovie *callCardShowMovie;

   /**********************静态信息，后续优化要放进mainwindow中处理****************************/






    myStyle st;                             //通用style

    int magicCount;                         //用于抽卡的能量
    const int magicNeed=100;                //抽卡耗费
    int callIdx;                            //一个抽卡计数器，达一定数时重置卡池
    int nowPoolIdx;                         //当前卡池ID，用于切换卡池倾向 道具/装备
    int newCardID;                         //抽取到的卡的ID

    QMessageBox tipBox;                     //提示BOX，用于在能量不足时提醒充值
    QString messageImageUrl = ":/images/icon/200_warning.png";

    QPixmap tmpPicOfCard;                   //对抽中的卡进行image展示
    QLabel *tmpImageShow;
    cardLabel *tmpShow;                      //提示抽中面板，点击消失

    QStackedWidget *backgroundWidget;       //一个stw作为背景 预想做限定卡池的切换
    QWidget *mainShowWidget;                //通用/主要卡池界面
    QLabel * movieLabel;                    //卡池看板娘-动态背景承载label

    /****************************|布局|*********************************************/
    //上方栏板需要一个横线label 一个返回label 一个group包括一图标一显示label
    QLabel *topLabel;               //上方横栏
    cardLabel *returnLabel;         //返回按钮

    //一个group表示通用卡池抽卡耗费
    QGroupBox *magicGroup;
    iconLabel *magicIconLabel;          //通用卡池能量图标          --用这个自建类直接传strurl进行图标设置
    cardLabel *magicShowLabel;          //通用卡池能量显示
    QString magicIconUrl=":/images/icon/icon_1.png";

    //下方需要一个背景板一个抽卡label   一个list包括了一个道具选项label一个装备选项label
    paintLabel *backgroundLabel;        //下方的抽卡背景板
    QString backgroundImageLabel=":/images/background/callCardLabel.png";
    cardLabel *propLabel;               //道具按钮label
    cardLabel *equipmentLabel;          //装备按钮label
    cardLabel *callCardLabel;           //召唤按钮label
    /****************************|布局|*********************************************/

    //卡池标准化：【0】ID【1】rarity【2】category【3】name
    QList<QList<QString>> propCardPool;
    QList<QList<QString>> equipmentCardPool;

private slots:
    void closeBob(cardLabel*);
    void callCard();
    void setProp();
    void setEquip();

signals:

};

#endif // CALLCARDWIDGET_H
