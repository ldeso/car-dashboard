#ifndef TACHOMETER_H
#define TACHOMETER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "objet_virtuel.h"

class Tachometer : public objet_virtuel
{
public:
    Tachometer(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    /* main parameters*/

        float pi = 3.14159265359;  /* Global variable */
        int speed;
};

#endif // TACHOMETER_H


