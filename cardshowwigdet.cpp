#include "cardshowwigdet.h"

cardShowWigdet::cardShowWigdet(QWidget *parent) : QWidget(parent)
{

    resize(1600,900);


        //创建页面

        //设置背景
        backgroundImage1=new QLabel(this);
        backgroundImage1->setGeometry(0,0,this->width(),this->height());
        backgroundImage2=new QLabel(this);
        backgroundImage2->setGeometry(0,0,this->width(),this->height());

        backgroundPix=new QPixmap();

        //主体
        idLabel=new QLabel(this);
        nameLabel=new QLabel(this);
        cateLabel=new QLabel(this);
        ratLabel=new QLabel(this);
        ATKLabel=new QLabel(this);
        DEFLabel=new QLabel(this);
        describeLabel=new QLabel(this);
        cardImage =new QImage();
        cardPic=new QPixmap();
        imageLabel=new QLabel(this);
        returnBtn=new QPushButton(" 返回 ",this);

        gradeLabel=new QLabel(this);
        expLabel=new QLabel(this);
        starShowLabel=new QLabel(this);
        sameNameCardLabel=new QLabel(this);





//        returnBtn->setMinimumSize(200,200);
//        idLabel->setMinimumSize(50,50);
//        idLabel->setStyleSheet("border-radius:3px;color:rgb(255,255,255); background-color:rgba(0,102,116,240);");
//        nameLabel->setMinimumSize(50,50);
//        cateLabel->setMinimumSize(50,50);
//        ratLabel->setMinimumSize(50,50);
//        ATKLabel->setMinimumSize(50,50);
//        describeLabel->setMinimumSize(50,50);
//        DEFLabel->setMinimumSize(50,50);

//        //左边
//        leftLayout=new QVBoxLayout();
//        leftLayout->setSpacing(30);
//        leftLayout->addWidget(idLabel);
//        leftLayout->addWidget(imageLabel);
//         //右边
//        oneLayout=new QHBoxLayout();
//        oneLayout->setSpacing(30);
//        oneLayout->addWidget(cateLabel);
//        oneLayout->addWidget(ratLabel);

//        rightLayout=new QVBoxLayout();
//        rightLayout->setSpacing(30);
//        rightLayout->addWidget(nameLabel);
//        rightLayout->addLayout(oneLayout);
//        rightLayout->addWidget(ATKLabel);
//        rightLayout->addWidget(DEFLabel);




//        //总体
//        btnHLayout=new QHBoxLayout();
//        btnHLayout->addStretch();
//        btnHLayout->addWidget(returnBtn);



//        mainLayout=new QGridLayout(this);
//        mainLayout->setSpacing(40);
//        mainLayout->setMargin(40);
//        mainLayout->addLayout(leftLayout,0,0,1,1);
//        mainLayout->addLayout(rightLayout,0,1,1,1);
//        mainLayout->addWidget(describeLabel,1,0,1,2);
//        mainLayout->addLayout(btnHLayout,1,1,1,1);
//        mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
//        mainLayout->setRowStretch(0,3);
//        mainLayout->setRowStretch(1,2);



        idLabel->setGeometry(500,150,250,80);
        imageLabel->setMaximumSize(254,450);
        imageLabel->move(idLabel->x()+(idLabel->width()-imageLabel->maximumWidth())/2,idLabel->height()+idLabel->y()+30);
        nameLabel->setGeometry(idLabel->x()+idLabel->width()+50,idLabel->y(),480,80);
        int w1=100,h1=50;
        cateLabel->setGeometry(nameLabel->x(),nameLabel->y()+nameLabel->height()+30,w1,h1);
        ratLabel->setGeometry(cateLabel->x()+cateLabel->width()+20,cateLabel->y(),cateLabel->width(),cateLabel->height());
        gradeLabel->setGeometry(ratLabel->x()+ratLabel->width()+20,cateLabel->y(),cateLabel->width()-50,cateLabel->height());
        expLabel->setGeometry(gradeLabel->x()+gradeLabel->width()+20,cateLabel->y(),cateLabel->width()+50,cateLabel->height());
        ATKLabel->setGeometry(nameLabel->x(),cateLabel->y()+cateLabel->height()+30,200,50);
        DEFLabel->setGeometry(nameLabel->x(),ATKLabel->y()+ATKLabel->height()+30,ATKLabel->width(),ATKLabel->height());
        starShowLabel->setGeometry(ATKLabel->x()+ATKLabel->width()+70,ATKLabel->y(),ATKLabel->height()+DEFLabel->height()+30,ATKLabel->height()+DEFLabel->height()+30);     
        describeLabel->setGeometry(nameLabel->x(),DEFLabel->y()+DEFLabel->height()+50,nameLabel->width(),100);
        sameNameCardLabel->setGeometry(describeLabel->x()+50,describeLabel->y()+describeLabel->height()+30,250,50);
        returnBtn->setGeometry(sameNameCardLabel->x()+sameNameCardLabel->width()+50, sameNameCardLabel->y(),50,50);


        /******************此处代码需要重构***********************/

        //关于背景的调整 ----因为直接把图片弄成了半透明的样子，所以不用再添加两层了


        backgroundImage1->setStyleSheet("background-color:rgb(255,255,255)");
        this->setStyleSheet(QString("border-radius:10%;color:rgb(255,255,255); background-color:rgba(180,180,180,150);font: 30 15pt 'Microsoft YaHei' ;")+"background-color:rgb(180,180,180);");

        //设置背景样式
        backgroundImage1->setStyleSheet("background-color:rgb(255,255,255)");

     /******************此处代码需要重构***********************/
}





