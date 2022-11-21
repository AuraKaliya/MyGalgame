#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include<QList>
#include <QString>
#include <QDebug>


#pragma execution_character_set("utf-8")


class player : public QObject
{
    Q_OBJECT
public:

    explicit player(QObject *parent = nullptr);
    //对于初始能力值进行判定
    void loadPlayerInformation(QList<QString>);
    void setOPPO(player*);
    void setNPC(bool);
    void changeHP(int DHP);
    void nextTurn();
    void settleOutBuff(int a,int d,int hp);
    //获取属性的接口
    bool isNPC();
    int getGrade();
    int getHP();
    int getHPMax();
    int getDHP();
    int getOATK();
    int getODEF();
    QString getName();
    player* getOPPO();
    bool isSurvival();
    QString getEquipBuff();
    QList<QList<QString>> getBuffNow();
    bool battle();
    void beusedCard(QList<QString> card);
    void initState();
private:
    bool NPC;
    //策略现在看起来没用，卡牌使用策略写在主要阶段。
    QList<QString> strategy;
    QString name;
    int HPMax;
    int HP;
    int grade;
    int star;
    int ATK;
    int DEF;
    //【0】HPMAX-【1】HP【2】ATK【3】DEF
    QList<int>baseAbility;
    //一个回合的临时提升/下降
    int tmpATK;
    int tmpDEF;
    int dHP;
    //【0】TMPATK【1】TMPDEF【2】DHP
    QList<int >tmpAbility;
    //装备带来的提升
    int equipATK;
    int equipDEF;
    int equipHP;
    //【0】equipATK【1】equipDEF【2】equipHP
    QList<int >equipAbility;
    //为了方便 单独把装备buff给提出来进行判定
    QString equipBuff;
    //记录buffid和持续时间；
    QList<QList<QString>>tmpBuff;
    //这个属性暂时看起来没什么用
    QList <QString>state;
    player* opponent;
signals:
};

#endif // PLAYER_H
