#include "Inna/fuellevelinna.h"
#include "objet_virtuel.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>

///
/// \file fuellevelinna.cpp
/// \brief Classe FuelLevelInna derivée de la classe objet_virtuel
/// \details Permettant la création de l' aiguille de la jauge du niveu d'essence qui tourne en fonction de la valeur "value".
///
/// \param value - la valeur du niveau d'essence
/// \param valueMax - le niveau d'd'essence maximum
/// \param A0 - l'aunge de debut de la jauge
/// \param Amax - l'ampleur de la jauge
/// \param r - le rayon de l'arche de la jauge
/// \param k - le coefficient pour convertir la valeur en degrés
///
FuelLevelInna::FuelLevelInna(objet_virtuel *parent) :  objet_virtuel(parent)

{   value = 0;
    A0 = 0 ;
    Amax = 90 ;
    r = 100.0 ;
    valueMax = 100;

}

FuelLevelInna::FuelLevelInna(int ALPHA0, int ALPHAMAX)
{
    value = 100;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100.0 ;
    valueMax = 100;

}

QRectF FuelLevelInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void FuelLevelInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{   valueMax = 100;
    painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
    double xf=xc + 30.0*cos((A0+220+Amax/2)*rad);
    double yf=yc-30.0*sin((A0+220+Amax/2)*rad);
    ///
    ///\brief dessin du circle central
    /// \details On crée le gradient radial pour en suite instancier la brosse du *painter et dessiner une ellipse avec un gradient de couleur.

        QRadialGradient radialGradol(QPointF(xf, yf), 50);
        radialGradol.setColorAt(0, Qt::black);
        radialGradol.setColorAt(1, "#e0e0d1");
        painter->setPen(QPen(Qt::transparent));
        painter->setBrush(QBrush(radialGradol));
        painter->drawEllipse(qRound(xf-15),qRound(yf-15),30,30);

        ///
        ///\brief Dessin de la flèche.
        ///\details On crée le gradient linear et un triangle, qu'on remplie avec un gradient de couleur. La position de la pointe de flèche est mathematiquement calculée.
        ///
    l = static_cast<double>(value);

    if (l < 0.0 || l > 100.0) l = (l < 0.0 ? 0.0 : 100.0);// condition to set the range and prevent arrow from pointing outside the scale


        k = (Amax+20)*0.01; // angle correction because the radius of a scale is not the same as the radius of the arrow trajectory

        QLinearGradient linearGradol  (QPointF(xf-(5*cos((A0+230+k*l-90)*rad)),yf+(5*sin((A0+230+k*l-90)*rad))), QPointF(xf+(7*cos((A0+230+k*l-90)*rad)),yf-(7*sin((A0+230+k*l-90)*rad))));
            linearGradol.setColorAt(0, "#F93737");
            linearGradol.setColorAt(0.5, "#ff4d4d");
            linearGradol.setColorAt(1, "#F93737");

        painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
        //painter->drawLine(xc,yc, xc+160*cos((225-shift)*rad),yc-160*sin((225-shift)*rad));
        painter->setBrush(QBrush(linearGradol));
        QPointF pointsF[3] = {
            QPointF(xf-(5*cos((A0+230+k*l-90)*rad)),yf+(5*sin((A0+230+k*l-90)*rad))),
            QPointF(xf+(r-15)*cos((A0+230+k*l)*rad),yf-5-(r-15)*sin((A0+230+k*l)*rad)),
            QPointF(xf+(5*cos((A0+230+k*l-90)*rad)),yf-(5*sin((A0+230+k*l-90)*rad))),
           };

        painter->drawConvexPolygon(pointsF, 3);

        ///
        ///\brief dessin de l'icone du niveau d'essence
        ///

        if (l >= 0 && l <=20.0)
                painter->drawPixmap(1270,380,50,50, QPixmap(":/I_fuelL_red.gif"));
        else
                painter->drawPixmap(1270,380,50,50, QPixmap(":/I_fuelL_white.gif"));



}
