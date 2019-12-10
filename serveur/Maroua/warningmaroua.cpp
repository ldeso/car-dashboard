#include "warningmaroua.h"

warningmaroua::warningmaroua()
{
    value=0;
    clignotant=0;
}
 QRectF warningmaroua::boundingRect() const
 {
     QRectF rectf(-800,-500,1600,1000);
     return rectf;
 }

 void warningmaroua::activate()
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

 void warningmaroua::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
 {
     painter->setRenderHint(QPainter::Antialiasing);

     if(getValue()!=0)
     {

             QPixmap img1("/home/sahli/Bureau/Icones/voyants-_warning.jpg");
             QPixmap img2=img1.scaled(30,30);
             QRadialGradient grad1(QPointF(0,-95),15);
             grad1.setColorAt(0, QColor(0,255,0));
             grad1.setColorAt(1, QColor(0,0,0,120));

             QBrush brush(grad1);
             painter->setBrush(brush);
             painter->setOpacity(clignotant);
             painter->drawPixmap(-157,-320,35,35,img2);
 //            painter->drawEllipse(-20,-295,60,60);
     }
     activate();
 }
