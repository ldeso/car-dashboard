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
    return QRect(-200,-200,400,400);

}

void tachometre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    //Loop to draw tiny concentric rectangles//
    for (int i= 0; i < 30; i+=1)
    {
        QRectF rectangle(-200+i, -200+i, 400.0-2*i, 400.0-2*i);
        int startAngle = -45* 16;
        int spanAngle = 280* 16;
        // set painter properties//

        QPen mPen;
        QColor mCol(17,225,230,220-20*i);
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

        startLinePos.setX(198 * cos(theta*pi/180));
        startLinePos.setY(-198*sin(theta*pi/180));

        endLinePos.setX(180* cos(theta*pi/180));
        endLinePos.setY(-180*sin(theta*pi/180));



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

        QFont displayFont("Courier");
        displayFont.setPointSize(25);
        displayFont.setWeight(75);
        painter->setFont(displayFont);

        int j = (-(theta-235))/20;

        if (theta < 90)
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText((210*cos((theta)*pi/180)),(-210 *sin((theta)*pi/180)),QString("%1").arg(j));}

        else
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText((230*cos((theta)*pi/180)),(-210 *sin((theta)*pi/180)),QString("%1").arg(j));
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


    needlestopPos.setX(196 * cos((needleAngle)*pi/180));
    needlestopPos.setY(-196*sin((needleAngle)*pi/180));

    needle.setPoints(needlestartPos,needlestopPos);

    painter->setRenderHint(QPainter::HighQualityAntialiasing);

    painter->setPen(QPen(QBrush("red"),3,Qt::SolidLine, Qt::SquareCap));
    painter->drawLine(needle);

    painter->setPen(QPen(QBrush("white"),3,Qt::SolidLine, Qt::SquareCap));
    painter->drawEllipse(-10,-10,20,20);

    //draw text to write rpm

    painter->setPen(QPen(QBrush("gray"),8,Qt::SolidLine, Qt::SquareCap));
    QFont displayFont("Courier");
    displayFont.setPointSize(30);
    displayFont.setWeight(75);
    painter->setFont(displayFont);
    painter->drawText(-60,-30,"X 1000rpm");





}
float tachometre::getRpmValue(float rpmValue)
{
    float rpmAngle;
    rpmAngle = rpmValue * (280.00/14000.0);
    qDebug()<<rpmAngle;
    return rpmAngle;
}

