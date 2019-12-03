#include "Inna/enginetinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>


EngineTInna::EngineTInna(objet_virtuel *parent) :  objet_virtuel(parent)
{
    value=55;
    tmax = 140 ;
    A0 = 0 ;
    Amax = 110 ;
    r = 100.0 ;

}

EngineTInna::EngineTInna(int TMAX, int ALPHA0, int ALPHAMAX)
{
    value=55;
    tmax = TMAX ;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100.0 ;

}

QRectF EngineTInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void EngineTInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering

      double xet=xc+20.0*cos((A0+20+Amax/2)*rad); //position of engine temperature arrow
      double yet=yc-20.0*sin((A0+20+Amax/2)*rad);

     // ***Draw central circle for engine temp ***

      QRadialGradient radialGradet(QPointF(xet, yet), 50);
      radialGradet.setColorAt(0, Qt::black);
      radialGradet.setColorAt(1, "#e0e0d1");
      painter->setPen(QPen(Qt::transparent));
      painter->setBrush(QBrush(radialGradet));
      painter->drawEllipse(qRound(xet-15),qRound(yet-15),30,30);

      //          *** draw fleche engine temp ***
    t=qRound(value);
	if (t < 50 || t > (tmax + 5)) t = ( t < 50 ?  50 : (tmax+5));

      k = (Amax+30) * 1.0f / (tmax-60) ;
      QLinearGradient linearGradot(QPointF(xet-(5*cos((A0+5+k*(t-60)-90)*rad)),yet+(5*sin((A0+5+k*(t-60)-90)*rad))), QPointF(xet+(7*cos((A0+5+k*(t-60)-90)*rad)),yet-(7*sin((A0+5+k*(t-60)-90)*rad))));
      linearGradot.setColorAt(0, "#F93737");
      linearGradot.setColorAt(0.5, "#ff4d4d");
      linearGradot.setColorAt(1, "#F93737");

      painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
      painter->setBrush(QBrush(linearGradot));
      QPointF points[3] = {
          QPointF(xet-(5*cos((A0+5+k*(t-60)-90)*rad)),yet+(5*sin((A0+5+k*(t-60)-90)*rad))),
          QPointF(xet+(r-15)*cos((A0+5+k*(t-60))*rad),yet-5-(r-15)*sin((A0+5+k*(t-60))*rad)),
          QPointF(xet+(5*cos((A0+5+k*(t-60)-90)*rad)),yet-(5*sin((A0+5+k*(t-60)-90)*rad))),
         };

      painter->drawConvexPolygon(points, 3);

     
}
