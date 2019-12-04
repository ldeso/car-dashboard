#include "tachometre.h"

#include "QPainter"
#include "QPainterPath"
#include "QGradient"
#include "QtMath"
#include "QDebug"
#include "QTextItem"
#include "QString"
#include "QRadialGradient"
#include "QPolygon"
#include "QPainter"


tachometre::tachometre()
{
    value =0;
    valueMax=14000;
}

QRectF tachometre::boundingRect() const
{

}

void tachometre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    //Loop to draw tiny concentric rectangles//
    for (int i= 0; i < 20; i+=1)
    {
        QRectF rectangle(-100+i, -100+i, 200.0-2*i, 200.0-2*i);
        int startAngle = -45* 16;
        int spanAngle = 280* 16;
        // set painter properties//

        QPen mPen;
        QColor mCol(17,225,230,255-20*i);
        mPen.setCapStyle(Qt::RoundCap);
        mPen.setWidth(1);
        mPen.setColor(mCol);
        QBrush mBrush;
        painter->setBrush(mBrush);
        painter->setPen(mPen);

        painter->setRenderHint(QPainter::Antialiasing);
        painter->drawArc(rectangle,startAngle,spanAngle);
    }

    for (int i= 0; i <= 280; i+=40)
    {
        int theta;
        theta = i-45;

        painter->setPen(QPen(QBrush("white"),5, Qt::SolidLine,Qt::SquareCap));

        QPoint startLinePos;
        QPoint endLinePos;

        startLinePos.setX(98 * cos(theta*pi/180));
        startLinePos.setY(-98*sin(theta*pi/180));

        endLinePos.setX(80* cos(theta*pi/180));
        endLinePos.setY(-80*sin(theta*pi/180));



        QLine Ticks;
        Ticks.setPoints(startLinePos,endLinePos);
        painter->setRenderHint(QPainter::Antialiasing);

        painter->drawLine(Ticks);

//        QLine graduations;
//        startLinePos.setX(98 * cos((theta+40)*pi/180));
//        startLinePos.setY(-98*sin((theta+40)*pi/180));

//        endLinePos.setX(90 * cos((theta+40)*pi/180));
//        endLinePos.setY(-90 *sin((theta+40)*pi/180));

//        graduations.setPoints(startLinePos,endLinePos);
//        painter->setRenderHint(QPainter::Antialiasing);

//        painter->setPen(QPen(QBrush("white") ,3, Qt::SolidLine,Qt::SquareCap));
//        //painter->drawLine(graduations);

        int j = (-(theta-235))/20;

        if (theta < 90)
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText((110*cos((theta)*pi/180)),(-110 *sin((theta)*pi/180)),QString("%1").arg(j));}

        else
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText((130*cos((theta)*pi/180)),(-110 *sin((theta)*pi/180)),QString("%1").arg(j));
        };



    }

    /* function to get the speed Value and put needle at the right position*/



    QLine needle;

    QPoint needlestartPos;
    QPoint needlestopPos;
    needlestartPos.setX(0);
    needlestartPos.setY(0);

    float needleAngle;
    rpmValue = getValue();
    needleAngle = getRpmValue(rpmValue);
    needleAngle= -(needleAngle) - 125.0;
    qDebug()<<"needleAngle"<< needleAngle;
    qDebug()<<rpmValue;


    needlestopPos.setX(96 * cos((needleAngle)*pi/180));
    needlestopPos.setY(-96*sin((needleAngle)*pi/180));

    needle.setPoints(needlestartPos,needlestopPos);

    painter->setRenderHint(QPainter::HighQualityAntialiasing);

    painter->setPen(QPen(QBrush("red"),3,Qt::SolidLine, Qt::SquareCap));
    painter->drawLine(needle);

    painter->setPen(QPen(QBrush("white"),3,Qt::SolidLine, Qt::SquareCap));
    painter->drawEllipse(-5,-5,10,10);

    //draw text to write rpm

    painter->setPen(QPen(QBrush("gray"),5,Qt::SolidLine, Qt::SquareCap));
    painter->drawText(-20,-30,"x 1000rpm");




}
float tachometre::getRpmValue(float rpmValue)
{
    float rpmAngle;
    rpmAngle = rpmValue * (280.00/14000.0);
    qDebug()<<rpmAngle;
    return rpmAngle;
}
