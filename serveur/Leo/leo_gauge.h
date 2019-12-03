#ifndef LEO_GAUGE_H
#define LEO_GAUGE_H

#include "objet_virtuel.h"

class Leo_gauge : public objet_virtuel
{
public:
    Leo_gauge(int maxValue, int spacing, objet_virtuel* parent = nullptr);
    QRectF boundingRect() const override { return mBoundingRect; }
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
private:
    const qreal mSizePx = 250;
    const QRectF mBoundingRect = QRectF(
        -0.5 * mSizePx, -0.5 * mSizePx, mSizePx, mSizePx
    );
    qreal mPenWidthPx = 2;
    qreal mBottomAngle = 90;
    qreal mTickSizePx = 15;
    QColor mColor = Qt::lightGray;
    int mFontSizePx = 25;
    int mNeedleSizePx = 60;
    int mSpacing = 20;
};

#endif // LEO_GAUGE_H
