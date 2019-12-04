#ifndef TACHOMETERGAUGE_LEA_H
#define TACHOMETERGAUGE_LEA_H
#include <QGraphicsItem>
#include <QRectF>
#include "objet_virtuel.h"

class TachometerGauge_Lea : public objet_virtuel
{
public:
    TachometerGauge_Lea(double,double, double,int, int, int, int, int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected :
    double r;
    double x;
    double y;
    int angle_debut;
    int angle_fin;
    int nb_graduation=41;
    int span_angle;
    int vitesse_max=270;
    int v;
    const double pi=3.14159265359;
    void setValue(int);

    virtual void parametrage(double param_x,double param_y, double param_r,int param_start, int param_end, int param_spanAngle, int param_graduation, int param_rpmMax );


};

#endif // TACHOMETERGAUGE_LEA_H
