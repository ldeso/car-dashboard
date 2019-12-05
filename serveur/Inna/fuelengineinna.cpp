#include "Inna/fuelengineinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>

///
/// \file fuelengineinna.cpp
/// \brief Classe dérivée de QGraphicsItem permettant l'affichage des jauges de l'essence et de la tepmerature du moteur.
/// \param tmax - température du moteur;
/// \param r - rayon de l'arche de la jauge;
/// \param A0 -  l'angle du début de la jauge;
/// \param Amax - l'angle total
/// \param k - coefficient pour convertir la valeur en degrés
///
FuelEngineInna::FuelEngineInna(QGraphicsItem *parent) :  QGraphicsItem(parent)

{
    tmax = 140 ;
    A0 = 0 ;
    Amax = 110 ;
    r = 100.0 ;
    dx = 10;
    dy = 9;
}

FuelEngineInna::FuelEngineInna(int TMAX, int ALPHA0, int ALPHAMAX)
{
    tmax = TMAX ;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100.0 ;
    dx = 10;
    dy = 9;
}

QRectF FuelEngineInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

/// \brief FuelEngineInna::paint
/// \param painter
///\details La fonction paint va permettre de réaliser un affichage des objets fixes de la représentation des jauges de l'essence et de la température du moteur.
void FuelEngineInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
    ///
    ///\brief Remplissage du fond et dessin de l'arche encadrante
    ///
    painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
    painter->drawEllipse(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2));
      QRadialGradient radialGrad(QPointF(xc, yc), r+30);
      radialGrad.setColorAt(0, Qt::transparent);
      radialGrad.setColorAt(0.8, "#f2f2f2");
      radialGrad.setColorAt(0.9, "#333333");
      radialGrad.setColorAt(1, "#f2f2f2");
      painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap));
      painter->drawArc(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2),206*16,285*16) ;
      painter->drawPixmap(1140,315,40,40, QPixmap(":/I_engineT_blue.gif"));

      k = Amax * 1.0 / (tmax - 60.0) ;
      // *** engine T ticks and tect ***
      ///
      ///\brief Affichage des traits et du texte pour la jauge de la température du moteur.
      ///
      for (int i = 0; i <= (tmax - 60) ; i+=10) {
          if (i % 30 == 0)
              {
              i<60 ? painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));

              painter->drawLine(xc+(r+15)*cos((A0+20+k*i)*rad),yc-(r+15)*sin((A0+20+k*i)*rad),xc+(r+3)*cos((A0+20+k*i)*rad),yc-(r+3)*sin((A0+20+k*i)*rad));
              painter->setFont(font);
              painter->setPen(QPen("#f5f5ef"));
              painter->drawText(xc-dx+(r-10)*cos((A0+20+k*i)*rad),yc+dy-(r-10)*sin((A0+20+k*i)*rad),QString("%1").arg(i+60));
              }
          else {
              i<60 ? painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));

             painter->drawLine( xc+(r+15)*cos((A0+20+k*i)*rad),yc-(r+15)*sin((A0+20+k*i)*rad),xc+(r+8)*cos((A0+20+k*i)*rad),yc-(r+8)*sin((A0+20+k*i)*rad));

              }

          }
      ///
      ///\brief Affichage des traits et du texte pour le niveau d'essance.
      ///
      // ** fuel level ticks and text **
       k = Amax * 1.0;
      for (int i=0; i <= 10 ; i++) {
          if (i%5==0)
          {painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
          painter->drawLine(xc+(r+15)*cos((A0+220+k*i/10.0)*rad),yc-(r+15)*sin((A0+220+k*i/10.0)*rad),xc+(r+3)*cos((A0+220+k*i/10.0)*rad),yc-(r+3)*sin((A0+220+k*i/10.0)*rad));
          painter->setFont(QFont("Chandas",12,QFont::Bold));
          painter->setPen(QPen("#f5f5ef"));
          painter->drawText(xc-5+(r-10)*cos((220+k*i/10.0)*rad),yc+7-(r-10)*sin((220+k*i/10.0)*rad),QString("%1").arg(i*1./10));
          }
          else {
             painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
             painter->drawLine( xc+(r+15)*cos((A0+220+k*i/10.0)*rad),yc-(r+15)*sin((A0+220+k*i/10.0)*rad),xc+(r+8)*cos((A0+220+k*i/10.0)*rad),yc-(r+8)*sin((A0+220+k*i/10.0)*rad));

}
}





}
