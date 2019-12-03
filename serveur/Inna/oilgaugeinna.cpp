#include "Inna/oilgaugeinna.h"
#include <QFont>
#include <QtMath>
#include <QPainter>

OilGaugeInna::OilGaugeInna(QGraphicsItem *parent) :  QGraphicsItem(parent)
{
    tmax = 160 ;
    lmax = 5;
    A0 = 180 ;
    Amax = 110 ;
    r = 100.0 ;
    dx = 10;
    dy = 9;

}

OilGaugeInna::OilGaugeInna(int TMAX, int LMAX, int ALPHA0, int ALPHAMAX)
{
    tmax = TMAX ;
    lmax = LMAX;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100.0 ;
    dx = 10;
    dy = 9;

}

QRectF OilGaugeInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void OilGaugeInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{ painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
  painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
  painter->drawEllipse(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2));
  QRadialGradient radialGrad(QPointF(xc, yc), r+30);
  radialGrad.setColorAt(0, Qt::transparent);
  radialGrad.setColorAt(0.8, "#f2f2f2");
  radialGrad.setColorAt(0.9, "#333333");
  radialGrad.setColorAt(1, "#f2f2f2");
  painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap));
  painter->drawArc(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2),50*16,285*16) ;

      k = Amax * 1.0f / (tmax - 60.0f) ;

         // ** oil temp ticks and numbers **
    for (int i = 0; i <= (tmax - 60) ; i+=10) {
        if (i % 30 == 0)
            {
            painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
            painter->drawLine(xc+(r+15)*cos((A0-15-k*i)*rad),yc-(r+15)*sin((A0-15-k*i)*rad),xc+(r+3)*cos((A0-15-k*i)*rad),yc-(r+3)*sin((A0-15-k*i)*rad));
            painter->setFont(font);
            painter->setPen(QPen("#f5f5ef"));
            painter->drawText(xc-dx+(r-10)*cos((A0-15-k*i)*rad),yc+dy-(r-10)*sin((A0-15-k*i)*rad),QString("%1").arg(i+60));
            }
        else {
           painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
           painter->drawLine( xc+(r+15)*cos((A0-15-k*i)*rad),yc-(r+15)*sin((A0-15-k*i)*rad),xc+(r+8)*cos((A0-15-k*i)*rad),yc-(r+8)*sin((A0-15-k*i)*rad));

            }

        }


    painter->drawPixmap(90,400,40,40, QPixmap(":/I_Oil_white.gif"));
    painter->drawPixmap(220,305,40,40, QPixmap(":/I_Oil_t_white.gif"));

    // ** Block oil level **
    k = Amax * 1.0f/lmax;

         // ** oil level ticks and numbers **
    for (int i=0; i <= lmax*2; i++) {
        if (i%2==0)
        {painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
        painter->drawLine(xc+(r+15)*cos((A0+40+k*i/2.0)*rad),yc-(r+15)*sin((A0+40+k*i/2.0)*rad),xc+(r+3)*cos((A0+40+k*i/2.0)*rad),yc-(r+3)*sin((A0+40+k*i/2.0)*rad));
        painter->setFont(font);
        painter->setPen(QPen("#f5f5ef"));
        painter->drawText(xc-dx+5+(r-10)*cos((A0+40+k*i/2.0)*rad),yc+dy-(r-10)*sin((A0+40+k*i/2.0)*rad),QString("%1").arg(i/2));
        }
        else {
           painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
           painter->drawLine( xc+(r+15)*cos((A0+40+k*i/2.0)*rad),yc-(r+15)*sin((A0+40+k*i/2.0)*rad),xc+(r+8)*cos((A0+40+k*i/2.0)*rad),yc-(r+8)*sin((A0+40+k*i/2.0)*rad));

        }

        }
}
