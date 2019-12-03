#ifndef LEO_INDICATOR_H
#define LEO_INDICATOR_H

#include "objet_virtuel.h"

class Leo_indicator : public objet_virtuel
{
public:
    Leo_indicator(QColor colorOff, QColor colorOn, objet_virtuel* parent = nullptr);
    QRectF boundingRect() const override { return mBoundingRect; }
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    QColor ColorOff;
    QColor ColorOn;
private:
    QRectF mBoundingRect = QRectF(0, 0, 25, 25);
    qreal PenWidthPx = 2;
};

#endif // LEO_INDICATOR_H
