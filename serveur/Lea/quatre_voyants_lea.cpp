#include "quatre_voyants_lea.h"
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

Quatre_Voyants_Lea::Quatre_Voyants_Lea(objet_virtuel *parent) :
   objet_virtuel(parent)
{

}

QRectF Quatre_Voyants_Lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);

    return rectf;
}

void Quatre_Voyants_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

    switch (on)
  {
    case 0:{
        QPen pen;
        QBrush brush;
        pen.setColor(Qt::transparent);
        brush.setColor(Qt::transparent);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawRect(x,y,30,30);
        break;
    }
    case 1:{
        QPixmap voyant (chemin);
        QPixmap voyant2= voyant.scaled(taille1);
        painter->drawPixmap(x,y,voyant2);
        break;
    }
    case 2:{
        QPixmap voyant (chemin2);
        QPixmap voyant3= voyant.scaled(taille1);
        painter->drawPixmap(x,y,voyant3);
        break;
    }
    case 3:{
        QPixmap voyant (chemin3);
        QPixmap voyant4= voyant.scaled(taille1);
        painter->drawPixmap(x,y,voyant4);
        break;
    }
    default:{
        QPen pen;
        QBrush brush;
        pen.setColor(Qt::transparent);
        brush.setColor(Qt::transparent);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawRect(x,y,30,30);
        break;
    }
  }

}

void Quatre_Voyants_Lea::setSize(int w, int h)
{
taille1=QSize(w,h);
}

void Quatre_Voyants_Lea::parametrage(int param_x, int param_y, QString param_chemin, QString param_chemin2, QString param_chemin3)
{
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    chemin2=param_chemin2;
    chemin3=param_chemin3;
}
