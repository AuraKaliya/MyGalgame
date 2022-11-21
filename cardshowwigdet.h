#ifndef CARDSHOWWIGDET_H
#define CARDSHOWWIGDET_H

#include<QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QMovie>
#include<QImage>
#include <QRect>
#include <QPixmap>
#include <QDebug>
#include <QPushButton>

#pragma execution_character_set("utf-8")





class cardShowWigdet : public QWidget
{
    Q_OBJECT
public:
    explicit cardShowWigdet(QWidget *parent = nullptr);

    //这是卡牌详细信息的界面，功能应该有存储&提供玩家的卡牌的信息
    //因为整体类共用一套卡牌信息，所以可以用Static载入存储所有卡牌信息，实例化时可以不用它赋值，但在其他调用时可以通过这个类的静态函数返回相关值。
    //不确定，到时候再看看QT源码和复习一下枚举、静态函数等知识

    /*************************此处代码需要重构*****************************/
    //每个卡牌初始化只用传一个int就行了 通过find函数在静态量中找idx再传给init函数   --不用每次初始化都传一大堆参数

    //载入数据函数
    void initCard(int cardId,  QList<QList<QString>> &database);
    int foundData(int cardId,QList<QList<QString>> &database);


    /*************************此处代码需要重构*****************************/
    int getCardId();
    QString getCardName();
    QString getCardCate();
    QString getCardCate2();
    QString getCardRarity();
    int getCardATK();
    int getCardDEF();
    int getCardDHP();
    int getCardBuffId();
    int getCardGrade();
    QString getCardPic();
    QString getCardImageUrl();
    QPushButton *getBtn();                  //返回按钮


private:
    //设立ID、名字、所属、稀有度、ATK、DEF、描述、2D立绘、动态立绘属性。
    //根据战斗页面新添： 【3】副类 【8】BUFFid（暂定最多一个buff）    --当星级提升到一定程度，人物卡会获得常驻buff  --判断条件在人物卡升星时候触发
    //buff信息页面应该是最大等级的影响，具体能力还需要根据卡牌等级综合计算
    int ID;
    QString name;
    QString category;
    //根据战斗页面新添
    QString category2;
    QString rarity;

    int ATK;
    int DEF;
    int DHP;
    int BUFFID;
    QString describe;
    QString imageUrl;
    QString bImageUrl;
    QString movieUrl;
    bool isMovie=false;

    //等级和经验
    int grade=0;
    int exp=0;
    int gradeMax[5]={10,20,30,40,50};
    int starToEXP[5]={100,200,500,1000,2000};
    //星级
    int star=0;
    int starMax=5;
    int sameNameCard=0;
    //设立label
    QLabel *idLabel;
    QLabel *nameLabel;
    QLabel *imageLabel;
    QLabel *cateLabel;
    QLabel *ratLabel;
    QLabel *ATKLabel;
    QLabel *DEFLabel;
    QLabel *describeLabel;
    QImage *cardImage;
    QPixmap *cardPic;
    QMovie *cardMovie;
    QLabel *gradeLabel;
    QLabel *expLabel;
    QLabel *starShowLabel;
    QLabel *sameNameCardLabel;
    QLabel *backgroundImage1;
    QLabel *backgroundImage2;

    QPixmap *backgroundPix;

    /**************废案 不太好用*********************/
    //设立布局 俩个v一个G俩个H
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *oneLayout;
    QGridLayout *mainLayout;
    QHBoxLayout *btnHLayout;
    /**************废案 不太好用*********************/


    //设置返回按钮
    QPushButton *returnBtn;
signals:
};

#endif // CARDSHOWWIGDET_H
