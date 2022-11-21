#include "iconlabel.h"


iconLabel::iconLabel(QWidget *parent, Qt::WindowFlags f):QLabel(parent)
{

}

void iconLabel::setIconUrl(QString url)
{
    iconUrl=url;
    resize(this->width(),this->height());
    update();
}

void iconLabel::paintEvent(QPaintEvent *)
{
//    QStyle *style=QWidget::style();
//    QPainter painter(this);
//    painter.setOpacity(0.5);
//    QRect cr=contentsRect();
//    cr.adjust(margin(),margin(),-margin(),-margin());

//    int align = QStyle::visualAlignment(text() == "" ? Qt::LeftToRight : layoutDirection(), alignment());


    QPainter painter(this);

    if(iconUrl!="")
    {
    QImage iconImage(iconUrl);

    QRect rc(0,0,this->width(),this->height());

    painter.drawPixmap(rc,QPixmap::fromImage(iconImage));

    }


}
