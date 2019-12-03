#include "feuxhenri.h"

feuxHenri::feuxHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
}

QRectF feuxHenri::boundingRect() const
{
    return QRect(-500,-300,1000,600);
}

void feuxHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    QPixmap *test=new QPixmap(":/new/prefix1/iconeRoute.png");
    if ( getValue()==1)
    painter->drawPixmap(-35,40,70,70,*test);
}
