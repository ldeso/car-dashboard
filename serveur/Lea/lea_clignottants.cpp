#include "lea_clignottants.h"
#include <QDebug>


lea_clignottants::lea_clignottants()
{
    value=0;
    cligno=0;
}


QRectF lea_clignottants::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}


void lea_clignottants::paint(QPainter *painter, const QStyleOptionGraphicsItem* , QWidget* )
{
    painter->setRenderHint(QPainter::Antialiasing);

    if (getValue() !=0)
    {
        if (getValue()==-1){
            QPixmap image(":/Lea/Icones_Voyants/turnLeft.gif");
            QPixmap image2=image.scaled(30,30);
            painter->setOpacity(cligno);
            painter->drawPixmap(180,50,70,50,image2);

        }
        if (getValue()==1){
            QPixmap image(":/Lea/Icones_Voyants/turnRight.gif");
            QPixmap image2=image.scaled(30,30);

            painter->setOpacity(cligno);
            painter->drawPixmap(580,50,70,50,image2);

        }
        if (getValue()==2){
            QPixmap image(":/Lea/Icones_Voyants/turnRight.gif");
            QPixmap image2=image.scaled(30,30);

            painter->setOpacity(cligno);
            painter->drawPixmap(580,50,70,50,image2);

            QPixmap image3(":/Lea/Icones_Voyants/turnLeft.gif");
            QPixmap image4=image3.scaled(30,30);

            painter->setOpacity(cligno);
            painter->drawPixmap(180,50,70,50,image4);
        }
         MAJ();
        update();
    }
}


void lea_clignottants::MAJ()
{
    if (this->cligno==1.0){
     this->cligno=0.0;
    }
    else{
        this->cligno=1.0;
    }
     QTest::qWait(500);
     //update();
}
