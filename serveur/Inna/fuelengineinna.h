#ifndef FUELENGINE_H
#define FUELENGINE_H
#include <QGraphicsItem>
#include <QRectF>
#include <QFont>

class FuelEngineInna : public QGraphicsItem
{
public:
    FuelEngineInna(QGraphicsItem *parent = nullptr);
    FuelEngineInna(int TMAX, int ALPHA0, int ALPHAMAX);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int r;
    int A0 ; //start Angle
    int Amax ; // max Angle
    int tmax ; // maximum engine temperature

    QFont font = QFont("Chandas",12,QFont::Bold); // font parameters par default
    int dx; //text shift
    int dy;
    double k;

private:
    const double rad=3.14159265359/180;
    const int lmax = 1 ; // maximum guel level
    double xc = 0.86 * this->boundingRect().width() ; //center of the rectangle
    double yc = 0.63 * this->boundingRect().height() ;

};

#endif // FUELENGINE_H
