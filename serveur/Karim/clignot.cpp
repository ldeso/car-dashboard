#include "Karim/clignot.h"
#include <QPainter>
#include "Karim/voyants.h"
#include <QTest>

clignot::clignot(QGraphicsItem*)
{
    value=0;
    cligno=0;
}

QRectF clignot::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void clignot::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if (getValue() !=0)
    {
        if (getValue()==-1){
            QPixmap pix(":/Icones/clignotg.jpg");
            painter->setOpacity(cligno);
            painter->drawPixmap(-500,-200,50,50,pix);
        }
        if (getValue()==1){
            QPixmap pix(":/Icones/clignotd.jpg");
            painter->setOpacity(cligno);
            painter->drawPixmap(250,-200,50,50,pix);
        }
        if (getValue()==2){
            QPixmap pix(":/Icones/clignotd.jpg");
            painter->setOpacity(cligno);
            painter->drawPixmap(250,-200,50,50,pix);

            QPixmap pix2(":/Icones/clignotg.jpg");
            painter->setOpacity(cligno);
            painter->drawPixmap(-500,-200,50,50,pix2);
        }

    MAJ();
    }
}
void clignot::MAJ()
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
