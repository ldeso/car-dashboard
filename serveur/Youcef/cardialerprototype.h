#ifndef CARDIALERPROTOTYPE_H
#define CARDIALERPROTOTYPE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>


class CarDialerPrototype : public QGraphicsItem
{
public:
    CarDialerPrototype(QGraphicsItem *parent=nullptr);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // CARDIALERPROTOTYPE_H
