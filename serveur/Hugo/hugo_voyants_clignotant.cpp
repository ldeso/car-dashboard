///
/// Classe permettant d'afficher les voyants pouvant clignoter
///
#include "hugo_voyants_clignotant.h"
#include <QDebug>

///
/// \brief hugo_voyants_clignotant::hugo_voyants_clignotant Constructeur avec initialisation des paramètres de la classe
///
hugo_voyants_clignotant::hugo_voyants_clignotant()
{
    value=0;
    cligno=0;
}

QRectF hugo_voyants_clignotant::boundingRect() const
{
    return QRect(-800,-450,1600,900);
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

void hugo_voyants_clignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setRenderHint(QPainter::Antialiasing);///<Antialiasing//

    if (getValue() !=0)///Va chercher la valeur de la variable "valeur" de la classe hugo_voyants. 1 correspond à l'affichaqge du clignotant droit, -1 à celui du clignotant gauche.
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

    MAJ();///<La mise à jour est effectuée à l'aide d'un timer, permettant un affichage alterné
    }
}
