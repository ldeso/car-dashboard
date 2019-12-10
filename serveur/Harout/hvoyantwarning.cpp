///
///\file hvoyantwarning.cpp
///\brief Classe dérivée de objet_virtuel permettant l'affichage d'un voyant warning clignotant
///
///
#include "hvoyantwarning.h"
#include <QTest>
#include "objet_virtuel.h"

///\details Constructeur de la classe initialisant la variable value de la classe mère, et la variable cligno qui permet de gérer l'affichage alternatif des voyants.

hvoyantwarning::hvoyantwarning()
{
    value=0;
    cligno=0;
}

QRectF hvoyantwarning::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

///
/// \brief hugo_voyants_clignotant::MAJ Fonction de mise à jour de l'affichage.
/// \details La valeur cligno controle l'opacité du painter, permettant de le rendre visible ou non
///
void hvoyantwarning::MAJ()
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

void hvoyantwarning::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

    painter->setRenderHint(QPainter::Antialiasing);

    ///Va chercher la valeur de la variable "valeur" de la classe hvoyant. 1 correspond à l'affichaqge du voyant.
    if (getValue() !=0)

    {
        int x=-10;
        int y=-128;
        QPixmap image("://voyants-_warning.jpg");
        QPixmap image2=image.scaled(20,20);
        QRadialGradient radialGrad(QPointF(x+10, y+10), 15);
        radialGrad.setColorAt(0, QColor(255,0,0,120));
        radialGrad.setColorAt(1, QColor(0,0,0,120));

        QBrush brush(radialGrad);
        painter->setBrush(brush);
        painter->setOpacity(cligno);
        painter->drawPixmap(x,y,20,20,image2);
        painter->drawEllipse(x,y,20,20);

        ///La mise à jour est effectuée à l'aide d'un timer, permettant un affichage alterné.
        MAJ();
    }
}
