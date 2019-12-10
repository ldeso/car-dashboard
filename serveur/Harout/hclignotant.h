#ifndef HCLIGNOTANT_H
#define HCLIGNOTANT_H
#include <QTest>
#include "objet_virtuel.h"

class hclignotant : public objet_virtuel
{
public:
    hclignotant();
//    int A = 250;
//    int B = 250;
//    QRectF rec     = QRectF(0,0, A, B);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void MAJ();

    int cligno;
private:


};

#endif // HCLIGNOTANT_H
