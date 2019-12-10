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
    A0 = -10 ;
    Amax = 90 ;
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
    // painter->drawPixmap(0,0,1400,600,QPixmap(":/fond.gif"));
    ///
    ///\brief Remplissage du fond et dessin de l'arche encadrante
    /// \details On crée le gradient radial pour en suite instancier la brosse du *painter et dessiner une arche  encadrante avec un gradient de couleur.


    painter->drawPixmap(1000,120, 485, 520, QPixmap(":/I_RR.gif"));
    painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
    painter->drawEllipse(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2));
      QRadialGradient radialGrad(QPointF(xc, yc), r+30);
      radialGrad.setColorAt(0, Qt::transparent);
      radialGrad.setColorAt(0.8, "#f2f2f2");
      radialGrad.setColorAt(0.9, "#333333");
      radialGrad.setColorAt(1, "#f2f2f2");
      painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap));
      painter->drawArc(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2),206*16,285*16) ;

      k = Amax * 1.0 / (tmax - 60.0) ;
      // *** engine T ticks and tect ***
      ///
      ///\brief Affichage des traits et du texte pour la jauge de la température du moteur.
      ///
      for (int i = 0; i <= (tmax - 60) ; i+=10) {
          if (i % 30 == 0)
              {
              i<60 ? painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));

              painter->drawLine(qRound(xc+(r+15)*cos((A0+20+k*i)*rad)),qRound(yc-(r+15)*sin((A0+20+k*i)*rad)),qRound(xc+(r+3)*cos((A0+20+k*i)*rad)),qRound(yc-(r+3)*sin((A0+20+k*i)*rad)));
              painter->setFont(font);
              painter->setPen(QPen("#f5f5ef"));
              painter->drawText(qRound(xc-dx+(r-10)*cos((A0+20+k*i)*rad)),qRound(yc+dy-(r-10)*sin((A0+20+k*i)*rad)),QString("%1").arg(i+60));
              }
          else {
              i<60 ? painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));

             painter->drawLine(qRound(xc+(r+15)*cos((A0+20+k*i)*rad)),qRound(yc-(r+15)*sin((A0+20+k*i)*rad)),qRound(xc+(r+8)*cos((A0+20+k*i)*rad)),qRound(yc-(r+8)*sin((A0+20+k*i)*rad)));

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
          painter->drawLine(qRound(xc+(r+15)*cos((A0+245+k*i/10.0)*rad)),qRound(yc-(r+15)*sin((A0+245+k*i/10.0)*rad)),qRound(xc+(r+3)*cos((A0+245+k*i/10.0)*rad)),qRound(yc-(r+3)*sin((A0+245+k*i/10.0)*rad)));
          painter->setFont(QFont("Chandas",12,QFont::Bold));
          painter->setPen(QPen("#f5f5ef"));
          painter->drawText(qRound(xc-20+(r-5)*cos((245+k*i/10.0)*rad)),qRound(yc+5-(r-10)*sin((235+k*i/10.0)*rad)),QString("%1").arg(i*1./10));
          }
          else {
             painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
             painter->drawLine( qRound(xc+(r+15)*cos((A0+245+k*i/10.0)*rad)),qRound(yc-(r+15)*sin((A0+245+k*i/10.0)*rad)),qRound(xc+(r+8)*cos((A0+245+k*i/10.0)*rad)),qRound(yc-(r+8)*sin((A0+245+k*i/10.0)*rad)));

}
}
       QRadialGradient radgrad(700.0,300.0,600,350.0, 150.0);
       radgrad.setColorAt(0, "#333333");
       radgrad.setColorAt(1, "#0d0d0d");
       QLinearGradient lingrad (0,0,1400,600);
       lingrad.setColorAt(0, "#333333");
       lingrad.setColorAt(0.7, "#0d0d0d");
       lingrad.setColorAt(1, "#333333");
      // QBrush brush;
      // brush.setTexture(QPixmap(":/distressed-texture-2.jpg"));
      //brush.setStyle(Qt::nse2Pattern);
//      painter->setPen(QPen(QBrush(lingrad),20,Qt::SolidLine,Qt::FlatCap,Qt::RoundJoin));
//     painter->setBrush(QBrush(Qt::transparent));
//       QPainterPath path;
//      path.moveTo(1330,470);
//      path.arcTo(40,510,1320,245,30,120);
//      path.lineTo(70,470);
//      path.arcTo(40,210,320,320,207,-137);
//      path.arcTo(245,140,390,370,144,-83);
//      path.arcTo(420,80,560,600,130,-80);
//      path.arcTo(790,140,390,370,118,-83);
//      path.arcTo(1050,210,320,320,112,-125);
//      path.closeSubpath();
//      painter->drawPath(path);



}
