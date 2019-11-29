#include "affichekmhenri.h"

afficheKmHenri::afficheKmHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
    valueMax=9999;
}

QRectF afficheKmHenri::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

void afficheKmHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

//.....affichage nombre de kilometres
    painter->setRenderHint(QPainter::Antialiasing);
    QRadialGradient gradient(0, 0, 1000);
    gradient.setColorAt(0, QColor("darkCyan"));
    gradient.setColorAt(1, QColor("dark"));
    QBrush brush(gradient);

    painter->setPen(QPen(QBrush("black") , 40 , Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor("black"));
    painter->drawRoundRect(QRect(40,-50,80,2),1,1);

    painter->setBrush(brush);
    painter->setPen(QPen(brush,20));

    painter->setFont(QFont("URW Gothic L",20));
    painter->drawText(40,-40,QString("%1").arg(getValue()));

//.....fin affichage nombre de kilometres

}