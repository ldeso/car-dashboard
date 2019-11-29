#ifndef JAUGECLIGNOTANT_H
#define JAUGECLIGNOTANT_H
#include "objet_virtuel.h"
#include <QTest>

class jaugeClignotantHenri : public objet_virtuel
{
public:
    jaugeClignotantHenri();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    int cligno;
    void MAJ();
};


#endif // JAUGECLIGNOTANT_H
