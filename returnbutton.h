#ifndef RETURNBUTTON_H
#define RETURNBUTTON_H

#include <QObject>
#include <QPushButton>
class returnButton : public QPushButton
{
    //特化的返回按钮 添加了hover的功能（不用设置stylesheet）
    Q_OBJECT
public:
   explicit returnButton( QWidget *parent=0,Qt::WindowFlags f=Qt::WindowFlags());
    ~returnButton(){};
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // RETURNBUTTON_H
