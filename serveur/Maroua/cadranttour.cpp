#include "cadranttour.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>
#include "cadrantvitesse.h"


cadranttour::cadranttour(objet_virtuel *parent)
{

}
QRectF cadranttour::boundingRect() const
{
    QRectF rectf(-800,-500,1600,1000);
    return rectf;
}

void cadranttour::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    float pi = 3.14159265359;
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen;

    ///création des traits désignants le tour minute
   {
      for (int i=0;i<=40;i+=1)
      {
        if (i%5==0){
        pen.setWidthF(50);
        painter->setPen(QPen(QBrush("white"), 25, Qt::SolidLine, Qt::FlatCap));
        QRect rectTrait(-520,-330,400,400);
        painter->drawArc(rectTrait,(260-i*5)*16,5*3);}

        else{
        painter->setPen(QPen(QBrush("white"), 5, Qt::SolidLine, Qt::FlatCap));
        QRect rectTrait(-520,-330,400,400);
        painter->drawArc(rectTrait,(260-i*5)*16,5*3);}
        }
    }

   ///création des nombres désignants les tours minute
   { int j=0;
     for (float i=260*pi/180; i>=75*pi/180; i-=23*pi/180)
     {
        if(j<6){
        painter->setFont(QFont("arial", 15, -1,false));
        painter->setPen(QPen(QBrush("white") , 40, Qt::SolidLine));
        painter->drawText(qCos(i)*175-320,-qSin(i)*180-130,QString("%1").arg(j));
        j+=1;
        }
     else{

        painter->setFont(QFont("arial", 15, -1,false));
        painter->setPen(QPen(QBrush("red") , 40, Qt::SolidLine));
        painter->drawText(qCos(i)*170-320,-qSin(i)*160-130,QString("%1").arg(j));
        j+=1;
        }
     }
   }


  ///création de l'aiguille tour minute

  {
      ///définition des paramétres pour dessiner l'aiguille
      QPen pen;
      double xCentre=-320.0;
      double yCentre=-130.0;
      double angStartAig = 260;
      double c=cos((angStartAig-value)*pi/180);
      double s=sin((angStartAig-value)*pi/180);
      double xpos=xCentre+200*c;
      double ypos=yCentre-200*s;

  ///la création de l'aiguille
  pen.setWidth(1);
  pen.setColor("white");
  QBrush brushAig(Qt::SolidPattern);
  brushAig.setColor("dark red");
  painter->setPen(pen);
  painter->setBrush(brushAig);
  QPointF pts[3]= {
      QPointF(xCentre-5*cos((angStartAig-value*90)*pi/180),yCentre+5*sin((angStartAig-value*90)*pi/180)),
      QPointF(xpos, ypos),
      QPointF(xCentre+5*cos((angStartAig-value*90)*pi/180),yCentre-5*sin((angStartAig-value*90)*pi/180))};
  painter->drawConvexPolygon(pts, 3);}

    ///création du cercle autour de l'aiguille
  {QPen pen;
  pen.setColor("white");
  QBrush brush(Qt::SolidPattern);
  brush.setColor("white");
  painter->setPen(pen);
  painter->setBrush(brush);
  QRect recticone (-330, -150, 30, 30);
  painter->drawEllipse(recticone);}

  }











