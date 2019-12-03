#ifndef PHARES_LEA_H
#define PHARES_LEA_H
#include "objet_virtuel.h"

class phares_Lea : public QGraphicsItem
{
public:
    phares_Lea();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem* , QWidget* );
};

#endif // PHARES_LEA_H
