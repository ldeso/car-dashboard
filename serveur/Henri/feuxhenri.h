#ifndef FEUXHENRI_H
#define FEUXHENRI_H
#include "objet_virtuel.h"

class feuxHenri : public objet_virtuel
{
public:
    feuxHenri(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // FEUXHENRI_H
