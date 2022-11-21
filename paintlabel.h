#ifndef PAINTLABEL_H
#define PAINTLABEL_H

#include <QObject>
#include <QLabel>
#include <QtWidgets>
#pragma execution_character_set("utf-8")

class paintLabel : public QLabel
{
    //绘制label 用于加载含透明的png图片  //头像框之类的
    Q_OBJECT
public:
     explicit paintLabel(QWidget *parent=0,Qt::WindowFlags f=Qt::WindowFlags()) ;
     void setPaintUrl(QString url);
     void setIDX(int i);
private:
    QString paintUrl;
    int idx=-1;
    void paintEvent(QPaintEvent *) override;
    void mouseReleaseEvent(QMouseEvent *ev) ;
signals:
    void clicked();
    void clicked(int);
};

#endif // PAINTLABEL_H
