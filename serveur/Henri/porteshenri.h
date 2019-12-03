#ifndef PORTESHENRI_H
#define PORTESHENRI_H
#include "objet_virtuel.h"
#include "onoff.h"


class portesHenri : public objet_virtuel
{
public:
    portesHenri(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    onoff* DD;
    onoff* DG;
    onoff* PG;
    onoff* PD;
    onoff* C;
};

#endif // PORTESHENRI_H
