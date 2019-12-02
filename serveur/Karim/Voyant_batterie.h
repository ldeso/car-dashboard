#ifndef Voyant_batterie_H
#define Voyant_batterie_H
#include "voyants.h"


class Voyant_batterie : public Voyants
{
public:
    Voyant_batterie();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    int x,y;

};


#endif // Voyant_batterie_H
