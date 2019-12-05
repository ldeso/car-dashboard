#include "Karim/cadranEss.h"
#include "qmath.h"
#include <QFont>

CadranEss::CadranEss(QGraphicsItem *)
{
    value=0;
    valueMax=60;

}

QRectF CadranEss::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void CadranEss::paint(QPainter *painter, const QStyleOptionGraphicsItem* ,QWidget* )
{

// Ajout des carree qui vont servir à dessiner nos objets
QRect carre[13];
   for(int i=0;i<13;i++)
    {
        carre[i]=QRect(-400+i*5,-15+i*5,200-i*10,200-i*10);
    }

//Design du cadran
   for(int i=5;i>0;i--)
    {
        painter->setPen(QPen( Qt::darkGray, i, Qt::SolidLine,Qt::FlatCap));
        painter->setRenderHints(QPainter::Antialiasing);
        painter->drawArc(carre[4],360*16,360*16);
    }

//Ajout de la graduations
    painter->setRenderHints(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush("white") , 10, Qt::SolidLine,Qt::FlatCap));
   for(float i=180;i>-1;i-=10.0*270/60)
    {
     painter->drawArc(carre[6],i*16,10);
    }

//Design de l'aiguille
   painter->setPen(QPen( Qt::darkRed , 8, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
   painter->drawLine(-300, 12, -300, 85);
   painter->setRenderHints(QPainter::Antialiasing);

}
