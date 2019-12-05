#ifndef LEO_LABEL_H
#define LEO_LABEL_H

#include "objet_virtuel.h"

class Leo_label : public QGraphicsSimpleTextItem
{
public:
    explicit Leo_label(const QString &text, const QRectF boundingRect, QGraphicsItem* parent=nullptr)
        : QGraphicsSimpleTextItem(text, parent), mText(text), mBoundingRect(boundingRect)
    {}
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;
private:
    const QString mText;
    const QRectF mBoundingRect;
};

#endif // LEO_LABEL_H
