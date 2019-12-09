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

///
///\file leds.cpp
/// \brief Cet classe est dérivé de la classe objet_virtuel et il affiche les voyant de deux valeurs. on peut dire les voyants d'affichage.
///


///
/// \brief LEDS::LEDS
///\details Ici le variable "value" est initialisé dans le constructeur. la position posX et posY donnent l'emplacement dans le bounding rectangle. la taille est aussi initailisée.
///

LEDS::LEDS(int x, int y, QString iconPathString, int red, int green, int blue, int icon_size)
{
    value=0;
    posX = x;
    posY = y;
    iconPath=iconPathString;
    ledColor=QColor(red,green,blue,160);
    size=icon_size;
}

QRectF LEDS::boundingRect() const
{
    return QRect(-200,-200,400,400);

}

///
/// \brief LEDS::paint
/// \param painter
/// \details Ici, la override function de paint est utilisé pour afficher les voyants
///
void LEDS::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
 // Here, we will take the value of 0 as default value for the LEDS and 1 if it is ON and 2 if the
 // system is in blinking state.

    if (getValue()==1.0f)
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



