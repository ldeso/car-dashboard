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
#include "objet_virtuel.h"

class fuel_guage : public objet_virtuel
{
public:
    fuel_guage();
    QRectF boundingRect()const;
    float tankLevelLitres= float(getValue());
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    const float pi=3.142f;
    float getrotationAngle(float tankLevelLitres);


};

#endif // FUEL_GUAGE_H
