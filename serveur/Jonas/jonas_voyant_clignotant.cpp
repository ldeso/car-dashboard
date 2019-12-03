#include "jonas_voyant_clignotant.h"
#include <QTest>

jonas_voyant_clignotant::jonas_voyant_clignotant()
{
    value = 0;
    enabled = 1;
}

void jonas_voyant_clignotant::updateTurnSignal()
{
    if (this->enabled==1){
     this->enabled=0;
    }
    else{
        this->enabled=1;
    }
    QTest::qWait(500);
    this->update();
}

QRectF jonas_voyant_clignotant::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

void jonas_voyant_clignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    if (value!=0) {
        if (value==-1) {
            QPixmap image(":/icons/icon-turn-left.jpg");
            QPixmap turnLeft = image.scaled(25,25);
            painter->setOpacity(enabled);
            painter->drawPixmap(-145, -145, turnLeft);
        }

        if (value==1) {
            QPixmap image1(":/icons/icon-turn-right.jpg");
            QPixmap turnRight = image1.scaled(25,25);
            painter->setOpacity(enabled);
            painter->drawPixmap(138, -145, turnRight);
        }
        updateTurnSignal();
    }
}

