#ifndef HUGO_BOITE_VITESSE_H
#define HUGO_BOITE_VITESSE_H
#include "objet_virtuel.h"


class hugo_boite_vitesse : public objet_virtuel
{
public:
    hugo_boite_vitesse();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // HUGO_BOITE_VITESSE_H
