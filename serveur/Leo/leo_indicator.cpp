#include "leo_indicator.h"

Leo_indicator::Leo_indicator(objet_virtuel* parent) :
    objet_virtuel(parent)
{
    mBoundingRect = QRectF(0., 0., 100., 100.);
}

QRectF Leo_indicator::boundingRect() const
{
    return mBoundingRect;
}

void Leo_indicator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(mBoundingRect);
}
