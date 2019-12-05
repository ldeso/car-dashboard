#ifndef COMPTEURKMINNA_H
#define COMPTEURKMINNA_H
#include "objet_virtuel.h"

class compteurKmInna : public objet_virtuel
{
public:
    compteurKmInna(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // COMPTEURKMINNA_H
