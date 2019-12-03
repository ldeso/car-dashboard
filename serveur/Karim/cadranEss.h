#ifndef Cadrans_H
#define Cadrans_H
#include <QGraphicsItem>
#include <QPainter>
#include <objet_virtuel.h>

class CadranEss : public objet_virtuel
{

public:
    CadranEss(QGraphicsItem *parent =0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   /* int value=0;
    int angle=225;
    int vitesse;
    int getValueMax();
    void setValue(int v);*/
 };




#endif // Cadrans_H
