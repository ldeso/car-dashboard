#include "Inna/arrowoilt.h"
#include <QFont>
#include <QtMath>
#include <QPainter>

ArrowOilT::ArrowOilT(objet_virtuel *parent) :  objet_virtuel(parent)
{   value =60;
    tmax = 160 ;
    lmax = 5;
    A0 = 180 ;
    Amax = 110 ;
    r = 100.0 ;
    dx = 10;
    dy = 9;

}

ArrowOilT::ArrowOilT(int TMAX, int LMAX, int ALPHA0, int ALPHAMAX)
{   value=60;
    tmax = TMAX ;
    lmax = LMAX;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100.0 ;
    dx = 10;
    dy = 9;

}

QRectF ArrowOilT::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void ArrowOilT::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{ painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
  
    double xot = xc + 30.0*cos((A0 - 15 - Amax / 2) * rad) ; //position of oil temperature arrow
    double yot = yc - 30.0*sin((A0 - 15 - Amax / 2) * rad);
    t = value;
   if (t < 60 || t > tmax) t = (t < 60 ? 60 : tmax);
    
  // ***Draw central circle for oil temp ***
    QRadialGradient radialGradot(QPointF(xot, yot), 50);
    radialGradot.setColorAt(0, Qt::black);
    radialGradot.setColorAt(1, "#e0e0d1");

    painter->setPen(QPen(Qt::transparent));
    painter->setBrush(QBrush(radialGradot));
    painter->drawEllipse(xot-15,yot-15,30,30);

 //          *** draw fleche oil temp ***

    k = (Amax+30) * 1.0f / (tmax - 60.0f) ; // angle correction
    QLinearGradient linearGradot(QPointF(xot-(5*cos((A0-k*(t-60)-90)*rad)),yot+(5*sin((A0-k*(t-60)-90)*rad))), QPointF(xot+(7*cos((A0-k*(t-60)-90)*rad)),yot-(7*sin((A0-k*(t-60)-90)*rad))));
    linearGradot.setColorAt(0, "#F93737");
    linearGradot.setColorAt(0.5, "#ff4d4d");
    linearGradot.setColorAt(1, "#F93737");

    painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
    painter->setBrush(QBrush(linearGradot));
    QPointF points[3] = {
        QPointF(xot-(5*cos((A0-k*(t-60)-90)*rad)),yot+(5*sin((A0-k*(t-60)-90)*rad))),
        QPointF(xot+(r-15)*cos((A0-k*(t-60))*rad),yot-5-(r-15)*sin((A0-k*(t-60))*rad)),
        QPointF(xot+(5*cos((A0-k*(t-60)-90)*rad)),yot-(5*sin((A0-k*(t-60)-90)*rad))),
       };

    painter->drawConvexPolygon(points, 3);
    



}

