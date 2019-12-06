#ifndef CADRANTCONTOUR_H
#define CADRANTCONTOUR_H


#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>

class cadrantcontour : public QGraphicsItem
{
public:
    cadrantcontour(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CADRANTESSENCE_H
