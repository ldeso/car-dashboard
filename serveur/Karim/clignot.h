#ifndef CLIGNOT_H
#define CLIGNOT_H
#include "objet_virtuel.h"

class clignot : public objet_virtuel
{
public:
   clignot(QGraphicsItem *parent=nullptr);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int cligno;
    void MAJ();
};
#endif // CLIGNOT_H
