#include "harc.h"
#include <Qt>
#include <QtCore>
#include <math.h>
#include <QDebug>
#include <QPainter>
#include <QtMath>
#include <QStringList>

Harc::Harc(int param_arc)
{
    spanAngle0 = param_arc;
}

QRectF Harc::boundingRect() const
{
    return QRectF(rec);
}

void Harc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->translate(A/2, B/2);
    painter->scale(1, -1);
    painter->translate(-A/2, -A/2);
    painter->setPen(QPen(QBrush("white"), 15, Qt::SolidLine, Qt::FlatCap ));
    painter->drawArc(rec,  startAngle, spanAngle);

    painter->setPen(QPen(QBrush("blue"), 10, Qt::SolidLine, Qt::FlatCap ));
    painter->drawArc(rec,  startAngle, spanAngle0);

}
