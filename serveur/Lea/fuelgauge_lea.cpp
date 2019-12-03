#include "fuelgauge_lea.h"
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

FuelGauge_lea::FuelGauge_lea(double param_x, double param_y, double param_width, double param_height, double param_x2, double param_y2, double param_x3, double param_y3)
{
    x=param_x;
    y=param_y;
    width=param_width;
    height=param_height;
    x2=param_x2;
    y2=param_y2;
    x3=param_x3;
    y3=param_y3;
}

QRectF FuelGauge_lea::boundingRect() const
{
    QRectF rectf(-100,0,800,500);

    return rectf;
}

void FuelGauge_lea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    QPen pen;
    QBrush brush(Qt::SolidPattern);
    painter->setRenderHint(QPainter::Antialiasing);
    pen.setColor(Qt::white);
    brush.setColor(Qt::transparent);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(x,y,width,height);

    std::vector<QLineF> vector_line;
    for(int j=0; j<6; j++)
        vector_line.push_back(QLineF((x-10),((y+height)-j*(height/5)),x,((y+height)-j*(height/5))));
    for (int j=0; j<6; j++)
        painter->drawLine(vector_line[j]);

    brush.setColor(Qt::white);
    pen.setColor(Qt::transparent);
    painter->setBrush(brush);
    painter->setPen(pen);

    std::vector<QRectF> vector_rect;
    if (value<25)
    {
        brush.setColor(Qt::red);
        painter->setBrush(brush);
     }
    for(int i=0; i<10; i++)
        vector_rect.push_back(QRectF((x+3),(((y+height)-7)-i*(height/10)),(width-6),((height/10)-3)));   //rentre les différents rectangles de la jauge d'escence
    for (int i=0;i<qRound(value*0.1f);i++)                           //value donnee en pourcentage et transformée en ordre d'entrée dans la liste du vecteur
        painter->drawRect(vector_rect[i]);
    pen.setColor(Qt::white);
    painter->setPen(pen);
    painter->drawText(x2,y2,"E");
    painter->drawText(x3,y3,"F");


    // ******************** Dessine l'icone blanche ou rouge de l'escence

    if (value<25)
    {
        QPixmap voyant (":/Lea/Icones_Voyants/fuelL_red.gif");
        QPixmap voyant2= voyant.scaled(40,40);
        painter->drawPixmap(x-70,y+70,voyant2);
    }
    else
    {
     QPixmap voyant (":/Lea/Icones_Voyants/fuelL_white.gif");
     QPixmap voyant2= voyant.scaled(40,40);
     painter->drawPixmap(x-70,y+70,voyant2);
    }




}

void FuelGauge_lea::setValue(int v)
{
    value = v;

}

void FuelGauge_lea::parametrage(double param_x, double param_y, double param_width, double param_height, double param_x2, double param_y2, double param_x3, double param_y3)
{
    x=param_x;
    y=param_y;
    width=param_width;
    height=param_height;
    x2=param_x2;
    y2=param_y2;
    x3=param_x3;
    y3=param_y3;

}
