#ifndef JONAS_VOYANT_WARNING_H
#define JONAS_VOYANT_WARNING_H
#include "objet_virtuel.h"

class jonas_voyant_warning : public objet_virtuel
{
public:
    jonas_voyant_warning();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    int enabled;
    void updateWarning();
};

#endif // JONAS_VOYANT_WARNING_H
