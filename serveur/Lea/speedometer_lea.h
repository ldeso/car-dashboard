#ifndef SPEEDOMETER_LEA_H
#define SPEEDOMETER_LEA_H
#include <QGraphicsItem>
#include <QRectF>
#include <QColor>
#include "objet_virtuel.h"

class speedometer_Lea : public objet_virtuel
{
public:
    speedometer_Lea(double, double, double, int, int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    const double pi=3.14159265359;
    double x;
    double y;
    double r;
    int angle_debut;
    int span_angle;
    int vitesse_max=270;
    int v;
    int nb_graduation =28;

};

#endif // SPEEDOMETER_LEA_H
