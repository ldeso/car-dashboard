#include "indicator_youss.h"



Indicator_Youss::Indicator_Youss(int param_x, int param_y, QString param_path, int param_width, int param_height, QColor param_color)
{
    x=param_x;
    y=param_y;
    path =param_path;
    width= param_width;
    height=param_height;
    value = 0;
    color = param_color;

}

QRectF Indicator_Youss::boundingRect() const
{
return QRectF(-600, -400, 1200, 800);
}

void Indicator_Youss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (getValue()==1)
  {
    QPixmap indic (path);
    QPixmap indic2= indic.scaled(width,height);
    QRadialGradient radialGrad(QPointF(x+width/2, y+height/2), width/2);
    radialGrad.setColorAt(0, color);
    radialGrad.setColorAt(1, Qt::transparent);
    QBrush brush(radialGrad);
    QPen pen (Qt::transparent);
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->setOpacity(0.7);
    painter->drawEllipse(x,y,width,height);
    painter->setOpacity(1);
    painter->drawPixmap(x,y,indic2);

  }
    else if (getValue()!=0)
    {
        QPen pen;
        QBrush brush;
        pen.setColor(Qt::transparent);
        brush.setColor(Qt::transparent);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawRect(x,y,30,30);
    }
    else
    {
        QPen pen;
        QBrush brush;
        pen.setColor(Qt::transparent);
        brush.setColor(Qt::transparent);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawRect(x,y,30,30);
    }

}




