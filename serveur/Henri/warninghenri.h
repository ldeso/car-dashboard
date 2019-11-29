#ifndef WARNINGHENRI_H
#define WARNINGHENRI_H
#include "objet_virtuel.h"


class warninghenri : public objet_virtuel
{
public:
    warninghenri();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // WARNINGHENRI_H
