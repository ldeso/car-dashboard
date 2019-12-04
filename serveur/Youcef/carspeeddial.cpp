#include "carspeeddial.h"

#include <QtMath>
#include <QGraphicsTextItem>
#include <QStringList>

CarSpeedDial::CarSpeedDial(QGraphicsItem *parent)
{

}

QRectF CarSpeedDial::boundingRect() const
{
  return QRectF(-600, -400, 1200, 800);
}

void CarSpeedDial::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);

       {QRadialGradient gradient(305, -95, 200);
       gradient.setColorAt(0, QColor(0,0,0,0));
         gradient.setColorAt(0.5, QColor("dark blue"));
       gradient.setColorAt(1, QColor("dark"));
       QBrush brush(gradient);
       painter->setBrush(brush);
       painter->drawEllipse(118,-282, 369, 369);
       }


    /*Draw the main circle of the speed scale*/
    {
    QRect RectSpeed (118,-282, 369, 369);


    int startAngle= 0*16;
    int spanAngle=  360*16;
    painter->setPen(QPen(QBrush("red"), 4, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
    painter->drawArc(RectSpeed,startAngle,spanAngle);
    }

    {
    QRect RectSpeed (122,-278, 360, 360);


    int startAngle= 0*16;
    int spanAngle=  360*16;
    painter->setPen(QPen(QBrush("white"), 4, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
    painter->drawArc(RectSpeed,startAngle,spanAngle);
    }




    /*Build a Speed Arc  */

    {
    QRect RectSpeed (180,-220, 250, 250);


    int startAngle= 220*16;
    int spanAngle= -260*16;
    painter->setPen(QPen(QBrush("white"), 6, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
    painter->drawArc(RectSpeed,startAngle,spanAngle);


    /*Build a speed scale*/

    {

        for (int i=0;i<=260;i+=10)
          { if (i%20==0)
             {
             QRect RectScale(175,-225,260,260);
             painter->setPen(QPen(QBrush("white "), 15, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
             painter->drawArc(RectScale,(220-i)*16,20*2);
             }
          }
     }
    /*For the text speed scale*/
    {
        int j=0;
        for (float i=222*pi/180;i> -52* pi/180;i-=20*pi/180)
        /* i is an angle,i start at 222°, we have to convert i to radian by multplied the starting angle
         * by pi and devied by 180°(Angle in degree =Angle in radian * 180/pi) ; i was less than the end angle -52°,
         * to deteminate  the good end angle, we have to reperate at 0° of the circle orgines axis, in this case,
         *  we move from 220° with an angle of -260° (negative values mean that angle move in the clockwise
         * direction. Zero degrees is at the 3 o'clock position); Finaly,i move with a step of 20° corresponding
         * to the speed value between two graduations, this is written with - 20°( step speed) multiplied also
         * by pi and devided by 180° */
        {

        painter->setFont(QFont("arial", 13, QFont::Bold, true));
        painter->setPen(QPen(QBrush("white") , 13, Qt::SolidLine));
        painter->drawText(qCos(i)*152+295,-qSin(i)*152-90,QString("%1").arg(j));

        /* For using the function drawText, we have to define 3 arguments in drawtext that determine the text position
         * we can write this as follow drawtext(x value, y value, const Qstring). The detailled description of this function is
         * " void QPainter::drawText(const QRectF &rectangle, int flags, const QString &text, QRectF *boundingRect = nullptr) "
         * In our case, we have to write text around a circle, we have to calculate the good position (x,y) by referring to
         * the center of the circle, we have to use trigonometric functions with x= cos(angle)*radius+ x (x-axis of center circle)
         * same for the y coordinate, by using here y = sin(angle)* radius+ y (y-axis of center circle). the negative value mean
         * that angle move in the clockwise direction. In brief, we have to detrminate the center of the main circle( with that
         * we can control the position of the circle; example x=300 and y=-90), calculate the radius ( with that we can control
         * the dimeter; example r=150) and finaly using the trigonometric functions to detrminate the good x, y position by using
         * the diffrent i values stated before in the loop "for". The third argument mean to transform number on string character.
         * The middle circle center is(305,-95), but you have to adjust the coordinates(x,y) to find the good position of the different
         * texts*/

        j+=20;
        }
      }

/*design speed display*/

    /*main rectangle*/

    {
        /*arc center is (x=305,y=-95)*/
        int deltaX=75;int deltaY=90;
        int X= 305-deltaX;
        int Y= -95+deltaY;

        int x1=250;int y1=30;

       /* line to define the right arc center*/
        painter->setPen(QPen(QBrush("dark") ,2, Qt::SolidLine,Qt::FlatCap));
        painter->drawLine(QLine (305,-400,305,300));
       /*end of the line draw*/

        {

            QLinearGradient gradient(QPoint(X,Y),QPoint(X,Y+60));/* coordinates gradient ((x,y),(x1,y1)) are cooresponding to line where starting the color variation*/
            gradient.setColorAt(1, QColor("#dark blue"));
            gradient.setColorAt(0.5, QColor("#D4CAC7"));
            gradient.setColorAt(0, QColor("#white"));
            QBrush brush(gradient);
            painter->setBrush(brush);

            painter->setPen(QPen(QBrush("dark") ,5, Qt::SolidLine,Qt::FlatCap));
            painter->drawRoundedRect(X,Y, deltaX*2,Y+60,15,15);
            painter->setPen(QPen(QBrush("white") ,5, Qt::SolidLine,Qt::FlatCap));
            painter->drawRoundedRect(X+3,Y+3, (deltaX*2)-6,Y+54,15,15);
        }


        painter->setFont(QFont("ariel", 18,  QFont::Bold, true));
        painter->setPen(QPen(QBrush("white") ,10, Qt::SolidLine,Qt::FlatCap));
        painter->drawText(x1,y1, QString("%1").arg(200)); /*replace after 20 by speedvalue*/


        painter->setFont(QFont("ariel", 15, QFont::Bold, true));
        painter->setPen(QPen(QBrush("white") ,10, Qt::SolidLine,Qt::FlatCap));
        painter->drawText(310, 30, "km/h");

    }

    /* Build speed needle */
    /*For the triangle*/
{

            double xArcCenter=305.0; /*Coordinates Arc Tachometer Center P(305,-95)*/
            double yArcCenter= -95.0;
            double AngleStart_Alpha = 270;


            double c = cos (AngleStart_Alpha-speedvalue* pi/180);
            double s = sin(AngleStart_Alpha-speedvalue* pi/180);

            double xpos=xArcCenter+140*c;
            double ypos=yArcCenter-140*s;

            QPen pen ;
            pen.setWidth(2);
            pen.setColor("red");
            painter->setPen(pen);

            QBrush NeedleColor("red",Qt::SolidPattern);
            painter->setBrush(NeedleColor);


            QPointF pts[3]= {
                QPointF(xArcCenter-5*cos((AngleStart_Alpha-speedvalue-90)*pi/180),yArcCenter+5*sin((AngleStart_Alpha-speedvalue-90)*pi/180)),
                QPointF(xpos, ypos),
                QPointF(xArcCenter+5*cos((AngleStart_Alpha-speedvalue-90)*pi/180),yArcCenter-9*sin((AngleStart_Alpha-speedvalue-90)*pi/180))
                             };

                painter->drawConvexPolygon(pts,3);

            }

    /*For the arc needle*/

    {

     QRect RectSpeed (280,-120, 50, 50); /*Coordinates Arc Tachometer Center P(305,-95)*/


    QPen pen ;
    pen.setWidth(2);
    pen.setColor("red");
    QBrush NeedleColor("red",Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(NeedleColor);
    painter->drawEllipse(RectSpeed);


    }

    {
    QRect RectSpeed (290,-110, 30, 30); /*Coordinates Arc Tachometer Center P(305,-95)*/
    QPen pen ;
    pen.setWidth(2);
    pen.setColor("white");
    QBrush NeedleColor("white",Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(NeedleColor);
    painter->drawEllipse(RectSpeed);

    }
    }
}



