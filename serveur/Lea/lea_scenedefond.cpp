#include "lea_scenedefond.h"
#include <QPainter>

lea_SceneDeFond::lea_SceneDeFond(QGraphicsItem *parent):QGraphicsItem (parent)
{

}

QRectF lea_SceneDeFond::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}

void lea_SceneDeFond::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
//    QRadialGradient gradient(0, 0, 1000);
//    gradient.setColorAt(0, QColor("darkCyan"));
//    gradient.setColorAt(1, QColor("dark"));
//    QBrush brush(gradient);
    QBrush brush;
    QPen pen;
    pen.setColor(Qt::red);
    brush.setColor(Qt::transparent);
    painter->setBrush(brush);
    painter->setPen(pen);

    painter->drawEllipse(-100,0,1000,600);

}


