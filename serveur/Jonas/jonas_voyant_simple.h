#ifndef JONAS_VOYANT_SIMPLE_H
#define JONAS_VOYANT_SIMPLE_H
#include "objet_virtuel.h"


class jonas_voyant_simple : public objet_virtuel
{
public:
    jonas_voyant_simple();
    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
};

#endif // JONAS_VOYANT_SIMPLE_H
