#ifndef CLIGNOTANT_H
#define CLIGNOTANT_H
#include "objet_virtuel.h"

class clignotant : public objet_virtuel
{
public:
    clignotant(QGraphicsItem *parent=nullptr);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void clignoter();
private:
    int temp;
};

#endif // CLIGNOTANT_H
