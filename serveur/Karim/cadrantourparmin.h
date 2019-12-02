#ifndef CADRANTOURPARMIN_H
#define CADRANTOURPARMIN_H
#include <objet_virtuel.h>
#include <QPainter>

class CadranTourParMin : public objet_virtuel
{

public:
    CadranTourParMin(QGraphicsItem *parent =0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
 };




#endif // CADRANTOURPARMIN_H
