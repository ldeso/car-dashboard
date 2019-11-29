#ifndef HUGO_VOYANTS_SIMPLES_H
#define HUGO_VOYANTS_SIMPLES_H

#include "objet_virtuel.h"



class hugo_voyants_simples : public objet_virtuel
{
public:
    hugo_voyants_simples(int,int, QString,int red=255,int green=0,int blue=0,int param_size=30);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    int x,y,size=30;
    QString chemin;
    QColor couleur;
};

#endif // HUGO_VOYANTS_SIMPLES_H
