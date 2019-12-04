#include "onoffpainthenri.h"

onoffpaintHenri::onoffpaintHenri()
{
    x=0;
    y=0;
    w=100;
    h=100;

}

onoffpaintHenri::onoffpaintHenri(int xx, int yy, int ww, int hh, QPixmap pixm)
{
    value=0;
    x=xx;
    y=yy;
    w=ww;
    h=hh;
    pix=pixm;
}

QRectF onoffpaintHenri::boundingRect() const
{
    return QRect(-500,-300,1000,600);
}

void onoffpaintHenri::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if ( getValue()==1)
    painter->drawPixmap(x,y,w,h,pix);
}