void cardShowWigdet::initCard(int cardId, QList<QList<QString> > &database)
{
    //待重构

    int idc=foundData(cardId,database);

        ID=database[idc][0].toInt();
        name=database[idc][1];
        category=database[idc][2];
        rarity=database[idc][3];
        ATK=database[idc][4].toInt();
        DEF=database[idc][5].toInt();
        describe=database[idc][6];
        imageUrl=database[idc][7];
        movieUrl=database[idc][8];
        grade=database[idc][10].toInt();
        star=database[idc][11].toInt();
        bImageUrl=database[idc][12];


        if(movieUrl==QString("0")) isMovie=false;                       //是否加载动图
                              else isMovie=true;


       //label的Text设置
     /******************此处代码需要重构***********************/
        idLabel->setText("ID:   "+QString::number(ID));
        idLabel->setAlignment(Qt::AlignCenter);
        nameLabel->setText(name);
        nameLabel->setAlignment(Qt::AlignCenter);
        cateLabel->setText(category);
        cateLabel->setAlignment(Qt::AlignCenter);
        ratLabel->setText(rarity);
        ratLabel->setAlignment(Qt::AlignCenter);
        ATKLabel->setText("  ATK: "+QString::number(ATK));
        DEFLabel->setText("  DEF: "+QString::number(DEF));
        describeLabel->setText(" 角色介绍: "+describe);
        describeLabel->setAlignment(Qt::AlignLeft);
        gradeLabel->setText(QString::number(grade));
        gradeLabel->setAlignment(Qt::AlignCenter);
        expLabel->setText("  EXP: "+QString::number(exp)+"/"+QString::number(starToEXP[star-1]));
        sameNameCardLabel->setText(" 同名卡数: " +QString::number(sameNameCard));                          //为升星设计，但没有实装

        //差starlabel的设置   ----原计划是贴图-需要加载五张同类不同星表现的图

        cardImage->load(imageUrl);
        cardPic->load(imageUrl);
        backgroundPix->load(bImageUrl);
        if (isMovie) cardMovie=new QMovie(movieUrl);                //没有后续语句


        imageLabel->setPixmap(*cardPic);                            //立绘
        imageLabel->setScaledContents(true);

        backgroundImage2->setPixmap(*backgroundPix);                //背景
        backgroundImage2->setScaledContents(true);



/******************此处代码需要重构***********************/


}

int cardShowWigdet::foundData(int cardId, QList<QList<QString> > &database)
{
    /******************此处代码需要重构***********************/
    for(int i=0;i<database.size();i++)
        if(cardId==database[i][0].toInt())
            return i;
    return 0;
/******************此处代码需要重构***********************/
}

QString cardShowWigdet::getCardCate()
{
    return category;
}

QString cardShowWigdet::getCardCate2()
{
    return  category2;
}

QString cardShowWigdet::getCardRarity()
{
    return rarity;
}

QString cardShowWigdet::getCardName()
{
    return name;
}

int cardShowWigdet::getCardATK()
{
    return ATK;
}

int cardShowWigdet::getCardDEF()
{
    return DEF;
}

int cardShowWigdet::getCardDHP()
{
    return DHP;
}

int cardShowWigdet::getCardBuffId()
{
    return BUFFID;
}

int cardShowWigdet::getCardId()
{
    return ID;
}

QString cardShowWigdet::getCardPic()
{
    return imageUrl;
}

QString cardShowWigdet::getCardImageUrl()
{
    return imageUrl;
}

int cardShowWigdet::getCardGrade()
{
    return grade;
}

QPushButton *cardShowWigdet::getBtn()
{
    return returnBtn;
}
