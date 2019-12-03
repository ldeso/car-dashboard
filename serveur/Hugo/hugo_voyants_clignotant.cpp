///
/// \file hugo_voyants_clignotants
/// \brief Classe permettant d'afficher les voyants clignotants
///
#include "hugo_voyants_clignotant.h"
#include <QDebug>

///
/// \brief hugo_voyants_clignotant::hugo_voyants_clignotant. Constructeur de la classe.
///\details Constructeur de la classe initialisant la variable value de la classe mère, et la variable cligno qui permet de gérer l'affichage alternatif des voyants.
///
hugo_voyants_clignotant::hugo_voyants_clignotant()
{
    value=0;
    cligno=0;
}

QRectF hugo_voyants_clignotant::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

///
/// \brief hugo_voyants_clignotant::MAJ Fonction de mise à jour de l'affichage. La valeur cligno controle l'opacité du painter, permettant de le rendre visible ou non
///
void hugo_voyants_clignotant::MAJ()
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

void hugo_voyants_clignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

    painter->setRenderHint(QPainter::Antialiasing);///<Antialiasing//

    ///Va chercher la valeur de la variable "valeur" de la classe hugo_voyants. 1 correspond à l'affichaqge du clignotant droit, -1 à celui du clignotant gauche.
    if (getValue() !=0)
    {
        if (getValue()==-1){
            QPixmap image(":/Images/clign-gauche.jpg");
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
            QPixmap image(":/Images/clign-droit.jpg");
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
            QPixmap image(":/Images/clign-droit.jpg");
            QPixmap image2=image.scaled(30,30);
            QRadialGradient radialGrad(QPointF(81+15, -90+15), 15);
            radialGrad.setColorAt(0, QColor(0,255,0));
            radialGrad.setColorAt(1, QColor(0,0,0,120));

            QBrush brush(radialGrad);
            painter->setBrush(brush);
            painter->setOpacity(cligno);
            painter->drawPixmap(81,-90,30,30,image2);
            painter->drawEllipse(81,-90,30,30);

            QPixmap image3(":/Images/clign-gauche.jpg");
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
