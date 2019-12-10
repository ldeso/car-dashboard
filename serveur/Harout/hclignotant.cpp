///
/// \file hclignotant
/// \brief Classe permettant d'afficher les voyants clignotants
///
#include "hclignotant.h"
#include <QDebug>
///
/// \brief hclignotant::hclignotant. Constructeur de la classe.
///\details Constructeur de la classe initialisant la variable value de la classe mère, et la variable cligno qui permet de gérer l'affichage alternatif des voyants.
///

hclignotant::hclignotant()
{
    value=0;
    cligno=0;
}

QRectF hclignotant::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

///
/// \brief hclignotant::MAJ Fonction de mise à jour de l'affichage. La valeur cligno controle l'opacité du painter, permettant de le rendre visible ou non
///
void hclignotant::MAJ()
{
   if (this->cligno==1){
    this->cligno=0;
   }
   else{
       this->cligno=1;
   }
    QTest::qWait(500);
    update();
}

void hclignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

    painter->setRenderHint(QPainter::Antialiasing);///<Antialiasing//

    ///Va chercher la valeur de la variable "valeur" de la classe hvoyant. 1 correspond à l'affichaqge du clignotant droit, -1 à celui du clignotant gauche.
    if (getValue() !=0)
    {
        if (getValue()==-1){
            QPixmap image("://clign-gauche.jpg");
            QPixmap image2=image.scaled(30,30);
            QRadialGradient radialGrad(QPointF(-111+15, -90+15), 15);
            radialGrad.setColorAt(0, QColor(0,255,0));
            radialGrad.setColorAt(1, QColor(0,0,0,120));

            QBrush brush(radialGrad);
            painter->setBrush(brush);
            painter->setOpacity(cligno);
            painter->drawPixmap(-111,-90,30,30,image2);
            painter->drawEllipse(-111,-90,30,30);
        }
        if (getValue()==1){
            QPixmap image("://clign-droit.jpg");
            QPixmap image2=image.scaled(30,30);
            QRadialGradient radialGrad(QPointF(81+15, -90+15), 15);
            radialGrad.setColorAt(0, QColor(0,255,0));
            radialGrad.setColorAt(1, QColor(0,0,0,120));

            QBrush brush(radialGrad);
            painter->setBrush(brush);
            painter->setOpacity(cligno);
            painter->drawPixmap(81,-90,30,30,image2);
            painter->drawEllipse(81,-90,30,30);
        }
        if (getValue()==2){
            QPixmap image("://clign-droit.jpg");
            QPixmap image2=image.scaled(30,30);
            QRadialGradient radialGrad(QPointF(81+15, -90+15), 15);
            radialGrad.setColorAt(0, QColor(0,255,0));
            radialGrad.setColorAt(1, QColor(0,0,0,120));

            QBrush brush(radialGrad);
            painter->setBrush(brush);
            painter->setOpacity(cligno);
            painter->drawPixmap(81,-90,30,30,image2);
            painter->drawEllipse(81,-90,30,30);

            QPixmap image3("://clign-gauche.jpg");
            QPixmap image4=image3.scaled(30,30);
            QRadialGradient radialGrad2(QPointF(-111+15, -90+15), 15);
            radialGrad2.setColorAt(0, QColor(0,255,0));
            radialGrad2.setColorAt(1, QColor(0,0,0,120));

            QBrush brush2(radialGrad2);
            painter->setBrush(brush2);
            painter->setOpacity(cligno);
            painter->drawPixmap(-111,-90,30,30,image4);
            painter->drawEllipse(-111,-90,30,30);
        }

    ///La mise à jour est effectuée à l'aide d'un timer, permettant un affichage alterné
    MAJ();
    }
}

