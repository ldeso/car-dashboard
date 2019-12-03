#include "Karim/voyants.h"

Voyants::Voyants(QString pixpath,int xp , int yp, int ims)
{
    value=0;
    path=pixpath;
    x= xp;
    y= yp;
    size= ims;
}

QRectF Voyants::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void Voyants::paint(QPainter *painter, const QStyleOptionGraphicsItem* ,QWidget* )
{
    painter->setRenderHints(QPainter::Antialiasing);
    QPixmap im_essence(":/Icones/essence.jpg");
    QPixmap im_tempmoteur(":/Icones/tempmoteur.jpg");
    painter->drawPixmap(-300,-150,50,50,im_essence);
    painter->drawPixmap(45,-150,50,50,im_tempmoteur);

    if  (getValue()==1) {
        QPixmap im(path);
        QPixmap im2=im.scaled(size,size);
        painter->drawPixmap(x,y,size,size,im2);
    }
}



