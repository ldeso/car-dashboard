#include "Karim/cadranEss.h"
#include "qmath.h"
#include <QFont>

CadranEss::CadranEss(QGraphicsItem * )
{
    value=0;
    valueMax=180;
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

    painter->setRenderHints(QPainter::Antialiasing);

//Ajout des gradients
    QLinearGradient linearGrad1(carre[0].topLeft(), carre[0].bottomRight());
    QLinearGradient linearGrad2(carre[9].topLeft(), carre[9].bottomRight());
    linearGrad1.setColorAt(0.0, Qt::white);
    linearGrad1.setColorAt(0.3, Qt::gray);
    linearGrad1.setColorAt(1.0, Qt::gray);
    linearGrad2.setColorAt(0.0, Qt::white);
    linearGrad2.setColorAt(0.35, Qt::black);
    linearGrad1.setSpread(QGradient::ReflectSpread);
    linearGrad2.setSpread((QGradient::ReflectSpread));
    painter->setBrush(QBrush(linearGrad2));
    painter->setPen(Qt::NoPen);
    painter->translate(-300,85);
    painter->rotate(180);
    painter->drawEllipse(QPoint(0,0), carre[4].height()/2, carre[4].height()/2);
    painter->rotate(-180);
    painter->translate(300,-85);

// Design du cercle aiguille
 painter->setBrush(Qt::darkGray);
 painter->setPen(QPen(QBrush("darkRed"),7,Qt::SolidLine));
 painter->drawEllipse(-313,70,25,25);

//Design du cadran
    painter->setPen(QPen( Qt::darkGray, 5, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre[4],360*16,360*16);

//Ajout des graduations
    painter->setPen(QPen(QBrush("white") , 10, Qt::SolidLine,Qt::FlatCap));
 for(float i=180;i>-1;i-=10.0*270/60)
  {
    painter->drawArc(carre[6],i*16,20);
  }

//Design et rotation de l'aiguille
   painter->setPen(QPen( Qt::darkRed , 8, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
   painter->translate(-300,85);
   painter->rotate(getValue()-90);
   painter->drawLine(0,-15,0,-73);
   painter->rotate(-(getValue()-90));


}
