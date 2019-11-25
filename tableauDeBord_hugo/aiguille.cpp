#include "aiguille.h"
#include <QtMath>
#include <QPainter>

#define pi 3.14159

Aiguille::Aiguille()
{

}

QRectF Aiguille::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void Aiguille::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QColor(Qt::darkGray) , 2, Qt::SolidLine,Qt::FlatCap));
    QRect carre_aiguille(x-10,y-10,20,20);
    painter->drawArc(carre_aiguille,0,360*16);
    //Création de l'aiguille
    QPointF points[4]={
        QPointF(x,y),
        QPointF(x+(r/4)*qCos((angle+8)*pi/180),y+(r/4)*qSin((angle+8)*pi/180)),
        QPointF(x+r*qCos(angle*pi/180),y+r*qSin(angle*pi/180)),
        QPointF(x+(r/4)*qCos((angle-8)*pi/180),y+(r/4)*qSin((angle-8)*pi/180)),
    };
    //Affichage de l'aiguille
    painter->setPen(QPen(QColor(Qt::white), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setBrush(QColor(Qt::darkRed));
    painter->drawPolygon(points,4);
}

void Aiguille::parametrage(int param_x, int param_y, int param_r)
{
    x=param_x;
    y=param_y;
    r=param_r;
}
