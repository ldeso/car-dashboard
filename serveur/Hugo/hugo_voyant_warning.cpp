#include <QTest>
#include "hugo_voyant_warning.h"

hugo_voyant_warning::hugo_voyant_warning()
{
    value=0;
    cligno=0;
}


QRectF hugo_voyant_warning::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

///
/// \brief hugo_voyants_clignotant::MAJ Fonction de mise à jour de l'affichage. La valeur cligno controle l'opacité du painter, permettant de le rendre visible ou non
///
void hugo_voyant_warning::MAJ()
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

void hugo_voyant_warning::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

    painter->setRenderHint(QPainter::Antialiasing);///<Antialiasing//

    if (getValue() !=0)///Va chercher la valeur de la variable "valeur" de la classe hugo_voyants. 1 correspond à l'affichaqge du clignotant droit, -1 à celui du clignotant gauche.
    {
        int x=-10;
        int y=-128;
        QPixmap image(":/Images/voyants-_warning.jpg");
        QPixmap image2=image.scaled(20,20);
        QRadialGradient radialGrad(QPointF(x+10, y+10), 15);
        radialGrad.setColorAt(0, QColor(255,0,0,120));
        radialGrad.setColorAt(1, QColor(0,0,0,120));

        QBrush brush(radialGrad);
        painter->setBrush(brush);
        painter->setOpacity(cligno);
        painter->drawPixmap(x,y,20,20,image2);
        painter->drawEllipse(x,y,20,20);

        MAJ();///<La mise à jour est effectuée à l'aide d'un timer, permettant un affichage alterné
    }
}
