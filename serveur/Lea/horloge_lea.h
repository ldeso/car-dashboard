#ifndef HORLOGE_LEA_H
#define HORLOGE_LEA_H
#include "objet_virtuel.h"

class horloge_lea : public objet_virtuel
{
public:
    horloge_lea(int, int, int, int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int x;
    int y;
    int width;
    int height;

};

#endif // HORLOGE_LEA_H
