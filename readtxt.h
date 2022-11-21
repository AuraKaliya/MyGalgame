#ifndef READTXT_H
#define READTXT_H

#include <QString>
#include<QObject>
#include<QFile>
#include<QList>

#include<QDebug>
#pragma execution_character_set("utf-8")

//读取txt可以，但如果要添加表情变换的化，显然excel进行二维表化更好些
//现在会连数据库 excel也不用啦~~~

class readTxt
{
public:
    readTxt();
    int countLine(); //用于返回idx，即该段文本的行数
    void loadTalk(QString str); //输入段进行载入文本
    QByteArray getLine(int x);  //将未转换的文本数据传回
    QList<QString> getStr();
private:
    //采取方案是整个文本直接读取，需要一个大容量容器进行存储，这里采用QByteArray的静态数组进行存储。
    QByteArray sceneTalkLine[200];   //一段剧情最大两百行/句的容量
    QList<QString> sceneTalkLineStr; //转换后数据
    int idx; //用于录入数据时对文本进行定位
};

#endif // READTXT_H
