#ifndef LEO_GAUGE_H
#define LEO_GAUGE_H

#include "objet_virtuel.h"

class Leo_gauge : public objet_virtuel
{
public:
    Leo_gauge(objet_virtuel* parent = nullptr) : objet_virtuel(parent) {}
    QRectF boundingRect() const override { return mBoundingRect; }
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override {}
private:
    const QRectF mBoundingRect = QRectF(0, 0, 100, 100);
};

#endif // LEO_GAUGE_H
