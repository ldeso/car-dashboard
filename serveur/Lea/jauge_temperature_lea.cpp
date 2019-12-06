///
///\file jauge_temperature_lea.cpp
/// \brief Classe jauge de température, permettant la création d'une jauge parametrable
/// \details Classe héritée de objet_virtuel. Utilisée pour l'affichage de la jauge d'essence ou de toute autre jauge du même type. L'appel au constructeur permet d'initialiser la totalité des paramètres, et la fonction paint permet l'affichage.
///

#include "jauge_temperature_lea.h"
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtDebug>
#include <QPointF>
///
/// \brief jauge_temperature_lea::jauge_temperature_lea, Constructeur de la classe, permet d'initialiser tous les paramètres ainsi que la valeur value de la classe mère à 50.
/// \param param_x position horizontale du centre du compteur
/// \param param_y position verticale du centre du compteur
/// \param param_r rayon du compteur et taille de l'aiguille
/// \param param_start Angle de départ pour le tracé de l'arc de cercle
/// \param param_spanAngle angle total du cadran
/// \param param_tempMax determine la température max à laquelle va le cadran
///

jauge_temperature_lea::jauge_temperature_lea(double param_x, double param_y, double param_r, int param_start, int param_spanAngle, int param_tempMax)
{
    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    span_angle=param_spanAngle;
    valueMax=param_tempMax;
    value=50;
}

QRectF jauge_temperature_lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);
    return rectf;
}

///
/// \brief jauge_temperature_lea::paint
/// \details Cette fonction construit un compteur en plusieurs étapes : création du cadran, des graduations, ajout du texte sur les graduations, ajout de l'aiguille et du'un pixmap représentant le voyant de température.
/// \param painter
///

void jauge_temperature_lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
///
/// \brief calibration de "value"
/// \details La variable "value" donnée par la fonction getValue() de la classe objet_virtuel est mise a 0 si la valeur entrée est inferieur à 0 et mise à "valueMax" si la valeur entrée est plus grande.
///

    if (value>=50 && value <=valueMax) {v=qRound(value);}
    else if (value<50) {v=50;}
    else {v=valueMax;}
    QPen pen;
    QBrush brush(Qt::SolidPattern);

///
/// \brief Création du cadran.
/// \details Le cadran est basé sur un arc de cercle déssiné à l'aide de la fonction drawArc. le cercle est dessiné avec un QPen a qui a été donné une QBrush contenant un gradient radial de couleur bleu.
///
 // ******************** Dessine l'arc au dessus du compteur

    painter->setRenderHint(QPainter::Antialiasing);

            QRadialGradient radial(QPointF(x+5,y+5),r+15);
            radial.setColorAt(0,Qt::transparent);
            radial.setColorAt(0.95,Qt::blue);
            radial.setColorAt(1,Qt::transparent);
            painter->setPen(QPen(QBrush(radial),20,Qt::SolidLine,Qt::FlatCap));
            painter->drawArc(qRound(x-r-15),qRound(y-r-15),qRound(r*2)+35,qRound(r*2)+35,(angle_debut-2)*16,-(span_angle)*16);
     //met le span angle en negatif pour que l'arc soit déssiné dans le sens des aiguilles d'une montre
            pen.setColor(Qt::transparent);
            pen.setCapStyle(Qt::RoundCap);
            painter->setPen(pen);

