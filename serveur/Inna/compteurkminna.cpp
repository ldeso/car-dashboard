#include "Inna/compteurkminna.h"

///\file compteurkminna.cpp
///\brief Classe dérivant de objet_virtuel permettant un affichage en temps réel de la distance parcourue depuis le redémarrage du programme
///\brief compteurKmInna::compteurKmInna
///\details Constructeur sans paramètres spécifiques. Initialise  la valeur ***value*** de la classe mère à 0.
///
compteurKmInna::compteurKmInna(objet_virtuel *parent) :  objet_virtuel(parent)
{
 value = 0.0;
}

QRectF compteurKmInna::boundingRect() const
{
    return QRectF(0.0,0.0,1400.0,600.0);
}
///
/// \brief compteurKmInna::paint
/// \param painter
///\details La fonction paint permet de réaliser un affichage du compteur kilometrique.La valeur ***value*** est envoyer par la fonction MainWindow::update_km() dans le fichier mainwindow.cpp.

void compteurKmInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{painter->setRenderHints(QPainter::Antialiasing);
    ///
    ///\brief Affichage de la valeur du kilométrage.
    ///
    painter->setPen(QPen("#19b5e4"));
    painter->setFont(QFont("Chandas", 12, 0));
    painter->drawText(470,440, "km");
    painter->setFont(QFont("SevenSegment", 20, 0));
    QRadialGradient rg(420, 435, 80);
    rg.setColorAt(0, Qt::black);
    rg.setColorAt(1,"#f2f2f2");
    painter->setBrush(rg);
    painter->drawText(QRect(380,420,80,30), Qt::AlignRight, QString("%1 ").arg(qRound(value)));
    ///
    ///\brief Affichage d'un rectangle avec gradient.
    ///
    painter->setPen(QPen(QBrush(rg),2));
    painter->setBrush(QBrush(Qt::transparent));
    painter->drawRoundRect(QRect(380,420,80,30), 20,30);
}
