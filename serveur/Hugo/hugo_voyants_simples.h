#ifndef HUGO_VOYANTS_SIMPLES_H
#define HUGO_VOYANTS_SIMPLES_H

#include "objet_virtuel.h"



class hugo_voyants_simples : public objet_virtuel
{
public:
    hugo_voyants_simples();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    virtual void parametrage(int param_x,int param_y, QString param_chemin,int red=255,int green=0,int blue=0);

protected:
    int x,y;
    QString chemin;
    QColor couleur;
};

#endif // HUGO_VOYANTS_SIMPLES_H
