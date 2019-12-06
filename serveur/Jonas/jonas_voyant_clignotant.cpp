#include "jonas_voyant_clignotant.h"
#include <QTest>

/**
 * @brief jonas_voyant_clignotant::jonas_voyant_clignotant
 * @details constructeur par défaut
 */
jonas_voyant_clignotant::jonas_voyant_clignotant()
{
    value = 0;
    enabled = 1;
}

/**
 * @brief jonas_voyant_clignotant::updateTurn
 * @details permet d'alterner l'affichage des clignotants
 */
void jonas_voyant_clignotant::updateTurn()
{
    if (this->enabled==1){
     this->enabled=0;
    }
    else{
        this->enabled=1;
    }
//    QTest::qWait(500);
//    update();
}

/**
 * @brief jonas_voyant_clignotant::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF jonas_voyant_clignotant::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

/**
 * @brief jonas_voyant_clignotant::paint
 * @param painter
 * @details dessine les clignotants
 */
void jonas_voyant_clignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    if (value!=0) {
        if (value==-1) {
            QPixmap image(":/icons/icon-turn-left.jpg");
            QPixmap turnLeft = image.scaled(25,25);
            painter->setOpacity(enabled);
            painter->drawPixmap(-145, -145, turnLeft);
        }

        if (value==1) {
            QPixmap image(":/icons/icon-turn-right.jpg");
            QPixmap turnRight = image.scaled(25,25);
            painter->setOpacity(enabled);
            painter->drawPixmap(138, -145, turnRight);
        }
        if (value==2) {
            QPixmap image(":/icons/icon-turn-left.jpg");
            QPixmap image1(":/icons/icon-turn-right.jpg");
            painter->setOpacity(enabled);
            painter->drawPixmap(-145, -145, 25, 25, image);
            painter->drawPixmap(138, -145, 25, 25, image1);
        }
        updateTurn();
    }
}
