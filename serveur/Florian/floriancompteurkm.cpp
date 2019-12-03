#include "floriancompteurkm.h"
#include <limits>
#include <QFontDatabase>

FlorianCompteurKm::FlorianCompteurKm(QGraphicsItem *parent)
{
    this->value = 0;
    this->valueMax = 999999;
    QFontDatabase::addApplicationFont(":/new/prefix1/voyant/digital-7.ttf");
}

QRectF FlorianCompteurKm::boundingRect() const
{
    return QRectF(0,0,80,30);
}

void FlorianCompteurKm::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setRenderHint(QPainter::Antialiasing); // ajout de l antialiasing au tableau de bord
    QPen pen1(QColor(0,160,250));
    QBrush brush(QColor(0,160,250));
    painter->setPen(pen1);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());
    QPen pen2(QColor(0,0,0));
    QFont font;

    font.setFamily("digital-7");
    font.setPixelSize(25);
    painter->setFont(font);
    painter->setPen(pen2);
    int temp = value;
    painter->drawText(5,5,70,20,0, QString("%1").arg(temp));
}

