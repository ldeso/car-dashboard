#include "phares_lea.h"

phares_Lea::phares_Lea()
{

}

QRectF phares_Lea::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}


void phares_Lea::paint(QPainter *, const QStyleOptionGraphicsItem* , QWidget* )
{
}
