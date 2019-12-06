#include "Inna/enginetinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>

///
/// \file enginetinna.cpp
/// \brief Classe EngineTInna derivée de la classe objet_virtuel
/// \details Permettant la création de l' aiguille de la jauge de la température mu moteur qui tourne en fonction de la valeur "value".
///
/// \param value - la valeur de la température du moteur
/// \param valueMax -  la température maximum
/// \param A0 - l'angle de debut de la jauge
/// \param Amax - l'ampleur de la jauge
/// \param r - le rayon de l'arche de la jauge
/// \param k - le coefficient pour convertir la valeur en degrés
///

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

      ///
      ///\brief Dessin du circle central.
      /// \details On crée le gradient radial pour en suite instancier la brosse du *painter et dessiner une ellipse avec un gradient de couleur.


      QRadialGradient radialGradet(QPointF(xet, yet), 50);
      radialGradet.setColorAt(0, Qt::black);
      radialGradet.setColorAt(1, "#e0e0d1");
      painter->setPen(QPen(Qt::transparent));
      painter->setBrush(QBrush(radialGradet));
      painter->drawEllipse(qRound(xet-15),qRound(yet-15),30,30);

      if (t > 115 ) {painter->drawPixmap(1140,315,40,40, QPixmap(":/I_engineT_red.gif"));}
      else {painter->drawPixmap(1140,315,40,40, QPixmap(":/I_engineT_blue.gif"));}

      ///
      ///\brief Dessin de la flèche
      ///\details On crée le gradient linear et un triangle, qu'on remplie avec un gradient de couleur. La position de la pointe de flèche est mathematiquement calculée.
      ///
    t=qRound(value);
    if (t < 50 || t > (tmax + 5)) t = ( t < 50 ?  50 : (tmax+5));// condition to set the range and prevent arrow from pointing outside the scale


      k = (Amax+30) * 1.0 / (tmax-60) ;
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
