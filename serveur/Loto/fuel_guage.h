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
    double tankLevelLitres=getValue();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    const double pi=3.142;
    double getrotationAngle(double tankLevelLitres);

private:
    bool blink=false;
    void blinker();


};

#endif // FUEL_GUAGE_H
