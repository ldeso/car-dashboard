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
    double engineTemp=getValue();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    const double pi=3.142;
    double getEngineTemp(double engineTemp);
};

#endif // TEMPGAUGE_H
