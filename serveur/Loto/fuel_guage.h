#ifndef FUEL_GUAGE_H
#define FUEL_GUAGE_H
#include "QGraphicsItem"
#include "QWidget"
#include "QPaintDevice"
#include "QColor"
#include "QGraphicsItem"
#include "qpainter.h"
#include "QPaintEvent"
#include "QBrush"


class fuel_guage : public QGraphicsItem
{
public:
    fuel_guage();
    QRectF boundingRect()const;
    double tankLevelLitres=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    const double pi=3.142;
    double getrotationAngle(double tankLevelLitres);

};

#endif // FUEL_GUAGE_H
