#ifndef WARNING_YOUSS_H
#define WARNING_YOUSS_H

#include "objet_virtuel.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTest>



class Warning_Youss : public objet_virtuel
{
public:
    Warning_Youss();
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    int clignotant;

    void Flashing();
};

#endif // WARNING_YOUSS_H
