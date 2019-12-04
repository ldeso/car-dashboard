#include "lea_scenedefond.h"
#include <QPainter>

lea_SceneDeFond::lea_SceneDeFond(QGraphicsItem *parent):QGraphicsItem (parent)
{

}

QRectF lea_SceneDeFond::boundingRect() const
{
    QRectF rectf(0,0,1000,500);

    return rectf;
}

void lea_SceneDeFond::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    QBrush brush;
    QPen pen;
    painter->setRenderHint(QPainter::Antialiasing);
    pen.setColor(Qt::blue);
    pen.setCapStyle(Qt::RoundCap);
    painter->setBrush(QBrush(Qt::black));
    painter->drawChord(100,10,900,450,310*16,280*16);

    QPixmap texture_fond (":/Effets/effet_verre5.png");
    QPixmap voyant2= texture_fond.scaled(1000,600);
    brush.setTexture(voyant2);
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawChord(100,10,900,450,310*16,280*16);

    pen.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRoundedRect(100,400,900,80,20,20);

}


