#ifndef STOPHENRI_H
#define STOPHENRI_H
#include "objet_virtuel.h"
#include "jaugetemperaturehenri.h"
#include "onoffpainthenri.h"
#include "onoff.h"
#include <QTest>

class stopHenri : public objet_virtuel
{
public:
    stopHenri();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int cligno;

    jaugeTemperatureHenri* jt;
    onoffpaintHenri* check;
    void MAJ();
};

#endif // STOPHENRI_H
