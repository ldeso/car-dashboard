#ifndef LEDS_H
#define LEDS_H
#include "QGraphicsItem"
#include "QGraphicsItem"
#include "QWidget"
#include "QPaintDevice"
#include "QColor"
#include "QGraphicsItem"
#include "qpainter.h"
#include "QPaintEvent"
#include "QBrush"
#include "objet_virtuel.h"

class LEDS : public objet_virtuel
{
public:
    LEDS(int, int, QString iconPathString, int red=235, int green=0, int blue =0, int icon_size=30);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect()const;

private:
    int posX,posY, size =30;
    QString iconPath;
    QColor ledColor;




};

#endif // LEDS_H
