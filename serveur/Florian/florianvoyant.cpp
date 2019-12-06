#include "florianvoyant.h"
#include <QPainter>
#include <QDebug>
FlorianVoyant::FlorianVoyant(QPixmap map, QGraphicsItem * parent):objet_virtuel(parent)
{
    this->voyant = map;
    this->value = 0;
}


/**
 * @brief FlorianVoyant::boundingRect
 * @return retourne le rectangle qui encadre l'objet
 */
QRectF FlorianVoyant::boundingRect() const
{
    QRectF rect(0,0,40,40);
    return rect;
}
/**
 * @brief FlorianVoyant::paint
 * @param painter
 * @details si value == 1, dessine l'image qui est en attribut
 */
void FlorianVoyant::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(this->value==1){

        //qDebug() << value;
        painter->drawPixmap(0,0,30,30,this->voyant);
    }
}

