#ifndef JAUGEESSENCE_H
#define JAUGEESSENCE_H

#include "jaugevirtuel.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtMath>


class jaugeEssence : public jaugeVirtuel
{
public:
    jaugeEssence(jaugeVirtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int essence;
};

#endif // JAUGEESSENCE_H
