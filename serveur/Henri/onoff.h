#ifndef ONOFF_H
#define ONOFF_H
#include "objet_virtuel.h"

class onoff : public objet_virtuel
{
public:
    onoff(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ONOFF_H
