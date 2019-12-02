#ifndef LEA_SCENEDEFOND_H
#define LEA_SCENEDEFOND_H
#include <QGraphicsItem>
#include <QRectF>

class lea_sceneDeFond : public QGraphicsItem
{
public:
    lea_sceneDeFond(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LEA_SCENEDEFOND_H
