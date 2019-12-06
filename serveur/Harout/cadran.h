#ifndef CADRAN_H
#define CADRAN_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QColor>
#include <QDebug>
#include "objet_virtuel.h"

class cadran : public objet_virtuel
{
public:
    cadran(QStringList,QString,QString,float,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void ellipse(QPainter *painter, QRectF);
    void aiguille(QPainter *painter, QRectF);
    void arc(QPainter *painter, QRectF);
//    void test(QPainter *painter, QRectF);
//    void frame(QPainter *painter, QRectF);


    void graduation(QPainter *painter, QRectF);




private:
    int A = 250;
    int B = 250;
    QRectF rec     = QRectF(0,0, A, B);
    //int startAngle = 30 * 16;  //C'est pour arc
    //int spanAngle  = 120 * 16;//C'est pour arc
    //int spanAngle0 = 10 * 16;
    QRectF recT     = QRectF(0,0, A/10, B/10);
    //QRectF recArc   =QRectF(0,0,A/2,B/2);
    int r =  A/2           ;
    int stAngled = 30     ;
    int EndAngled = -210  ;
    int grad_max;

protected:
    QStringList gradVitesse;
    QStringList gradRPM;
    QStringList grad;
    QString text;
    QString Vtext;
    QString RPMtext;
    QString text1;
    QString Temptext1;
    QString Essencetext1;
    float valueVitesse ;
    float valueRPM;
    float ANGLE=0;

    float angled;
    int spanAngle0;

};

#endif // CADRAN_H
