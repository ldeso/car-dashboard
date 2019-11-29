#include "voyant.h"
#include <QPainter>
#include <QDebug>
Voyant::Voyant(QPixmap map, QGraphicsItem * parent):objet_virtuel(parent)
{
    this->voyant = map;
    this->value = 0;
}

QRectF Voyant::boundingRect() const
{
    QRectF rect(0,0,40,40);
    return rect;
}

void Voyant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->value==1){

        qDebug() << value;
        painter->drawPixmap(0,0,30,30,this->voyant);
    }
}

