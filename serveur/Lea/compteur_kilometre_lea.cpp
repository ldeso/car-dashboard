///
///\file compteur_kilometre_lea.cpp
///\brief Classe dérivant de objet_virtuel permettant un affichage en temps réel de la distance parcourue depuis le démarrage du programme.
///
#include "compteur_kilometre_lea.h"
#include <QTime>
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>


///
/// \brief Compteur_kilometre_lea::Compteur_kilometre_lea Constructeur de la classe, permet d'initialiser tous les paramètres ainsi que la valeur value de la classe mère à 0
/// \param param_x position horizontale du coin en haut à gauche du rectangle dans lequel apparaitra le compteur kilométrique.
/// \param param_y position verticale du coin en haut à gauche du rectangle dans lequel apparaitra le compteur de kilométrique.
///

Compteur_kilometre_lea::Compteur_kilometre_lea(int param_x, int param_y)
{
    x= param_x;
    y=param_y;
    value =0;
}

QRectF Compteur_kilometre_lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);
    return rectf;
}

///
/// \brief Compteur_kilometre_lea::paint
/// \param painter
/// \details La fonction paint va permettre de réaliser un affichage pour le compteur kilometrique et de récupérer le kilometrage avec la fonction getValue().
///
void Compteur_kilometre_lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::white);
    painter->setPen(pen);

    QRectF affiche_km_totaux (x,y,150,15);
    painter->drawRoundedRect(affiche_km_totaux,2,2);

    QRectF affiche_km_trip_A (x,y+30,150,15);
    painter->drawRoundedRect(affiche_km_trip_A,2,2);
    QRectF affiche_km_trip_A_texte (x+85,y+30,60,15);
    QRectF affiche_time (x+30, y+60, 100, 15);
    painter->drawRoundedRect(affiche_time,2,2);
    QTime time=QTime::currentTime();
    time.currentTime();

 // ******************** Dessine le texte de la valeur du compteur kilométrique, des kilomètres totaux parcourus et de l'heure.
    QFont font("Seven Segment",10,QFont::Bold);
    painter->setFont(font);
    painter->drawText(affiche_km_totaux, Qt::AlignRight ,QString("%1  ").arg(271963+getValue()));
    painter->drawText(affiche_km_trip_A_texte, Qt::AlignLeft ,QString::number(getValue(),'f',1));
 //donne un équivalent du numéro en String avec le format "f"(float) et une précision de un chiffre après la virgule.
    painter->drawText(affiche_time,Qt::AlignRight,time.toString("hh.mm "));

    QFont font2("Arial",10,QFont::Bold);
    painter->setFont(font2);
    painter->drawText(affiche_km_trip_A, Qt::AlignLeft ,QString("   TRIP A"));
    painter->drawText(affiche_km_trip_A_texte, Qt::AlignRight ,QString("km "));
    painter->drawText(affiche_time, Qt::AlignLeft ,QString("   Time"));
    painter->drawText(affiche_km_totaux, Qt::AlignLeft ,QString("   ODOMETRE"));
}
