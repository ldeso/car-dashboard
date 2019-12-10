#include "cadran.h"
#include <Qt>
#include <QtCore>
#include <math.h>
#include <QDebug>
#include <QPainter>
#include <QtMath>
#include <QStringList>


cadran::cadran(QStringList param_grad, QString param_text, QString param_text1,
               float param_value,int param_grad_max )
{
    grad = param_grad;
    text = param_text;
    text1= param_text1;

    value = param_value;
    grad_max=param_grad_max;
    valueMax=param_grad_max;

}

QRectF cadran::boundingRect() const
{
    return QRectF(recgrd);
}

void cadran::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    ellipse(painter, rec);
    aiguille(painter, rec);
    graduation(painter,recT);

}

void cadran::ellipse(QPainter *painter, QRectF)
{
    painter->setRenderHints(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush("black") , 20 , Qt::SolidLine,Qt::FlatCap));

    QBrush b1( Qt::green, Qt::Dense4Pattern );
    painter->setBrush(b1);

    painter->drawEllipse(rec);
    painter->drawText(A/2-20,A/2-5, text);
    painter->drawText(A/2-20,A/2+80, text1);
}

void cadran::aiguille(QPainter *painter, QRectF)
{
    painter->translate(A/2, B/2);
    int r =  A/2           ;
    //changer angle change l'aiguille


    float angled = stAngled-value*(-EndAngled+stAngled)/grad_max;

    //float angler = qDegreesToRadians(angled);
    int x = -r*qCos(qDegreesToRadians(angled));
    int y = r*qSin(qDegreesToRadians(angled));

    painter->setPen(QPen(QBrush("yellow") , 5 , Qt::SolidLine,Qt::FlatCap));
    QBrush ba1( Qt::red, Qt::Dense4Pattern );
    painter->setBrush(ba1);
    painter->drawLine(0,0,x,y);
}

void cadran::graduation(QPainter *painter, QRectF)
{
    painter->setPen(QPen(QBrush("red") , 5 , Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Arial", 9, -1,false));
    int compteur=0         ;

    while (compteur< grad.count())
    {
        float id=stAngled+1.0*compteur*(1.0*(EndAngled-stAngled))/(grad.count()-1);
        //       qDebug()<<id;
        float ir= qDegreesToRadians(id);
        //        qDebug()<<ir;
        painter->drawText((r-40)*qCos(ir)-11,(r-25)*qSin(ir)+3, grad[compteur] );

        //grande graduation
        painter->drawLine((r+10)*qCos(ir),(r+10)*qSin(ir),((r-10)*qCos(ir)),((r-10)*qSin(ir)));
        compteur++;
    }
}


//    QPen framepen(Qt::red);
//    framepen.setWidth(6);
//    painter->setPen(framepen);
//    painter->drawRect(rec);


