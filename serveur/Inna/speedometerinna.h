#ifndef SPEEDOMETERINNA_H
#define SPEEDOMETERINNA_H
#include <QGraphicsItem>
#include <QRectF>
#include <QFont>

class SpeedometerInna : public QGraphicsItem
{
public:
    SpeedometerInna(QGraphicsItem *parent = nullptr);
    SpeedometerInna(int VMAX, int ALPHA0, int ALPHAMAX);
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

#endif // SPEEDOMETERINNA_H
