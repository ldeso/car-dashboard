#include "warning_youss.h"

Warning_Youss::Warning_Youss()
{
value=0;
clignotant=0;
}

QRectF Warning_Youss::boundingRect() const
{
    return QRectF(-600, -400, 1200, 800);
}

void Warning_Youss::Flashing()
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


void Warning_Youss::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);

    if(getValue()!=0)
    {

            QPixmap img1(":/new/logos/Icones/Warning.png");
            QPixmap img2=img1.scaled(30,30);
            QRadialGradient grad1(QPointF(0,-95),15);
            grad1.setColorAt(0, QColor(0,255,0));
            grad1.setColorAt(1, QColor(0,0,0,120));

            QBrush brush(grad1);
            painter->setBrush(brush);
            painter->setOpacity(clignotant);
            painter->drawPixmap(-30,-295,50,50,img2);
//            painter->drawEllipse(-20,-295,60,60);
    Flashing();
    }

}
