#include "Inna/arrowspeedometerinna.h"
#include <QFont>
#include <QtMath>
#include <QPainter>

ArrowSpeedometerInna::ArrowSpeedometerInna(objet_virtuel *parent) :  objet_virtuel(parent)
{   value=0.0;
    vmax = 300 ;
    valueMax = vmax;
    A0 = 225 ;
    Amax = 180 ;
    r = 150.0 ;
    dx = 7;
    dy = 10;
    k = Amax * 1.0 / vmax ;
}

ArrowSpeedometerInna::ArrowSpeedometerInna(int VMAX, int ALPHA0, int ALPHAMAX)
{   value=0.0;
    vmax = VMAX ;
    valueMax = vmax;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 150.0 ;
    dx = 7;
    dy = 10;
    k = Amax * 1.0 / vmax ;
}

QRectF ArrowSpeedometerInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void ArrowSpeedometerInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{ painter->setRenderHints(QPainter::Antialiasing);
    // ***Draw central circle ***
     QRadialGradient radialGrad2(QPointF(xc, yc), 50);
         radialGrad2.setColorAt(0, Qt::black);
         radialGrad2.setColorAt(1, "#e0e0d1");
     painter->setPen(QPen(Qt::transparent));
     painter->setBrush(QBrush(radialGrad2));
     painter->drawEllipse(qRound(xc-15),qRound(yc-15),30,30);
    v=qRound(value);
  if (v < 0 || v > (vmax +10) ) v = (v < 0 ? 0 : (vmax+10));
     v *= Amax * 1.0f / vmax ; // correction of the speed to angle

     QLinearGradient linearGradl(QPointF(xc-(9*cos((A0-v-90)*rad)),yc+(9*sin((A0-v-90)*rad))), QPointF(xc+(9*cos((A0-v-90)*rad)),yc-(9*sin((A0-v-90)*rad))));
         linearGradl.setColorAt(0, "#F93737");
         linearGradl.setColorAt(0.5, "#ff3333");
         linearGradl.setColorAt(1, "#F93737");

     painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
     painter->setBrush(QBrush(linearGradl));
     QPointF points[3] = {
         QPointF(xc-5*cos((A0-v-90)*rad),yc+5*sin((A0-v-90)*rad)),
         QPointF(xc+(r-20)*cos((A0-v)*rad),yc-(r-20)*sin((A0-v)*rad)),
         QPointF(xc+5*cos((A0-v-90)*rad),yc-5*sin((A0-v-90)*rad))
          };
     painter->drawConvexPolygon(points, 3);
    painter->setPen(QPen("#19b5e4"));
    painter->setFont(QFont("Chandas", 12, 0));
    painter->drawText(740,435, "km/h");
    painter->setFont(QFont("SevenSegment", 35, 0));
    QRadialGradient rg(670, 421, 60);
    rg.setColorAt(0, "#4c5959");
    rg.setColorAt(1,Qt::black);
    painter->setBrush(rg);
    painter->drawText(QRect(610,400,120,42), Qt::AlignRight, QString("%1").arg(qRound(value)));
}
