#include "leo_gauge.h"

Leo_gauge::Leo_gauge(objet_virtuel* parent) :
    objet_virtuel(parent)
{}

QRectF Leo_gauge::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void Leo_gauge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(0, 0, 100, 100);
}
