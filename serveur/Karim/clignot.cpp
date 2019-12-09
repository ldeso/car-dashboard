///
///\file clignot.cpp
/// \brief Classe dérivant de objet_virtuel permettant l'affichage des voyants clignotant.
///

#include "Karim/clignot.h"
#include <QPainter>
#include "Karim/voyants_karim.h"
#include <QTest>

/**
 * @brief clignot::clignot
 * @details constructeur par défaut
 */
clignot::clignot(QGraphicsItem*)
{
    value=0;
    cligno=0;
}

/**
 * @brief clignot::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF clignot::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

/**
 * @brief clignot::paint
 * @param painter
 * @details dessine les clignotants
 */
void clignot::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if (getValue() !=0)
    {
        if (getValue()==-1){
            QPixmap pix(":/Icones/clignotg.jpg");
            painter->setOpacity(cligno);
            painter->drawPixmap(-500,-200,50,50,pix);
        }
        if (getValue()==1){
            QPixmap pix(":/Icones/clignotd.jpg");
            painter->setOpacity(cligno);
            painter->drawPixmap(250,-200,50,50,pix);
        }
        if (getValue()==2){
            QPixmap pix(":/Icones/clignotd.jpg");
            painter->setOpacity(cligno);
            painter->drawPixmap(250,-200,50,50,pix);

            QPixmap pix2(":/Icones/clignotg.jpg");
            painter->setOpacity(cligno);
            painter->drawPixmap(-500,-200,50,50,pix2);
        }

    MAJ();
    }
}

/**
 * @brief clignot::MAJ
 * @param painter
 * @details fonction qui fait clignoter
 */
void clignot::MAJ()
{
   if (this->cligno==1){
    this->cligno=0;
   }
   else{
       this->cligno=1;
   }
    QTest::qWait(80);
    update();
}
