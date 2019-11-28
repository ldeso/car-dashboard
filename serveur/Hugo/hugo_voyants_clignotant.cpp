#include "hugo_voyants_clignotant.h"
#include <QDebug>


hugo_voyants_clignotant::hugo_voyants_clignotant()
{
    valeur=0;
    cligno=0;
}

QRectF hugo_voyants_clignotant::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

void hugo_voyants_clignotant::MAJ()
{
   if (this->cligno==1){
    this->cligno=0;
   }
   else{
       this->cligno=1;
   }
    QTest::qWait(500);
    update();
}

void hugo_voyants_clignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setRenderHint(QPainter::Antialiasing);

    if (getValue() !=0)

    {
        if (getValue()==-1){
            QPixmap image("/home/utilisateur/Images/clign-gauche.jpg");
            QPixmap image2=image.scaled(30,30);
            QRadialGradient radialGrad(QPointF(-111+15, -90+15), 15);
            radialGrad.setColorAt(0, QColor(0,255,0));
            radialGrad.setColorAt(1, QColor(0,0,0,120));

            QBrush brush(radialGrad);
            painter->setBrush(brush);
            painter->setOpacity(cligno);
            painter->drawPixmap(-111,-90,30,30,image2);
            painter->drawEllipse(-111,-90,30,30);
        }
        if (getValue()==1){
            QPixmap image("/home/utilisateur/Images/clign-droit.jpg");
            QPixmap image2=image.scaled(30,30);
            QRadialGradient radialGrad(QPointF(81+15, -90+15), 15);
            radialGrad.setColorAt(0, QColor(0,255,0));
            radialGrad.setColorAt(1, QColor(0,0,0,120));

            QBrush brush(radialGrad);
            painter->setBrush(brush);
            painter->setOpacity(cligno);
            painter->drawPixmap(81,-90,30,30,image2);
            painter->drawEllipse(81,-90,30,30);
        }

    MAJ();
    }
}
