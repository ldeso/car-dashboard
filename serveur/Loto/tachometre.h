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
#include "objet_virtuel.h"


class tachometre : public objet_virtuel
{
public:
    tachometre();
    QRectF boundingRect()const;
    float rpmValue=getValue();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    const double pi=3.142;
    float getRpmValue(float rpmValue);

};

#endif // TACHOMETRE_H
