#include "loto_dashboard.h"
#include "QPainter"
#include "QPainterPath"
#include "QGradient"
#include "QtMath"
#include "QDebug"
#include "QTextItem"
#include "QString"
#include "QRadialGradient"
#include "QPolygon"
#include "objet_virtuel.h"
#include <qdebug.h>

loto_dashboard::loto_dashboard()
{
 value =0;
 valueMax=280;
}

QRectF loto_dashboard::boundingRect() const
{

}

void loto_dashboard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    /*re draw new method*/

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



    for (int i= 0; i <= 280; i+=20)
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

        QLine graduations;
        startLinePos.setX(98 * cos((theta+10)*pi/180));
        startLinePos.setY(-98*sin((theta+10)*pi/180));

        endLinePos.setX(90 * cos((theta+10)*pi/180));
        endLinePos.setY(-90 *sin((theta+10)*pi/180));

        graduations.setPoints(startLinePos,endLinePos);
        painter->setRenderHint(QPainter::Antialiasing);

        painter->setPen(QPen(QBrush("white") ,3, Qt::SolidLine,Qt::SquareCap));
        painter->drawLine(graduations);

        int j = -(theta-235);
        if (theta < 90)
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText((110*cos((theta)*pi/180)),(-110 *sin((theta)*pi/180)),QString("%1").arg(j));}

        else
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText((130*cos((theta)*pi/180)),(-110 *sin((theta)*pi/180)),QString("%1").arg(j));};
        }

    /* function to get the speed Value and put needle at the right position*/
        QLine needle;
        QPoint needlestartPos;
        QPoint needlestopPos;
        needlestartPos.setX(0);
        needlestartPos.setY(0);

        double needleAngle;

        speedValue = getValue();
        qDebug()<<speedValue;

        needleAngle = getSpeedAngle(speedValue);
        needleAngle= -(needleAngle) - 125.0;
        qDebug()<<"needleAngle"<< needleAngle;


        needlestopPos.setX(96 * cos((needleAngle)*pi/180));
        needlestopPos.setY(-96*sin((needleAngle)*pi/180));

        needle.setPoints(needlestartPos,needlestopPos);

        painter->setRenderHint(QPainter::HighQualityAntialiasing);

        painter->setPen(QPen(QBrush("red"),3,Qt::SolidLine, Qt::SquareCap));
        painter->drawLine(needle);

        painter->setPen(QPen(QBrush("white"),3,Qt::SolidLine, Qt::SquareCap));
        painter->drawEllipse(-5,-5,10,10);

        //draw text to write km/h
        painter->setPen(QPen(QBrush("gray"),5,Qt::SolidLine, Qt::SquareCap));
        painter->drawText(-20,-30,"km/h");


        //draw text of speedValue in the dashboard.
        QString SpeedValueStr;
        speedValue = getValue();
        SpeedValueStr.setNum(speedValue);
        QBrush displayBrush;
        displayBrush.setStyle(Qt::Dense6Pattern);
        QColor mCol(102,255,255,255);
        displayBrush.setColor(mCol);
        painter->setPen(Qt::NoPen);
        painter->setBrush(displayBrush);
        painter->drawRect(-30,30,70,30);

        painter->setPen(QPen(QBrush("white"),10,Qt::SolidLine, Qt::SquareCap));
        QFont displayFont("Courier");
        displayFont.setPointSize(15);
        displayFont.setWeight(75);
        painter->setFont(displayFont);
        painter->drawText(-25,50,SpeedValueStr);




    // Cordinates to attach the necessary voyants

//    for (int i = 1000;i >= -1000; i-=100)
//    {
//        for (int j = 1000;j >= -1000; j-=100)
//        {
//            painter->setPen(QPen(QBrush("white"),10,Qt::SolidLine, Qt::SquareCap));
//            QFont displayFont("Helvetica");
//            displayFont.setPointSize(8);
//            painter->setFont(displayFont);
//            painter->drawText(i,j,QString("*%1,%2").arg(i).arg(j));

//        }
//    }

}



double loto_dashboard::getSpeedAngle(double speedValue)
{
    double givenSpeedValue = speedValue;
    double speedAngle;
    speedAngle = givenSpeedValue * (280.0/280.0);
    qDebug()<<"speedAngle"<< speedAngle;

    return speedAngle;
}
