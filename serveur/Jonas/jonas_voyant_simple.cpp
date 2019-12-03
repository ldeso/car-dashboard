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
    return QRect(-800,-450,1600,900);
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
