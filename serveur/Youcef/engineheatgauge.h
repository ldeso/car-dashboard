#ifndef ENGINEHEATGAUGE_H
#define ENGINEHEATGAUGE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class EngineHeatGauge : public QGraphicsItem
{
public:
    EngineHeatGauge(QGraphicsItem *parent=nullptr);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);


    /* main parameters*/
    float pi = 3.14159265359;  /* Global variable */

};

#endif // ENGINEHEATGAUGE_H






