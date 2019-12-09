#include "loto_dashboard.h"
#include "QPainter"
#include "QGradient"
#include "QtMath"
#include "QTextItem"
#include "QString"
#include "QPolygon"
#include "objet_virtuel.h"
#include <QDebug>
#include "QFontDatabase"
#include "QDateTime"

///
///\file loto_dashboard.cpp
/// \brief Cet classe est faire pour la affichage de compteur de vitesse
///


loto_dashboard::loto_dashboard()
{
 value =0;
 valueMax=280;
 QFontDatabase::addApplicationFont(":/digital-7.ttf");

}

QRectF loto_dashboard::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

void loto_dashboard::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    /*re draw new method*/

    //Loop to draw tiny concentric rectangles//

    for (int i= 0; i <= 40; i+=1)
    {
        QRectF rectangle(-200+i, -200+i, 400.0-2*i,400.0-2*i);
        int startAngle = -45* 16;
        int spanAngle = 280* 16;
        // set painter properties//

        QPen mPen;
        QColor mCol(17,225,230,220-5*i);
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

        startLinePos.setX(qRound(198 * cos(theta*pi/180)));
        startLinePos.setY(qRound(-198*sin(theta*pi/180)));

        endLinePos.setX(qRound(180* cos(theta*pi/180)));
        endLinePos.setY(qRound(-180*sin(theta*pi/180)));

        QLine Ticks;
        Ticks.setPoints(startLinePos,endLinePos);
        painter->setRenderHint(QPainter::Antialiasing);

        painter->drawLine(Ticks);

        if (theta < 235)

        {
        QLine graduations;
        startLinePos.setX(qRound(198 * cos((theta+10)*pi/180)));
        startLinePos.setY(qRound(-198*sin((theta+10)*pi/180)));

        endLinePos.setX(qRound(190 * cos((theta+10)*pi/180)));
        endLinePos.setY(qRound(-190 *sin((theta+10)*pi/180)));

        graduations.setPoints(startLinePos,endLinePos);
        painter->setRenderHint(QPainter::Antialiasing);

        painter->setPen(QPen(QBrush("white") ,3, Qt::SolidLine,Qt::SquareCap));
        painter->drawLine(graduations);

        }

        QFont displayFont("Courier");
        displayFont.setPointSize(25);
        displayFont.setWeight(75);
        painter->setFont(displayFont);

        int j = -(theta-235);
        if (theta < 90)
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText(qRound(210.0f*cos((theta)*pi/180.0f)),qRound(-210.0f*sin((theta)*pi/180.0f)),QString("%1").arg(j));}
        else
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText(qRound(250.0f*cos((theta)*pi/180.0f)),qRound(-210.0f *sin((theta)*pi/180.0f)),QString("%1").arg(j));}
        }

    /* function to get the speed Value and put needle at the right position*/

        QLine needle;
        QPoint needlestartPos;
        QPoint needlestopPos;
        needlestartPos.setX(0);
        needlestartPos.setY(0);


        speedValue = getValue();

        float needleAngle = getSpeedAngle(speedValue);
        needleAngle= (needleAngle) - 125.0f;


        needlestopPos.setX(qRound(196.0 * cos((needleAngle)*pi/180.0)));
        needlestopPos.setY(qRound(-196.0 *sin((needleAngle)*pi/180.0 )));

        needle.setPoints(needlestartPos,needlestopPos);

        painter->setRenderHint(QPainter::HighQualityAntialiasing);

        painter->setPen(QPen(QBrush("red"),6,Qt::SolidLine, Qt::SquareCap));
        painter->drawLine(needle);

        painter->setPen(QPen(QBrush("white"),6,Qt::SolidLine, Qt::SquareCap));
        painter->drawEllipse(-10,-10,20,20);

        //draw text to write km/h
        painter->setPen(QPen(QBrush("gray"),8,Qt::SolidLine, Qt::SquareCap));
        QFont displayFont("Courier");
        displayFont.setPointSize(30);
        displayFont.setWeight(75);
        painter->setFont(displayFont);
        painter->drawText(-20,-30,"km/h");

        QFont Font;
        Font.setFamily("digital-7");
        Font.setPointSize(40);
        Font.setWeight(75);
        painter->setFont(Font);
        QBrush displayBrush;
        displayBrush.setStyle(Qt::Dense6Pattern);
        QColor mCol(102,255,255,255);
        displayBrush.setColor(mCol);
        painter->setFont(Font);
        painter->setPen(Qt::NoPen);
        painter->setBrush(displayBrush);

        painter->setPen(QPen(QBrush("white"),10,Qt::SolidLine, Qt::SquareCap));
        displayFont.setPointSize(40);
        displayFont.setWeight(75);
        painter->setFont(Font);

        QTime time= QTime::currentTime();
        QString currentTime = time.toString("hh:mm:ss");
        painter->drawText(-40,40,120,50, Qt::AlignCenter,currentTime);

        /* to form the background arc in */


        for (int i= 0; i < 40; i+=1)
        {
            QRectF rectangle(-1900+i, -450+i, 3300.0-2*i, 3300.0-2*i);
            int startAngle = 60* 16;
            int spanAngle = 60* 16;
            // set painter properties//

            QRectF rectangle2(-1900+i, 300+i, 3300.0-2*i, 3300.0-2*i);


            QPen mPen;
            QColor mCol(128,128,128,220-5*i);
            mPen.setCapStyle(Qt::RoundCap);
            mPen.setWidth(1);
            mPen.setColor(mCol);
            QBrush mBrush;
            painter->setBrush(mBrush);
            painter->setPen(mPen);

            painter->setRenderHint(QPainter::Antialiasing);
            painter->drawArc(rectangle,startAngle,spanAngle);            painter->drawArc(rectangle,startAngle,spanAngle);
            painter->drawArc(rectangle2,startAngle,spanAngle);


        }

}

///
/// \brief loto_dashboard::getSpeedAngle
/// \param speedValue
/// \details Ici, la function loto_dashboard::getSpeedAngle prendre la valeur de vitesse et puis faire le calcule de position d'aiguille.
///


float loto_dashboard::getSpeedAngle(float speedValue)
{

    float givenSpeedValue = speedValue;
    float speedAngle;
    speedAngle = givenSpeedValue * (280.0f/280.0f);
    return speedAngle;
}
