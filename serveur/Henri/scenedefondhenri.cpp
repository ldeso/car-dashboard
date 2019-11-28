#include "scenedefondhenri.h"
#include <QPainter>

sceneDeFondHenri::sceneDeFondHenri(QGraphicsItem *parent):QGraphicsItem (parent)
{

}

void sceneDeFondHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
//  Designe de l'elipse de fond

    QRadialGradient gradient(0, 0, 1000);
    gradient.setColorAt(0, QColor("darkCyan"));
    gradient.setColorAt(1, QColor("dark"));
    QBrush brush(gradient);
    painter->setBrush(brush);
    painter->drawEllipse(-800,-500,1600,1000);

// fin designe elipse de fond
}


QRectF sceneDeFondHenri::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}
