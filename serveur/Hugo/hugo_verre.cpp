#include "hugo_verre.h"
#include <QPainter>
#include <QtMath>
#define pi 3.14159

hugo_verre::hugo_verre()
{

}

QRectF hugo_verre::boundingRect() const{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void hugo_verre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing);
    QRect carre(x-r,y-r,2*r,2*r);
    painter->setPen(QPen( QColor(0,0,0,0) ,1, Qt::SolidLine,Qt::FlatCap));
    if (a==1){
        QLinearGradient linearGrad(QPointF((x+r*qCos(135*pi/180)), (y-r*qSin(135*pi/180))), QPointF(x, y));
        linearGrad.setColorAt(0, QColor(255,255,255,80));
        linearGrad.setColorAt(1, QColor(0,0,0,0));
        QBrush brush(linearGrad);
        painter->setBrush(brush);
        painter->drawEllipse(carre);}
    else if (a==-1){
        QLinearGradient linearGrad(QPointF((x+r*qCos(135*pi/180)), (y-r*qSin(135*pi/180))), QPointF(x, y));
        linearGrad.setColorAt(0, QColor(255,255,255,30));
        linearGrad.setColorAt(1, QColor(0,0,0,0));
        QBrush brush(linearGrad);
        painter->setBrush(brush);
        painter->drawEllipse(carre);
    }

}

void hugo_verre::parametrage(int param_x, int param_y, int param_r,int param_a)
{
    x=param_x;
    y=param_y;
    r=param_r;
    a=param_a;
}
