#include "player.h"


player::player(QObject *parent) : QObject(parent)
{
  HPMax=10000;
  HP=10000;

  tmpATK=0;
  tmpDEF=0;
  dHP=0;

    grade=0;
    star=0;
    ATK=0;
    DEF=0;

    equipHP=0;
    equipATK=0;
    equipDEF=0;
    equipBuff="";


    NPC=false;




}

void player::loadPlayerInformation(QList<QString>p)
{
    //传入名字

    name=p[1];

    grade=p[2].toInt();

    star=p[3].toInt();

    ATK=p[4].toInt();

    DEF=p[5].toInt();


}

bool player::isNPC()
{
    return NPC;

}

int player::getGrade()
{
    return grade;

}

int player::getHP()
{
    return HP;

}

int player::getHPMax()
{
    return HPMax;
}

int player::getDHP()
{
    return dHP;
}

int player::getOATK()
{
    return ATK+tmpATK+equipATK;
}

int player::getODEF()
{
    return tmpDEF+equipDEF+DEF;
}

void player::changeHP(int DHP)
{
    HP=DHP;
}

void player::nextTurn()
{
    tmpATK=0;
    tmpDEF=0;
    dHP=0;


    for(int i=0;i<tmpBuff.size();i++)
    {
        int idx=tmpBuff[i][1].toInt()-1;
        tmpBuff[i][1]=QString::number(idx);
    }
    for(int i=0;i<tmpBuff.size();i++)
    {
        if(tmpBuff[i][1].toInt()<=0)
        {
            tmpBuff.removeOne(tmpBuff[i]);
            i-=1;
        }
    }


}

void player::settleOutBuff(int a, int d, int hp)
{
    tmpATK+=a;
    tmpDEF+=d;
    dHP+=hp;
}

void player::setOPPO(player *p)
{
    opponent=p;
}

void player::setNPC(bool i)
{
    NPC=i;
}

QString player::getName()
{
    return name;
}

player *player::getOPPO()
{
    return opponent;
}

bool player::isSurvival()
{
    if(HP<=0) return false;
    else return true;

}

QString player::getEquipBuff()
{
    return equipBuff;

}

QList<QList<QString> > player::getBuffNow()
{
    return tmpBuff;
}

bool player::battle()
{
    //进入战斗结算
    int thisATK=tmpATK+equipATK+ATK;
    qDebug()<<"!ATK!"<<thisATK;
  //  int thisDEF=tmpDEF+equipDEF+DEF;

// int OATK=this->getOPPO()->getOATK();
    int ODEF=this->getOPPO()->getODEF();
    qDebug()<<"OPPO !DEF!"<<ODEF;
        HP+=dHP;
        if(HP>=HPMax) HP=HPMax;
     qDebug()<<"!HP!"<<HP;

    bool isEndFlag=false;

    if(thisATK>ODEF)
    {

        this->getOPPO()->changeHP(this->getOPPO()->getHP()-(thisATK-ODEF));

        if(this->getOPPO()->getHP()<=0)
        {
            isEndFlag=true;
            return isEndFlag;

        }

    }


//    if(thisDEF<OATK)
//    {
//        changeHP(HP-(OATK-thisDEF));

//        if(HP<=0)
//        {
//            isEndFlag=true;
//            return isEndFlag;

//        }

//    }




 return isEndFlag;


}

void player::beusedCard(QList<QString> card)
{

    //先判断卡牌种类-通过副类进行判断（攻增减益、恢复、装备）
    if(card[3]=="装备")
    {
        equipATK=card[5].toInt();
        equipDEF=card[6].toInt();
        equipHP=card[7].toInt();

        equipBuff=card[8];



    }
    else  // if(card[3]=="攻减益"||card[3]=="防减益")
    {
       tmpATK+=card[5].toInt();
       tmpDEF+=card[6].toInt();
       dHP+=card[7].toInt();

       QList <QString> tmpStr;
       tmpStr<<card[8]<<card[9];
       tmpBuff<<tmpStr;
    }


}

void player::initState()
{
    HPMax=10000;
    HP=10000;
    tmpATK=0;
    tmpDEF=0;
    dHP=0;
    grade=0;
    star=0;
    ATK=0;
    DEF=0;
    equipHP=0;
    equipATK=0;
    equipDEF=0;
    equipBuff="";
    tmpBuff.clear();

}
