///
/// \file tachometergauge_lea.cpp
/// \brief Classe jauge de tours/minute, permettant la création d'un compteur paramétrable avec aiguille.
/// \details Classe héritée de objet_virtuel. Utilisée pour l'affichage du compteur rpm. L'appel au constructeur permet d'initialiser la totalité des paramètres, et la fonction paint permet l'affichage.
///


#include "tachometergauge_lea.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>

///
/// \brief TachometerGauge_Lea::TachometerGauge_Lea Constructeur de la classe, permet d'initialiser tous les paramètres
/// \param param_x position horizontale du centre du compteur
/// \param param_y position verticale du centre du compteur
/// \param param_r rayon et taille de l'aiguille
/// \param param_start Angle de départ pour le tracé de l'arc de cercle
/// \param param_end Angle de fin pour le tracé de l'arcle de cercle
/// \param param_spanAngle angle total de cadran
/// \param param_graduation nombre de graduation voulue pour le cadran
/// \param param_param_rpmMax determine le rpm maximum jusqu'à laquelle va le cadran
///

TachometerGauge_Lea::TachometerGauge_Lea(double param_x,double param_y, double param_r,int param_start, int param_spanAngle, int param_graduation, int param_rpmMax )
{
    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    nb_graduation = param_graduation;
    span_angle=param_spanAngle;
    valueMax=param_rpmMax;
    value=0;
}

QRectF TachometerGauge_Lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);

    return rectf;
}

///
/// \brief  Fonction permettant l'affichage du compteur
/// \details Cette fonction construit un compteur en plusieurs étapes : création du cadran, des graduations, ajout du texte sur les graduations, ajout de l'aiguille.
/// \param painter
///

void TachometerGauge_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if (value>=0 && value <=valueMax) {v=value;}
    else if (value<0) {v=0;}
    else {v=valueMax;}
    QPen pen;
    QBrush brush(Qt::SolidPattern);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);

///
/// \brief Création du cadran.
/// \details Le cadran est basé sur un arc de cercle déssiné à l'aide de la fonction drawArc. le cercle est dessiné avec un QPen a qui a été donné une QBrush contenant un gradient radial de couleur bleu.
///
    // ******************** Dessine le gradient au dessus

       QRadialGradient radial(QPointF(x,y),r+10);
       radial.setColorAt(0,Qt::transparent);
       radial.setColorAt(0.98,Qt::blue);
       radial.setColorAt(1,Qt::transparent);
       painter->setPen(QPen(QBrush(radial),20,Qt::SolidLine,Qt::FlatCap));
       painter->drawArc(qRound(x-r-15),qRound(y-r-15),qRound(r*2)+35,qRound(r*2)+35,angle_debut*16, -span_angle*16);
     //met le span angle en negatif pour que l'arc soit déssiné dans le sens des aiguilles d'une montre

///
/// \brief Création des graduations et du texte du cadran.
/// \details Les graduations sont créées en utilisant la fonction drawLine et une boucle for pour changer la couleur des graduations, comme le compteur n'est pas divisé régulièrement, le numéro des graduations sur lesquels les chiffres sont ajoutés sont rentrés à la main.
///

       for (int i=0;i<=nb_graduation;i++)
       {
            int j;
           pen.setColor(Qt::white);
           pen.setWidth(2);
           painter->setPen(pen);
           if (i==0 || i==8 || i==15 || i==22 || i==29 || i==35 || i==41)
           {
               i==41 ? (j=i+1) : (j=i);                                        //i+1 quand on arrive a 41 pour pouvoir avoir 6 quand on le divise par 7
               pen.setWidth(4);
               pen.setColor(Qt::white);
               painter->setPen(pen);
               painter->drawText(qRound(x-10+(r-30)*(cos((angle_debut-(i*span_angle/nb_graduation))*pi/180))),qRound(y+8-(r-30)*(sin((angle_debut-(i*span_angle/nb_graduation))*pi/180))),QString("%1").arg(j/7));
               pen.setColor(Qt::red);
               painter->setPen(pen);

           }
           painter->drawLine(qRound(x+r*(cos((angle_debut-(i*span_angle/nb_graduation))*pi/180))),qRound(y-r*(sin((angle_debut-(i*span_angle/nb_graduation))*pi/180))),qRound(x+(r-10)*(cos((angle_debut-(i*span_angle/nb_graduation))*pi/180))),qRound(y-(r-10)*(sin((angle_debut-(i*span_angle/nb_graduation))*pi/180))));
       }

///
///\brief Création de l'aiguille.
/// \details Dans un premier temps, affichage de l'aiguille à l'aide de la fonction drawPolygon. Puis affichage d'un petit cercle à la base de l'aiguille.
///


       painter->setRenderHints(QPainter::Antialiasing);
       pen.setWidth(1);
       pen.setColor(Qt::red);
       brush.setColor(Qt::red);
       pen.setJoinStyle(Qt::RoundJoin);
       painter->setPen(pen);
       painter->setBrush(brush);
       QPointF points[3] =
       {
             QPointF(x-9*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y+9*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180)),     //xc -9(taille rayon base aiguille)*cos (angle -90(angle droit aiguille))
             QPointF(x+r*(cos((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180)), y-r*(sin((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180))),
             QPointF(x+9*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y-9*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180))
        };

       painter->drawConvexPolygon(points, 3);


   // ******************** Dessine le cercle au centre du cadran par dessus la fin de l'aiguille
       pen.setColor(Qt::transparent);
       QLinearGradient linearGradie(QPointF(385, 185), QPointF(415, 215));
          linearGradie.setColorAt(0,"#9d0409" );
          linearGradie.setColorAt(1,Qt::red);
       QBrush brush9(linearGradie)  ;
       painter->setPen(pen);
       painter->setBrush(brush9);
       painter->drawEllipse(x-20,y-20,40,40);

   brush.setColor(Qt::black);
   QLinearGradient linearGradi(QPointF(415, 215), QPointF(385, 185));
      linearGradi.setColorAt(0, "#9d0409");
      linearGradi.setColorAt(1,"#5e0407");
   QBrush brush8(linearGradi)  ;
   painter->setPen(pen);
   painter->setBrush(brush8);
   painter->drawEllipse(x-15,y-15,30,30);

///
///\brief Création de l'affichage RPM.
///\details L'affichage RPM se fait avec la fonction drawText.
///

   // ******************** Dessine l'affichage de RPM

   QFont font2("Impact",10);
   pen.setColor(Qt::white);
   painter->setPen(pen);
   painter->setFont(font2);
   painter->drawText(qRound(x-50),qRound(y+75),"RPM x 1000");

}
