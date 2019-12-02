#include "feuxhenri.h"

feuxHenri::feuxHenri(objet_virtuel *parent):objet_virtuel (parent)
{

}

QRectF feuxHenri::boundingRect() const
{
    return QRect(-700,-380,1400,780);
}

void feuxHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
}
