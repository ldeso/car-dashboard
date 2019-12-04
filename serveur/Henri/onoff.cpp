#include "onoff.h"

onoff::onoff(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
    valueMax=999;
}

QRectF onoff::boundingRect() const
{
    return QRect(-500,-300,1000,600);
}

void onoff::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{

}
