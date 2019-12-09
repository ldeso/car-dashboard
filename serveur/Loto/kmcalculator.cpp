#include "kmcalculator.h"
#include "QFontDatabase"

///
///\file kmCalculator.cpp
/// \brief Cet classe est dérivé de la classe objet_virtuel et il fait le calcule pour les compteur kilometre jauge essence et affiche le vraie nombre de kilometre parcours.
///

///
/// \brief kmCalculator::kmCalculato
///\details Ici le variable "value" est initialisé  à 999 et la valeur maximal est déclaré aussi
///
kmCalculator::kmCalculator()
{
 value = 0;
 valueMax = 500000;
 QFontDatabase::addApplicationFont(":/digital-7.ttf");

}

QRectF kmCalculator::boundingRect() const
{
    return QRect(-40,30,100,60);

}

///
/// \brief kmCalculator::paint
/// \param painter
///\details Ici, la override function de paint est utilisé pour afficher les kilomètres parcourus.
///

void kmCalculator::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);

    QPen pen1(QColor(255,255,255));
    QBrush brush(QColor(102,255,255,255));
    brush.setStyle(Qt::Dense6Pattern);
    painter->setPen(pen1);
    painter->setBrush(brush);

    QFont displayFont;
    displayFont.setFamily("digital-7");
    displayFont.setPointSize(30);
    displayFont.setWeight(50);
    painter->setFont(displayFont);
    painter->drawRect(boundingRect());

    QBrush displayBrush;
    displayBrush.setColor(Qt::white);
    painter->setBrush(displayBrush);

    int kmtravelled = static_cast<int>(value);
    painter->drawText(boundingRect(),Qt::AlignCenter,QString("%1").arg(kmtravelled));
}
