#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //对于静态信息的载入，规定在mainwindow中进行全部加载，然后再对各页面提供的接口进行调用，因为只用初始化一次，其在类中应该设置为static
    //同级界面的单项连接采用指针方式进行链接（如在召唤页面抽卡后给白玉宫添加卡牌），交互式采用信号进行联动（如页面跳转），同级交互信号在其上一级页面中进行设置，若类独立则在mainWindow中进行




    /******************************对整个程序的初始化******************************************/
    //设置窗体Title
    this->setWindowTitle("缘亦不圆");
    //设置窗体的图标（其实在pro界面已经设置了）
    //这种设置一般只在特化弹窗时编辑，比如抽卡界面的提示能量不足
    this->setWindowIcon(QIcon(":/images/icon/widgetIcon.ico"));


    //设置窗体宽高——这里统一采用1600：900;
    //其实是懒得计算百分比size和算gridlayout的填充比例
    this->setMinimumSize(1600,900);
    this->setMaximumSize(1600,900);

    //初始的故事界面为0，在数据初始化时进行加载变动
    StoryCount=0;



    //实例化读取功能的对象
    readCardData=new readExcel();
    readStoryData=new readExcel();
    readBuff=new readExcel();
    readCardHub=new readExcel();
    readStoryNPC=new readExcel();
    readStoryTalkData=new readExcel();

    gameShowWidget=new QStackedWidget(this);            //实例化游戏界面整体
    gameShowWidget->setGeometry(0,0,1600,900);

    mainShowWidget=new QWidget(this);                   //实例化主界面
    //将主界面添加到游戏整体界面中
    gameShowWidget->addWidget(mainShowWidget);      /**********为gameShow添加页面mainShow**********/
    mainShowWidget->setGeometry(0,0,1600,900);

        mainBackgroundLabel=new QLabel(mainShowWidget);  //实例化背景label
        titleLabel=new paintLabel(mainShowWidget);      //实例化标题label

            mainBackgroundLabel->setGeometry(0,0,1600,900);
            QPixmap mainPix;                            //采用QPixmap和QLabel的方式添加背景图片
            mainPix.load(":/images/background/mainPageBackground.png");
            mainBackgroundLabel->setPixmap(mainPix);

        //实例化按钮组
        mainPageBtnGroup=new QGroupBox(mainShowWidget);
        mainNewStoryBtn=new QPushButton(tr(" 新篇章 "),mainPageBtnGroup);
        mainCallBtn=new QPushButton(tr(" 召唤 "),mainPageBtnGroup);
        mainSettingBtn=new QPushButton(tr(" 设置 "),mainPageBtnGroup);
        mainCardHomeBtn=new QPushButton(tr(" 白玉宫 "),mainPageBtnGroup);
        mainEndBtn=new QPushButton(tr(" 归隐 "),mainPageBtnGroup);
        buttonList<<mainNewStoryBtn<<mainCallBtn<<mainSettingBtn<<mainCardHomeBtn<<mainEndBtn;
            //设置排布，先设置group的位置，然后以group为基准设置其他控件位置
            mainPageBtnGroup->setGeometry(mainShowWidget->width()/2-300,250,600,500);

            titleLabel->setGeometry(mainPageBtnGroup->x(),mainPageBtnGroup->y()-130,600,100);
            titleLabel->setPaintUrl(":/images/background/mainPageTitle.png");   //使用的是自定义label中的paintevent来绘制
            titleLabel->setScaledContents(true);

            mainPageBtnGroup->setStyleSheet ("QGroupBox {border:none}");    //这一步是去掉Group的边框（虽然不知道为什么要添加它进来，但是边框确实很丑）
            mainNewStoryBtn->setGeometry(100,30,400,75);        //在group中的相对位置，设置第一个然后参照其设置其他的
            mainCallBtn->setGeometry(100,mainNewStoryBtn->height()+mainNewStoryBtn->y()+10,mainNewStoryBtn->width(),mainNewStoryBtn->height());
            mainSettingBtn->setGeometry(100,mainCallBtn->height()+mainCallBtn->y()+10,mainNewStoryBtn->width(),mainNewStoryBtn->height());
            mainCardHomeBtn->setGeometry(100,mainSettingBtn->height()+mainSettingBtn->y()+10,mainNewStoryBtn->width(),mainNewStoryBtn->height());
            mainEndBtn->setGeometry(100,mainCardHomeBtn->height()+mainCardHomeBtn->y()+10,mainNewStoryBtn->width(),mainNewStoryBtn->height());

            for(int i=0;i<buttonList.size();i++)        //对按钮组进行样式的改变-想法是对位置的设置应该拎出来进行，对样式的设置比较统一就在循环里批量处理
            {
                buttonList[i]->setAttribute (Qt::WA_TranslucentBackground); //设置按钮背景为透明
                buttonList[i]->setStyleSheet(st.style_buttonLabel());       //然后设置为通用按钮样式
            }





    pageWidget=new QStackedWidget(this);                //实例化子页面承载页
    //子界面承载页添加到gameshow上，位于mainWidget之后，与mainWidget是同级页关系
    gameShowWidget->addWidget(pageWidget);   /**********为gameShow添加页面pageWidget**********/
    pageWidget->setGeometry(0,0,this->width(),this->height());

        whiteStone=new cardWidget(this);       //实例化白玉宫
        //添加白玉宫 到 子页面承载页
        pageWidget->addWidget(whiteStone);       /**********为pageWidget添加页面whiteStone**********/
        whiteStone->setGeometry(0,0,1600,900);

             cardInformationList=readCardData->readExcelData(cardInformationName);      //读取卡牌信息
             whiteStone->readCardInformation(cardInformationList);                      //将数据传给白玉宫页面中


        callStar = new callCardWidget(this);   //实例化召唤页面
        //添加召唤页面 到 子界面承载页
        pageWidget->addWidget(callStar);       /**********为pageWidget添加页面callStar**********/
        callStar->setGeometry(0,0,1600,900);

        callStar->linkCardHome(whiteStone);    //召唤页面单向连接白玉宫，用于召唤后为其添加卡牌
        callStar->initCardPool();              //连接后，

    //实例化故事界面
    storyWidget=new QStackedWidget(this);
    storyWidget->setGeometry(0,0,1600,900);

    //story 页面添加到gameshow页上，位于第三位，与mainWidget和gameShowWidget是同级页关系
    gameShowWidget->addWidget(storyWidget);  /**********为gameShow添加页面storyWidget**********/
    storyWidget->setGeometry(0,0,1600,900);





  /***************************引导页面***********************************/
      gameMainPage=new gameGuidePage(this);               //实例化story引导页面

      //添加 story引导页面 到故事页面
      storyWidget->addWidget(gameMainPage);/**********为storyWidget添加页面gameMainPage**********/
      gameMainPage->setGeometry(0,0,1600,900);

        storyInformaitonList=readStoryData->readExcelData(storyInformationName);       //读取剧情信息
        gameMainPage->readStroyInformation(storyInformaitonList);                      //将数据传给导航页面中
        gameMainPage->initThisWidget();                                                //传入信息后，进行初始化

    /***************************剧情对话页面***********************************/
      storyScene1=new gameStoryScene(this);       //实例化剧情对话页面
      //添加剧情页面1 到 故事页面 和引导页面同级是为了方便跳转
      storyWidget->addWidget(storyScene1);        /**********为storyWidget添加页面storyScene1**********/
      storyScene1->setGeometry(0,0,1600,900);

      /******************连接引导页面中的展示页面和相应的剧情对话页面**************************/
      linkStoryScene(gameMainPage->getStoryPage()->getStoryLabel(StoryCount));
      StoryCount+=1;            //连接完后代表添加好了这一项，剧情页计数+1
      /**************************************************************/

      storyTalkStr=readStoryTalkData->readExcelData(story_1_name);                  //读取剧情对话信息
      storyScene1->loadTalkInformation(storyTalkStr);                               //将数据传给相应的剧情对话界面

      /***************************剧情对话1******|over|***************************/

    /***************************战斗页面***********************************/
      battleWidgetForest =new battleWidget_1(this);  //实例化战斗界面
      //添加 战斗页面-森林 到故事页面  和引导页面等同级是为了方便跳转
      storyWidget->addWidget(battleWidgetForest);        /**********为storyWidget添加页面battleWidgetForest**********/
      battleWidgetForest->setGeometry(0,0,1600,900);

      //静态数据
      battleBuffStr=readBuff->readExcelData(battleBuffInformationName);
      cardHubStr=readCardHub->readExcelData(battleCardHubName);
      storyCharactorStr=readStoryNPC->readExcelData(storyNPCInformationName);

      //这里应该进行设置背景图片-标识森林|海洋|天空

      battleWidgetForest->loadCardHub(cardHubStr);          //载入卡牌数据

      battleWidgetForest->loadNPCInformation(storyCharactorStr);    //随机初始化NPC数据        /**因为没有添加卡组功能目前玩家卡组也是用NPC模板**/
      battleWidgetForest->loadNPCInformation(storyCharactorStr);

      battleWidgetForest->loadBuffInformation(battleBuffStr);       //载入buff数据

      /***************************战斗页面1******|over|***************************/


