#include "voyantsmaroua.h"



VoyantsMaroua::VoyantsMaroua()
{
clignotant=0;
value=0;
}


QRectF VoyantsMaroua::boundingRect() const
{
    QRectF rectf(-800,-500,1600,1000);
    return rectf;
}
void VoyantsMaroua::activate()
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

void VoyantsMaroua::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);

    if(getValue()!=0)
    {

    if(getValue()==-1)
    {
    QPixmap img1("/home/sahli/Bureau/Icones/clign-gauche.jpg");
    QPixmap img2=img1.scaled(50,50);
    QRadialGradient grad1(QPointF(0,-95),15);
    grad1.setColorAt(0, QColor(0,255,0));
    grad1.setColorAt(1, QColor(0,0,0,120));

    QBrush brush(grad1);
    painter->setBrush(brush);
    painter->setOpacity(clignotant);
    painter->drawPixmap(-160,200,80,53,img2);

    }

     if(getValue()==1)
    {
          QPixmap img1("/home/sahli/Bureau/Icones/clign-droit.jpg");
          QPixmap img2=img1.scaled(50,50);
          QRadialGradient grad1(QPointF(0,-95),15);
          grad1.setColorAt(0, QColor(0,255,0));
          grad1.setColorAt(1, QColor(0,0,0,120));

          QBrush brush(grad1);
          painter->setBrush(brush);
          painter->setOpacity(clignotant);
          painter->drawPixmap(100,200,70,50,img2);

      }

    if(getValue()==2)
    {
        QPixmap img1("/home/sahli/Bureau/Icones/clign-droit.jpg");
        QPixmap img2=img1.scaled(50,50);
        QRadialGradient grad1(QPointF(0,-95),15);
        grad1.setColorAt(0, QColor(0,255,0));
        grad1.setColorAt(1, QColor(0,0,0,120));

        QBrush brush(grad1);
        painter->setBrush(brush);
        painter->setOpacity(clignotant);
        painter->drawPixmap(100,200,70,50,img2);


        QPixmap img3("/home/sahli/Bureau/Icones/clign-gauche.jpg");
        QPixmap img4=img3.scaled(50,50);
        QRadialGradient grad2(QPointF(0,-95),15);
        grad1.setColorAt(0, QColor(0,255,0));
        grad1.setColorAt(1, QColor(0,0,0,120));

        painter->setBrush(brush);
        painter->setOpacity(clignotant);
        painter->drawPixmap(-160,200,80,53,img4);

    }
activate();

}
}
