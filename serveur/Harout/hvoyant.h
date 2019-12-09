#ifndef HVOYANT_H
#define HVOYANT_H

#include "objet_virtuel.h"

class hvoyant : public objet_virtuel
{
public:
    hvoyant(int,int, QString,int red=255,int green=0,int blue=0,int param_size=30);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    int x,y,size=30;
    QString chemin;
    QColor couleur;
};

#endif // HVOYANT_H
