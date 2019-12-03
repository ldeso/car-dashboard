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


class loto_dashboard : public QGraphicsItem
{
public:
    loto_dashboard();
    QRectF boundingRect()const;
    double speedValue=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    const double pi=3.142;
    double getSpeedAngle(double speedValue);
    void drawtachometertext(int theta);

};

#endif // LOTO_DASHBOARD_H
