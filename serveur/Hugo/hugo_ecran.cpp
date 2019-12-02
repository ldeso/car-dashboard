///
///\file hugo_ecran.cpp
///\brief Classe dérivant de objet_virtuel permettant un affichage en temps réel du temps ainsi que de la distance parcourue depuis le redémarrage du programme
///
#include "hugo_ecran.h"
#include <QTime>

///
/// \brief hugo_ecran::hugo_ecran
///\details Constructeur sans paramètres spécifiques. Initialise simplement la valeur value de la classe mère à 0.
///
hugo_ecran::hugo_ecran()
{
    value=0;
}

QRectF hugo_ecran::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

///
/// \brief hugo_ecran::paint
/// \param painter
///\details La fonction paint va permettre de réaliser un affichage pour le compteur kilometrique et l'heure. Dans un premier temps, affichage des objets fixes, puis on récupère et affiche les différentes variables.
void hugo_ecran::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    ///
    ///\brief Affichage d'un rectangle avec gradient, et effet de luminosité
    ///
    painter->setPen(QPen(QColor(0,0,0,0) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor(0,128,255,15));
    painter->drawRect(-45,25,90,40);
    QRadialGradient radialGrad(QPointF(0, 45), 50);
    radialGrad.setColorAt(0, QColor(0,204,255));
    radialGrad.setColorAt(1, QColor(0, 128, 255));
    painter->setPen(QPen(QColor(0,204,255) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(radialGrad);

    ///
    ///\brief Affichage des différents textes. Le kilométrage est récupéré grâce à la fonction getValue.
    ///
    painter->drawRect(-40,30,80,30);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Arial", 5, -1,false));
    painter->drawText(-38,40,"TIME");
    painter->drawText(-38,55,"TRIP");
    QTime time=QTime::currentTime();
    time.currentTime();
    painter->setFont(QFont("Arial", 9, -1,false));
    painter->drawText(0,45,time.toString("hh.mm"));
    painter->drawText(0,60, QString::number(getValue(),'f', 1));


    painter->setPen(QPen(QColor( 26, 13, 0), 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor( 26,13,0));
}
