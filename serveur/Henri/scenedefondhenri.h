#ifndef SCENEDEFONDHENRI_H
#define SCENEDEFONDHENRI_H

#include "scenedefond.h"

class sceneDeFondHenri : public QGraphicsItem
{
public:
    sceneDeFondHenri(QGraphicsItem *parent=nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // SCENEDEFONDHENRI_H
