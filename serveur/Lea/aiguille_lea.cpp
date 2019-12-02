#include "aiguille_lea.h"
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

aiguille_Lea::aiguille_Lea(QGraphicsItem *parent):
    QGraphicsItem(parent)
{

}

QRectF aiguille_Lea::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}

void aiguille_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int v;
    if (vitesse>=0 && vitesse <=vitesse_max) {v=vitesse;}
    else if (vitesse<0) {v=0;}
    else {v=vitesse_max;}

    QPen pen;
    QBrush brush(Qt::SolidPattern);
    painter->setRenderHints(QPainter::Antialiasing);
    pen.setWidth(1);
    pen.setColor(Qt::red);
    brush.setColor(Qt::red);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(brush);
    QPointF points[3] =
    {
          QPointF(x-r*cos((angle_depart-(angle_fin*1.0f/vitesse_max)*vitesse-90)*pi/180),y+r*sin((angle_depart-(angle_fin*1.0f/vitesse_max)*vitesse-90)*pi/180)),     //xc -9(taille rayon base aiguille)*cos (angle -90(angle droit aiguille))
          QPointF(x+taille_aiguille*(cos((angle_depart-(angle_fin*1.0f/vitesse_max)*vitesse)*pi/180)), y-taille_aiguille*(sin((angle_depart-(angle_fin*1.0f/vitesse_max)*vitesse)*pi/180))),
          QPointF(x+r*cos((angle_depart-(angle_fin*1.0f/vitesse_max)*vitesse-90)*pi/180),y-r*sin((angle_depart-(angle_fin*1.0f/vitesse_max)*vitesse-90)*pi/180))
     };

    painter->drawConvexPolygon(points, 3);


// ******************** Dessine le cercle au centre du cadran par dessus la fin de l'aiguille
    pen.setColor(Qt::transparent);
    QLinearGradient linearGradie(QPointF(385, 185), QPointF(415, 215));
       linearGradie.setColorAt(0,"#9d0409" );
       linearGradie.setColorAt(1,Qt::red);
    QBrush brush9(linearGradie)  ;
    painter->setPen(pen);
    painter->setBrush(brush9);
    painter->drawEllipse(x-20,y-20,40,40);

brush.setColor(Qt::black);
QLinearGradient linearGradi(QPointF(415, 215), QPointF(385, 185));
   linearGradi.setColorAt(0, "#9d0409");
   linearGradi.setColorAt(1,"#5e0407");
QBrush brush8(linearGradi)  ;
painter->setPen(pen);
painter->setBrush(brush8);
painter->drawEllipse(x-15,y-15,30,30);


}

int aiguille_Lea::getValueMax()
{
    return vitesse_max;
}

void aiguille_Lea::setValue(int v)
{
    vitesse=v;
}

void aiguille_Lea::parametrage(double param_x,double param_y, double param_r, double param_t ,int param_start, int param_end, int param_value)
{
    x= param_x;
    y= param_y;
    r= param_r;
    taille_aiguille= param_t;
    angle_depart= param_start;
    angle_fin= param_end;
    vitesse_max=param_value;
}
