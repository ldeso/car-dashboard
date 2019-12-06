#ifndef HARC_H
#define HARC_H
#include <objet_virtuel.h>

class Harc : public objet_virtuel
{
public:
    Harc(int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int A = 250;
    int B = 250;
    QRectF rec     = QRectF(0,0, A, B);
    int startAngle = 30 * 16;  //C'est pour arc
    int spanAngle  = 120 * 16;//C'est pour arc
    int spanAngle0;

};

#endif // HARC_H
