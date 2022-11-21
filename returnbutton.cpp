#include "returnbutton.h"

returnButton::returnButton(QWidget *parent, Qt::WindowFlags f):QPushButton(parent)
{

}

void returnButton::enterEvent(QEvent *)
{


    setStyleSheet("border-bottom-right-radius: 80px 40px;;color:rgb(255,255,255);font: 30 25pt 'Microsoft YaHei' ;background-color:rgba(100,100,100,180);");

}

void returnButton::leaveEvent(QEvent *)
{
     setStyleSheet("border-bottom-right-radius: 80px 40px;;color:rgb(255,255,255);font: 30 25pt 'Microsoft YaHei' ;background-color:rgba(150,150,150,120);");
}
