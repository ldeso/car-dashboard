#ifndef HUGO_VOYANT_WARNING_H
#define HUGO_VOYANT_WARNING_H
#include "objet_virtuel.h"


class hugo_voyant_warning : public objet_virtuel
{
public:
    hugo_voyant_warning();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    int cligno;
    void MAJ();
};

#endif // HUGO_VOYANT_WARNING_H
