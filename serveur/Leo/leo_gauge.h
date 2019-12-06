#ifndef LEO_GAUGE_H
#define LEO_GAUGE_H

#include "leo_object.h"

class Leo_gauge : public Leo_object {
public:
    Leo_gauge(const QRectF boundingRect, QGraphicsItem* parent = nullptr);
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    enum Data { MAX, DIVS, SUBDIVS, STARTANGLE, ARCLENGTH, WIDTH, FONT };
};

#endif // LEO_GAUGE_H
