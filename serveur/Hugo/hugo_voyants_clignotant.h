#ifndef HUGO_VOYANTS_CLIGNOTANT_H
#define HUGO_VOYANTS_CLIGNOTANT_H
#include "hugo_voyants.h"
#include <QTest>


class hugo_voyants_clignotant : public hugo_voyants
{
public:
    hugo_voyants_clignotant();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    int cligno;
    void MAJ();
};

#endif // HUGO_VOYANTS_CLIGNOTANT_H

