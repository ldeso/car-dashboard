#include "leds.h"
#include "objet_virtuel.h"
#include "QDebug"
#include "QPainter"
#include "QPainterPath"
#include "QGradient"
#include "QtMath"
#include "QDebug"
#include "QTextItem"
#include "QString"
#include "QRadialGradient"
#include "QPolygon"
#include "QPixmap"


LEDS::LEDS(int x, int y, QString iconPathString, int red, int green, int blue, int icon_size)
{
    value=0;
    posX = x;
    posY = y;
    iconPath=iconPathString;
    ledColor=QColor(red,green,blue,160);
    size=icon_size;
}

void LEDS::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 // Here, we will take the value of 0 as default value for the LEDS and 1 if it is ON and 2 if the
 // system is in blinking state.

    if (getValue()==1)
    {
        QPixmap icon(iconPath);
        QPixmap icon2=icon.scaled(size,size);
        QBrush brush;
        brush.setColor(ledColor);
        painter->setBrush(brush);
        painter->drawPixmap(posX,posY,size,size,icon2);
        painter->drawRect(posX,posY,size,size);

    }
}

QRectF LEDS::boundingRect() const
{
 return QRect (-800,-400,1000,1000);
}



