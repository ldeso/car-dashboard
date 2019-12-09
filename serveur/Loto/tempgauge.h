#ifndef TEMPGAUGE_H
#define TEMPGAUGE_H
#include "QGraphicsItem"
#include "QWidget"
#include "QPaintDevice"
#include "QColor"
#include "QGraphicsItem"
#include "qpainter.h"
#include "QPaintEvent"
#include "QBrush"
#include "objet_virtuel.h"


class tempGauge : public objet_virtuel
{
public:
    tempGauge();
    QRectF boundingRect()const;
    float engineTemp=float(getValue());
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    const float pi=3.142f;
    float getEngineTemp(float engineTemp);
};

#endif // TEMPGAUGE_H
