#include "voyants.h"



Voyants::Voyants(QString pixpath, int xp, int yp, int ims)
{
    value=0;
    path=pixpath;
    x= xp;
    y= yp;
    size= ims;
}

QRectF Voyants::boundingRect() const
{
    QRectF rectf(-800,-500,1600,1000);
    return rectf;
}

void Voyants::paint(QPainter *painter, const QStyleOptionGraphicsItem* ,QWidget* )
{
    painter->setRenderHints(QPainter::Antialiasing);
    QPixmap esse("/home/sahli/Bureau/TableauMini/Icones/voyant_carburant.jpg");
    QPixmap tempmot("/home/sahli/Bureau/TableauMini/voyant-ldr-liquide-refroidissement.gif");
    painter->drawPixmap(-300,-150,50,50,esse);
    painter->drawPixmap(45,-150,50,50,tempmot);

    if  (getValue()==1) {
        QPixmap im(path);
        QPixmap im2=im.scaled(size,size);
        painter->drawPixmap(x,y,size,size,im2);
    }
}
