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

///
///\file fuel_guage.cpp
/// \brief Cet classe est dérivé de la classe objet_virtuel et il fait la calcule pour les jauge essence et affiche les icones quand le value d'entree est trop petit ou trop grande.
///

///
/// \brief fuel_guage::fuel_guage
///\details Ici le variable "value" est initialisé et la valeur maximal est déclaré aussi
///
    fuel_guage::fuel_guage()
    {
        value =0;
        valueMax=100;
    }

    QRectF fuel_guage::boundingRect() const
    {
        return QRect(-200,-200,400,400);

    }



    ///
    /// \brief fuel_guage::paint
    /// \param painter
    ///\details Ici, la override function de paint est utilisé pour dessiner les voyants. Les directions: A droite, a gauche, sont representé par la valeur de la variable value.
    ///

    void fuel_guage::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
    {   painter->setRenderHint(QPainter::Antialiasing);

        //Loop to draw tiny concentric rectangles//

        for (int i= 0; i < 40; i+=1)
        {
            QRectF rectangle(-200+i, -200+i, 400.0-2*i, 400.0-2*i);
            int startAngle = 0 * 16;
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
            mPen.setWidth(2);
            mPen.setColor(mCol);
            QBrush mBrush;
            painter->setBrush(mBrush);
            painter->setPen(mPen);


        for (int theta= 1; theta <=50; theta+=20)
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
            painter->drawLine(Ticks);

            QLine graduations;
            startLinePos.setX(qRound(198 * cos((theta+10)*pi/180)));
            startLinePos.setY(qRound(-198*sin((theta+10)*pi/180)));

            endLinePos.setX(qRound(190 * cos((theta+10)*pi/180)));
            endLinePos.setY(qRound(-190 *sin((theta+10)*pi/180)));

            graduations.setPoints(startLinePos,endLinePos);
            painter->setRenderHint(QPainter::Antialiasing);

            painter->setPen(QPen(QBrush("white"),5, Qt::SolidLine,Qt::SquareCap));
            painter->drawLine(graduations);

            // Here we set the text to add to our gauge.
            //For fuel gauge, we will label only E for empty and  F for full with Red and Green/blue respectively

            // This CANot be done in a loop else we will skip the point to label. Else create a variable to take the position

            QFont displayFont("Courier");
            displayFont.setPointSize(25);
            displayFont.setWeight(75);
            painter->setFont(displayFont);

            int fuelEmptyLabel= 0;
            painter->setPen(QPen(QBrush("red"),5,Qt::SolidLine));
            painter->drawText(qRound(210*cos((fuelEmptyLabel)*pi/180)),qRound(-210 *sin((fuelEmptyLabel)*pi/180)),"E");

            int fuelFullLabel= 50;
            painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine));
            painter->drawText(qRound(210*cos((fuelFullLabel)*pi/180)),qRound(-210 *sin((fuelFullLabel)*pi/180)),"F");

        }

        /* function to get the speed Value and put needle at the right position*/

            QLine needle;

            QPoint needlestartPos;
            QPoint needlestopPos;
            needlestartPos.setX(0);
            needlestartPos.setY(0);

            float needleAngle;
            tankLevelLitres=float(getValue());
            needleAngle = getrotationAngle(tankLevelLitres);


            needlestopPos.setX(qRound(196 * cos((needleAngle)*pi/180)));
            needlestopPos.setY(qRound(-196*sin((needleAngle)*pi/180)));

            needle.setPoints(needlestartPos,needlestopPos);
            painter->setPen(QPen(QBrush("red"),6,Qt::SolidLine, Qt::SquareCap));
            painter->drawLine(needle);

            //draw ellipse for needle wheel
            painter->setPen(QPen(QBrush("white"),3,Qt::SolidLine, Qt::SquareCap));
            painter->drawEllipse(-5,-5,10,10);

            ///boucle qui prendre la valeur et affiche les icons si l'essence est trop ou moins.

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
            }

    }

    ///
    /// \brief fuel_guage::getrotationAngle
    /// \param tankLevelLitres
    /// \details Ici, la function fuel_guage::getrotationAngle() prendre la niveau d'essence et puis faire le calcule de position d'aiguille.
    ///
    ///
    float fuel_guage::getrotationAngle(float tankLevelLitres)
    {
        float inputTankLevel = tankLevelLitres;
        float tankLevelAngle;
        tankLevelAngle = inputTankLevel * (50.0f/100.0f);
        return tankLevelAngle;
    }

