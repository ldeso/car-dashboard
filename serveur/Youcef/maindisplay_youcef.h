#ifndef MAINDISPLAY_YOUCEF_H
#define MAINDISPLAY_YOUCEF_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "objet_virtuel.h"
#include <QGraphicsItem>

class MainDisplay_Youcef : public QGraphicsItem
{
public:
    MainDisplay_Youcef(QGraphicsItem *parent=nullptr);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // MAINDISPLAY_YOUCEF_H
