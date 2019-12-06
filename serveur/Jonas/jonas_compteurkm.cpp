#include "jonas_compteurkm.h"
#include <QFontDatabase>

/**
 * @brief jonas_compteurKm::jonas_compteurKm
 * @details il n'y a qu'un seul constructeur par défaut
 */
jonas_compteurKm::jonas_compteurKm()
{
    this->value = 0;
    this->valueMax = 999999;
    QFontDatabase::addApplicationFont(":/LCDfont.ttf");
}

/**
 * @brief jonas_compteurKm::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF jonas_compteurKm::boundingRect() const
{
    return QRectF(0,0,80,30);
}

/**
 * @brief jonas_compteurKm::paint
 * @param painter
 * @details dessine un écran affichant les km parcourus
 */
void jonas_compteurKm::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen1(QColor(0,160,250));
    QBrush brush(QColor(0,160,250));
    painter->setPen(pen1);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());
    QPen pen2(QColor(0,0,0));
    QFont font;

    font.setFamily("digital-7");
    font.setPixelSize(20);
    painter->setFont(font);
    painter->setPen(pen2);
    int temp = value;
    painter->drawText(5,4,70,20,0, QString("%1").arg(temp));
}
