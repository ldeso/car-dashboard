#ifndef CLIGNOTANT_H
#define CLIGNOTANT_H
#include "objet_virtuel.h"

class FlorianClignotant : public objet_virtuel
{
public:
    FlorianClignotant(QGraphicsItem *parent=nullptr);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void clignoter();
private:
    int temp;
};

#endif // CLIGNOTANT_H
