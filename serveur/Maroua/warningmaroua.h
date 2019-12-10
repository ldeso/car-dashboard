#ifndef WARNINGMAROUA_H
#define WARNINGMAROUA_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include "objet_virtuel.h"
#include <QTest>

class warningmaroua : public objet_virtuel
{
public:
    warningmaroua();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void activate();
  int clignotant;
};

#endif // WARNINGMAROUA_H
