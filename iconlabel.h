#ifndef ICONLABEL_H
#define ICONLABEL_H

#include <QObject>
#include <QLabel>
#include<QtWidgets>

#pragma execution_character_set("utf-8")


class iconLabel : public QLabel
{
    Q_OBJECT
public:
    //为承载图标而特化的label
   explicit iconLabel(QWidget *parent=0,Qt::WindowFlags f=Qt::WindowFlags()) ;
   void setIconUrl(QString url);
private:
    QString iconUrl;
    void paintEvent(QPaintEvent *) override;
};

#endif // ICONLABEL_H
