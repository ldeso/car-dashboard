#ifndef KMCALCULATOR_H
#define KMCALCULATOR_H
#include "QPainter"
#include "QGraphicsItem"
#include "objet_virtuel.h"


class kmCalculator : public objet_virtuel
{
public:
    kmCalculator();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

};

#endif // KMCALCULATOR_H
