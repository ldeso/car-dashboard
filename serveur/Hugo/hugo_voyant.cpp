#include "hugo_voyant.h"
#include "QPainter"
#include <QPixmap>

hugo_voyant::hugo_voyant()
{

}

QRectF hugo_voyant::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);

}

void hugo_voyant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (on==1){
        QPixmap image(chemin);
        QPixmap image2=image.scaled(30,30);
        QRadialGradient radialGrad(QPointF(x+15, y+15), 15);
        radialGrad.setColorAt(0, couleur);
        radialGrad.setColorAt(1, QColor(0,0,0,120));

        QBrush brush(radialGrad);
        painter->setBrush(brush);
        painter->drawPixmap(x,y,30,30,image2);
        painter->drawEllipse(x,y,30,30);

    }
    else if(on==2 ){
        QPixmap image(chemin2);
        QPixmap image2=image.scaled(30,30);
        painter->drawPixmap(x,y,30,30,image2);
    }
}

void hugo_voyant::parametrage(int param_x, int param_y, QString param_chemin,QString param_chemin2,int red,int green,int blue)
{
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    chemin2=param_chemin2;
    couleur=QColor(red,green,blue,160);
}

void hugo_voyant::setValue(int a)
{
    on=a;
}
