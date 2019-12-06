#ifndef CADRANTHUILE_H
#define CADRANTHUILE_H

#include "objet_virtuel.h"
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>

class cadranthuile : public objet_virtuel
{
public:
    cadranthuile(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CADRANTESSENCE_H
