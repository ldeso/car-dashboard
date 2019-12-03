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
    painter->setPen(QPen(brush,1));
    painter->drawEllipse(-660,-380,1320,760);

// fin designe elipse de fond
}


QRectF sceneDeFondHenri::boundingRect() const
{
    return QRect(-660,-360,1320,720);
}
