#include "callcardwidget.h"

callCardWidget::callCardWidget(QWidget *parent) : QWidget(parent)
{
    //实例化时的初始化设置

    resize(1600,900);
    magicCount=1000;        //初始通用卡池能量为1000
    callIdx=0;              //初始化召唤计数器
    nowPoolIdx=1;           //默认卡池为道具卡池   -1 道具 -2 装备

    newCardID=0;           //初始化抽中卡的ID     ----------这个好像没什么用----------



    backgroundWidget = new QStackedWidget(this);        //实例化各卡池的承载页面
    backgroundWidget->setGeometry(0,0,1600,900);

    mainShowWidget = new QWidget();                     //实例化通用卡池页面
    backgroundWidget->addWidget(mainShowWidget);        /******************将通用卡池添加到承载页面中*********************/
    mainShowWidget->setGeometry(0,0,1600,900);
    backgroundWidget->setCurrentIndex(0);

        movieLabel=new QLabel(mainShowWidget);          //用Qlabel承载召唤看板娘的动图页面
        movieLabel->setGeometry(0,0,1600,900);
        callCardShowMovie=new QMovie;                   //对于gif图应该用QMovie加载
        callCardShowMovie->setFileName(movieName);

        QSize si(movieLabel->width(),movieLabel->height());
        callCardShowMovie->setScaledSize(si);
        movieLabel->setMovie(callCardShowMovie);

        /********************此处代码重构*****************************/
            //这地方应该放到主界面的跳转至这个页面的函数里，然后在return中设置停止的函数        --节省内存
            //应该需要个返回label的接口
        callCardShowMovie->start();

         /********************此处代码重构*****************************/



    topLabel = new QLabel(this);                                    //实例化顶部横栏
    topLabel->setGeometry(0,0,1600,100);
    topLabel->setStyleSheet(st.style_longLabel());                  //通用长条label

    returnLabel=new cardLabel(this);                                //实例化返回按钮/label
    returnLabel->setGeometry(0,0,200,100);
    returnLabel->setText("返 回");
    returnLabel->setAlignment(Qt::AlignCenter);                      //设置文字居中
    returnLabel->setStyleSheet(st.style_returnButtonLabelLeft());    //通用置于左上角的return

    magicGroup=new QGroupBox(this);                                  //实例化通用卡池能量，放在顶部横栏上
        magicIconLabel=new iconLabel(magicGroup);                    //实例化图标显示
        magicIconLabel->setGeometry(10,2,50,50);                     //在group中定位
        magicIconLabel->setMaximumSize(50,50);                       //设置size最大值
        magicIconLabel->setIconUrl(magicIconUrl);                    //加载图标
        magicIconLabel->setAttribute(Qt::WA_TranslucentBackground);  //透明背景
        magicIconLabel->setStyleSheet("background-color:transparent");//设置为透明
        magicIconLabel->setScaledContents(true);                      //设置label自适应图标大小
    /*****************************这上面的其实可以先设置图片的大小，再设置控件自适应*************************************/
        magicShowLabel =new cardLabel(magicGroup);                    //实例化通用卡池能量显示label
        magicShowLabel->setText(QString::number(magicCount));
        magicShowLabel->setStyleSheet(st.style_buttonLabel()+"border-radius:0%;"+"font: 30 22pt 'Microsoft YaHei';");       //对于特殊需求的在后面加相关设置  ----后续如果有多个卡池考虑添加到Style中
        magicShowLabel->setAlignment(Qt::AlignCenter);
        magicShowLabel->setGeometry(72,2,150,50);
        magicGroup->setGeometry(500,20,226,55);
        magicGroup->setStyleSheet(st.bkGreyH(200));

    backgroundLabel=new paintLabel(this);                             //实例化抽卡面的背景板
    backgroundLabel->setGeometry(0,580,1600,320);
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);
    backgroundLabel->setStyleSheet("background-color:transparent");
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setPaintUrl(backgroundImageLabel);

    propLabel=new cardLabel(this);                                    //实例化道具卡池按钮
    propLabel->setGeometry(154,793,200,100);
    propLabel->setStyleSheet(st.style_buttonLabel()+"border-radius:0%;"+"font: 30 22pt 'Microsoft YaHei' ;");
    propLabel->setText(" 道具 ");
    propLabel->setAlignment(Qt::AlignCenter);

    equipmentLabel =new cardLabel(this);                              //实例化装备卡池按钮
    equipmentLabel->setGeometry(1246,793,200,100);
    equipmentLabel->setStyleSheet(st.style_buttonLabel()+"border-radius:0%;"+"font: 30 22pt 'Microsoft YaHei' ;");
    equipmentLabel->setText(" 装备 ");
    equipmentLabel->setAlignment(Qt::AlignCenter);



    callCardLabel=new cardLabel(this);                                //实例化召唤按钮
    callCardLabel->setGeometry(700,600,200,200);
    callCardLabel->setStyleSheet(st.style_roLabel()+"border: 2px solid red");                                   //这是圆形按钮--设置了透明
    callCardLabel->setText("召唤");
    callCardLabel->setAlignment(Qt::AlignCenter);

    tmpShow=new cardLabel(this);                                      //实例化展示label
    tmpShow->setGeometry(-2000,0,500,300);                            //界面以外
    /*****************需要设置style***************************/
    tmpShow->setStyleSheet("background-color:rgb(152,126,140);font: 30 20pt 'Microsoft YaHei';color:rgb(255,255,255);");    //这个暂时没想好用什么style
    /*****************需要设置style***************************/
    tmpShow->setAlignment(Qt::AlignCenter);
    tmpImageShow=new  QLabel(this);
    tmpImageShow->setGeometry(-2000,0,169,300);
    tmpImageShow->setScaledContents(true);
    tmpImageShow->setStyleSheet(st.bkGreyH(0)+"border: 2px solid red");//加了个边框
    tmpImageShow->setPixmap(tmpPicOfCard) ;


    tipBox.setWindowTitle("警告！能量不足！");                           //先预设一下消息框
    tipBox.setWindowIcon(QIcon(":/images/icon/256_warning.ico"));     //左上方图标
    //tipBox.setIcon(QIcon(":/images/icon/256_warning.ico"));
    QPixmap iconpix(messageImageUrl);
    QSize sized(80,80);
    iconpix.scaled(sized);
    tipBox.setIconPixmap(iconpix);                                    //弹窗的预设图片可以通过这个设置
    QTextFormat  fo;
   // fo.setFontPointSize(20);
    tipBox.setTextFormat(Qt::TextFormat(1));                          //将弹窗的文本信息设置为富文本，即可通过html语句进行样式设计





    connect(callCardLabel,SIGNAL(clickedCard3()),this,SLOT(callCard()));                //点击召唤按钮时抽卡
    connect(propLabel,SIGNAL(clickedCard3()),this,SLOT(setProp()));                     //切换道具卡池
    connect(equipmentLabel,SIGNAL(clickedCard3()),this,SLOT(setEquip()));               //切换装备卡池
    connect(tmpShow,SIGNAL(clicked(cardLabel*)),this,SLOT(closeBob(cardLabel*)));       //点击后关闭抽中卡展示的页面

}

