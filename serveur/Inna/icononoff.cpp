#include "Inna/icononoff.h"
#include "Inna/iconinna.h"
#include <QPainter>

iconOnOff::iconOnOff(IconInna *parent) : IconInna (parent)
{
    value = 1;
}

iconOnOff::iconOnOff(QPoint p, QSize s, QString pth, double Z)
{
    value = 1;
    position = p;
    size = s;
    imagePath = pth;
    this->setZValue(Z);
}

QRectF iconOnOff::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void iconOnOff::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{painter->setRenderHints(QPainter::Antialiasing);

    if (value == 1)
        {
             painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap( imagePath));
        }
    else
         {   painter->setPen(Qt::transparent);
             painter->setBrush(QBrush(Qt::transparent));
             painter->drawRect(position.x(),position.y(),size.width(),size.height());
         }

    }