/**************************初页面设置************************************/

    pageWidget->setCurrentIndex(0);


    storyWidget->setCurrentWidget(gameMainPage);
    gameShowWidget->setCurrentWidget(mainShowWidget);

/**************************初页面设置**********|over|************************/

      //作为素材展示，将所有卡加入到白玉宫中
      for(int i=1;i<cardInformationList.size();i++)
      {
          whiteStone->addCard(cardInformationList[i][0].toInt());
      }

      //信号与槽关联



    connect(mainCardHomeBtn,SIGNAL(clicked()),this,SLOT(On_mainCardHomeBtn()));              //主页面跳转白玉宫
    connect(mainCallBtn,SIGNAL(clicked()),this,SLOT(On_mainCallBtn()));                      //主页面跳转召唤页面
    connect(callStar->getReturnLabel(),SIGNAL(clickedCard3()),this,SLOT(On_returnBtn()));    //召唤页面返回主页面
    connect(whiteStone->getReturnBtn(),SIGNAL(clicked()),this,SLOT(On_returnBtn()));         //白玉宫返回主页面
    connect(gameMainPage->getReturnButton(),SIGNAL(clicked()),this,SLOT(On_returnBtn()));    //引导页面返回主页面
    connect(mainNewStoryBtn,SIGNAL(clicked()),this,SLOT(To_newPages()));                     //主页面跳转引导页面
    connect(storyScene1,SIGNAL(finished()),this,SLOT(storyBattle()));                        //剧情对话1结束跳转战斗页面  --跳过按钮也是这个信号
    connect(gameMainPage->getBattleTestButton(),SIGNAL(clicked()),this,SLOT(storyBattle())); //战斗测试的接口--在冒险页面上
    connect(battleWidgetForest,SIGNAL(returnGuidePage()),this,SLOT(storyEnd()));             //战斗结束回到引导页面
    connect(storyScene1,SIGNAL(returnPageMain()),this,SLOT(storyEnd()));                     //剧情对话1直接退出到引导页面里
    connect(mainEndBtn,SIGNAL(clicked()),this,SLOT(close()));                                //主界面中退出







    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("mygame");
        db.setUserName("root");
        db.setPassword("123456");
        db.open();

        QSqlQuery qurey;
        qurey.exec("select * from  cardinformation");
        while(qurey.next()){

            qDebug()<<qurey.value(0).toInt()
                   <<qurey.value(1).toString()
                  <<qurey.value(2).toString()
                 <<qurey.value(3).toString()
                <<qurey.value(4).toString()
               <<qurey.value(5).toString()
                 <<qurey.value(6).toString()
                   <<qurey.value(7).toString()
                     <<qurey.value(8).toString()
                       <<qurey.value(9).toString()
                          <<qurey.value(10).toString()
                             <<qurey.value(11).toString()
                                <<qurey.value(12).toString()
                                   <<qurey.value(13).toString()
                                      <<qurey.value(14).toString()
                                         <<qurey.value(15).toString()
                                            <<qurey.value(16).toString()
                                               <<qurey.value(17).toString()
                                                  <<qurey.value(18).toString()
                 ;


        }






















}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::linkStoryScene(cardLabel *cl)
{
    connect(cl,SIGNAL(clickedCard(int)),this,SLOT(To_storyScene(int)));
}

