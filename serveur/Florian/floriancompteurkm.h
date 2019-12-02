#ifndef COMPTEURKM_H
#define COMPTEURKM_H
#include "objet_virtuel.h"

class FlorianCompteurKm:public objet_virtuel
{
public:
    FlorianCompteurKm(QGraphicsItem *parent=nullptr);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // COMPTEURKM_H
