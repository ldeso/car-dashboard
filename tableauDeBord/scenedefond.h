#ifndef SCENEDEFOND_H
#define SCENEDEFOND_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class sceneDeFond : public QGraphicsItem
{
public:
    sceneDeFond(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SCENEDEFOND_H
