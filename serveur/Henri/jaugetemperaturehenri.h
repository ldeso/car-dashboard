#ifndef JAUGETEMPERATUREHENRI_H
#define JAUGETEMPERATUREHENRI_H

#include "objet_virtuel.h"

class jaugeTemperatureHenri : public objet_virtuel
{
public:
    jaugeTemperatureHenri();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // JAUGETEMPERATUREHENRI_H
