#include "leo_object.h"

Leo_object::Leo_object(QRectF boundingRect, QGraphicsItem* parent)
    : objet_virtuel(parent)
    , mBoundingRect(boundingRect)
{
    value = 0;
    valueMax = 0;
}

QRectF Leo_object::boundingRect() const
{
    return mBoundingRect;
}
