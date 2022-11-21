#include "paintlabel.h"

paintLabel::paintLabel(QWidget *parent, Qt::WindowFlags f):QLabel(parent)
{
    setAttribute (Qt::WA_TranslucentBackground);
}

void paintLabel::setPaintUrl(QString url)
{
    paintUrl=url;
    resize(this->width(),this->height());
    update();

}

void paintLabel::setIDX(int i)
{
    idx=i;

}

void paintLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if(paintUrl!="")
    {
        QImage paintImg(paintUrl);
        QRect re(0,0,this->width(),this->height());

        painter.drawPixmap(re,QPixmap::fromImage(paintImg));
    }
}

void paintLabel::mouseReleaseEvent(QMouseEvent *ev)
{
     emit clicked();
     emit clicked(idx);
}
