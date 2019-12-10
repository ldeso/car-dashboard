#include "autresvoyants.h"

autresvoyants::autresvoyants(QString chemin, int posx, int posy, int size)
{
   value =0;
   ch=chemin;
   x=posx;
   y=posy;
   taille=size;
}

QRectF autresvoyants::boundingRect() const
{
    QRectF rectf(-800,-500,1600,1000);
    return rectf;
}
void autresvoyants::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing);

    if  (getValue()==1) {
        QPixmap im(ch);
        QPixmap im2=im.scaled(taille,taille);
        painter->drawPixmap(x,y,taille,taille,im2);
    }
}
