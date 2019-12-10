#ifndef CADRANTCONTOUR_H
#define CADRANTCONTOUR_H

#include "objet_virtuel.h"


class cadrantcontour : public objet_virtuel
{
public:
    cadrantcontour(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CADRANTESSENCE_H
