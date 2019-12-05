#include "Inna/compteurkminna.h"

compteurKmInna::compteurKmInna(objet_virtuel *parent) :  objet_virtuel(parent)
{

}

QRectF compteurKmInna::boundingRect() const
{
    return QRectF(0.0,0.0,1400.0,600.0);
}

void compteurKmInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{painter->setRenderHints(QPainter::Antialiasing);

    painter->setPen(QPen("#19b5e4"));
    painter->setFont(QFont("Chandas", 12, 0));
    painter->drawText(470,440, "km");
    painter->setFont(QFont("SevenSegment", 20, 0));
    QRadialGradient rg(420, 435, 80);
    rg.setColorAt(0, Qt::black);
    rg.setColorAt(1,"#f2f2f2");
    painter->setBrush(rg);
    painter->drawText(QRect(380,420,80,30), Qt::AlignRight, QString("%1").arg(qRound(value)));
    painter->setPen(QPen(QBrush(rg),2));
    painter->setBrush(QBrush(Qt::transparent));
    painter->drawRoundRect(QRect(380,420,80,30), 20,30);
}
