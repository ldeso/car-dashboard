#ifndef CADRANTESSENCE_H
#define CADRANTESSENCE_H

#include "objet_virtuel.h"
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>

class cadrantessence : public objet_virtuel
{
public:
    cadrantessence(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CADRANTESSENCE_H
