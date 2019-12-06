#ifndef TACHOMETER_H
#define TACHOMETER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Tachometer : public QGraphicsItem
{
public:
    Tachometer(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    /* main parameters*/

        float pi = 3.14159265359;  /* Global variable */
        int speed;
};

#endif // TACHOMETER_H


