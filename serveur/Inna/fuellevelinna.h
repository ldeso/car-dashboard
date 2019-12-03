#ifndef FUELLEVELINNA_H
#define FUELLEVELINNA_H
#include <QGraphicsItem>
#include "objet_virtuel.h"
#include <QRectF>
#include <QFont>

class FuelLevelInna : public objet_virtuel
{
public:
    FuelLevelInna(objet_virtuel *parent = nullptr);
    FuelLevelInna(int ALPHA0, int ALPHAMAX);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int r;
    int A0 ; //start Angle
    int Amax ; // max Angle
    double l ; // current fuel level
    double k ; // coefficient to calculate current angle

private:
    const double rad=3.14159265359/180;
    //const int lmax = 1 ; // maximum guel level
    double xc = 0.86 * this->boundingRect().width() ; //center of the rectangle
    double yc = 0.63 * this->boundingRect().height() ;

};

#endif // FUELLEVELINNA_H
