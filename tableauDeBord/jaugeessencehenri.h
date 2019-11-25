#ifndef JAUGEESSENCEHENRI_H
#define JAUGEESSENCEHENRI_H

#include "jaugevirtuel.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtMath>


class jaugeEssenceHenri : public jaugeVirtuel
{
public:
    jaugeEssenceHenri(jaugeVirtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // JAUGEESSENCEHENRI_H
