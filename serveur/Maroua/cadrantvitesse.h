#ifndef CADRANTVITESSE_H
#define CADRANTVITESSE_H
#include "objet_virtuel.h"

class cadrantvitesse : public objet_virtuel
{
public:
    cadrantvitesse(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CADRANTVITESSE_H
