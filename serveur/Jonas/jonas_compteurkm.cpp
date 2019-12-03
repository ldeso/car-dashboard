#include "jonas_compteurkm.h"
#include <QFontDatabase>

jonas_compteurKm::jonas_compteurKm()
{
    this->value = 0;
    this->valueMax = 999999;
    QFontDatabase::addApplicationFont(":/LCDfont.ttf");
}

QRectF jonas_compteurKm::boundingRect() const
{
    return QRectF(0,0,80,30);
}

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
    font.setPixelSize(21);
    painter->setFont(font);
    painter->setPen(pen2);
    int temp = value;
    painter->drawText(5,5,70,20,0, QString("%1").arg(temp));
}
