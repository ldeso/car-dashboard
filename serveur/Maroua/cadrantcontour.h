#ifndef CADRANTCONTOUR_H
#define CADRANTCONTOUR_H

#include "objet_virtuel.h"
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>

class cadrantcontour : public objet_virtuel
{
public:
    cadrantcontour(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CADRANTESSENCE_H
