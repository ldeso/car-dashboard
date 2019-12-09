#include "jonas_compteurkm.h"
#include <QLinearGradient>
#include <QFontDatabase>

/**
 * @brief jonas_compteurKm::jonas_compteurKm
 * @details il n'y a qu'un seul constructeur par défaut
 */
jonas_compteurKm::jonas_compteurKm()
{
    this->value = 0;
    this->valueMax = 999999;
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

    painter->setRenderHint(QPainter::Antialiasing); /// active l'antialiasing pour les figures géométriques

    /// Ajoute un effet de dégradé sur l'écran LCD
    QLinearGradient linearGrad(boundingRect().topLeft(), boundingRect().bottomRight());
    linearGrad.setColorAt(0, QColor(255,255,255,120));
    linearGrad.setColorAt(0.20, QColor(58,3,21));
    linearGrad.setSpread(QGradient::ReflectSpread);

    /// Dessine l'écran LCD
    QPen pen1(QColor(58,3,21));
    painter->setPen(pen1);
    painter->setBrush(QBrush(linearGrad));
    painter->drawRect(boundingRect());

    /// Dessine le texte sur l'écran
    int id = QFontDatabase::addApplicationFont(":/LCDfont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    font.setPixelSize(21);
    painter->setFont(font);
    painter->setPen(QColor(220,73,65));
    double temp = value;
    painter->drawText(boundingRect(), Qt::AlignRight, QString("%1").arg(temp, -4, 'f', 1));
    painter->setFont(QFont("Ubuntu", 9));
    painter->drawText(5,8,80,30,0, QString("TRIP"));
}
