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
#include "qtimer.h"

///
///\file tempgauge.cpp
/// \brief Cet classe est faire pour la affichage de jauge temperature.
///


///
/// \brief tempGauge::tempGauge
///\details Ici le variable "value" est initialisé dans le constructeur. La valueMax est aussi initailisée.
///

tempGauge::tempGauge()
{
    value =0;
    valueMax = 150;
}

QRectF tempGauge::boundingRect() const
{
    return QRect(-200,-200,400,400);

}

void tempGauge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);

    //Loop to draw tiny concentric rectangles//

    for (int i= 0; i < 40; i+=1)
    {
        QRectF rectangle(-200+i, -200+i, 400.0-2*i, 400.0-2*i);
        int startAngle = 135 * 16;
        int spanAngle = 50* 16;

        // set painter properties//

        QPen mPen;
        QColor mCol(17,225,230,220-5*i);
        mPen.setCapStyle(Qt::RoundCap);
        mPen.setWidth(1);
        mPen.setColor(mCol);
        QBrush mBrush;
        painter->setBrush(mBrush);
        painter->setPen(mPen);

        painter->drawArc(rectangle,startAngle,spanAngle);
    }

    QPen mPen;
    QColor mCol(35,191,230,255);
    mPen.setCapStyle(Qt::RoundCap);
    mPen.setWidth(3);
    mPen.setColor(mCol);
    QBrush mBrush;
    painter->setBrush(mBrush);
    painter->setPen(mPen);


    for (int theta= 135; theta <=185; theta+=10)
    {
        painter->setPen(QPen(QBrush("white"),3, Qt::SolidLine,Qt::SquareCap));
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

        QLine graduations;
        startLinePos.setX(qRound(198 * cos((theta+10)*pi/180)));
        startLinePos.setY(qRound(-198*sin((theta+10)*pi/180)));

        endLinePos.setX(qRound(190 * cos((theta+10)*pi/180)));
        endLinePos.setY(qRound(-190 *sin((theta+10)*pi/180)));

        graduations.setPoints(startLinePos,endLinePos);
        painter->setRenderHint(QPainter::Antialiasing);

        painter->setPen(QPen(QBrush("white"),5, Qt::SolidLine,Qt::SquareCap));
        //painter->drawLine(graduations);

        // Here we set the text to add to our gauge.
        //For fuel gauge, we will label only E for empty and  F for full with Red and Green/blue respectively

        // This CANot be done in a loop else we will skip the point to label. Else create a variable to take the position

        QFont displayFont("Courier");
        displayFont.setPointSize(25);
        displayFont.setWeight(75);
        painter->setFont(displayFont);

        int fuelEmptyLabel= 135; //angle to place high temperature

        painter->setPen(QPen(QBrush("red"),5,Qt::SolidLine));
        painter->drawText(qRound(210*cos((fuelEmptyLabel)*pi/180)),qRound(-210 *sin((fuelEmptyLabel)*pi/180)),"H");

        int fuelFullLabel= 185; // angle to place low temperature

        painter->setPen(QPen(QBrush("green"),5,Qt::SolidLine));
        painter->drawText(qRound(215*cos((fuelFullLabel)*pi/180)),qRound(-210 *sin((fuelFullLabel)*pi/180)),"C");

    }

    /* function to get the speed Value and put needle at the right position*/
    QLine needle;
    QPoint needlestartPos;
    QPoint needlestopPos;
    needlestartPos.setX(0);
    needlestartPos.setY(0);

     float needleAngle;
    float jaugeTemp = getValue();
    needleAngle = - (175.0f + getEngineTemp(jaugeTemp));

    needlestopPos.setX(qRound(196 * cos((needleAngle)*pi/180)));
    needlestopPos.setY(qRound(-196*sin((needleAngle)*pi/180)));

    needle.setPoints(needlestartPos,needlestopPos);

    painter->setRenderHint(QPainter::HighQualityAntialiasing);

    painter->setPen(QPen(QBrush("red"),6,Qt::SolidLine, Qt::SquareCap));
    painter->drawLine(needle);

    painter->setPen(QPen(QBrush("white"),3,Qt::SolidLine, Qt::SquareCap));
    painter->drawEllipse(-5,-5,10,10);

    if (jaugeTemp >120)
    {
    QPixmap ledEngineTemp(":/engineT_red");
    QPixmap ledEngineTemp2=ledEngineTemp.scaled(70,70,Qt::IgnoreAspectRatio,Qt::FastTransformation);
    painter->drawPixmap(-100,-70,ledEngineTemp2);
    }
    else if(jaugeTemp < 70)
    {
        QPixmap ledEngineTemp(":/engineT_blue");
        QPixmap ledEngineTemp2=ledEngineTemp.scaled(70,70,Qt::IgnoreAspectRatio,Qt::FastTransformation);
        painter->drawPixmap(-150,-70,ledEngineTemp2);
    }


}


///
/// \brief tempGauge::getEngineTemp
/// \param engineTemp
/// \details Ici, la function tempGauge::getEngineTemp prendre la valeur pour la temperature et puis faire le calcule de position d'aiguille.
///

float tempGauge::getEngineTemp(float engineTemp)
{
    float inputTemp = engineTemp; float engineTempAngle;
    engineTempAngle = inputTemp * (50.0f/150.0f);
    return engineTempAngle;
}


