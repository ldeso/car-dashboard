#include "jaugebatteriehenri.h"

jaugeBatterieHenri::jaugeBatterieHenri()
{

}

QRectF jaugeBatterieHenri::boundingRect() const
{
    return QRect(-100,-100,200,200);
}



void jaugeBatterieHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem* , QWidget* )
{
    QPixmap *test=new QPixmap(":/new/prefix1/iconeBatterie.png");
    if ( getValue()==1)
    painter->drawPixmap(-170,10,55,50,*test);
}
