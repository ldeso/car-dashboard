#include "voyant_lea.h"
#include <iostream>
#include <vector>
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>
#include <QPixmap>

voyant_Lea::voyant_Lea(int param_x, int param_y, QString param_chemin, int param_width, int param_height)
{
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    width= param_width;
    height=param_height;

}

QRectF voyant_Lea::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}

void voyant_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if (getValue()==1)
  {   QPixmap voyant (chemin);
    QPixmap voyant2= voyant.scaled(width,height);
    painter->drawPixmap(x,y,voyant2);
  }
    else if (getValue()==0)
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

//void voyant_Lea::setSize(int w, int h)
//{
//   taille1=QSize(w,h);


//}

void voyant_Lea::parametrage(int param_x, int param_y, QString param_chemin)
{
    x=param_x;
    y=param_y;
    chemin=param_chemin;

}
