#ifndef JAUGEBATTERIEHENRI_H
#define JAUGEBATTERIEHENRI_H
#include "objet_virtuel.h"


class jaugeBatterieHenri : public objet_virtuel
{
public:
    jaugeBatterieHenri();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // JAUGEBATTERIEHENRI_H
