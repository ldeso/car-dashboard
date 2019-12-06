#ifndef LEO_OBJECT_H
#define LEO_OBJECT_H

#include "objet_virtuel.h"

class Leo_object : public objet_virtuel
{
public:
    Leo_object(const QRectF boundingRect, QGraphicsItem* parent = nullptr);
    virtual QRectF boundingRect() const final override;
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override = 0;
protected:
    QRectF mBoundingRect;
};

#endif // LEO_OBJECT_H
