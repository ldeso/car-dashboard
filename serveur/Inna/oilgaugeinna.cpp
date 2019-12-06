#include "Inna/oilgaugeinna.h"
#include <QFont>
#include <QtMath>
#include <QPainter>
///
/// \file oilgaugeinna.cpp
/// \brief Classe dérivée de QGraphicsItem permettant l'affichage des jauges de niveau et de température d'huile.
/// \param tmax - la température maximum;
/// \param lmax - le niveau maximum
/// \param r - rayon de l'arche de la jauge;
/// \param A0 -  l'angle du début de la jauge;
/// \param Amax - l'angle total
/// \param k - coefficient pour convertir la valeur en degrés
///
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
/// \brief FuelEngineInna::paint
/// \param painter
///\details La fonction paint va permettre de réaliser un affichage des objets fixes de la représentation des jauges de niveau et de température d'huile.

void OilGaugeInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{ painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
    ///
    ///\brief Remplissage du fond et dessin de l'arche encadrante
    /// \details On crée le gradient radial pour en suite instancier la brosse du *painter et dessiner une arche  encadrante avec un gradient de couleur.

  painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
  painter->drawEllipse(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2));
  QRadialGradient radialGrad(QPointF(xc, yc), r+30);
  radialGrad.setColorAt(0, Qt::transparent);
  radialGrad.setColorAt(0.8, "#f2f2f2");
  radialGrad.setColorAt(0.9, "#333333");
  radialGrad.setColorAt(1, "#f2f2f2");
  painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap));
  painter->drawArc(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2),50*16,285*16) ;

      k = Amax * 1.0 / (tmax - 60.0) ;

      ///
      ///\brief Affichage des traits et du texte pour la jauge de la température d'huile.
      ///
    for (int i = 0; i <= (tmax - 60) ; i+=10) {
        if (i % 30 == 0)
            {
            painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
            painter->drawLine(qRound(xc+(r+15)*cos((A0-15-k*i)*rad)),qRound(yc-(r+15)*sin((A0-15-k*i)*rad)),qRound(xc+(r+3)*cos((A0-15-k*i)*rad)),qRound(yc-(r+3)*sin((A0-15-k*i)*rad)));
            painter->setFont(font);
            painter->setPen(QPen("#f5f5ef"));
            painter->drawText(qRound(xc-dx+(r-10)*cos((A0-15-k*i)*rad)),qRound(yc+dy-(r-10)*sin((A0-15-k*i)*rad)),QString("%1").arg(i+60));
            }
        else {
           painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
           painter->drawLine( qRound(xc+(r+15)*cos((A0-15-k*i)*rad)),qRound(yc-(r+15)*sin((A0-15-k*i)*rad)),qRound(xc+(r+8)*cos((A0-15-k*i)*rad)),qRound(yc-(r+8)*sin((A0-15-k*i)*rad)));

            }

        }




    ///
    ///\brief Affichage des traits et du texte pour le niveau d'huile.
    ///
    k = Amax * 1.0/lmax;

         // ** oil level ticks and numbers **
    for (int i=0; i <= lmax*2; i++) {
        if (i%2==0)
        {painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
        painter->drawLine(qRound(xc+(r+15)*cos((A0+40+k*i/2.0)*rad)),qRound(yc-(r+15)*sin((A0+40+k*i/2.0)*rad)),qRound(xc+(r+3)*cos((A0+40+k*i/2.0)*rad)),qRound(yc-(r+3)*sin((A0+40+k*i/2.0)*rad)));
        painter->setFont(font);
        painter->setPen(QPen("#f5f5ef"));
        painter->drawText(qRound(xc-dx+5+(r-10)*cos((A0+40+k*i/2.0)*rad)),qRound(yc+dy-(r-10)*sin((A0+40+k*i/2.0)*rad)),QString("%1").arg(i/2));
        }
        else {
           painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
           painter->drawLine( qRound(xc+(r+15)*cos((A0+40+k*i/2.0)*rad)),qRound(yc-(r+15)*sin((A0+40+k*i/2.0)*rad)),qRound(xc+(r+8)*cos((A0+40+k*i/2.0)*rad)),qRound(yc-(r+8)*sin((A0+40+k*i/2.0)*rad)));

        }

        }
}
