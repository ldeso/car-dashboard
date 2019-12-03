#ifndef OILGAUGEINNA_H
#define OILGAUGEINNA_H
#include <QGraphicsItem>
#include <QRectF>
#include <QFont>


class OilGaugeInna : public QGraphicsItem
{
public:
    OilGaugeInna(QGraphicsItem *parent = nullptr);
    OilGaugeInna(int TMAX, int LMAX, int ALPHA0, int ALPHAMAX);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int r;
    int A0 ; //start Angle
    int Amax ; // max Angle
    int tmax ; // maximum oil temperature
    int t ; // current oil temperature
    int lmax ; // maximum oil level
    double l ; // current oil level
    QFont font = QFont("Chandas",12,QFont::Bold); // font parameters par default
    double k ; // coefficient to calculate current angle
    int dx; //text shift
    int dy;
private:
    const double rad=3.14159265359/180;
    double xc = 0.14 * this->boundingRect().width() ; //center of the rectangle
    double yc = 0.63 * this->boundingRect().height() ;

};

#endif // OILGAUGEINNA_H
