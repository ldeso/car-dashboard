#ifndef CADRANTESSENCE_H
#define CADRANTESSENCE_H


#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QGraphicsView>

class cadrantessence : public QGraphicsItem
{
public:
    cadrantessence(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int niveauessence;
};

#endif // CADRANTESSENCE_H
