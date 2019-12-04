#ifndef NEEDLESPEED_H
#define NEEDLESPEED_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>


class needleSpeed : public QGraphicsItem
{
public:
    needleSpeed(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // NEEDLESPEED_H
