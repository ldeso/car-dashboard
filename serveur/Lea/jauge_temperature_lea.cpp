#include "jauge_temperature_lea.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>

jauge_temperature_lea::jauge_temperature_lea(double param_x, double param_y, double param_r, int param_start, int param_end, int param_spanAngle, int param_tempMax)
{
    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    angle_fin = param_end;
    span_angle=param_spanAngle;
    valueMax=param_tempMax;
    value=50;
}

QRectF jauge_temperature_lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);
    return rectf;
}

void jauge_temperature_lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (value>=50 && value <=valueMax) {v=qRound(value);}
    else if (value<50) {v=50;}
    else {v=valueMax;}
    QPen pen;
    QBrush brush(Qt::SolidPattern);

 // ******************** Dessine l'arc au dessus du compteur

    painter->setRenderHint(QPainter::Antialiasing);

            QRadialGradient radial(QPointF(x+5,y+5),r+15);
            radial.setColorAt(0,Qt::transparent);
            radial.setColorAt(0.95,Qt::blue);
            radial.setColorAt(1,Qt::transparent);
            painter->setPen(QPen(QBrush(radial),20,Qt::SolidLine,Qt::FlatCap));
            painter->drawArc(qRound(x-r-15),qRound(y-r-15),qRound(r*2)+35,qRound(r*2)+35,(angle_debut-2)*16,-(span_angle)*16);
     //met le span angle en negatif pour que l'arc soit déssiné dans le sens des aiguilles d'une montre
            pen.setColor(Qt::transparent);
            pen.setCapStyle(Qt::RoundCap);
            painter->setPen(pen);

 // ******************** Dessine les traits du compteur vitesse
       {     pen.setColor(Qt::white);
            for (int i=50; i<=temperature_max; i+=20)
            {
                if (i>90)
                    pen.setColor(Qt::red);
                pen.setWidth(2);
                pen.setCapStyle(Qt::FlatCap);
                pen.setStyle(Qt::SolidLine);
                painter->setPen(pen);
                painter->drawLine(qRound(x+r*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-r*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(x+(r-10)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-(r-10)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))));

                pen.setColor(Qt::white);
                painter->setPen(pen);
                painter->setRenderHint(QPainter::Antialiasing);
                QFont font("Arial",10, QFont::Bold);
                painter->setFont(font);
            if (i==50 || i==90 || i==130)
                {   pen.setWidth(5);
                if (i>90)
                    pen.setColor(Qt::red);
                if (i==50)
                    pen.setColor(Qt::blue);
                    painter->setPen(pen);
                    painter->drawLine(qRound(x+r*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-r*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(x+(r-15)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-(r-15)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))));
                    painter->drawText(qRound(x-17+(r-20)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y+8-(r-20)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),QString("%1").arg(i));
                }
            }
}

  // ******************** Dessine l'aiguille

            painter->setRenderHints(QPainter::Antialiasing);
            brush.setStyle(Qt::SolidPattern);
            pen.setWidth(1);
            pen.setColor(Qt::red);
            brush.setColor(Qt::red);
            pen.setJoinStyle(Qt::RoundJoin);
            painter->setPen(pen);
            painter->setBrush(brush);
            QPointF points[3] =
            {
                 QPointF(x-3*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y+3*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180)),     //xc -9(taille rayon base aiguille)*cos (angle -90(angle droit aiguille))
                 QPointF(x+r*(cos((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180)), y-r*(sin((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180))),
                 QPointF(x+3*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y-3*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180))
            };

            painter->drawConvexPolygon(points, 3);

  // ******************** Dessine le cercle au centre du cadran par dessus la fin de l'aiguille(deux cercles l'un sur l'autre avec un gradient linéaire inversé
                    pen.setColor(Qt::transparent);
                    QLinearGradient linearGradie(QPointF(x-15, y-15), QPointF(x+15, y-15));
                       linearGradie.setColorAt(0,"#9d0409" );
                       linearGradie.setColorAt(1,Qt::red);
                    QBrush brush9(linearGradie)  ;
                    painter->setPen(pen);
                    painter->setBrush(brush9);
                    painter->drawEllipse(x-10,y-10,20,20);

                brush.setColor(Qt::black);
                QLinearGradient linearGradi(QPointF(x+15, y+15), QPointF(x-15, y-15));
                   linearGradi.setColorAt(0, "#9d0409");
                   linearGradi.setColorAt(1,"#5e0407");
                QBrush brush8(linearGradi)  ;
                painter->setPen(pen);
                painter->setBrush(brush8);
                painter->drawEllipse(x-5,y-5,10,10);

 // ******************** Dessine le pixmap icone de température avec changement de couleur quand il dépasse les 90°


      if (value<95)
      {
          QPixmap voyant (":/Lea/Icones_Voyants/engineT_white.gif");
          QPixmap voyant2= voyant.scaled(40,40);
          painter->drawPixmap(x-35,y-90,voyant2);
      }
      else
      {
          QPixmap voyant (":/Lea/Icones_Voyants/engineT_red.gif");
          QPixmap voyant2= voyant.scaled(40,40);
          painter->drawPixmap(x-35,y-90,voyant2);
      }



}
