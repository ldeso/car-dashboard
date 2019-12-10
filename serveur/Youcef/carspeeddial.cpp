#include "carspeeddial.h"

#include <QtMath>
#include <QGraphicsTextItem>
#include <QStringList>
#include <QDebug>

CarSpeedDial::CarSpeedDial(objet_virtuel *)
{
    value=0;
    valueMax=260;
}

QRectF CarSpeedDial::boundingRect() const
{
    return QRectF(-600, -400, 1200, 800);
}

void CarSpeedDial::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);

    {
        QRadialGradient gradient(305, -95, 200);

        gradient.setColorAt(0, QColor(0,204,255));
        gradient.setColorAt(0.2, QColor("dark blue"));
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
        for (int i=0;i<=260;i+=10)
        { if (i%20==0)
            {
                QRect RectScale(175,-225,260,260);
                painter->setPen(QPen(QBrush("white "), 15, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
                painter->drawArc(RectScale,(220-i)*16,20*2);
            }
        }

        for (int i=0;i<=260;i+=5)
        { if (i%10==0)
            {
                QRect RectScale(175,-225,260,260);
                painter->setPen(QPen(QBrush("white "), 8, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
                painter->drawArc(RectScale,(220-i)*16,20*2);
            }
        }


        /*For the text speed scale*/
        {
            int j=0;
            for (float i=222*pi/180;i> -52* pi/180;i-=20*pi/180)
            {
                painter->setFont(QFont("Seven Segment", 13, QFont::Bold, true));
                painter->setPen(QPen(QBrush("white") , 13, Qt::SolidLine));
                painter->drawText(qCos(i)*152+295,-qSin(i)*152-90,QString("%1").arg(j));
                j+=20;
            }
        }



        /* Build speed needle */
        /*For the triangle*/
        {

            double xArcCenter=305.0; /*Coordinates Arc Tachometer Center P(305,-95)*/
            double yArcCenter= -95.0;
            double AngleStart_Alpha = 220;


            double c = cos ((AngleStart_Alpha-value)* pi/180);
            double s = sin((AngleStart_Alpha-value)* pi/180);

            double xpos=xArcCenter+140*c;
            double ypos=yArcCenter-140*s;

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
        /*design speed display*/
        /*main rectangle*/

        {
            /*arc center is (x=305,y=-95)*/
            int dX=75;int dY=90;
            int X= 305-dX;
            int Y= -95+dY;
            int x1=250;int y1=30;


            {


                painter->setPen(QPen(QColor(0,0,0,0) , 1, Qt::SolidLine,Qt::FlatCap));
                painter->setBrush(QColor(0,128,255,15));
                painter->drawRect(X,Y, dX*2,Y+60);
                QRadialGradient radialGrad(QPointF(0, 45), 50);
                radialGrad.setColorAt(0, QColor(0,204,255));
                radialGrad.setColorAt(0.5, QColor("#D4CAC7"));
                radialGrad.setColorAt(1, QColor(0, 128, 255));
                painter->setPen(QPen(QColor(0,204,255) , 1, Qt::SolidLine,Qt::FlatCap));
            }

            QFont font("Seven Segment", 25,  QFont::Bold, true);
            painter->setFont(font);
            painter->setPen(QPen(QBrush("white") ,10, Qt::SolidLine,Qt::FlatCap));
            painter->drawText(x1,y1, QString("%1").arg(value));


            painter->setFont(QFont("ariel", 15, QFont::Bold, true));
            painter->setPen(QPen(QBrush("white") ,10, Qt::SolidLine,Qt::FlatCap));
            painter->drawText(310, 30, "km/h");

        }
    }
    /*design Tachometer display*/

    {
        {
            int dX=60;int dY=80;
            int X= -290-dX;
            int Y= -95+dY;



            painter->setPen(QPen(QColor(0,0,0,2) , 1, Qt::SolidLine,Qt::FlatCap));
            painter->setBrush(QColor(0,128,255,15));
            painter->drawRect(X,Y, dX*2,Y+95);
            QRadialGradient radialGrad(QPointF(X-dX, Y-dY), 50);
            radialGrad.setColorAt(0, QColor(0,204,255));
            radialGrad.setColorAt(0.5, QColor("red"));
            radialGrad.setColorAt(1, QColor(0, 128, 255));
            painter->setPen(QPen(QColor(0,204,255) , 1, Qt::SolidLine,Qt::FlatCap));


    }

    {
        int x=-290;int y=25;int Ax=30;int Ay=10;int r=10;
        painter->setPen(QPen(QBrush("red") , 2, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
        painter->drawLine(QPoint(x-Ax,y),QPoint(x+Ax,y));
        painter->drawLine(QPoint(x-Ax,y),QPoint(x-Ax,y+Ay));
        painter->drawLine(QPoint(x,y),QPoint(x,y+Ay));
        painter->drawLine(QPoint(x,y),QPoint(x,y-Ay));
        painter->drawLine(QPoint(x+Ax,y),QPoint(x+Ax,y-Ay));
        painter->drawLine(QPoint(x+Ax,y),QPoint(x+Ax,y+Ay));


        QRadialGradient gradient(x, y, 100);
//        gradient.setColorAt(0.2, QColor(0,0,0,0));

        gradient.setColorAt(1, QColor("white"));
        QBrush brush(gradient);
        painter->setBrush(brush);
        painter->setFont(QFont("Times", 13, QFont::Bold, false));
        painter->setPen(QPen(QBrush("red") , 3, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));


        if  (getValue()==0)

        {}

        else if (getValue()<10)

        {
            painter->drawEllipse(QRect(x-Ax-r,y+Ay,2*r,2*r));
            painter->drawText(x-Ax-(0.5*r),y+Ay+(1.6*r),QString("%1").arg(2));}
        else if (getValue()>=30 && getValue()<40)
        {painter->drawEllipse(QRect(x-r,y-Ay-(2*r),2*r,2*r));
            painter->drawText(x-(0.5*r),y-Ay-(0.4*r),QString("%1").arg(3));}

        else if (getValue()>=40 && getValue()<60)
        {
            painter->drawEllipse(QRect(x-r,y+Ay,2*r,2*r));
            painter->drawText(x-(0.5*r),y+Ay+(1.6*r),QString("%1").arg(4));}

        else if (getValue()>=60 && getValue()<80)
        { painter->drawEllipse(QRect(x+Ax-r,y-Ay-(2*r),2*r,2*r));

            painter->drawText(x+Ax-(0.5*r),y-Ay-(0.4*r),QString("%1").arg(5));

        }


        else
        { painter->drawEllipse(QRect(x+Ax-r,y+Ay,2*r,2*r));

            painter->drawText(x+Ax-(0.5*r),y+Ay+(1.6*r),QString("%1").arg(6));}

    }
}


}
