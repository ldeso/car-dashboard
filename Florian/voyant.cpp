#include "voyant.h"
#include <QPainter>
Voyant::Voyant(QPixmap map, QGraphicsItem * parent):QGraphicsItem(parent)
{
    this->voyant = map;
    this->valeur = 0;
}

QRectF Voyant::boundingRect() const
{
    QRectF rect(0,0,40,40);
    return rect;
}

void Voyant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(valeur==1){
        painter->drawPixmap(0,0,30,30,this->voyant);
    }
}

void Voyant::setValeur(int valeur)
{
    this->valeur = valeur;
}
