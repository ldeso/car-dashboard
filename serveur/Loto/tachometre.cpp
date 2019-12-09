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


///
///\file tachometre.cpp
/// \brief Cet classe est faire pour la affichage de compteur tours per minute d'engine.
///


///
/// \brief tachometre::tachometre
///\details Ici le variable "value" est initialisé dans le constructeur. La valueMax est aussi initailisée.
///
tachometre::tachometre()
{
    value =0;
    valueMax=14000;
}

QRectF tachometre::boundingRect() const
{
    return QRect(-200,-200,400,400);

}

void tachometre::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    //Loop to draw tiny concentric rectangles//
    for (int i= 0; i < 40; i+=1)
    {
        QRectF rectangle(-200+i, -200+i, 400.0-2*i, 400.0-2*i);
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

    for (int i= 0; i <= 280; i+=40)
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
        QFont displayFont("Courier");
        displayFont.setPointSize(25);
        displayFont.setWeight(75);
        painter->setFont(displayFont);
        painter->setRenderHint(QPainter::Antialiasing);


        int j = (-(theta-235))/20;

        if (theta < 90)
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText(qRound(210*cos((theta)*pi/180)),qRound(-210 *sin((theta)*pi/180)),QString("%1").arg(j));
        }

        else
        {
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText(qRound(230*cos(theta*pi/180)),qRound(-210 *sin(theta*pi/180)),QString("%1").arg(j));
        }


    /* function to get the speed Value and put needle at the right position*/

    QLine needle;

    QPoint needlestartPos;
    QPoint needlestopPos;
    needlestartPos.setX(0);
    needlestartPos.setY(0);

    float needleAngle;
    rpmValue = float(getValue());
    needleAngle = getRpmValue(rpmValue);
    needleAngle= -(needleAngle) - 125.0f;


    needlestopPos.setX(qRound(196.0f* (cos((needleAngle)*pi/180.0f))));
    needlestopPos.setY(qRound(-196.0f*(sin((needleAngle)*pi/180.0f))));

    needle.setPoints(needlestartPos,needlestopPos);

    painter->setRenderHint(QPainter::HighQualityAntialiasing);

    painter->setPen(QPen(QBrush("red"),6,Qt::SolidLine, Qt::SquareCap));
    painter->drawLine(needle);

    painter->setPen(QPen(QBrush("white"),6,Qt::SolidLine, Qt::SquareCap));
    painter->drawEllipse(-10,-10,20,20);

    //draw text to write rpm

    painter->setPen(QPen(QBrush("gray"),8,Qt::SolidLine, Qt::SquareCap));
    displayFont.setPointSize(30);
    displayFont.setWeight(50);
    painter->setFont(displayFont);
    painter->drawText(-85,-30,"x 1000rpm");

}




    ///
    /// \brief tachometre::getRpmValue
    /// \param rpmValue
    /// \details Ici, la function tachometre::getRpmValue prendre la valeur de rpm et puis faire le calcule de position d'aiguille.
    ///


}

float tachometre::getRpmValue(float rpmValue)
{
    float rpmAngle;
    rpmAngle = float(rpmValue * (280.0f/14000.0f));
    return rpmAngle;
}

