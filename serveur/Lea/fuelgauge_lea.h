#ifndef FUELGAUGE_LEA_H
#define FUELGAUGE_LEA_H
#include <QGraphicsItem>
#include <QRectF>
#include "objet_virtuel.h"


class FuelGauge_lea : public objet_virtuel
{
public:
    FuelGauge_lea(double, double, double, double, double, double, double, double);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  //  void setValue(int);
    double x;
    double y;
    double x2;
    double y2;
    double x3;
    double y3;
    double width;
    double height;

};

#endif // FUELGAUGE_LEA_H
