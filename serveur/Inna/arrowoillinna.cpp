#include "Inna/arrowoillinna.h"
#include "objet_virtuel.h"
#include <QFont>
#include <QtMath>
#include <QPainter>
///
/// \file arrowoillinna.cpp
/// \brief Classe ArrowOilLInna derivée de la classe objet_virtuel
/// \details Permet la création de l' aiguille de la jauge du niveu d'huile qui tourne en fonction de la valeur ***value***.
///
/// \param value - la valeur du niveau d'huile
/// \param valueMax - le niveau d'huile maximum
/// \param A0 - l'aunge de debut de la jauge
/// \param Amax - l'ampleur de la jauge
/// \param r - le rayon de l'arche de la jauge
/// \param k - le coefficient pour convertir la valeur en degrés
///
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
     
    double  xol = xc +30.0*cos((A0+40+Amax/2)*rad) ; // calculation of the center
    double yol = yc - 30.0*sin((A0+40+Amax/2)*rad); // depending on the senter of the central window
      
///
///\brief Dessin du circle central.
/// \details On crée le gradient radial pour en suite instancier la brosse du *painter et dessiner une ellipse avec un gradient de couleur.
///
      QRadialGradient radialGradol(QPointF(xol, yol), 50);
             radialGradol.setColorAt(0, Qt::black);
             radialGradol.setColorAt(1, "#e0e0d1");
      
      painter->setPen(QPen(Qt::transparent));
      painter->setBrush(QBrush(radialGradol));
      painter->drawEllipse(qRound(xol-15),qRound(yol-15),30,30);

     if(l < 1.5 || l > 4.5) {painter->drawPixmap(90,400,40,40, QPixmap(":/I_Oil_red.gif"));}
      else {painter->drawPixmap(90,400,40,40, QPixmap(":/I_Oil_white.gif"));}


///
///\brief Dessin de la flèche.
///\details On crée le gradient linear et un triangle, qu'on remplie avec un gradient de couleur. La position de la pointe de flèche est mathematiquement calculée.
///

    l=static_cast<double>(value);

    k = (Amax+20) * 1.0/valueMax; // angle correction because the radius of a scale is not the same as the radius of the arrow trajectory

   if (l < 0 || l > valueMax) l = (l < 0 ? 0 : valueMax); // condition to set the range and prevent arrow from pointing outside the scale
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

