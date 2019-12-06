#ifndef LEO_GAUGE_H
#define LEO_GAUGE_H

#include "leo_object.h"

class Leo_gauge : public Leo_object {
public:
    Leo_gauge(QRectF boundingRect, int max = 100, int bigStep = 10, int smallStep = 10, QGraphicsItem* parent = nullptr);
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) final override;
private:
    qreal mPenWidth = 2;
    qreal mStartAngle = 215;
    qreal mArcLength = -250;
    int mBigStep;
    int mSmallStep;
};

#endif // LEO_GAUGE_H
