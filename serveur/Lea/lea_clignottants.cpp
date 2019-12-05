///
///\file lea_clignottants.cpp
///\brief Classe dérivée de objet_virtuel permettant l'affichage d'un voyant clignotant droite ou gauche
///


#include "lea_clignottants.h"
#include <QDebug>
///
/// \brief lea_clignottants::lea_clignottants Constructeur de la classe
///\details Constructeur de la classe initialisant la variable value de la classe mère, et la variable cligno qui permet de gérer l'affichage alternatif des voyants.

lea_clignottants::lea_clignottants()
{
    value=0;
    cligno=0;
}


QRectF lea_clignottants::boundingRect() const
{
    QRectF rectf(0,0,1000,500);

    return rectf;
}


void lea_clignottants::paint(QPainter *painter, const QStyleOptionGraphicsItem* , QWidget* )
{
    painter->setRenderHint(QPainter::Antialiasing);

    if (getValue() !=0)
    {
        if (getValue()==-1){
            QPixmap image(":/Lea/Icones_Voyants/turnLeft.gif");
            QPixmap image2=image.scaled(30,30);
            painter->setOpacity(cligno);
            painter->drawPixmap(380,50,70,50,image2);

        }
        if (getValue()==1){
            QPixmap image(":/Lea/Icones_Voyants/turnRight.gif");
            QPixmap image2=image.scaled(30,30);

            painter->setOpacity(cligno);
            painter->drawPixmap(780,50,70,50,image2);

        }
        if (getValue()==2){
            QPixmap image(":/Lea/Icones_Voyants/turnRight.gif");
            QPixmap image2=image.scaled(30,30);

            painter->setOpacity(cligno);
            painter->drawPixmap(780,50,70,50,image2);

            QPixmap image3(":/Lea/Icones_Voyants/turnLeft.gif");
            QPixmap image4=image3.scaled(30,30);

            painter->setOpacity(cligno);
            painter->drawPixmap(380,50,70,50,image4);
        }
         MAJ();
//        update();
    }
}

///
/// \brief lea_clignottants::MAJ Fonction de mise à jour de l'affichage.
/// \details La valeur cligno controle l'opacité du painter, permettant de le rendre visible ou non. La mise à jour est effectuée à l'aide d'un timer, permettant un affichage alterné.
///


void lea_clignottants::MAJ()
{
    if (this->cligno==1.0){
     this->cligno=0.0;
    }
    else{
        this->cligno=1.0;
    }
     QTest::qWait(500);
     //update();
}
