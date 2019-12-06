#include "Karim/voyants_warning.h"
#include <QTest>

voyants_warning::voyants_warning()
{
    value = 0;
    enabled = 1;
}

void voyants_warning::updateWarning()
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

QRectF voyants_warning::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

void voyants_warning::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);

    if (value!=0) {
        QPixmap image(":/icons/icon-warning.jpg");
        QPixmap warning = image.scaled(30,30);
        painter->setOpacity(enabled);
        painter->drawPixmap(-120, -190, warning);
    }
}
