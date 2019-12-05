#ifndef CARSPEEDDIAL_H
#define CARSPEEDDIAL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "objet_virtuel.h"

class CarSpeedDial : public objet_virtuel
{
public:
    CarSpeedDial(objet_virtuel *parent=nullptr);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    /* main parameters*/

        float pi = 3.14159265359;




};

#endif // CARSPEEDDIAL_H




