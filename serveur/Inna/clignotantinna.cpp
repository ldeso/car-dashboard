///
/// \file clignotantinna.cpp
/// \brief Classe permettant d'afficher les voyants clignotants
///
///
#include "clignotantinna.h"
#include "Inna/iconinna.h"
#include <QPainter>
#include <QDebug>
#include <QTest>
 ///
/// \brief clignotantInna::clignotantInna -  Constructeur de la classe.
///\details Constructeur de la classe initialisant la variable _value_ de la classe mère, et la variable _cligno_ qui permet de gérer l'affichage alternatif des voyants.
///
clignotantInna::clignotantInna(IconInna *parent) : IconInna (parent)
{   value = 2;
    cligno = 0;
    this->setZValue(5.0);
}

QRectF clignotantInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void clignotantInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{  painter->setRenderHint(QPainter::Antialiasing);

 /// Va chercher la valeur de la variable _value_ de la classe clignotantInna.
 /// value = 1 correspond à l'affichaqge du clignotant droit
 /// value = -1 correspond à l'affichaqge du clignotant gauche
 /// value = 2 correspond à l'affichaqge des clignotants droit et gauche au même temps

    mode = qRound(value); // mode is ineger and value is float
    if  (mode != 0)
    {if (mode == -1)
        {painter->setOpacity(cligno);
        painter->drawPixmap(630,160,50,50, QPixmap(":/I_turnLeft.gif"));
        }

     if (mode == 1)
        {painter->setOpacity(cligno);
        painter->drawPixmap(730,230,50,50, QPixmap(":/I_turnRight.gif"));
        }

    if (mode == 2)
        {painter->setOpacity(cligno);
         painter->drawPixmap(630,230,50,50, QPixmap(":/I_turnLeft.gif"));
         painter->drawPixmap(730,230,50,50, QPixmap(":/I_turnRight.gif"));
         }
    MAJ();
    }

   else
    {   painter->setPen(Qt::transparent);
        painter->setBrush(QBrush(Qt::transparent));
        painter->drawRect(500,120,50,50);
    }


}
///
/// \brief clignotantInna::MAJ() Fonction de mise à jour de l'affichage. La valeur _cligno_ controle l'opacité du painter, permettant de le rendre visible ou non
///
void clignotantInna::MAJ()
{cligno = !cligno;
 QTest::qWait(300);//
 update();
}
