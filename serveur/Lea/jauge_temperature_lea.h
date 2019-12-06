#ifndef JAUGE_TEMPERATURE_LEA_H
#define JAUGE_TEMPERATURE_LEA_H
#include "objet_virtuel.h"

class jauge_temperature_lea : public objet_virtuel
{
public:
    jauge_temperature_lea(double, double, double, int, int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    const double pi=3.14159265359;
    double x;
    double y;
    double r;
    int angle_debut;
    int span_angle;
    int temperature_max=130;
    int v;

};

#endif // JAUGE_TEMPERATURE_LEA_H
