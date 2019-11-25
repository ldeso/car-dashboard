#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class MyGraphicsitem : public QGraphicsItem
{
public:
    MyGraphicsitem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int angle=150;
    int angle_rpm=150;
};

#endif // MYGRAPHICSITEM_H
