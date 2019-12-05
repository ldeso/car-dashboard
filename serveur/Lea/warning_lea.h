#ifndef WARNING_LEA_H
#define WARNING_LEA_H
#include "objet_virtuel.h"

class warning_lea : public objet_virtuel
{
public:
    warning_lea(int,int, QString, int, int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString chemin;
    int x,y;
    int width;
    int height;
};

#endif // WARNING_LEA_H
