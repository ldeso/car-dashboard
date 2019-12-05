#include "Inna/prnd_inna.h"
#include "Inna/iconinna.h"
#include <QPainter>
#include <QtMath>
///\file prnd_inna.cpp
/// \brief Classe PRND_Inna derivée de la classe IconInna pour afficher les modes de la transmission.
/// \details Affiche la mode de la transmission de la boîte de vitesse automatique.
///
PRND_Inna::PRND_Inna(IconInna *parent) : IconInna (parent)
{
value = 1;
position = QPoint(700,320);
size = QSize(70,70);
}

QRectF PRND_Inna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}
///
/// \brief PRND_Inna::paint
/// \param painter
/// \details La fonction permets de l'afficher l'image correspondante au mode de la transmission engagée.
/// \details Le choix est fait en fonction de la valeur _value_ :
/// \details 1 - Park;
/// \details 2 - Reverse;
/// \details 3 - Neutral;
/// \details 4 - Drive;
/// \details Dans autres cas le voyant "_probleme avec la boite de vitesse_" et affiché.
void PRND_Inna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    switch (qRound(value)) {
    case 1:
      {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/I_auto_P_blue.gif"));break;}
    case 2:
      {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/I_auto_R_blue.gif"));break;}
    case 3:
       {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/I_auto_N_blue.gif"));break;}
    case 4:
       {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/I_auto_D_blue.gif"));break;}
    default:
    {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/I_gearProblem.gif"));break;}


    }
}
