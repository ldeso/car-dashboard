#include "Inna/icononoffinna.h"
#include "Inna/iconinna.h"
#include <QPainter>
#include <QtMath>

iconOnOffInna::iconOnOffInna(IconInna *parent) : IconInna (parent)
{
    value = 0;
}

iconOnOffInna::iconOnOffInna(QPoint p, QSize s, QString pth, double Z)
{
    value = 0;
    position = p;
    size = s;
    imagePath = pth;
    this->setZValue(Z);
}

QRectF iconOnOffInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void iconOnOffInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{painter->setRenderHints(QPainter::Antialiasing);
 val = qRound(value);
    if (val == 1)
        {
             painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap( imagePath));
        }
    else
         {   painter->setPen(Qt::transparent);
             painter->setBrush(QBrush(Qt::transparent));
             painter->drawRect(position.x(),position.y(),size.width(),size.height());
         }

    }

