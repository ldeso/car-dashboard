#include "leo_label.h"

QRectF Leo_label::boundingRect() const
{
    return mBoundingRect;
}

void Leo_label::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QColor(Qt::white));
    painter->drawText(mBoundingRect, mText, Qt::AlignCenter | Qt::AlignVCenter);
}
