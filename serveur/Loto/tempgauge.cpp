#include "tempgauge.h"
#include "QPainter"
#include "QPainterPath"
#include "QGradient"
#include "QtMath"
#include "QDebug"
#include "QTextItem"
#include "QString"
#include "QRadialGradient"
#include "QPolygon"
#include "QPixmap"


tempGauge::tempGauge()
{

}

QRectF tempGauge::boundingRect() const
{

}

void tempGauge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Loop to draw tiny concentric rectangles//
    for (int i= 0; i < 20; i+=1)
    {
        QRectF rectangle(-100+i, -100+i, 200.0-2*i, 200.0-2*i);
        int startAngle = 135 * 16;
        int spanAngle = 50* 16;

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

    QPen mPen;
    QColor mCol(35,191,230,255);
    mPen.setCapStyle(Qt::RoundCap);
    mPen.setWidth(2.5);
    mPen.setColor(mCol);
    QBrush mBrush;
    painter->setBrush(mBrush);
    painter->setPen(mPen);


    for (int theta= 135; theta <=185; theta+=10)
    {
        painter->setPen(QPen(QBrush("white"),3, Qt::SolidLine,Qt::SquareCap));
        QLine line_j[theta];
        QPoint startLinePos;
        QPoint endLinePos;

        startLinePos.setX(98 * cos(theta*pi/180));
        startLinePos.setY(-98*sin(theta*pi/180));

        endLinePos.setX(80* cos(theta*pi/180));
        endLinePos.setY(-80*sin(theta*pi/180));

        line_j[theta].setPoints(startLinePos,endLinePos);


        QLine Ticks;
        Ticks.setPoints(startLinePos,endLinePos);
        painter->setRenderHint(QPainter::Antialiasing);

        painter->drawLine(Ticks);

        QLine graduations;
        startLinePos.setX(98 * cos((theta+10)*pi/180));
        startLinePos.setY(-98*sin((theta+10)*pi/180));

        endLinePos.setX(90 * cos((theta+10)*pi/180));
        endLinePos.setY(-90 *sin((theta+10)*pi/180));

        graduations.setPoints(startLinePos,endLinePos);
        painter->setRenderHint(QPainter::Antialiasing);

        painter->setPen(QPen(QBrush("white"),5, Qt::SolidLine,Qt::SquareCap));
        //painter->drawLine(graduations);

        // Here we set the text to add to our gauge.
        //For fuel gauge, we will label only E for empty and  F for full with Red and Green/blue respectively

        // This cannot be done in a loop else we will skip the point to label. Else create a variable to take the position

        int fuelEmptyLabel= 135; //angle to place high temperature

        painter->setPen(QPen(QBrush("red"),5,Qt::SolidLine));
        painter->drawText((110*cos((fuelEmptyLabel)*pi/180)),(-110 *sin((fuelEmptyLabel)*pi/180)),"H");

        int fuelFullLabel= 185; // angle to place low temperature

        painter->setPen(QPen(QBrush("green"),5,Qt::SolidLine));
        painter->drawText((115*cos((fuelFullLabel)*pi/180)),(-110 *sin((fuelFullLabel)*pi/180)),"C");

    }

    /* function to get the speed Value and put needle at the right position*/



    QLine needle;

    QPoint needlestartPos;
    QPoint needlestopPos;
    needlestartPos.setX(0);
    needlestartPos.setY(0);

    double needleAngle;
    needleAngle = - (175.0 + getEngineTemp(engineTemp));

    needlestopPos.setX(96 * cos((needleAngle)*pi/180));
    needlestopPos.setY(-96*sin((needleAngle)*pi/180));

    needle.setPoints(needlestartPos,needlestopPos);

    painter->setRenderHint(QPainter::HighQualityAntialiasing);

    painter->setPen(QPen(QBrush("red"),3,Qt::SolidLine, Qt::SquareCap));
    painter->drawLine(needle);

    painter->setPen(QPen(QBrush("white"),3,Qt::SolidLine, Qt::SquareCap));
    painter->drawEllipse(-5,-5,10,10);


    QPixmap ledEngineTemp(":/engineT_red");
    QPixmap ledEngineTemp2=ledEngineTemp.scaled(40,40,Qt::IgnoreAspectRatio,Qt::FastTransformation);
    painter->drawPixmap(-70,-40,ledEngineTemp2);

}

double tempGauge::getEngineTemp(double engineTemp)
{
    double inputTemp = engineTemp; double engineTempAngle;
    engineTempAngle = inputTemp * (50.0/50.0);
    return engineTempAngle;
}