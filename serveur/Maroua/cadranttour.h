#ifndef CADRANTTOUR_H
#define CADRANTTOUR_H

#include "objet_virtuel.h"
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>


class cadranttour : public objet_virtuel
{
public:
    cadranttour(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CADRANTTOUR_H
