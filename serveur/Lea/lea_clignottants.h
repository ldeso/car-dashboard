#ifndef LEA_CLIGNOTTANTS_H
#define LEA_CLIGNOTTANTS_H
#include "objet_virtuel.h"
#include <QTest>

class lea_clignottants : public objet_virtuel
{
public:
    lea_clignottants();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    int cligno;
    void MAJ();
};

#endif // LEA_CLIGNOTTANTS_H
