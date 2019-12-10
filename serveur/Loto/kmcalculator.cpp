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
 value = 999;
 valueMax = 500000;
 QFontDatabase::addApplicationFont(":/fonts/SFDigitalReadout-Medium.ttf");

}

QRectF kmCalculator::boundingRect() const
{
    return QRect(-40,90,100,60);

}

///
/// \brief kmCalculator::paint
/// \param painter
///\details Ici, la override function de paint est utilisé pour afficher les kilomètres parcourus.
///

void kmCalculator::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);

    QPen pen1(QColor(0,0,0));
    QBrush brush(QColor(102,255,255,255));
    //brush.setStyle(Qt::Dense6Pattern);
    painter->setPen(pen1);
    painter->setBrush(brush);

    QFont displayFont;
    displayFont.setFamily("SFDigitalReadout");
    displayFont.setPointSize(50);
    displayFont.setWeight(60);
    painter->setFont(displayFont);
    painter->drawRect(boundingRect());

    QBrush displayBrush;
    displayBrush.setColor(Qt::white);
    painter->setBrush(displayBrush);

    float kmtravelled = value;
    painter->drawText(boundingRect(),Qt::AlignCenter,QString("%1").arg(kmtravelled));
}
