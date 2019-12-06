#include "leo_object.h"

Leo_object::Leo_object(const QRectF boundingRect, QGraphicsItem* parent)
    : objet_virtuel(parent)
    , mBoundingRect(boundingRect)
{
    value = 0;
}

QRectF Leo_object::boundingRect() const
{
    return mBoundingRect;
}
