#include "jonas_voyant_clignotant.h"
#include <QTest>

jonas_voyant_clignotant::jonas_voyant_clignotant()
{
    value = 0;
    enabled = 1;
}

void jonas_voyant_clignotant::updateTurn()
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
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
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
            QPixmap image(":/icons/icon-turn-right.jpg");
            QPixmap turnRight = image.scaled(25,25);
            painter->setOpacity(enabled);
            painter->drawPixmap(138, -145, turnRight);
        }
        if (value==2) {
            QPixmap image(":/icons/icon-turn-left.jpg");
            QPixmap image1(":/icons/icon-turn-right.jpg");
            painter->setOpacity(enabled);
            painter->drawPixmap(-145, -145, 25, 25, image);
            painter->drawPixmap(138, -145, 25, 25, image1);
        }
        updateTurn();
    }
}

