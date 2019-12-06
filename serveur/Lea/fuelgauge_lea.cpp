///
/// \file fuelgauge_lea.cpp
/// \brief Classe jauge d'essence, permettant la création d'une jauge paramétrables .
/// \details Classe héritée de objet_virtuel. Utilisée pour l'affichage de la jauge d'essence ou de toute autre jauge du même type. L'appel au constructeur permet d'initialiser la totalité des paramètres, et la fonction paint permet l'affichage.
///

#include "fuelgauge_lea.h"
#include <iostream>
#include <vector>
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>

///
/// \brief FuelGauge_lea::FuelGauge_lea, Constructeur de la classe, permet d'initialiser tous les paramètres ainsi que la valeur value de la classe mère à 30
/// \param param_x position horizontale du coin en haut à gauche du rectangle définissant la jauge
/// \param param_y position verticale coin en haut à gauche du rectangle définissant la jauge
/// \param param_width largeur voulue de la jauge
/// \param param_height hauteur voulue de la jauge
/// \param param_x2 position horizontale du coin en haut à gauche de la position de la lettre F (Full)
/// \param param_y2 position verticale du coin en haut à gauche de la position de la lettre F (Full)
/// \param param_x3 position horizontale du coin en haut à gauche de la position de la lettre E (Empty)
/// \param param_y3 position verticale coin du coin en haut à gauche de la position de la lettre F (Empty)
///

FuelGauge_lea::FuelGauge_lea(double param_x, double param_y, double param_width, double param_height, double param_x2, double param_y2, double param_x3, double param_y3)
{
    x=param_x;
    y=param_y;
    width=param_width;
    height=param_height;
    x2=param_x2;
    y2=param_y2;
    x3=param_x3;
    y3=param_y3;
    value = 30;
}

QRectF FuelGauge_lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);
    return rectf;
}

///
/// \brief  FuelGauge_lea::paint Fonction permettant l'affichage du compteur
/// \details Cette fonction construit un compteur en plusieurs étapes : création du cadre de la jauge, des rectangles indiquant le niveau d'essence, du E et du F ainsi que l'icone/voyant d'essence.
/// \param painter
///

void FuelGauge_lea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

///
/// \brief Création du cadre.
/// \details Le cadre est basé sur un rectangle obtenu avec un drawRect parametrable.
///

    QPen pen;
    QBrush brush(Qt::SolidPattern);
    painter->setRenderHint(QPainter::Antialiasing);
    pen.setColor(Qt::white);
    brush.setColor(Qt::transparent);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(qRound(x),qRound(y),qRound(width),qRound(height));

///
/// \brief Création des graduations du cadre.
/// \details Les graduations sont obtenus avec un drawLine d'un vecteur(pour automatiser le dessin avec un interval constant), ici 6 graduations seont déssinées representant le 0%, 20%, 40%, 60%, 80% et 100%.
///

    std::vector<QLineF> vector_line;
    for(int j=0; j<6; j++)
        vector_line.push_back(QLineF(qRound(x-10),qRound((y+height)-j*(height/5)),qRound(x),qRound((y+height)-j*(height/5))));
    for (int j=0; j<6; j++)
        painter->drawLine(vector_line[j]);

///
/// \brief Création des rectangle amplissant le cadre.
/// \details Les rectangles sont obtenus avec un drawRect d'un vecteur(pour automatiser le dessin avec un interval constant), ici 10 rectangles sont déssinées representant chacun 10% du niveau d'essence.
///

    brush.setColor(Qt::white);
    pen.setColor(Qt::transparent);
    painter->setBrush(brush);
    painter->setPen(pen);

    std::vector<QRectF> vector_rect;
    if (value<25)
    {
        brush.setColor(Qt::red);
        painter->setBrush(brush);
     }
    for(int i=0; i<10; i++)
        vector_rect.push_back(QRectF((x+3),(((y+height)-7)-i*(height/10)),(width-6),((height/10)-3)));   //rentre les différents rectangles de la jauge d'essence
    for (int i=0;i<qRound(value*0.1f);i++)                           //value donnee en pourcentage et transformée en ordre d'entrée dans la liste du vecteur
        painter->drawRect(vector_rect[i]);
    pen.setColor(Qt::white);
    painter->setPen(pen);
    painter->drawText(x2,y2,"E");
    painter->drawText(x3,y3,"F");


///
/// \brief Création de l'icone d'essence de couleur blanche et devenant rouge l'orsqu'on passe en dessous de 25% d'essence.
/// \details Les voyants sont obtenus via un drawPixmap dans une boucle if pour changer le pixmap en fonction de la "value" d'essence(devient rouge quand le niveau passe en dessous de 25%).
///
    // ******************** Dessine l'icone blanche ou rouge de l'essence

    if (value<25)
    {
        QPixmap voyant (":/Lea/Icones_Voyants/fuelL_red.gif");
        QPixmap voyant2= voyant.scaled(40,40);
        painter->drawPixmap(x-70,y+70,voyant2);
    }
    else
    {
     QPixmap voyant (":/Lea/Icones_Voyants/fuelL_white.gif");
     QPixmap voyant2= voyant.scaled(40,40);
     painter->drawPixmap(x-70,y+70,voyant2);
    }
}
