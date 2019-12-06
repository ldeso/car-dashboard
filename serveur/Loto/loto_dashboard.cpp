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
    return QRect(-200,-200,400,400);
}

void loto_dashboard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    /*re draw new method*/

    //Loop to draw tiny concentric rectangles//
    for (int i= 0; i <= 30; i+=1)
    {
        QRectF rectangle(-200+i, -200+i, 400.0-2*i,400.0-2*i);
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



    for (int i= 0; i <= 280; i+=20)
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

        QLine graduations;
        startLinePos.setX(198 * cos((theta+10)*pi/180));
        startLinePos.setY(-198*sin((theta+10)*pi/180));

        endLinePos.setX(190 * cos((theta+10)*pi/180));
        endLinePos.setY(-190 *sin((theta+10)*pi/180));

        graduations.setPoints(startLinePos,endLinePos);
        painter->setRenderHint(QPainter::Antialiasing);

        painter->setPen(QPen(QBrush("white") ,3, Qt::SolidLine,Qt::SquareCap));
        painter->drawLine(graduations);

        QFont displayFont("Courier");
        displayFont.setPointSize(25);
        displayFont.setWeight(75);
        painter->setFont(displayFont);

        int j = -(theta-235);
        if (theta < 90)
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText((210*cos((theta)*pi/180)),(-210 *sin((theta)*pi/180)),QString("%1").arg(j));}

        else
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText((250*cos((theta)*pi/180)),(-210 *sin((theta)*pi/180)),QString("%1").arg(j));};
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


        needlestopPos.setX(196 * cos((needleAngle)*pi/180));
        needlestopPos.setY(-196*sin((needleAngle)*pi/180));

        needle.setPoints(needlestartPos,needlestopPos);

        painter->setRenderHint(QPainter::HighQualityAntialiasing);

        painter->setPen(QPen(QBrush("red"),3,Qt::SolidLine, Qt::SquareCap));
        painter->drawLine(needle);

        painter->setPen(QPen(QBrush("white"),3,Qt::SolidLine, Qt::SquareCap));
        painter->drawEllipse(-10,-10,20,20);

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
