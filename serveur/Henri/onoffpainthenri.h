#ifndef ONOFFPAINTHENRI_H
#define ONOFFPAINTHENRI_H
#include "objet_virtuel.h"

class onoffpaintHenri : public objet_virtuel
{
public:
    onoffpaintHenri();
    onoffpaintHenri(int xx,int yy,int ww,int hh,QPixmap pixm);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int x,y,w,h;
    QPixmap pix;
};

#endif // ONOFFPAINTHENRI_H
