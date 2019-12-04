#ifndef LEO_DISPLAY_H
#define LEO_DISPLAY_H

#include "objet_virtuel.h"

class Leo_display : public objet_virtuel
{
public:
    Leo_display(objet_virtuel* parent = nullptr);
    QRectF boundingRect() const override { return mBoundingRect; }
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
private:
    QRectF mBoundingRect = QRectF(0, 0, 60, 40);
    qreal mPenWidthPx = 2;
    int mFontSizePx = 25;
};

#endif // LEO_DISPLAY_H
