#include "leo_indicator.h"

Leo_indicator::Leo_indicator(QColor colorOff, QColor colorOn, objet_virtuel* parent)
    : objet_virtuel(parent)
{
    value = 0;
    valueMax = 0;
    ColorOff = colorOff;
    ColorOn = colorOn;
}

void Leo_indicator::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addEllipse(
        mBoundingRect.center(),
        (mBoundingRect.width()-PenWidthPx) / 2,
        (mBoundingRect.height()-PenWidthPx) / 2
    );
    if (value < 0.5f)
        painter->fillPath(path, ColorOff);
    else
        painter->fillPath(path, ColorOn);
    painter->setPen(QPen(Qt::black, PenWidthPx));
    painter->drawPath(path);
}
