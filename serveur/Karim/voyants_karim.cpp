///
///\file voyants_karim.cpp
/// \brief Classe dérivant de objet_virtuel permettant l'affichage des voyants.
///

#include "Karim/voyants_karim.h"

/**
 * @brief Voyants_karim::Voyants_karim
 * @details constructeur par défaut
 */
Voyants_karim::Voyants_karim(QString pixpath,int xp , int yp, int ims)
{
    value=0;
    path=pixpath;
    x= xp;
    y= yp;
    size= ims;
}

/**
 * @brief Voyants_karim::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF Voyants_karim::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

/**
 * @brief Voyants_karim::paint
 * @param painter
 * @details dessine les différents voyants qui vont être activé ou pas
 */
void Voyants_karim::paint(QPainter *painter, const QStyleOptionGraphicsItem* ,QWidget* )
{
    painter->setRenderHints(QPainter::Antialiasing);
    QPixmap im_essence(":/Lea/Icones_Voyants/fuelL_red.gif");
    QPixmap im_tempmoteur(":/Lea/Icones_Voyants/engineT_red.gif");
    painter->drawPixmap(-275,-130,50,50,im_essence);
    painter->drawPixmap(15,-130,50,50,im_tempmoteur);

    if  (getValue()==1) {
        QPixmap im(path);
        QPixmap im2=im.scaled(size,size);
        painter->drawPixmap(x,y,size,size,im2);
    }
}



