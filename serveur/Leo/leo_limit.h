#ifndef LEO_LIMIT_H
#define LEO_LIMIT_H

#include "leo_object.h"

class Leo_limit : public Leo_object {
public:
    Leo_limit(const QRectF boundingRect, QGraphicsItem* parent = nullptr);
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    enum Data { LIMITS, FONT, WIDTH, BLINKS, PERIOD };
};

#endif // LEO_LIMIT_H
