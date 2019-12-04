#include "jonas_voyant_simple.h"

jonas_voyant_simple::jonas_voyant_simple(QString iconPath, int xPos, int yPos, int iconSize)
{
    value = 0;
    path = iconPath;
    x = xPos;
    y = yPos;
    size = iconSize;
}

QRectF jonas_voyant_simple::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void jonas_voyant_simple::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHints(QPainter::Antialiasing);
    if  (value==1) {
        QPixmap icon(path);
        QPixmap icon_scaled=icon.scaled(size,size);
        painter->drawPixmap(x,y,size,size,icon_scaled);
    }
}