///
/// \brief Création des graduations du cadran.
/// \details Les graduations sont créées en utilisant la fonction drawLine et une boucle if pour changer la couleur des graduations en rouge quand on dépasse les 100°et en bleuquand on est en dessous de 70°. Les graduations sont déssinées tous les 20°.
///

 // ******************** Dessine les traits du compteur vitesse
       {     pen.setColor(Qt::white);
            for (int i=50; i<=temperature_max; i+=20)
            {
                pen.setWidth(2);
                pen.setCapStyle(Qt::FlatCap);
                pen.setStyle(Qt::SolidLine);
                painter->setPen(pen);
                painter->drawLine(qRound(x+r*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-r*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(x+(r-10)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-(r-10)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))));

                pen.setColor(Qt::white);
                painter->setPen(pen);
                painter->setRenderHint(QPainter::Antialiasing);
                QFont font("Arial",10, QFont::Bold);
                painter->setFont(font);
            if (i==50 || i==90 || i==130)
                {   pen.setWidth(5);
                if (i>120)
                    pen.setColor(Qt::red);
                if (i<=70)
                    pen.setColor(Qt::blue);
                 painter->setPen(pen);
                 painter->drawLine(qRound(x+r*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-r*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(x+(r-15)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-(r-15)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))));
///
/// \brief Ajout du texte sur les graduations
/// \details Le texte est positionné de la même façon que les graduations, tous les 40°, avec une translation de manière à correspondre le plus possible aux positions des graduations.
///
                 painter->drawText(qRound(x-17+(r-20)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y+8-(r-20)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),QString("%1").arg(i));
                 //ajoute un delta au x (-17) et au y (+8) pour que le texte se retrouve en face des graduations
                }
            }
}

///
///\brief Création de l'aiguille.
/// \details Dans un premier temps, affichage de l'aiguille à l'aide de la fonction drawConvexPolygon. Puis affichage d'un petit cercle à la base de l'aiguille.
///



  // ******************** Dessine l'aiguille

            painter->setRenderHints(QPainter::Antialiasing);
            brush.setStyle(Qt::SolidPattern);
            pen.setWidth(1);
            pen.setColor(Qt::red);
            brush.setColor(Qt::red);
            pen.setJoinStyle(Qt::RoundJoin);
            painter->setPen(pen);
            painter->setBrush(brush);
            QPointF points[3] =
            {
                 QPointF(x-3*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y+3*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180)),     //xc -9(taille rayon base aiguille)*cos (angle -90(angle droit aiguille))
                 QPointF(x+r*(cos((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180)), y-r*(sin((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180))),
                 QPointF(x+3*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y-3*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180))
            };

            painter->drawConvexPolygon(points, 3);

  // ******************** Dessine le cercle au centre du cadran par dessus la fin de l'aiguille(deux cercles l'un sur l'autre avec un gradient linéaire inversé
                    pen.setColor(Qt::transparent);
                    QLinearGradient linearGradie(QPointF(x-15, y-15), QPointF(x+15, y-15));
                       linearGradie.setColorAt(0,"#9d0409" );
                       linearGradie.setColorAt(1,Qt::red);
                    QBrush brush9(linearGradie)  ;
                    painter->setPen(pen);
                    painter->setBrush(brush9);
                    painter->drawEllipse(x-10,y-10,20,20);

                brush.setColor(Qt::black);
                QLinearGradient linearGradi(QPointF(x+15, y+15), QPointF(x-15, y-15));
                   linearGradi.setColorAt(0, "#9d0409");
                   linearGradi.setColorAt(1,"#5e0407");
                QBrush brush8(linearGradi)  ;
                painter->setPen(pen);
                painter->setBrush(brush8);
                painter->drawEllipse(x-5,y-5,10,10);
///
/// \brief Création de l'icone de température de couleur blanche et devenant rouge l'orsqu'on passe au dessus des 100°.
/// \details Les voyants sont obtenus via un drawPixmap dans une boucle if pour changer le pixmap en fonction de la "value" de la température.
///

 // ******************** Dessine le pixmap icone de température avec changement de couleur quand il dépasse les 90°
      if (value<100)
      {
          QPixmap voyant (":/Lea/Icones_Voyants/engineT_white.gif");
          QPixmap voyant2= voyant.scaled(40,40);
          painter->drawPixmap(x-35,y-90,voyant2);
      }
      else
      {
          QPixmap voyant (":/Lea/Icones_Voyants/engineT_red.gif");
          QPixmap voyant2= voyant.scaled(40,40);
          painter->drawPixmap(x-35,y-90,voyant2);
      }

}
