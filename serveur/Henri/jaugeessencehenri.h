#ifndef JAUGEESSENCEHENRI_H
#define JAUGEESSENCEHENRI_H

#include "objet_virtuel.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtMath>


class jaugeEssenceHenri : public objet_virtuel
{
public:
    jaugeEssenceHenri(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // JAUGEESSENCEHENRI_H