void MainWindow::On_mainCardHomeBtn()
{
    pageWidget->setCurrentWidget(whiteStone);
    gameShowWidget->setCurrentWidget(pageWidget);
}

void MainWindow::On_mainCallBtn()
{
    pageWidget->setCurrentWidget(callStar);
    gameShowWidget->setCurrentWidget(pageWidget);

}

void MainWindow::On_returnBtn()
{

    gameShowWidget->setCurrentWidget(mainShowWidget);


}

void MainWindow::To_storyScene(int i)
{
    storyWidget->setCurrentIndex(i+1);
}

void MainWindow::To_newPages()
{
       storyWidget->setCurrentIndex(0);
       gameShowWidget->setCurrentWidget(storyWidget);
}

void MainWindow::storyEnd()
{
    storyWidget->setCurrentIndex(0);
    gameShowWidget->setCurrentWidget(storyWidget);
}

void MainWindow::storyBattle()
{

    storyWidget->setCurrentWidget(battleWidgetForest);
    battleWidgetForest->initCardInformation();
    gameShowWidget->setCurrentWidget(storyWidget);
    battleWidgetForest->initBattleTest();
    battleWidgetForest->update();
    battleWidgetForest->resetBattleRole()  ;
    battleWidgetForest->loadNPCInformation(storyCharactorStr);
    battleWidgetForest->loadNPCInformation(storyCharactorStr);

}



