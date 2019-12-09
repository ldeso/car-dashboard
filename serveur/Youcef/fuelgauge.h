#ifndef FUELGAUGE_H
#define FUELGAUGE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "objet_virtuel.h"


class FuelGauge : public objet_virtuel
{
public:
    FuelGauge(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    /* main parameters*/
    float pi = 3.14159265359;  /* Global variable */
};

#endif // FUELGAUGE_H
