///
///\file voyants_warning.cpp
/// \brief Classe dérivant de objet_virtuel permettant l'affichage du voyants warning.
///
#include "Karim/voyants_warning.h"
#include <QTest>

/**
 * @brief voyants_warning::voyants_warning
 * @details constructeur par défaut
 */
voyants_warning::voyants_warning()
{
    value = 0;
    enabled = 1;
}

/**
 * @brief voyants_warning::updateWarning
 * @details
 */
void voyants_warning::updateWarning()
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
 * @brief voyants_warning::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF voyants_warning::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

/**
 * @brief voyants_warning::paint
 * @param painter
 * @details dessine le signe warning
 */
void voyants_warning::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);

    if (value!=0) {
        QPixmap image(":/icons/icon-warning.jpg");
        QPixmap warning = image.scaled(30,30);
        painter->setOpacity(enabled);
        painter->drawPixmap(-120, -190, warning);
    }
}
