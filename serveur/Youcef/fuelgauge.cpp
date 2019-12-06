#include "fuelgauge.h"
#include <QtMath>
#include <QGraphicsTextItem>
#include <QStringList>

FuelGauge::FuelGauge(QGraphicsItem *parent)
{

}

QRectF FuelGauge::boundingRect() const
{
   return QRectF(-600, -400, 1200, 800);
}

void FuelGauge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     painter->setRenderHint(QPainter::Antialiasing);

     {
     QRect RectSpeed (100,-300, 405, 405);


     int startAngle= 244*16;
     int spanAngle= -63*16;
     painter->setPen(QPen(QBrush("red"), 4, Qt::SolidLine,Qt::RoundCap,Qt::BevelJoin));

      QPolygonF polygon;
      QPainterPath rectPath;
      rectPath.moveTo(102,-64);
      rectPath.lineTo(20,-64);
      rectPath.lineTo(20, 85);
      rectPath.lineTo(212,85);
      rectPath.arcTo(RectSpeed,244, -50);
      rectPath.closeSubpath();
      rectPath.addPolygon(polygon);

      QRadialGradient gradient(119, -4.5, 200);
      gradient.setColorAt(0, QColor(0,0,0,0));
      gradient.setColorAt(0.5, QColor("dark blue"));
      gradient.setColorAt(1, QColor("dark"));
      QBrush brush(gradient);
      painter->setBrush(brush);
      painter->drawPath(rectPath);

     }

     {
         QPen pen ;
         pen.setWidth(2);
         pen.setColor("#DF3A01");
         painter->setPen(pen);

         QBrush NeedleColor("#DF3A01",Qt::SolidPattern);
         painter->setBrush(NeedleColor);

         for (int i=0;i<=9;i++)
         {
           float x1,y1;int r=15;
           x1=260+195*(cos((170-(i*4.8))*pi/180));
           y1=-90+195*(sin((170-(i*4.8))*pi/180));
           painter->drawRoundedRect(x1,y1,2*r,r/2,2,2);
         }
      }
      {
         QRect RectSpeed (53,-350, 505, 505);


         int startAngle= 222*16;
         int spanAngle= -32.5*16;
         int spanAngle1 = -7.5*16;

         painter->setPen(QPen(QBrush("dark"), 5, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
         painter->drawArc(RectSpeed,startAngle,spanAngle);
         painter->drawLine(QPoint(40,-53),QPoint(55,-53));
         painter->drawLine(QPoint(60,16),QPoint(80,16));
         painter->drawLine(QPoint(53,-17),QPoint(65,-17));

         painter->setPen(QPen(QBrush("red"), 5, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
         painter->drawLine(QPoint(85,45),QPoint(99,45));
         painter->drawArc(RectSpeed,startAngle,spanAngle1);
         painter->drawLine(QPoint(95,70),QPoint(115,70));

         painter->setFont(QFont("ariel", 15,  QFont::Bold, false));
         painter->setPen(QPen(QBrush("dark") ,10, Qt::SolidLine,Qt::FlatCap));
         painter->drawText(25,-45, "F");
         painter->setPen(QPen(QBrush("red") ,10, Qt::SolidLine,Qt::FlatCap));
         painter->drawText(75, 75, "E");


     }


}
