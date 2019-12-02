#ifndef LEO_GAUGE_H
#define LEO_GAUGE_H

#include "objet_virtuel.h"

class Leo_gauge : public objet_virtuel
{
public:
    Leo_gauge(objet_virtuel* parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LEO_GAUGE_H
