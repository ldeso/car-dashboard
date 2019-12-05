#include "onoff.h"

onoff::onoff(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
    valueMax=999;
}

QRectF onoff::boundingRect() const
{
    return QRect(-300,-300,600,600);
}

void onoff::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{

}
