///
///\file warning_lea.cpp
///\brief Classe dérivée de objet_virtuel permettant l'affichage d'un voyant warning clignotant
///
///

#include "warning_lea.h"

warning_lea::warning_lea(int param_x, int param_y, QString param_chemin, int param_width, int param_height)
{   x=param_x;
    y=param_y;
    chemin=param_chemin;
    width= param_width;
    height=param_height;

}

QRectF warning_lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);
    return rectf;
}

void warning_lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (getValue()==1)
  {
    QPixmap voyant (chemin);
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
