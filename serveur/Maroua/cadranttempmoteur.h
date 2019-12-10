#ifndef CADRANTTEMPMOTEUR_H
#define CADRANTTEMPMOTEUR_H

#include "objet_virtuel.h"
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>

class cadranttempmoteur : public objet_virtuel
{
public:
    cadranttempmoteur(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CADRANTTEMPMOTEUR_H
