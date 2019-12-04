#include "jonas_voyant_warning.h"
#include <QTest>

jonas_voyant_warning::jonas_voyant_warning()
{
    value = 0;
    enabled = 1;
}

void jonas_voyant_warning::updateWarning()
{
    if (this->enabled==1){
        this->enabled=0;
    }
    else{
        this->enabled=1;
    }
    //    QTest::qWait(500);
    //    update();
}

QRectF jonas_voyant_warning::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

void jonas_voyant_warning::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);

    if (value!=0) {
        QPixmap image(":/icons/icon-warning.jpg");
        QPixmap warning = image.scaled(30,30);
        painter->setOpacity(enabled);
        painter->drawPixmap(-6, -190, warning);
    }
}
