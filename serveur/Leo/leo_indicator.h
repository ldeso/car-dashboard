#ifndef LEO_INDICATOR_H
#define LEO_INDICATOR_H

#include "objet_virtuel.h"

class Leo_indicator : public objet_virtuel
{
public:
    Leo_indicator(objet_virtuel* parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QRectF mBoundingRect;
};

#endif // LEO_INDICATOR_H
