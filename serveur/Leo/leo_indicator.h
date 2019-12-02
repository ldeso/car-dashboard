#ifndef LEO_INDICATOR_H
#define LEO_INDICATOR_H

#include "objet_virtuel.h"

class Leo_indicator : public objet_virtuel
{
public:
    Leo_indicator(objet_virtuel* parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LEO_INDICATOR_H
