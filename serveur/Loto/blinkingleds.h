#ifndef BLINKINGLEDS_H
#define BLINKINGLEDS_H
#include "leds.h"




class blinkingleds : public objet_virtuel
{
public:
    blinkingleds();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

private:

    int blinker;
    void blinkled();
};

#endif // BLINKINGLEDS_H
