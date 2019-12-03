#include "tachometergauge_lea.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>


TachometerGauge_Lea::TachometerGauge_Lea(double param_x,double param_y, double param_r,int param_start, int param_end, int param_spanAngle, int param_graduation, int param_rpmMax )
{
    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    angle_fin = param_end;
    nb_graduation = param_graduation;
    span_angle=param_spanAngle;
    valueMax=param_rpmMax;
}

QRectF TachometerGauge_Lea::boundingRect() const
{
    QRectF rectf(-100,0,800,500);

    return rectf;
}

void TachometerGauge_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

    int v;
    if (value>=0 && value <=valueMax) {v=value;}
    else if (value<0) {v=0;}
    else {v=valueMax;}
    QPen pen;
    QBrush brush(Qt::SolidPattern);
  //  QRectF rect_tours_min (x-r,y-r,r*2,r*2);
    pen.setColor(Qt::black);
    painter->setPen(pen);
       painter->setRenderHint(QPainter::Antialiasing);
    //   painter->drawArc(rect_tours_min,angle_debut*16,span_angle*16);
       for (int i=0;i<=nb_graduation;i++)
       {
            int j;
           pen.setColor(Qt::white);
           pen.setWidth(2);
           painter->setPen(pen);
           if (i==0 || i==8 || i==15 || i==22 || i==29 || i==35 || i==41)
           {
               i==41 ? (j=i+1) : (j=i);                                        //i+1 quand on arrive a 41 pour pouvoir avoir 6 quand on le divise par 7
               pen.setWidth(4);
               pen.setColor(Qt::white);
               painter->setPen(pen);
               painter->drawText((x-10+(r-30)*(cos((angle_debut-(i*span_angle/nb_graduation))*pi/180))),(y+8-(r-30)*(sin((angle_debut-(i*span_angle/nb_graduation))*pi/180))),QString("%1").arg(j/7));
               pen.setColor(Qt::red);
               painter->setPen(pen);

           }
           painter->drawLine((x+r*(cos((angle_debut-(i*span_angle/nb_graduation))*pi/180))),(y-r*(sin((angle_debut-(i*span_angle/nb_graduation))*pi/180))),(x+(r-10)*(cos((angle_debut-(i*span_angle/nb_graduation))*pi/180))),(y-(r-10)*(sin((angle_debut-(i*span_angle/nb_graduation))*pi/180))));
       }



       painter->setRenderHints(QPainter::Antialiasing);
       pen.setWidth(1);
       pen.setColor(Qt::red);
       brush.setColor(Qt::red);
       pen.setJoinStyle(Qt::RoundJoin);
       painter->setPen(pen);
       painter->setBrush(brush);
       QPointF points[3] =
       {
             QPointF(x-9*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y+9*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180)),     //xc -9(taille rayon base aiguille)*cos (angle -90(angle droit aiguille))
             QPointF(x+r*(cos((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180)), y-r*(sin((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180))),
             QPointF(x+9*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y-9*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180))
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

// ******************** Dessine le gradient au dessus

   QRadialGradient radial(QPointF(x,y),r+10);
   radial.setColorAt(0,Qt::transparent);
   radial.setColorAt(0.98,Qt::blue);
   radial.setColorAt(1,Qt::transparent);
   painter->setPen(QPen(QBrush(radial),20,Qt::SolidLine,Qt::FlatCap));
   painter->drawArc((x-r-15),(y-r-15),(r*2)+35,(r*2)+35,angle_debut*16, -span_angle*16);



   // ******************** Dessine l'affichage de RPM

   QFont font2("Impact",10);
   pen.setColor(Qt::white);
   painter->setPen(pen);
   painter->setFont(font2);
   painter->drawText(x-50,y+75,"RPM x 1000");





}

int TachometerGauge_Lea::getValueMax()
{
    return valueMax;
}

void TachometerGauge_Lea::setValue(int v)
{
  //  value=v/1000;
}

void TachometerGauge_Lea::parametrage(double param_x, double param_y, double param_r, int param_start, int param_end, int param_spanAngle, int param_graduation,int param_rpmMax)
{
    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    angle_fin = param_end;
    nb_graduation = param_graduation;
    span_angle=param_spanAngle;
    valueMax=param_rpmMax;
}
