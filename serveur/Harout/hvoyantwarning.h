#ifndef HVOYANTWARNING_H
#define HVOYANTWARNING_H

#include "objet_virtuel.h"

class hvoyantwarning : public objet_virtuel
{
public:
    hvoyantwarning();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    int cligno;
    void MAJ();
};

#endif // HVOYANTWARNING_H

