#ifndef LOTO_DASHBOARD_H
#define LOTO_DASHBOARD_H
#include "QGraphicsItem"
#include "QWidget"
#include "QPaintDevice"
#include "QColor"
#include "QGraphicsItem"
#include "qpainter.h"
#include "QPaintEvent"
#include "QBrush"
#include "objet_virtuel.h"


class loto_dashboard : public objet_virtuel
{
public:
    loto_dashboard();
    QRectF boundingRect()const;
    float speedValue;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    const float pi=3.142f;
    float getSpeedAngle(float speedValue);

};

#endif // LOTO_DASHBOARD_H
