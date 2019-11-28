#ifndef HUGO_VOYANTS_CLIGNOTANT_H
#define HUGO_VOYANTS_CLIGNOTANT_H
#include "objet_virtuel.h"
#include <QTest>


class hugo_voyants_clignotant : public objet_virtuel
{
public:
    hugo_voyants_clignotant();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    int cligno;
    void MAJ();
};

#endif // HUGO_VOYANTS_CLIGNOTANT_H

