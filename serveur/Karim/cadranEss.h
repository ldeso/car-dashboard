#ifndef Cadrans_H
#define Cadrans_H
#include <objet_virtuel.h>

class CadranEss : public objet_virtuel
{

public:
    CadranEss(QGraphicsItem *parent =0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};




#endif // Cadrans_H
