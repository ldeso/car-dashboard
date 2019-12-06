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
    //angled = param_aiguille;
    value = param_value;
    grad_max=param_grad_max;
    valueMax=param_grad_max;

}

QRectF cadran::boundingRect() const
{
    return QRectF(rec);
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

       // float angled = stAngled-getValue()*(-EndAngled+stAngled)/grad_max;
     float angled = stAngled-value*(-EndAngled+stAngled)/grad_max;
        int coef = 0; //coefV = 28 ; coefRPM = 21
        //float angler = qDegreesToRadians(angled);
        int x = -r*qCos(qDegreesToRadians(angled+coef));
        int y = r*qSin(qDegreesToRadians(angled+coef));
        static const QPointF bout[3] =
        {
            QPointF(7, 8),
            QPointF(3, 8),
            QPointF(x, y)
        };
            painter->setPen(QPen(QBrush("yellow") , 5 , Qt::SolidLine,Qt::FlatCap));
            QBrush ba1( Qt::red, Qt::Dense4Pattern );
            painter->setBrush(ba1);
            //painter->drawPolygon(bout, 3);
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


//petite graduation
    //        painter->setPen(QPen(QBrush("yellow") , 5 , Qt::SolidLine,Qt::FlatCap));
    //        painter->drawLine((r+20)*qCos(ir),(r+20)*qSin(ir),((r)*qCos(ir)),((r)*qSin(ir)));
//        for (int j = 0; j < 60; j++)
//    {
//         if((j %5) != 0)
//         painter->drawLine(A/2, 0, A/2-20, 0);
//         painter->rotate(6.0);
//              }


//    QPen framepen(Qt::red);
//    framepen.setWidth(6);
//    painter->setPen(framepen);
//    painter->drawRect(rec);


