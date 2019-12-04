#ifndef CARSPEEDDIAL_H
#define CARSPEEDDIAL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class CarSpeedDial : public QGraphicsItem
{
public:
    CarSpeedDial(QGraphicsItem *parent=nullptr);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    /* main parameters*/

        float pi = 3.14159265359;  /* Global variable */
        int speedvalue;



};

#endif // CARSPEEDDIAL_H




