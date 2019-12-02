#include "lea_clignottants.h"
#include <QDebug>


lea_clignottants::lea_clignottants()
{
    value=0;
    cligno=0;
}

void lea_clignottants::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);

    if (getValue() !=0)
    {
        if (getValue()==-1){
            QPixmap image(":/Images/clign-gauche.jpg");
            QPixmap image2=image.scaled(30,30);
//            QRadialGradient radialGrad(QPointF(-111+15, -90+15), 15);
//            radialGrad.setColorAt(0, QColor(0,255,0));
//            radialGrad.setColorAt(1, QColor(0,0,0,120));

//            QBrush brush(radialGrad);
//            painter->setBrush(brush);
            painter->setOpacity(cligno);
            painter->drawPixmap(180,50,70,50,image2);
            //painter->drawEllipse(-111,-90,30,30);
        }
        if (getValue()==1){
            QPixmap image(":/Images/clign-droit.jpg");
            QPixmap image2=image.scaled(30,30);
//            QRadialGradient radialGrad(QPointF(81+15, -90+15), 15);
//            radialGrad.setColorAt(0, QColor(0,255,0));
//            radialGrad.setColorAt(1, QColor(0,0,0,120));

//            QBrush brush(radialGrad);
//            painter->setBrush(brush);
            painter->setOpacity(cligno);
            painter->drawPixmap(580,50,70,50,image2);
//            painter->drawEllipse(81,-90,30,30);
        }
        if (getValue()==2){
            QPixmap image(":/Images/clign-droit.jpg");
            QPixmap image2=image.scaled(30,30);
//            QRadialGradient radialGrad(QPointF(81+15, -90+15), 15);
//            radialGrad.setColorAt(0, QColor(0,255,0));
//            radialGrad.setColorAt(1, QColor(0,0,0,120));

//            QBrush brush(radialGrad);
//            painter->setBrush(brush);
            painter->setOpacity(cligno);
            painter->drawPixmap(580,50,70,50,image2);
//            painter->drawEllipse(81,-90,30,30);

            QPixmap image3(":/Images/clign-gauche.jpg");
            QPixmap image4=image3.scaled(30,30);
//            QRadialGradient radialGrad2(QPointF(-111+15, -90+15), 15);
//            radialGrad2.setColorAt(0, QColor(0,255,0));
//            radialGrad2.setColorAt(1, QColor(0,0,0,120));

//            QBrush brush2(radialGrad2);
//            painter->setBrush(brush2);
            painter->setOpacity(cligno);
            painter->drawPixmap(180,50,70,50,image4);
//            painter->drawEllipse(-111,-90,30,30);
        }
         MAJ();

    }


}

QRectF lea_clignottants::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}

void lea_clignottants::MAJ()
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