void callCardWidget::linkCardHome(cardWidget *p)
{
    this->whiteStone=p;
}

void callCardWidget::initCardPool()
{
    //重新播种
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    //清空QList;
    propCardPool.clear();
    equipmentCardPool.clear();

    /***************************需要进行代码重构*******************************/
    //因为会重置卡池，需要反复读取数据，更好的方案是将数据加载至页面之中作为static，然后在函数中直接进行读取。
    QList<QList<QString>> tmp=whiteStone->showInformation();
    /**************************需要进行代码重构********************************/

    //初始化道具卡池
    for(int sp=0;sp<40;sp++)
    {
        for(int i=0;i<tmp.size();i++)
        {   //卡池添加策略 ----对道具卡特化添加  ----对人物卡稀有添加  ----对其他卡普通添加

            if(tmp[i][2]=="道具卡")
            {
                if(qrand()%2==1) {
                    QList<QString> tmpCard;
                    tmpCard.append(tmp[i][0]);
                    tmpCard.append(tmp[i][3]);
                    tmpCard.append(tmp[i][2]);
                    tmpCard.append(tmp[i][1]);
                    tmpCard.append(tmp[i][7]);
                    propCardPool.append(tmpCard);
                    sp++;
                }
            }else if(tmp[i][2]=="人物卡")
            {
                if(qrand()%5==1) {
                    QList<QString> tmpCard;
                    tmpCard.append(tmp[i][0]);
                    tmpCard.append(tmp[i][3]);
                    tmpCard.append(tmp[i][2]);
                    tmpCard.append(tmp[i][1]);
                    tmpCard.append(tmp[i][7]);
                    propCardPool.append(tmpCard);
                    sp++;
                }
            }else
            {
                if(qrand()%4==1) {
                    QList<QString> tmpCard;
                    tmpCard.append(tmp[i][0]);
                    tmpCard.append(tmp[i][3]);
                    tmpCard.append(tmp[i][2]);
                    tmpCard.append(tmp[i][1]);
                    tmpCard.append(tmp[i][7]);
                    propCardPool.append(tmpCard);
                    sp++;
                }
            }

        }
    }

    //初始化装备卡池
    for(int sp=0;sp<40;sp++)
    {
        for(int i=0;i<tmp.size();i++)
        {   //卡池添加策略 ----对装备卡特化添加  ----对人物卡稀有添加  ----对其他卡普通添加

            if(tmp[i][2]=="装备卡")
            {
                if(qrand()%2==1) {
                    QList<QString> tmpCard;
                    tmpCard.append(tmp[i][0]);
                    tmpCard.append(tmp[i][3]);
                    tmpCard.append(tmp[i][2]);
                    tmpCard.append(tmp[i][1]);
                    tmpCard.append(tmp[i][7]);
                    equipmentCardPool.append(tmpCard);
                    sp++;
                }
            }else if(tmp[i][2]=="人物卡")
            {
                if(qrand()%5==1) {
                    QList<QString> tmpCard;
                    tmpCard.append(tmp[i][0]);
                    tmpCard.append(tmp[i][3]);
                    tmpCard.append(tmp[i][2]);
                    tmpCard.append(tmp[i][1]);
                    tmpCard.append(tmp[i][7]);
                    equipmentCardPool.append(tmpCard);
                    sp++;
                }
            }else
            {
                if(qrand()%4==1) {
                    QList<QString> tmpCard;
                    tmpCard.append(tmp[i][0]);
                    tmpCard.append(tmp[i][3]);
                    tmpCard.append(tmp[i][2]);
                    tmpCard.append(tmp[i][1]);
                    tmpCard.append(tmp[i][7]);
                    equipmentCardPool.append(tmpCard);
                    sp++;
                }
            }

        }
    }



}

