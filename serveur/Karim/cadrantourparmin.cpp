///
///\file CadranTourParMin.cpp
/// \brief Classe dérivant de objet_virtuel permettant l'affichage du cadran tour par minute.
///

#include "Karim/cadrantourparmin.h"
#include "qmath.h"
#include <QFont>
#define pi 3.1415

/**
 * @brief CadranTourParMin::CadranTourParMin
 * @details constructeur par défaut
 */
CadranTourParMin::CadranTourParMin(QGraphicsItem*)
{
    value=0;
    valueMax=8000; //Nombre de tours max
}

/**
 * @brief CadranTourParMin::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF CadranTourParMin::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

/**
 * @brief CadranTourParMin::paint
 * @param painter
 * @details dessine les différents élements du compteur tour par minute
 */
void CadranTourParMin::paint(QPainter *painter, const QStyleOptionGraphicsItem* ,QWidget* )
{

// Ajout des carree qui vont servir à dessiner nos objets
QRect carre[13];
   for (int i=0;i<13;i++)
    {
        carre[i]=QRect(-200+i*5,-200+i*5,400-i*10,400-i*10);
    }

//Ajout des gradients
    painter->setRenderHints(QPainter::Antialiasing);
    QLinearGradient linearGrad1(carre[0].topLeft(), carre[0].bottomRight());
    QLinearGradient linearGrad2(carre[4].topLeft(), carre[4].bottomRight());
    linearGrad1.setColorAt(0.0, Qt::white);
    linearGrad1.setColorAt(0.3, Qt::gray);
    linearGrad1.setColorAt(1.0, Qt::gray);
    linearGrad2.setColorAt(0.0, Qt::white);
    linearGrad2.setColorAt(0.35, Qt::black);
    linearGrad1.setSpread(QGradient::ReflectSpread);
    linearGrad2.setSpread((QGradient::ReflectSpread));
    painter->setBrush(QBrush(linearGrad2));
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(QPoint(0,0), carre[4].height()/2, carre[4].height()/2);

   //Design du cercle de l'aiguille
    painter->setBrush(Qt::darkRed);
    painter->setPen(QPen(QBrush("darkRed"),8,Qt::SolidLine));
    painter->drawEllipse(-20,-20,40,40);

   //Design du cadran tours par minutes
   painter->setPen(QPen( Qt::gray, 5, Qt::SolidLine,Qt::FlatCap));
   painter->drawArc(carre[4],300*16,300*16);
   painter->drawLine(92, 155, -92, 155);
   painter->setPen(QPen(QBrush("blue") , 5, Qt::SolidLine,Qt::FlatCap));
   painter->drawArc(carre[2],300*16,300*16);
   painter->drawLine(96, 165, -96, 165);

   //Ajout des traits
    painter->setPen(QPen(QBrush("white") , 10, Qt::SolidLine,Qt::FlatCap));
    int k=0;
 for(float i=225;i>-46;i-=10.0*270/80)
  {
     if(k==6 || k==7  ||k==8)
     {
         painter->setPen(QPen(Qt::red ,8, Qt::SolidLine));
         if(k==6 || k==8)
            painter->drawArc(carre[6],i*16,8*4);
         if(k==7)
             painter->drawArc(carre[6],i*16,8);
     }
   if(k%2==0)
        painter->drawArc(carre[6],i*16,8*4);
   else
         painter->drawArc(carre[6],i*16,8);
      k++;
 }

   painter->setPen(QPen(QBrush("white") ,15, Qt::SolidLine,Qt::FlatCap));
   painter->drawText(QRectF(-70,50,150,80),Qt::AlignCenter,"*1000r/min");

   //Ajout des graduations
   int j=0;
   for(float i=35*pi/28;i>=-7*pi/28;i-=6*pi/(27*4)*270/(80+1))
     {
       painter->drawText(qCos(i)*150-6,-qSin(i)*150+6,QString("%1").arg(j/10));
       j+=10;
       if (j/10 == 6 || j/10 == 7 || j/10 == 8)
          painter->setPen(QPen(QBrush("red") , 40, Qt::SolidLine,Qt::FlatCap));
     }

   //Design et rotation de l'aiguille
   painter->rotate((getValue()-4000)*180./5300.);
   painter->setPen(QPen( Qt::darkRed , 8, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
   painter->drawLine(0, -22, 0, -170);
   painter->rotate(-((getValue()-4000)*180./5300.));
}

