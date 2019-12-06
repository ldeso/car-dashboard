///
///\file hugo_boite_vitesse.cpp
/// \brief Classe dérivant de objet_virtuel permettant l'affichage du mode de transmission automatique du véhicule.
///
#include "hugo_boite_vitesse.h"

///
/// \brief hugo_boite_vitesse::hugo_boite_vitesse
///\details Initialise la variable value de la classe mère à 1 i.e. au mode P (Park)
hugo_boite_vitesse::hugo_boite_vitesse()
{
    value=1;
}

QRectF hugo_boite_vitesse::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

///
/// \brief hugo_ecran::paint
/// \param painter
///\details La fonction paint va permettre l'affichage des différents modes P,R,N,D,3,2,L suivant un arc de cercle autour du compteur vitesse.
/// L'affichage se fait par l'intermédiaire d'une boucle. Si l'itérateur correspond à value, le mode de transmission est affiché en vert avec un effet
/// de halo autour.
///
void hugo_boite_vitesse::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setFont(QFont("Arial", 8, -1,false));
    painter->setPen(QPen(QColor(Qt::darkGray), 1, Qt::SolidLine,Qt::FlatCap));
    QStringList Regimes;
    Regimes<<"P"<<"R"<<"N"<<"D"<<"3"<<"2"<<"L";
    float teta=-30*3.14159/180;//Angle de départ pour l'arc de cercle qui va servir de support aux caractères
    int i=0;
    while (i<7){
        teta+=10*3.14159/180;//Mise à jour de l'angle (mouverment de 10 degrés)
        if (i==getValue()-1){//Le -1 vient du fait que la liste commence à 0.
            QRadialGradient radialGrad(QPointF(110*(qCos(teta))+4,110*(qSin(teta))-3), 12);//Mise en place d'un gradient circulaire vert
            radialGrad.setColorAt(0, QColor(0,255,0,80));
            radialGrad.setColorAt(1, QColor(0,0,0,0));
            painter->setPen(QPen(QColor(0,0,0,0) , 1, Qt::SolidLine,Qt::FlatCap));
            painter->setBrush(radialGrad);
            painter->drawEllipse(QPointF(110*(qCos(teta))+4,110*(qSin(teta))-3),20,20);
            painter->setPen(QPen(QColor(Qt::green), 1, Qt::SolidLine,Qt::FlatCap));//Ecriture en vert
        }
        else{
            painter->setPen(QPen(QColor(Qt::darkGray), 1, Qt::SolidLine,Qt::FlatCap));//Ecriture en blanc
        }
        painter->drawText(110*(qCos(teta)),110*(qSin(teta)),Regimes[i]);
        i++;
    }
}
