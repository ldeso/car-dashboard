#include "florianclignotant.h"

#include <QTest>
/**
 * @brief FlorianClignotant::FlorianClignotant
 * @param parent
 */
FlorianClignotant::FlorianClignotant(QGraphicsItem *parent):objet_virtuel(parent)
{
    this->value = 0;
    this->temp = this->value;
}

/**
 * @brief FlorianClignotant::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF FlorianClignotant::boundingRect() const
{
    QRectF rect(0,0,40,40);
    return rect;
}

void FlorianClignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(this->value != 0){
        clignoter();
        //temp = value;
        if(this->temp==1){
            painter->drawPixmap(180, -20,30,30,QPixmap(":/new/prefix1/voyant/clignotantDroite.jpg"));

        }
        else if(this->temp == -1){
            painter->drawPixmap(-300, -20,30, 30,QPixmap(":/new/prefix1/voyant/clignotantGauche.jpg"));

        }
        else if(this->temp == 2){
            painter->drawPixmap(-300, -20,30, 30,QPixmap(":/new/prefix1/voyant/clignotantGauche.jpg"));
            painter->drawPixmap(180, -20,30,30,QPixmap(":/new/prefix1/voyant/clignotantDroite.jpg"));
        }

    }

}

void FlorianClignotant::clignoter()
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
