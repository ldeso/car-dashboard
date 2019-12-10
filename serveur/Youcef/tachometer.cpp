#include "tachometer.h"
#include <QtMath>
#include <QGraphicsItem>

Tachometer::Tachometer(objet_virtuel *)
{
value=0;
}

QRectF Tachometer::boundingRect() const
{
 return QRectF(-600, -400, 1200, 800);
}

void Tachometer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)

{
 painter->setRenderHint(QPainter::Antialiasing);

    {
    QRadialGradient gradient(-295, -95, 200);

    gradient.setColorAt(0, QColor(0,204,255));
    gradient.setColorAt(0.2, QColor("dark blue"));
    gradient.setColorAt(1, QColor("dark"));
    QBrush brush(gradient);
    painter->setBrush(brush);
    painter->drawEllipse(-482,-282, 369, 369);
    }

    {
    QRect RectSpeed (-482,-282, 369, 369);

    int startAngle= 0*16;
    int spanAngle=  360*16;
    painter->setPen(QPen(QBrush("red"), 4, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
    painter->drawArc(RectSpeed,startAngle,spanAngle);
    }





    {
    QRect RectSpeed (-478,-278, 360, 360);


    int startAngle= 0*16;
    int spanAngle=  360*16;
    painter->setPen(QPen(QBrush("white"), 4, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
    painter->drawArc(RectSpeed,startAngle,spanAngle);
    }


    /*Build an Tachometer Arc   */

    {
    QRect RectSpeed (-400,-200, 210, 210);


    int startAngle= 220*16;
    int spanAngle= -260*16;
    painter->setPen(QPen(QBrush("White"), 8, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
    painter->drawArc(RectSpeed,startAngle,spanAngle);
    }

    /* for the red Arc*/

    {
    QRect RectSpeed (-400,-200, 210, 210);


    int startAngle= 30*16;
    int spanAngle= -65*16;
    painter->setPen(QPen(QBrush("red"), 9, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
    painter->drawArc(RectSpeed,startAngle,spanAngle);
    }

    /*Build a Tachometer scale*/

      {

        for (int i =0; i<=5;i++)
        {

        QRect RectScale(-410,-210,230,230);
        painter->setPen(QPen(QBrush("white") , 25, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
        painter->drawArc(RectScale,(220-32.5*i)*16,32.5);
        }
       /* For the red Scale*/

        for (int i =6; i<=8;i++)
        {

        QRect RectScale(-412,-210,230,230);
        painter->setPen(QPen(QBrush("red") , 25, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
        painter->drawArc(RectScale,(220-32.5*i)*16,32.5*5);/* spanAngle was multiplied by factor 5, that allow to control the circle lenght*/
        }
      }


    { int j=0;
    for (float i=222*pi/180;i> 28* pi/180;i-=32.5*pi/180)

    {

    painter->setFont(QFont("arial", 15, QFont::Bold, true));
    painter->setPen(QPen(QBrush("white ") , 13, Qt::SolidLine));
    painter->drawText(qCos(i)*150-297,-qSin(i)*150-93,QString("%1").arg(j));
    j++;
    }
     }


     {int j=6;
    for (float i=28*pi/180;i> -52* pi/180;i-=32.5*pi/180)
    {

    painter->setFont(QFont("arial", 16, QFont::Bold, true));
    painter->setPen(QPen(QBrush("red ") , 13, Qt::SolidLine));
    painter->drawText(qCos(i)*145-295,-qSin(i)*145-95,QString("%1").arg(j));
    j++;
    }
  }




    /* Build needle tachometer*/
    /*For the triangle*/
  {


            double xArcCenter=-295.0;
            double yArcCenter= -95.0;
            double AngleStart_Alpha = 220;
            int Round;

            double c = cos ((AngleStart_Alpha-value)* pi/180);
            double s = sin((AngleStart_Alpha-value)* pi/180);

            double xpos=xArcCenter+150*c;
            double ypos=yArcCenter-150*s;


            QPen pen ;
            pen.setWidth(2);
            pen.setColor("red");
            painter->setPen(pen);

            QBrush NeedleColor("red",Qt::SolidPattern);
            painter->setBrush(NeedleColor);




            QPointF pts[3]= {
                QPointF(xArcCenter-5*cos((AngleStart_Alpha-value-90)*pi/180),yArcCenter+5*sin((AngleStart_Alpha-value-90)*pi/180)),
                QPointF(xpos, ypos),
                QPointF(xArcCenter+5*cos((AngleStart_Alpha-value-90)*pi/180),yArcCenter-9*sin((AngleStart_Alpha-value-90)*pi/180))
                             };

                painter->drawConvexPolygon(pts,3);

            }



    /*For the arc needle*/

    {

    QRect RectSpeed (-320,-120, 50, 50); /*Coordinates Arc Tachometer Center P(-295,-95)*/

    QPen pen ;
    pen.setWidth(2);
    pen.setColor("red");
    QBrush NeedleColor("red",Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(NeedleColor);
    painter->drawEllipse(RectSpeed);

    }

    {
    QRect RectSpeed (-310,-110, 30, 30); /*Coordinates Arc Tachometer Center P(-295,-95)*/
    QPen pen ;
    pen.setWidth(2);
    pen.setColor("white");
    QBrush NeedleColor("white",Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(NeedleColor);

    painter->drawEllipse(RectSpeed);

    }


}

