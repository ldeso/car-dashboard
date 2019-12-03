#include "Inna/arrowtachometerinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>

ArrowTachometerInna::ArrowTachometerInna(objet_virtuel *parent) :  objet_virtuel(parent)
{
    value=0.0;
    vmax = 8000 ;
    valueMax =vmax;
    A0 = 225 ;
    Amax = 270 ;
    r = 170.0 ;
    dx = 10;
    dy = 12;
    k = Amax * 1.0f / vmax ;  
}

ArrowTachometerInna::ArrowTachometerInna(int VMAX, int ALPHA0, int ALPHAMAX)
{
    value=0.0;
    vmax = VMAX ;
    valueMax =vmax;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 170.0 ;
    dx = 10;
    dy = 12;
    k = Amax * 1.0f / vmax ;
    
}

QRectF ArrowTachometerInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf; 
}

void ArrowTachometerInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
   painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
    v=qRound(value);
  if (v < 0 || v > vmax) v = (v < 0 ? 0 : vmax);
   v = qRound(v*Amax * 1.0f / vmax) ;
  
  // ***Draw central circle ***
   QRadialGradient radialGrad2(QPointF(xc, yc), 50);
   radialGrad2.setColorAt(0, Qt::black);
   radialGrad2.setColorAt(1, "#e0e0d1");
   painter->setPen(QPen(Qt::transparent));
   painter->setBrush(QBrush(radialGrad2));
   painter->drawEllipse(qRound(xc-15),qRound(yc-15),30,30);

  // *** draw fleche ***
  QLinearGradient linearGrad(QPointF(xc-(5*cos((A0-v-90)*rad)),yc+(5*sin((A0-v-90)*rad))), QPointF(xc+(5*cos((A0-v-90)*rad)),yc-(5*sin((A0-v-90)*rad))));
   linearGrad.setColorAt(0, "#F93737");
   linearGrad.setColorAt(0.5, "#ff3333");
   linearGrad.setColorAt(1, "#F93737");
   painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
   painter->setBrush(QBrush(linearGrad));
   QPointF points[3] = {
         QPointF(xc-5*cos((A0-v-90)*rad),yc+5*sin((A0-v-90)*rad)),

         QPointF(xc+(r-25)*cos((A0-v)*rad),yc-(r-25)*sin((A0-v)*rad)),
         QPointF(xc+5*cos((A0-v-90)*rad),yc-5*sin((A0-v-90)*rad))
          };

   painter->drawConvexPolygon(points, 3);

}

