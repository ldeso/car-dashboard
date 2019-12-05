///
///\file voyant_lea.cpp
/// \brief Classe permettant l'affichage de voyants dont l'état est allumé ou éteint
///

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

///
/// \brief voyant_Lea::voyant_Lea Constructeur permettant de paramétrer la position et l'image des voyants
/// \param param_x position horizontale
/// \param param_y position verticale
/// \param param_chemin chemin de la ressource
/// \param param_width contrôle de l'épaisseur du pixmap
/// \param param_height contrôle de la hauteur du pixmap
///

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
    QRectF rectf(0,0,1000,500);

    return rectf;
}

void voyant_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

///\brief Va chercher la valeur de la variable "valeur" de la classe mère. Si ==1, le voyant doit être affiché. Si ==0, le voyant doit être éteint
    if (getValue()==1)
  {
    QPixmap voyant (chemin);
    QPixmap voyant2= voyant.scaled(width,height);
    QRadialGradient radialGrad(QPointF(x+width/2, y+height/2), width/2);
    radialGrad.setColorAt(0, Qt::red);
    radialGrad.setColorAt(1, QColor(0,0,0,120));
    QBrush brush(radialGrad);
    painter->setBrush(brush);
    painter->drawPixmap(x,y,voyant2);
  //  painter->drawEllipse(x,y,width,height);
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