void callCardWidget::callCard()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    if(magicCount<=magicNeed)
    {
        QString tmpTEXT="<h1>莉莉娅娜轻蔑地看了你一眼：穷鬼。</h1>";
        QString tmpTip=QString("<font color =\"red\">重拾男人雄风，十万天兵点击就送！决战沙城攻坚战，是兄弟就氪一发！</font>");
        tipBox.setText(tmpTEXT);
        tipBox.setInformativeText(tmpTip);
        tipBox.setStandardButtons(QMessageBox::Ok|QMessageBox::No);
        tipBox.setDefaultButton(QMessageBox::Ok);
        tipBox.setButtonText (QMessageBox::Ok,QString("充它丫的"));
        tipBox.setButtonText (QMessageBox::No,QString("充充充"));
        tipBox.exec();
        magicCount=1100;
    }


    if(magicCount>magicNeed)   //能量充足
    {
        int tempIDX;
        QString tmpStr="恭喜你抽中 ";

        if(nowPoolIdx==1)//道具卡池
        {
            tempIDX=qrand()%propCardPool.size();                 //在道具卡池中
            tmpPicOfCard.load(propCardPool[tempIDX][4]);        //给展示页面加载相应图片
    /************************这个应该在放在主函数中进行*****************************************/
            whiteStone->addCard(propCardPool[tempIDX][0].toInt());
            //用信号方式传递
    /************************这个应该在放在主函数中进行*****************************************/

            //展示的文字信息加载
            tmpStr+=propCardPool[tempIDX][1];
            tmpStr+=" ";
            tmpStr+=propCardPool[tempIDX][2];
            tmpStr+=" ";
            tmpStr+=propCardPool[tempIDX][3];
            tmpStr+=" !";             
        }
        else if(nowPoolIdx==2)//装备卡池
        {   tempIDX=qrand()%equipmentCardPool.size();
            tmpPicOfCard.load(equipmentCardPool[tempIDX][4]);
            whiteStone->addCard(equipmentCardPool[tempIDX][0].toInt());
            tmpStr+=equipmentCardPool[tempIDX][1];
            tmpStr+=" ";
            tmpStr+=equipmentCardPool[tempIDX][2];
            tmpStr+=" ";
            tmpStr+=equipmentCardPool[tempIDX][3];
            tmpStr+=" !";
        }

        //展示抽中的卡牌
        tmpImageShow->setPixmap(tmpPicOfCard);
        tmpShow->setText(tmpStr);
        tmpShow->move(600,300);
        tmpImageShow->move(420,300);
        magicCount-=magicNeed;
        updatePage();

                    //计数达一定量重置卡池
                    callIdx++;
                    if(callIdx>=20)
                    {
                        initCardPool();
                        callIdx=0;
                    }
    }


    update();



}

void callCardWidget::setProp()      //切换至道具卡池
{
    nowPoolIdx=1;
    equipmentLabel->setStyleSheet(st.style_buttonLabel()+"border-radius:0%;"+"font: 30 22pt 'Microsoft YaHei' ;");
    propLabel->setStyleSheet(st.style_buttonLabel()+"background:rgb(70,70,70);"+"border-radius:0%;"+"font: 30 22pt 'Microsoft YaHei' ;");

}

void callCardWidget::setEquip()     //切换至装备卡池
{

    nowPoolIdx=2;
    propLabel->setStyleSheet(st.style_buttonLabel()+"border-radius:0%;"+"font: 30 22pt 'Microsoft YaHei' ;");
    equipmentLabel->setStyleSheet(st.style_buttonLabel()+"background:rgb(70,70,70);"+"border-radius:0%;"+"font: 30 22pt 'Microsoft YaHei' ;");
}



void callCardWidget::updatePage()       //因为是每次抽卡后才更新，所以不用放在paintevevnt中
{
    magicShowLabel->setText(QString::number(magicCount));

}

cardLabel *callCardWidget::getReturnLabel()         //用于给mainWindow提供页面中返回按钮的接口
{
    return returnLabel;
}

void callCardWidget::closeBob(cardLabel*p)          //点击后模拟关闭的方法，实际上是移动到看不到的地方
{

  p->move(-2000,0);
  tmpImageShow->move(-2000,0);
  update();
}
