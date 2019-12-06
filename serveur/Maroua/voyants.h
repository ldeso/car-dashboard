#ifndef VOYANTS_H
#define VOYANTS_H
#include "objet_virtuel.h"
#include <QPainter>

class Voyants : public objet_virtuel
{

public:
    Voyants(QString , int, int , int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int x;
    int y;
    int size;
    QString path;


};

#endif // VOYANTS_H
