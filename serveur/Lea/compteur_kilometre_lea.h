#ifndef COMPTEUR_KILOMETRE_LEA_H
#define COMPTEUR_KILOMETRE_LEA_H
#include "objet_virtuel.h"

class Compteur_kilometre_lea : public objet_virtuel
{
public:
    Compteur_kilometre_lea(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int x,y;

};

#endif // COMPTEUR_KILOMETRE_LEA_H
