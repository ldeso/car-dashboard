#include "blinkingleds.h"
#include "objet_virtuel.h"
#include "QPainter"
#include "QPainterPath"
#include "QGradient"
#include "QtMath"
#include "QDebug"
#include "QTextItem"
#include "QString"
#include "QRadialGradient"
#include "QPolygon"
#include "QTest"


///
///\file blinkingleds.cpp
/// \brief Cet classe est dérivé de la classe objet_virtuel et il affiche toute les voyants qu'ont prendre la valeur ON et OFF
///


///
/// \brief blinkingleds::blinkingleds
///\details Ici le variable "value" est initialisé
///
blinkingleds::blinkingleds()
{
    value = 0; /// set default value to 0
    blinker = 0;
}

QRectF blinkingleds::boundingRect() const
{
    return QRect(-200,-200,400,400);
}

///
/// \brief blinkingleds::paint
/// \param painter
///\details Ici, la override function de paint est utilisé pour dessiner les voyants. Les directions: A droite, a gauche, sont representé par la valeur de la variable value.
///
void blinkingleds::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    int direction = static_cast<int>(getValue()); ///getValue() retourner une float, static cast est necessaire pour faire explicit conversion

    if (direction != 0)
    {
        if (direction==-1)
        {
            QPixmap pointerL(":/turnLeft.gif");
            QPixmap pointerL2=pointerL.scaled(50,50);
            painter->setOpacity(blinker);
            painter->drawPixmap(120,-350,90,90,pointerL2);
        }
        if (direction==1){
            QPixmap pointerR(":/turnRight.gif");
            QPixmap pointerR2=pointerR.scaled(50,50);
            painter->setOpacity(blinker);
            painter->drawPixmap(250,-350,90,90,pointerR2);
        }
        if (direction==2){
            QPixmap pointerR(":/turnRight.gif");
            QPixmap pointerR2=pointerR.scaled(50,50);
            painter->setOpacity(blinker);
            painter->drawPixmap(250,-350,90,90,pointerR2);

            QPixmap pointerL3(":/turnLeft.gif");
            QPixmap pointerL4=pointerL3.scaled(50,50);
            painter->setOpacity(blinker);
            painter->drawPixmap(-120,-350,90,90,pointerL4);
        }

        blinkled();
    }
}

///
/// \brief blinkingleds::blinkled()
/// \param blinker
///\details La fonction effectué la effet clignotant de les voyants.La function, appellée dans la boucle continuer l'affichage de paint en utilisant de methode "setOpacity" de paint.
///

void blinkingleds::blinkled()
{
    if (this->blinker==1){
        this->blinker=0;
    }
    else{
        this->blinker=1;
    }
    QTest::qWait(400);
    update();
}
