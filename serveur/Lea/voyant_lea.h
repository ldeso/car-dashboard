#ifndef VOYANT_LEA_H
#define VOYANT_LEA_H
#include <QString>
#include <QGraphicsItem>
#include <QRectF>
#include "objet_virtuel.h"

class voyant_Lea: public objet_virtuel
{
public:
    voyant_Lea(int,int, QString, int, int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString chemin;
    int x,y,on=0;
    int width;
    int height;
   // void setSize(int, int);
    virtual void parametrage(int param_x,int param_y, QString param_chemin);
};

#endif // VOYANT_LEA_H
