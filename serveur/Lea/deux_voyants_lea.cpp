#include "deux_voyants_lea.h"
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

deux_voyants_lea::deux_voyants_lea(objet_virtuel *parent) :
    objet_virtuel(parent)
{

}

QRectF deux_voyants_lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);

    return rectf;
}

void deux_voyants_lea::paint(QPainter *painter, const QStyleOptionGraphicsItem* , QWidget* )
{
    if (getValue()==1)
  {   QPixmap voyant (chemin);
    QPixmap voyant2= voyant.scaled(taille1);
    painter->drawPixmap(x,y,voyant2);
  }
    else if (getValue()==2)
    {
        QPixmap voyant (chemin2);
        QPixmap voyant2 = voyant.scaled(taille1);
        painter->drawPixmap(x,y,voyant2);
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

void deux_voyants_lea::setSize(int w, int h)
{
    taille1=QSize(w,h);
}

void deux_voyants_lea::parametrage(int param_x, int param_y, QString param_chemin, QString param_chemin2)
{
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    chemin2=param_chemin2;
}
