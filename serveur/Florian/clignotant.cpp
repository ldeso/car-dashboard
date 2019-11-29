#include "clignotant.h"

#include <QTest>

clignotant::clignotant(QGraphicsItem *parent):objet_virtuel(parent)
{
    this->value = 0;
    this->temp = this->value;
}


QRectF clignotant::boundingRect() const
{
    QRectF rect(0,0,40,40);
    return rect;
}

void clignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->value != 0){
        clignoter();
        //temp = value;
        if(this->temp==1){
            painter->drawPixmap(180, -20,30,30,QPixmap(":/new/prefix1/Florian/voyant/clignotantDroite.jpg"));

        }
        else if(this->temp == -1){
            painter->drawPixmap(-300, -20,30, 30,QPixmap(":/new/prefix1/Florian/voyant/clignotantGauche.jpg"));

        }
        else if(this->temp == 2){
            painter->drawPixmap(-300, -20,30, 30,QPixmap(":/new/prefix1/Florian/voyant/clignotantGauche.jpg"));
            painter->drawPixmap(180, -20,30,30,QPixmap(":/new/prefix1/Florian/voyant/clignotantDroite.jpg"));
        }

    }

}

void clignotant::clignoter()
{
    if (this->temp==this->value){
        this->temp=0;
    }
    else{
        this->temp=value;
    }
     /*QTest::qWait(500);
     update();*/
}
