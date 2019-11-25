#include "scenedefond.h"

sceneDeFond::sceneDeFond(QGraphicsItem *parent):QGraphicsItem(parent)
{

}

QRectF sceneDeFond::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}



void sceneDeFond::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

//  Designe de l'elipse de fond //////////////////////////////////////////////////////////////
    QRadialGradient gradient(0, 0, 1000);
    gradient.setColorAt(0, QColor("darkCyan"));
    gradient.setColorAt(1, QColor("dark"));
    QBrush brush(gradient);
    painter->setBrush(brush);
    painter->drawEllipse(-800,-500,1600,1000);
// fin designe elipse de fond //////////////////////////////////////////////////////////////

}
