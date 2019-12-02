#ifndef LEO_GAUGE_H
#define LEO_GAUGE_H

#include "objet_virtuel.h"

class Leo_gauge : public objet_virtuel
{
public:
    Leo_gauge(objet_virtuel* parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    QRectF mBoundingRect;
};

#endif // LEO_GAUGE_H
