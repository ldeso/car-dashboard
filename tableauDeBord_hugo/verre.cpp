#include "verre.h"
#include <QPainter>
#include <QtMath>
#define pi 3.14159

verre::verre()
{

}

QRectF verre::boundingRect() const{
qreal penWidth = 5;
return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void verre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     QRect carre(x-r,y-r,2*r,2*r);
    painter->setPen(QPen( QColor(0,0,0,0) ,1, Qt::SolidLine,Qt::FlatCap));
    QLinearGradient linearGrad(QPointF(x+r*qCos(135*pi/180), y-r*qSin(135*pi/180)), QPointF(x, y));
    linearGrad.setColorAt(0, QColor(255,255,255,127));
    linearGrad.setColorAt(1, QColor(0,0,0,127));
    QBrush brush(linearGrad);
    painter->setBrush(brush);
    painter->drawEllipse(carre);
}

void verre::parametrage(int param_x, int param_y, int param_r)
{
    x=param_x;
    y=param_y;
    r=param_r;
}
