#ifndef TACHOMETRE_H
#define TACHOMETRE_H
#include "QGraphicsItem"
#include "QWidget"
#include "QPaintDevice"
#include "QColor"
#include "QGraphicsItem"
#include "qpainter.h"
#include "QPaintEvent"
#include "QBrush"

class tachometre : public QGraphicsItem
{
public:
    tachometre();
    QRectF boundingRect()const;
    double rpmValue=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    const double pi=3.142;
    double getRpmValue(double rpmValue);

};

#endif // TACHOMETRE_H
