#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class hugo_MyGraphicsitem : public QGraphicsItem
{
public:
    hugo_MyGraphicsitem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int current_speed=0;
    QString station="";
    float km=0.0;
};

#endif // MYGRAPHICSITEM_H
