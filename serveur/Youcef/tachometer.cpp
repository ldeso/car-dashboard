#include "tachometer.h"
#include <QtMath>
#include <QGraphicsItem>

Tachometer::Tachometer(QGraphicsItem *parent)
{

}

QRectF Tachometer::boundingRect() const
{
 return QRectF(-600, -400, 1200, 800);
}

void Tachometer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

{
 painter->setRenderHint(QPainter::Antialiasing);

    {
    QRadialGradient gradient(-295, -95, 200);
    gradient.setColorAt(0, QColor(0,0,0,0));
    gradient.setColorAt(0.5, QColor("dark blue"));
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

    /*test: line to define the center of the left main circle*/

     painter->setPen(QPen(QBrush("dark") ,2, Qt::SolidLine,Qt::FlatCap));
     painter->drawLine(QLine (-295,-400,-295,300));
     painter->drawLine(QLine (-600,25,600,25));
    /*test end */


    /*design Tachometer display*/

     {
         {
             int deltaX=60;int deltaY=80;
             int X= -295-deltaX;
             int Y= -95+deltaY;


             QLinearGradient gradient(QPoint(X,Y),QPoint(X,Y+90));/* coordinates gradient ((x,y),(x1,y1)) are cooresponding to line where starting the color variation*/
             gradient.setColorAt(1, QColor("#dark blue"));
             gradient.setColorAt(0.5, QColor("#D4CAC7"));
             gradient.setColorAt(0, QColor("#white"));
             QBrush brush(gradient);
             painter->setBrush(brush);

             painter->drawRoundedRect(X,Y, deltaX*2,Y+95,15,15);
             painter->setPen(QPen(QBrush("white") ,5, Qt::SolidLine,Qt::FlatCap));
             painter->drawRoundedRect(X+3,Y+3, (deltaX*2)-6,Y+90,15,15);
         }

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

     {
        int x=-295;int y=25;int Ax=30;int Ay=10;int r=10;
        painter->setPen(QPen(QBrush("red") , 2, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
        painter->drawLine(QPoint(x-Ax,y),QPoint(x+Ax,y));
        painter->drawLine(QPoint(x-Ax,y),QPoint(x-Ax,y+Ay));
        painter->drawLine(QPoint(x,y),QPoint(x,y+Ay));
        painter->drawLine(QPoint(x,y),QPoint(x,y-Ay));
        painter->drawLine(QPoint(x+Ax,y),QPoint(x+Ax,y-Ay));
        painter->drawLine(QPoint(x+Ax,y),QPoint(x+Ax,y+Ay));


        QRadialGradient gradient(x, y, 100);
        gradient.setColorAt(1, QColor(0,0,0,0));

        gradient.setColorAt(1, QColor("#FE2E2E"));
        QBrush brush(gradient);
        painter->setBrush(brush);

        painter->drawEllipse(QRect(x-Ax-r,y+Ay,2*r,2*r));
        painter->drawEllipse(QRect(x-r,y-Ay-(2*r),2*r,2*r));
        painter->drawEllipse(QRect(x-r,y+Ay,2*r,2*r));
        painter->drawEllipse(QRect(x+Ax-r,y-Ay-(2*r),2*r,2*r));
        painter->drawEllipse(QRect(x+Ax-r,y+Ay,2*r,2*r));

        painter->setFont(QFont("arial", 12, QFont::Bold, false));
        painter->setPen(QPen(QBrush("white") , 5, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
        painter->drawText(x-Ax-(0.5*r),y+Ay+(1.6*r),QString("%1").arg(2));
        painter->drawText(x-(0.5*r),y-Ay-(0.4*r),QString("%1").arg(3));
        painter->drawText(x-(0.5*r),y+Ay+(1.6*r),QString("%1").arg(4));
        painter->drawText(x+Ax-(0.5*r),y-Ay-(0.4*r),QString("%1").arg(5));
        painter->drawText(x+Ax-(0.5*r),y+Ay+(1.6*r),QString("%1").arg(6));

     }


    /* Build needle tachometer*/
    /*For the triangle*/
  {


            double xArcCenter=-295.0;
            double yArcCenter= -95.0;
            double AngleStart_Alpha = 220;
            int Round;

            double c = cos (AngleStart_Alpha* pi/180);
            double s = sin(AngleStart_Alpha* pi/180);

            double xpos=xArcCenter+150*c;
            double ypos=yArcCenter-150*s;


            QPen pen ;
            pen.setWidth(2);
            pen.setColor("red");
            painter->setPen(pen);

            QBrush NeedleColor("red",Qt::SolidPattern);
            painter->setBrush(NeedleColor);




            QPointF pts[3]= {
                QPointF(xArcCenter-5*cos((AngleStart_Alpha-90)*pi/180),yArcCenter+5*sin((AngleStart_Alpha-90)*pi/180)),
                QPointF(xpos, ypos),
                QPointF(xArcCenter+5*cos((AngleStart_Alpha-90)*pi/180),yArcCenter-9*sin((AngleStart_Alpha-90)*pi/180))
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


   /*test: line to define the center of the display rectangle*/
     painter->setPen(QPen(QBrush("dark") ,2, Qt::SolidLine,Qt::FlatCap));
     painter->drawLine(QLine (-600,-95,600,-95));

     /*test end*/


}

