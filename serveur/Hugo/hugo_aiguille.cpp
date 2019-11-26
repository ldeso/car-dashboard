#include "hugo_aiguille.h"
#include <QtMath>
#include <QPainter>

#define pi 3.14159

/*hugo_Aiguille::hugo_Aiguille()
{

}*/

QRectF hugo_Aiguille::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void hugo_Aiguille::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing);
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

void hugo_Aiguille::parametrage(int param_x, int param_y, int param_r,int param_start, int param_end, int param_value)
{
    x=param_x;
    y=param_y;
    r=param_r;
   start=param_start;
   end=param_end;
   value=param_value;
}

int hugo_Aiguille::getValueMax()
{
    return value;
}

int hugo_Aiguille::getValue()
{
    return value*1.0*(angle+(start-360))/(start-end);
}

void hugo_Aiguille::setValue(int v)
{
    angle=((1.0*(start-end))/(value*1.0))*v*1.0+(360-start);
}
