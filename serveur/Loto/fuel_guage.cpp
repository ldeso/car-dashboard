    #include "fuel_guage.h"
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
#include "qtest.h"

    fuel_guage::fuel_guage()
    {
        value =0;
        valueMax=100;
    }

    QRectF fuel_guage::boundingRect() const
    {
        return QRect(-200,-200,400,400);

    }

    void fuel_guage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {


        //Loop to draw tiny concentric rectangles//
        for (int i= 0; i < 30; i+=1)
        {
            QRectF rectangle(-200+i, -200+i, 400.0-2*i, 400.0-2*i);
            int startAngle = 0 * 16;
            int spanAngle = 50* 16;

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

            QPen mPen;
            QColor mCol(35,191,230,255);
            mPen.setCapStyle(Qt::RoundCap);
            mPen.setWidth(2.5);
            mPen.setColor(mCol);
            QBrush mBrush;
            painter->setBrush(mBrush);
            painter->setPen(mPen);


        for (int theta= 1; theta <=50; theta+=20)
        {
            painter->setPen(QPen(QBrush("white"),3, Qt::SolidLine,Qt::SquareCap));
            QLine line_j[theta];
            QPoint startLinePos;
            QPoint endLinePos;

            startLinePos.setX(198 * cos(theta*pi/180));
            startLinePos.setY(-198*sin(theta*pi/180));

            endLinePos.setX(180* cos(theta*pi/180));
            endLinePos.setY(-180*sin(theta*pi/180));

            line_j[theta].setPoints(startLinePos,endLinePos);


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

            painter->setPen(QPen(QBrush("white"),5, Qt::SolidLine,Qt::SquareCap));
            painter->drawLine(graduations);

            // Here we set the text to add to our gauge.
            //For fuel gauge, we will label only E for empty and  F for full with Red and Green/blue respectively

            // This cannot be done in a loop else we will skip the point to label. Else create a variable to take the position

            QFont displayFont("Courier");
            displayFont.setPointSize(25);
            displayFont.setWeight(75);
            painter->setFont(displayFont);

            int fuelEmptyLabel= 0;

            painter->setPen(QPen(QBrush("red"),5,Qt::SolidLine));
            painter->drawText((210*cos((fuelEmptyLabel)*pi/180)),(-210 *sin((fuelEmptyLabel)*pi/180)),"E");

            int fuelFullLabel= 50;

            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText((210*cos((fuelFullLabel)*pi/180)),(-210 *sin((fuelFullLabel)*pi/180)),"F");

        }

        /* function to get the speed Value and put needle at the right position*/



            QLine needle;

            QPoint needlestartPos;
            QPoint needlestopPos;
            needlestartPos.setX(0);
            needlestartPos.setY(0);

            double needleAngle;
            tankLevelLitres= getValue();
            needleAngle = getrotationAngle(tankLevelLitres);
            needleAngle= needleAngle;


            needlestopPos.setX(196 * cos((needleAngle)*pi/180));
            needlestopPos.setY(-196*sin((needleAngle)*pi/180));

            needle.setPoints(needlestartPos,needlestopPos);

            painter->setRenderHint(QPainter::HighQualityAntialiasing);

            painter->setPen(QPen(QBrush("red"),3,Qt::SolidLine, Qt::SquareCap));
            painter->drawLine(needle);

            painter->setPen(QPen(QBrush("white"),3,Qt::SolidLine, Qt::SquareCap));
            painter->drawEllipse(-5,-5,10,10);

            if (getValue() > 90)
            {
            QPixmap ledEngineTemp(":/fuelL_white.gif");
            QPixmap ledEngineTemp2=ledEngineTemp.scaled(70,70,Qt::IgnoreAspectRatio,Qt::FastTransformation);
            painter->drawPixmap(100,-70,ledEngineTemp2);
            }
            else if(getValue()< 30)
            {
                    QPixmap ledEngineTemp(":/fuelL_red.gif");
                    QPixmap ledEngineTemp2=ledEngineTemp.scaled(70,70,Qt::IgnoreAspectRatio,Qt::FastTransformation);
                    painter->drawPixmap(100,-70,ledEngineTemp2);
                    blinker();

            }


    }

    double fuel_guage::getrotationAngle(double tankLevelLitres)
    {
        double inputTankLevel = tankLevelLitres;
        double tankLevelAngle;
        tankLevelAngle = inputTankLevel * (50.0/100.0);
        return tankLevelAngle;
    }

    void fuel_guage::blinker()
    {
            blink = !blink;
            QTest::qWait(500);
            update();
    }
