#include "Inna/arrowoillinna.h"
#include "objet_virtuel.h"
#include <QFont>
#include <QtMath>
#include <QPainter>

ArrowOilLInna::ArrowOilLInna(objet_virtuel *parent) :  objet_virtuel(parent)
{
    value =0.0;
    lmax = 5;
    valueMax = lmax;
    A0 = 180 ;
    Amax = 110 ;
    r = 100 ;
    dx = 10;
    dy = 9;

}

ArrowOilLInna::ArrowOilLInna(int LMAX, int ALPHA0, int ALPHAMAX)
{
    value=0.0;
    lmax= LMAX;
    valueMax = lmax;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100 ;
    dx = 10;
    dy = 9;

}

QRectF ArrowOilLInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void ArrowOilLInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{ painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
     
    double  xol = xc +30.0*cos((A0+40+Amax/2)*rad) ;
    double yol = yc - 30.0*sin((A0+40+Amax/2)*rad);
      
    // ***Draw central circle for oil level ***
      QRadialGradient radialGradol(QPointF(xol, yol), 50);
             radialGradol.setColorAt(0, Qt::black);
             radialGradol.setColorAt(1, "#e0e0d1");
      
      painter->setPen(QPen(Qt::transparent));
      painter->setBrush(QBrush(radialGradol));
      painter->drawEllipse(qRound(xol-15),qRound(yol-15),30,30);

   //          *** draw fleche oil level ***
    l=static_cast<double>(value);

    k = (Amax+20) * 1.0/valueMax;
   if (l < 0 || l > valueMax) l = (l < 0 ? 0 : valueMax);
 QLinearGradient linearGradol  (QPointF(xol-(5*cos((A0+30+k*l-90)*rad)),yol+(5*sin((A0+30+k*l-90)*rad))), QPointF(xol+(7*cos((A0+30+k*l-90)*rad)),yol-(7*sin((A0+30+k*l-90)*rad))));
          linearGradol.setColorAt(0, "#F93737");
          linearGradol.setColorAt(0.5, "#ff4d4d");
          linearGradol.setColorAt(1, "#F93737");

      painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
      painter->setBrush(QBrush(linearGradol));
      QPointF points[3] = {
          QPointF(xol-(5*cos((A0+30+k*l-90)*rad)),yol+(5*sin((A0+30+k*l-90)*rad))),
          QPointF(xol+(r-10)*cos((A0+30+k*l)*rad),yol-5-(r-10)*sin((A0+30+k*l)*rad)),
          QPointF(xol+(5*cos((A0+30+k*l-90)*rad)),yol-(5*sin((A0+30+k*l-90)*rad))),
         };

      painter->drawConvexPolygon(points, 3);
       



}
