#ifndef TACHOMETERINNA_H
#define TACHOMETERINNA_H
#include <QGraphicsItem>
#include <QRectF>
#include <QFont>

class TachometerInna : public QGraphicsItem
{
public:
    TachometerInna(QGraphicsItem *parent = nullptr);
    TachometerInna(int VMAX, int ALPHA0, int ALPHAMAX);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int r;
    int A0 ; //start Angle
    int Amax ; // max Angle
    int vmax ; // maximum rotations per minute
    int v ; // current speed
    QFont font = QFont("MechEffects2 BB",22, -1, true ); // font parameters par default
    double k ; // coefficient to calculate current angle
    int dx; //text shift
    int dy;
private:
    const double rad=3.14159265359/180;
    double xc = 0.5 * this->boundingRect().width() ; //center of the rectangle
    double yc = 0.5 * this->boundingRect().height() ;
    
};

#endif // TACHOMETERINNA_H
