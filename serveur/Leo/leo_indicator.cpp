#include "leo_indicator.h"

Leo_indicator::Leo_indicator(objet_virtuel* parent) :
    objet_virtuel(parent)
{}

QRectF Leo_indicator::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void Leo_indicator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(0, 0, 100, 100);
}
