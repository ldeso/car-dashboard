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
    float rpmValue=float(getValue());
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    const float pi=3.142f;
    float getRpmValue(float rpmValue);

};

#endif // TACHOMETRE_H
