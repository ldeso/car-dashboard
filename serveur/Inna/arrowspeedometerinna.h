#ifndef ARROWSPEEDOMETERINNA_H
#define ARROWSPEEDOMETERINNA_H
#include "objet_virtuel.h"
#include <QRectF>
#include <QFont>

class ArrowSpeedometerInna : public objet_virtuel
{
public:
    ArrowSpeedometerInna(objet_virtuel *parent = nullptr);
    ArrowSpeedometerInna(int VMAX, int ALPHA0, int ALPHAMAX);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int r;
    int A0 ; //start Angle
    int Amax ; // max Angle
    int vmax ; // maximum speed
    int v ; // current speed
    QFont font = QFont("Chandas",12,QFont::Bold); // font parameters par default
    double k ; // coefficient to calculate current angle
    int dx; //text shift
    int dy;
private:
    const double rad=3.14159265359/180;
    double xc = 0.3 * this->boundingRect().width() ; //center of the rectangle
    double yc = 0.55 * this->boundingRect().height() ;

};

#endif // ARROWSPEEDOMETERINNA_H
