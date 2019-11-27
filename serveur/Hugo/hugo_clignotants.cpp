#include "hugo_clignotants.h"
#include <QPainter>
#include <QTest>
hugo_clignotants::hugo_clignotants()
{

}

QRectF hugo_clignotants::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void hugo_clignotants::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setRenderHints(QPainter::Antialiasing);
    if (on==1){
        if (affiche==1){
            QBrush brush(Qt::green);
            painter->setBrush(brush);
            painter->drawEllipse(80,-91,30,30);
        }
        else{
            qDebug()<<"ok";
            QBrush brush(Qt::black);
            painter->setBrush(brush);
            painter->drawEllipse(80,-91,30,30);
        }
        MAJ();
        update();

    }
    if (on==-1){
        QPixmap image("/home/utilisateur/Images/clign-gauche.jpg");
        QPixmap image2=image.scaled(30,30);
        QRadialGradient radialGrad(QPointF(-112+15, -90+15), 15);
        radialGrad.setColorAt(0, QColor(0,255,0));
        radialGrad.setColorAt(1, QColor(0,0,0,120));

        QBrush brush(radialGrad);
        painter->setBrush(brush);
        painter->drawPixmap(-112,-90,30,30,image2);
        painter->drawEllipse(-112,-90,30,30);

    }

}

void hugo_clignotants::setValue(int a)
{
    on=a;
}

void hugo_clignotants::MAJ()
{
    QTest::qWait(500);
    if (affiche==1){
        affiche=0;
    }
    else if(affiche==0){
        affiche=1;
    }

    update();
}
