#ifndef LEA_SCENEDEFOND_H
#define LEA_SCENEDEFOND_H
#include <QGraphicsItem>
#include "scene_globale.h"

class lea_SceneDeFond: public QGraphicsItem
{
public:
    lea_SceneDeFond(QGraphicsItem *parent=nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // LEA_SCENEDEFOND_H
