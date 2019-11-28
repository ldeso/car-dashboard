#include "hugo_voyants_simples.h"

hugo_voyants_simples::hugo_voyants_simples()
{
    valeur=0;

}


QRectF hugo_voyants_simples::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}


void hugo_voyants_simples::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing);
    if (getValue()==1){
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

}

void hugo_voyants_simples::parametrage(int param_x, int param_y, QString param_chemin,QString param_chemin2,int red,int green,int blue)
{
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    chemin2=param_chemin2;
    couleur=QColor(red,green,blue,160);
}
