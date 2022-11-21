#include "readtxt.h"

readTxt::readTxt()
{

    idx=0;
}

int readTxt::countLine()
{
    return idx;
}

void readTxt::loadTalk(QString str)
{
    QFile file(str);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;

    }else
    {
        idx=0;
        sceneTalkLineStr.clear();
    }
    while(!file.atEnd())
    {
        sceneTalkLine[idx]=file.readLine();
        QString tmpStr(sceneTalkLine[idx]);
        qDebug()<<tmpStr;
        sceneTalkLineStr.append(tmpStr);
        idx++;
    }


}

QByteArray readTxt::getLine(int x)
{
    return sceneTalkLine[x];
}

QList<QString> readTxt::getStr()
{
    return sceneTalkLineStr;
}
