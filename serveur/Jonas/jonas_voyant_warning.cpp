#include "jonas_voyant_warning.h"
#include <QTest>

/**
 * @brief jonas_voyant_warning::jonas_voyant_warning
 */
jonas_voyant_warning::jonas_voyant_warning()
{
    value = 0;
    enabled = 1;
}

/**
 * @brief jonas_voyant_warning::updateWarning
 * @details permet d'alterner l'affichage du warning avec les clignotants
 */
void jonas_voyant_warning::updateWarning()
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
 * @brief jonas_voyant_warning::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF jonas_voyant_warning::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

/**
 * @brief jonas_voyant_warning::paint
 * @param painter
 * @details dessine l'icône des warning
 */
void jonas_voyant_warning::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);

    if (value!=0) {
        QPixmap image(":/icons/icon-warning.jpg");
        QPixmap warning = image.scaled(30,30);
        painter->setOpacity(enabled);
        painter->drawPixmap(-6, -190, warning);
    }
}
