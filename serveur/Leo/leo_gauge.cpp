#include "leo_gauge.h"

Leo_gauge::Leo_gauge(objet_virtuel* parent) :
    objet_virtuel(parent)
{
    mBoundingRect = QRectF(0., 0., 100., 100.);
}

QRectF Leo_gauge::boundingRect() const
{
    return mBoundingRect;
}

void Leo_gauge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(mBoundingRect);
}
