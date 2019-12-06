#include "Inna/icononoffinna.h"
#include "Inna/iconinna.h"
#include <QPainter>
#include <QtMath>
///
/// \file icononoffinna.cpp
/// \brief Classe iconOnOffInna derivée de la classe IconInna
/// \details La classe et utiliser pour instancier les voyants qui n'ont que deux etats: allumé ou etaint.

iconOnOffInna::iconOnOffInna(IconInna *parent) : IconInna (parent)
{
    value = 0;
}
/// \brief iconOnOffInna::iconOnOffInna(QPoint p, QSize s, QString pth, double Z) - le constructeur multiparametrique
/// \details Le constructeur permet d'instancier un voyant a la position p, de la taille s,
///  \details avec une image donnée par le chemin pth et au niveu Z dans l'ordre de l'affichage des elements.
///
iconOnOffInna::iconOnOffInna(QPoint p, QSize s, QString pth, double Z)
{
    value = 0;
    position = p;
    size = s;
    imagePath = pth;
    this->setZValue(Z);
}

QRectF iconOnOffInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}
/// \bref iconOnOffInna::paint
/// \param painter
///  \details La fonction permet l'affichage d'un voyant instancié un fonction de la valeur _value_ :
///  \details Si _value_ = 1 => l'etait _allumé_ , sinon l'etait _etaint_.
///
void iconOnOffInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{painter->setRenderHints(QPainter::Antialiasing);
 val = qRound(value);
    if (val == 1)
        {
             painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap( imagePath));
        }
    else
         {   painter->setPen(Qt::transparent);
             painter->setBrush(QBrush(Qt::transparent));
             painter->drawRect(position.x(),position.y(),size.width(),size.height());
         }

    }

