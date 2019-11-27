#ifndef JAUGETEMPERATUREHENRI_H
#define JAUGETEMPERATUREHENRI_H

#include "jaugevirtuel.h"

class jaugeTemperatureHenri : public jaugeVirtuel
{
public:
    jaugeTemperatureHenri();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // JAUGETEMPERATUREHENRI_H
