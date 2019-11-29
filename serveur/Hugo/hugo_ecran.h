#ifndef HUGO_ECRAN_H
#define HUGO_ECRAN_H
#include "objet_virtuel.h"



class hugo_ecran : public objet_virtuel
{
public:
    hugo_ecran();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // HUGO_ECRAN_H
