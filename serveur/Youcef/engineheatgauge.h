#ifndef ENGINEHEATGAUGE_H
#define ENGINEHEATGAUGE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "objet_virtuel.h"

class EngineHeatGauge : public objet_virtuel
{
public:
    EngineHeatGauge(objet_virtuel *parent=nullptr);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);


    /* main parameters*/
    float pi = 3.14159265359;  /* Global variable */

};

#endif // ENGINEHEATGAUGE_H






