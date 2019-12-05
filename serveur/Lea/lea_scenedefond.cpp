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


    pen.setColor(Qt::transparent);
    QPixmap texture (":/Effets/Icones_Voyants/index.jpeg");
    QPixmap voyant= texture.scaled(1000,600);
    brush.setTexture(voyant);
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawChord(100,10,900,450,310*16,280*16);


    painter->setBrush(QBrush(Qt::black));
    painter->drawChord(102,12,896,446,310*16,280*16);

    QPixmap texture_fond (":/Effets/effet_verre5.png");
    QPixmap voyant2= texture_fond.scaled(1000,600);
    brush.setTexture(voyant2);
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawChord(102,12,896,446,310*16,280*16);

    pen.setColor(Qt::transparent);
    QPixmap texture_fond_rectangle (":/Effets/Icones_Voyants/index.jpeg");
    QPixmap voyant3= texture_fond_rectangle.scaled(1000,600);
    brush.setTexture(voyant3);
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawRoundedRect(140,400,820,80,20,20);

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRoundedRect(142,402,816,76,20,20);

    QPixmap texture_fond_rectangle2 (":/Effets/effet_verre5.png");
    QPixmap voyant4= texture_fond_rectangle2.scaled(1000,100);
    brush.setTexture(voyant4);
    painter->setBrush(brush);
    painter->drawRoundedRect(142,402,816,76,20,20);

}


