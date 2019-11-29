#include "affichekmhenri.h"

afficheKmHenri::afficheKmHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
    valueMax=9999;
}

QRectF afficheKmHenri::boundingRect() const
{
    return QRect(-700,-380,1400,780);
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
    painter->drawRoundRect(QRect(80,-50,80,2),1,1);

    painter->setBrush(brush);
    painter->setPen(QPen(brush,20));

    painter->setFont(QFont("URW Gothic L",20));
    painter->drawText(80,-39,QString("%1").arg(getValue()));

//.....fin affichage nombre de kilometres


    //.....affichage nombre de kilometres totaux

        painter->setPen(QPen(QBrush("black") , 40 , Qt::SolidLine,Qt::FlatCap));
        painter->setBrush(QColor("black"));
        painter->drawRoundRect(QRect(-160,-50,80,2),1,1);

        painter->setBrush(brush);
        painter->setPen(QPen(brush,20));

        painter->setFont(QFont("URW Gothic L",20));
        painter->drawText(-170,-39,QString("%1").arg(123456+getValue()));

    //.....fin affichage nombre de kilometres totaux

}
