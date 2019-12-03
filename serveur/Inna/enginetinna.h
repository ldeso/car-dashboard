#ifndef ENGINETINNA_H
#define ENGINETINNA_H
#include "objet_virtuel.h"
#include <QRectF>
#include <QFont>

class EngineTInna : public objet_virtuel
{
public:
    EngineTInna(objet_virtuel *parent = nullptr);
    EngineTInna(int TMAX, int ALPHA0, int ALPHAMAX);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int r;
    int A0 ; //start Angle
    int Amax ; // max Angle
    int tmax ; // maximum engine temperature
    int t ; // current engine temperature
    double k ; // coefficient to calculate current angle

private:
    const double rad=3.14159265359/180;
    
    double xc = 0.86 * this->boundingRect().width() ; //center of the rectangle
    double yc = 0.63 * this->boundingRect().height() ;

};

#endif // ENGINETINNA_H
