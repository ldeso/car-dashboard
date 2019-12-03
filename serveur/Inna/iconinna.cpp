#include "Inna/iconinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>
#include "objet_virtuel.h"

IconInna::IconInna(objet_virtuel *parent) :  objet_virtuel(parent)
{

}

IconInna::IconInna(QPoint p, QSize s, QString pth)
{   value = 0;
    position = p;
    size = s;
    imagePath = pth;
}

QRectF IconInna::boundingRect() const
{
    QRectF rectf(0.0,0.0,1400.0,600.0);
    return rectf;
}

void IconInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{ painter->setRenderHints(QPainter::Antialiasing);

  painter->drawPixmap(position.x(),position.y(),size.width(),size.height(),QPixmap(imagePath));

}

void IconInna::init(QPoint p, QSize s, QString pth)
{
    position = p;
    size = s;
    imagePath = pth;
}


