#include "flashinglight_youss.h"


FlashingLight_Youss::FlashingLight_Youss()
{
clignotant=0;
value=0;
}


QRectF FlashingLight_Youss::boundingRect() const
{
    return QRectF(-600, -400, 1200, 800);
}
void FlashingLight_Youss::flashing()
{
    if (clignotant==1){
     clignotant=0;
    }
    else{
        clignotant=1;
    }
     QTest::qWait(500);
     update();
}

void FlashingLight_Youss::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);

    if(getValue()!=0)
    {

    if(getValue()==-1)
    {
    QPixmap img1(":/new/logos/Icones/ClignottantGauche.png");
    QPixmap img2=img1.scaled(50,50);
    QRadialGradient grad1(QPointF(0,-95),15);
    grad1.setColorAt(0, QColor(0,255,0));
    grad1.setColorAt(1, QColor(0,0,0,120));

    QBrush brush(grad1);
    painter->setBrush(brush);
    painter->setOpacity(clignotant);
    painter->drawPixmap(-165,-300,70,70,img2);
//         painter->drawEllipse(-160,-295,60,60);
    }

     if(getValue()==1)
    {
          QPixmap img1(":/new/logos/Icones/ClignottantDroit.png");
          QPixmap img2=img1.scaled(50,50);
          QRadialGradient grad1(QPointF(0,-95),15);
          grad1.setColorAt(0, QColor(0,255,0));
          grad1.setColorAt(1, QColor(0,0,0,120));

          QBrush brush(grad1);
          painter->setBrush(brush);
          painter->setOpacity(clignotant);
          painter->drawPixmap(105,-300,70,70,img2);
//          painter->drawEllipse(105,-295,60,60);
      }

    if(getValue()==2)
    {
        QPixmap img1(":/new/logos/Icones/ClignottantDroit.png");
        QPixmap img2=img1.scaled(50,50);
        QRadialGradient grad1(QPointF(0,-95),15);
        grad1.setColorAt(0, QColor(0,255,0));
        grad1.setColorAt(1, QColor(0,0,0,120));

        QBrush brush(grad1);
        painter->setBrush(brush);
        painter->setOpacity(clignotant);
        painter->drawPixmap(105,-300,70,70,img2);
//        painter->drawEllipse(105,-295,60,60);

        QPixmap img3(":/new/logos/Icones/ClignottantGauche.png");
        QPixmap img4=img3.scaled(50,50);
        QRadialGradient grad2(QPointF(0,-95),15);
        grad1.setColorAt(0, QColor(0,255,0));
        grad1.setColorAt(1, QColor(0,0,0,120));

        painter->setBrush(brush);
        painter->setOpacity(clignotant);
        painter->drawPixmap(-165,-300,70,70,img4);
//        painter->drawEllipse(-160,-295,60,60);
    }
flashing();

}
}





