#ifndef JONAS_VOYANT_CLIGNOTANT_H
#define JONAS_VOYANT_CLIGNOTANT_H
#include "objet_virtuel.h"

class jonas_voyant_clignotant : public objet_virtuel
{
public:
    jonas_voyant_clignotant();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void updateTurn();

private:
    int enabled;
};

#endif // JONAS_VOYANT_CLIGNOTANT_H
