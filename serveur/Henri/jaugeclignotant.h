#ifndef JAUGECLIGNOTANT_H
#define JAUGECLIGNOTANT_H
#include "jaugevirtuel.h"
#include <QTest>

class jaugeClignotant : public jaugeVirtuel
{
public:
    jaugeClignotant();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    int cligno;
    void MAJ();
};


#endif // JAUGECLIGNOTANT_H
