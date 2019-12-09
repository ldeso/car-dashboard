#include "cadrantvitesse.h"
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>
#include <QDateTime>
#include "objet_virtuel.h"

cadrantvitesse::cadrantvitesse(objet_virtuel *parent)
{
    value = 0;
}

QRectF cadrantvitesse::boundingRect() const
{
    QRectF rectf(-800,-500,1600,1000);
    return rectf;
}

void cadrantvitesse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //définition des paramétres :

       painter->setRenderHint(QPainter::Antialiasing);

       float pi = 3.14159265359;
       double xCentre=0.0;
       double yCentre=0.0;
       double angStart = 220;
       double c=cos((angStart-value)*pi/180);
       double s=sin((angStart-value)*pi/180);
       double xpos=xCentre+280*c;
       double ypos=yCentre-280*s;
       //création aiguille calcul Vitesse

           {int vitesse =0;
           QPen pen;
           pen.setWidth(1);
           pen.setColor("white");
           QBrush brushAig(Qt::SolidPattern);
           brushAig.setColor("#DF0101");
           painter->setPen(pen);
           painter->setBrush(brushAig);


           QPointF pts[3]= {
               QPointF(-9*cos((angStart-value-90)*pi/180),9*sin((angStart-value-90)*pi/180)),
               QPointF(xpos, ypos),
               QPointF(+9*cos((angStart-value-90)*pi/180),-9*sin((angStart-value-90)*pi/180))
           };
            painter->drawConvexPolygon(pts, 3);}


               {QPen pen;
               pen.setColor("dark");
               QBrush brush(Qt::SolidPattern);
               brush.setColor("dark");
               painter->setPen(pen);
               painter->setBrush(brush);
               painter->drawEllipse(-120,-120,240,240);
               }

          { painter->setFont(QFont("arial", 45, -1,false));
           painter->setPen(QPen(QBrush("white") ,45, Qt::SolidLine,Qt::FlatCap));
           painter->drawText(-45,20, QString("%1").arg(value));
           painter->setFont(QFont("arial", 10, -1,false));
           painter->setPen(QPen(QBrush("white") ,10, Qt::SolidLine,Qt::FlatCap));
           painter->drawText(30, 40, "km/h");}



      //création des traits désignants la vitesse
      {QPen pen;
      for (int i=0;i<=260;i+=10)
      {
         if (i%20==0)
          {
          pen.setWidthF(35);
          painter->setPen(QPen(QBrush("white"), 30, Qt::SolidLine, Qt::FlatCap));
          QRect rectTrait(-210,-210,420,420);
          painter->drawArc(rectTrait,(220-i)*16,19.28*0.8);}

         if(i%20!=0){
             pen.setWidthF(15);
             pen.setColor("white");
             pen.setCapStyle(Qt::FlatCap);
             pen.setStyle(Qt::SolidLine);
             painter->setPen(pen);
             QRect rectTrait(-210,-210,420,420);
             painter->drawArc(rectTrait,(220-i)*16,19.28*0.8);
         }

      }
      }
      //création des nombres désignants la vitesse
      {int j=0;
      for (float i=220*pi/180; i>-45*pi/180; i-=20*pi/180)
      {
          QPen pen;
          painter->setFont(QFont("arial", 16, -1,false));
          painter->setPen(QPen(QBrush("white") , 10, Qt::SolidLine));
          painter->drawText(qCos(i)*255-10,-qSin(i)*255+10,QString("%1").arg(j));
          j+=20;

       }
      }

      {QRect rectHeure(-50,140,200,100);
          painter->setPen(QPen(QBrush("white"), 5, Qt::SolidLine));
        painter->setFont(QFont("Bullpen Italic ", 20,QFont::Bold, Qt::AlignVCenter));
        QString stime = QDateTime::currentDateTime().toString("hh:mm");
      painter->drawText(rectHeure,stime);
      }

      {QRect rectDate(-65,170,200,100);
          painter->setPen(QPen(QBrush("white"), 5, Qt::SolidLine));
        painter->setFont(QFont("Bullpen Italic ", 20, Qt::AlignVCenter,false));
        QString sDate = QDateTime::currentDateTime().toString("dd/MM/yy");
      painter->drawText(rectDate,sDate);}

}