#include "horloge_lea.h"
#include <QTime>

horloge_lea::horloge_lea(int param_x, int param_y, int param_width, int param_height)
{
    x=param_x;
    y=param_y;
    width=param_width;
    height=param_height;
    value=0;
}

QRectF horloge_lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);
    return rectf;
}

void horloge_lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(Qt::white , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(Qt::transparent);
    QRectF rect_time(x,y,width,height);
    painter->drawRoundedRect(rect_time,2,2);
    QTime time=QTime::currentTime();
    time.currentTime();
    painter->setFont(QFont("Arial", 9, -1,false));
    painter->drawText(rect_time,Qt::AlignRight,time.toString("hh.mm"));


}
