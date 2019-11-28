
#include "hugo_compteur.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>
#define pi 3.14159265


hugo_Compteur::hugo_Compteur()
{

}


QRectF hugo_Compteur::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void hugo_Compteur::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing);///<Mise en place Antialiasing//

    ///
    /// \brief La première étape est la création de l'arc de cercle servant de support au cadran.
    /// L'option critique permet d'ajouter une autre couleur à une partie du cadran
    ///
    QRect carre_rpm(x-r,y-r,2*r,2*r);
    painter->setPen(QPen( couleur ,2, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre_rpm,start_angle*16,(end_angle-start_angle)*16);
    painter->setPen(QPen(couleurgrad ,5, Qt::SolidLine,Qt::FlatCap));
    for (int i=1;i<5;i++){
        QRect carre_grad(x-(r-i),y-(r-i),2*(r-i),2*(r-i));
        painter->drawArc(carre_grad,start_angle*16,(end_angle-start_angle)*16);
    }
    if (critique!=100){
        painter->setPen(QPen( QColor(0,0,0) ,5, Qt::SolidLine,Qt::FlatCap));
        for (int i=1;i<5;i++){
            QRect carre_grad(x-(r-i),y-(r-i),2*(r-i),2*(r-i));
            painter->drawArc(carre_grad,98*16,-39*16);
        }
        painter->setPen(QPen( couleur2 ,2, Qt::SolidLine,Qt::FlatCap));
        painter->drawArc(carre_rpm,98*16,-39*16);
        painter->setPen(QPen( couleurgrad2 ,5, Qt::SolidLine,Qt::FlatCap));
        for (int i=1;i<5;i++){
            QRect carre_grad(x-(r-i),y-(r-i),2*(r-i),2*(r-i));
            painter->drawArc(carre_grad,98*16,-39*16);
        }
    }

    ///
    ///\brief Création des graduations en deux boucles (grandes et petites graduations)
    ///
    painter->setPen(QPen( couleur ,1, Qt::SolidLine,Qt::FlatCap));
    int compteur=0;
    while (compteur<=nbre_graduations)
    {
        float i=start_angle*1.0+compteur*(end_angle*1.0-start_angle*1.0)/(nbre_graduations*1.0);
        if (compteur>critique){
            painter->setPen(QPen( couleur2 ,1, Qt::SolidLine,Qt::FlatCap));
        }
        painter->drawLine((r-10)*qCos(i*(pi/180))+x,-(r-10)*qSin(i*(pi/180))+y,(r)*qCos(i*(pi/180))+x,-(r)*qSin(i*(pi/180))+y);
        compteur++;
    }
    compteur=0;
    painter->setPen(QPen( couleur ,1, Qt::SolidLine,Qt::FlatCap));
    while (compteur<=nbre_graduations-1)
    {
        float i=start_angle*1.0+(end_angle*1.0-start_angle*1.0)/(nbre_graduations*2.0)+compteur*(end_angle*1.0-start_angle*1.0)/(nbre_graduations*1.0);
        if (compteur>critique){
            painter->setPen(QPen( couleur2 ,1, Qt::SolidLine,Qt::FlatCap));
        }
        painter->drawLine((r-5)*qCos(i*(pi/180))+x,-(r-5)*qSin(i*(pi/180))+y,(r)*qCos(i*(pi/180))+x,-(r)*qSin(i*(pi/180))+y);
        compteur++;
    }

    ///
    /// \brief Ajout du texte sur les graduations
    ///
    int j=0;
    painter->setPen(QPen(QColor(Qt::darkGray) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Arial", 9, -1,false));
    compteur=0;
    while (compteur<=nbre_graduations)
    {
        float i=start_angle*1.0+compteur*(end_angle*1.0-start_angle*1.0)/(nbre_graduations*1.0);
        painter->drawText(qCos(i*pi/180)*(r-20)+x-11,-qSin(i*pi/180)*(r-20)+y+3,graduations[j]);
        j++;
        compteur++;
    }

    ///
    ///\brief Mise en place de l'aiguille
    ///
    painter->setPen(QPen(QColor(Qt::darkGray) , 1, Qt::SolidLine,Qt::FlatCap));
    QRect carre_aiguille(x-10,y-10,20,20);
    painter->drawEllipse(carre_aiguille);///<Cercle au centre de l'aiguille//
    QRect carre_aiguille2(x-8,y-8,16,16);
    QLinearGradient linearGrad(QPointF((x+10*qCos(135*pi/180)), (y-10*qSin(135*pi/180))), QPointF(x, y));
    linearGrad.setColorAt(0, QColor(200,200,200,80));
    linearGrad.setColorAt(1, QColor(0,0,0,0));
    painter->setBrush(linearGrad);
    painter->setPen(QPen(QColor(30,30,30) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->drawEllipse(carre_aiguille2);///<Dégradé à la base de l'aiguille pour donner une impression de relief//

    ///
    /// \brief Création d'un polygone pour représenter l'aiguille, et affichage
    ///
    QPointF points[4]={
        QPointF(x,y),
        QPointF(x+(r/4)*qCos((angle+8)*pi/180),y+(r/4)*qSin((angle+8)*pi/180)),
        QPointF(x+r*qCos(angle*pi/180),y+r*qSin(angle*pi/180)),
        QPointF(x+(r/4)*qCos((angle-8)*pi/180),y+(r/4)*qSin((angle-8)*pi/180)),
    };
    painter->setPen(QPen(QColor(Qt::white), 0.5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setBrush(QColor(Qt::darkRed));
    painter->drawPolygon(points,4);

    ///
    /// \brief Affichage d'un effet verre en superposant un cercle transparent avec gradient blanc->noir sur le cadran//
    ///
    QRect carre(x-r_verre,y-r_verre,2*r_verre,2*r_verre);
    painter->setPen(QPen( QColor(0,0,0,0) ,1, Qt::SolidLine,Qt::FlatCap));
    if (direction_grad==1){
        QLinearGradient linearGrad(QPointF((x+r_verre*qCos(135*pi/180)), (y-r_verre*qSin(135*pi/180))), QPointF(x, y));
        linearGrad.setColorAt(0, QColor(255,255,255,80));
        linearGrad.setColorAt(1, QColor(0,0,0,0));
        QBrush brush(linearGrad);
        painter->setBrush(brush);
        painter->drawEllipse(carre);}
    else if (direction_grad==-1){
        QLinearGradient linearGrad(QPointF((x+r_verre*qCos(135*pi/180)), (y-r_verre*qSin(135*pi/180))), QPointF(x, y));
        linearGrad.setColorAt(0, QColor(255,255,255,30));
        linearGrad.setColorAt(1, QColor(0,0,0,0));
        QBrush brush(linearGrad);
        painter->setBrush(brush);
        painter->drawEllipse(carre);
    }
}

///
/// \brief hugo_Compteur::Parametrage : fonction permettant de parmaétrer le compteur
/// \param param_x position horizontale du centre du compteur
/// \param param_y position verticale du centre du compteur
/// \param param_r rayon
/// \param param_start_angle Angle de départ pour le tracé de l'arc de cercle
/// \param param_end_angle Angle de fin pour le tracé de l'arcle de cercle
/// \param param_graduations QStringList des textes à afficher sur les graduations. Le nombre d'éléments correspondra au nombre de grandes graduations
/// \param param_value valeur max de la quantité représentée par le compteur, utile pour le calcul du rapport angle de l'aiguille / valeur à afficher
/// \param param_r_verre permet de varier la surface du disc pour l'effet de verre
/// \param param_direction_grad permet de varier la direction du gradient : +1 = blanc-->noir, -1= noir-->blanc
/// \param red Couleurs rgb de l'arc de cercle et des graduations
/// \param green
/// \param blue
/// \param param_critique Parmètre optionnel, graduation à partir de laquelle un changement de couleur doit être effectué sur le compteur
/// \param red2 Couleur optionnelle,
/// \param green2
/// \param blue2
///
void hugo_Compteur::Parametrage(int param_x, int param_y, int param_r,int param_start_angle, int param_end_angle,QStringList param_graduations,int param_value,int param_r_verre,int param_direction_grad,int red,int green,int blue,int param_critique, int red2,int green2,int blue2)
{
    x=param_x;
    y=param_y;
    r=param_r;
    start_angle=param_start_angle;
    end_angle=param_end_angle;
    nbre_graduations=param_graduations.length()-1;
    graduations=param_graduations;
    couleur=QColor(red,green,blue);
    couleurgrad=QColor(red,green,blue,20),
    critique=param_critique;
    couleur2=QColor(red2,green2,blue2);
    couleurgrad2=QColor(255,green2,blue2,20);
    value=param_value;
    direction_grad=param_direction_grad;
    r_verre=param_r_verre;
}

///
/// \brief hugo_Compteur::setValue Setter qui permet de positionner l'aiguille en fonction de ce que l'on désire afficher
/// \param v Paramètre d'entrée
///
void hugo_Compteur::setValue(int v)
{
    angle=((1.0*(start_angle-end_angle))/(value*1.0))*v*1.0+(360-start_angle);
}

///
/// \brief hugo_Compteur::getValueMax Renvoie la valeur max que le compteur peut afficher
/// \return
///
int hugo_Compteur::getValueMax()
{
    return value;
}

