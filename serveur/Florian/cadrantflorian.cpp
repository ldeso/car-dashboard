#include "cadrantflorian.h"
#include <QDebug>
#include <QtMath>
CadrantFlorian::CadrantFlorian(bool hasText, bool hasSubTrait,int invertAiguille, int pas, int angleB, int angleE, int valeurMax, QGraphicsItem * parent):objet_virtuel(parent)
{
    this->invertAiguille = invertAiguille;
    this->hasText = hasText;
    this->hasSubTrait = hasSubTrait;
    this->width = 200;
    this->pas = pas;
    this->height = 200;
    this->valueMax = valeurMax;
    this->angleB = angleB;
    this->angleE = angleE;
    this->value = 0;
}

QRectF CadrantFlorian::boundingRect()const
{
    QRectF rect(0,0,width,height);
    return rect;
}
// paint la scène
void CadrantFlorian::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing); // ajout de l antialiasing au tableau de bord
    QPen pen2(QColor(10,10,200));
    QPen pen1(QColor(Qt::gray));
    QPen pen3(QColor(Qt::white));
    pen1.setWidth(1);
    QFont font = QFont();
    font.setPixelSize(9);
    pen2.setWidth(1);
    painter->setPen(pen2);
    // dessine plusieurs cercles pour le compteur pour donner un effet de flou en variant l'alpha
    painter->drawArc(0, 0, width-2, height-2, 16*(angleB+10),(-angleE-20)*16);
    pen2.setColor(QColor(10,10,200,175));
    pen2.setWidth(3);
    painter->setPen(pen2);
    painter->drawArc(0, 0, width-1, height-1, 16*(angleB+10),(-angleE-20)*16);
    pen2.setColor(QColor(10,10,200,120));
    QBrush b(QColor(Qt::red));
    pen2.setWidth(5);
    painter->setPen(pen2);
    painter->drawArc(0, 0, width, height, 16*(angleB+10),(-angleE-20)*16);

    painter->setBrush(b);
    painter->setPen(pen1);
    float f = generateAngle();
    QPoint * p = (QPoint *) malloc(sizeof(QPoint)*4);
    //dessine l'aiguille
    if(invertAiguille==1){
        p[0].setX(width/2);
        p[0].setY(height/2);
        p[1].setX(cos(qDegreesToRadians(-angleB+10+f))*(15)+ width/2);
        p[1].setY(sin(qDegreesToRadians(-angleB+10+f))*(15) + height/2);
        p[2].setX(cos(qDegreesToRadians(-angleB+f))*(width/2-25)+ width/2);
        p[2].setY(sin(qDegreesToRadians(-angleB+f))*(height/2-25) + height/2);
        p[3].setX(cos(qDegreesToRadians(-angleB-10+f))*(15)+ width/2);
        p[3].setY(sin(qDegreesToRadians(-angleB-10+f))*(15) + height/2);
    }
    else{

        p[0].setX(width/2);
        p[0].setY(height/2);
        p[1].setX(cos(qDegreesToRadians(-angleB+10+angleE+f))*(15)+ width/2);
        p[1].setY(sin(qDegreesToRadians(-angleB+10+angleE+f))*(15) + height/2);
        p[2].setX(cos(qDegreesToRadians(-angleB+angleE+f))*(width/2-25)+ width/2);
        p[2].setY(sin(qDegreesToRadians(-angleB+angleE+f))*(height/2-25) + height/2);
        p[3].setX(cos(qDegreesToRadians(-angleB+angleE-10+f))*(15)+ width/2);
        p[3].setY(sin(qDegreesToRadians(-angleB+angleE-10+f))*(15) + height/2);
    }
    painter->drawPolygon(p,4);
    painter->setPen(pen3);
    painter->setFont(font);
    int pair = 0;
    //dessine les petits traits, le texte...
    for(int i=0; i <= this->valueMax; i+=pas){
        float val = (float)angleE/valueMax* i;
        if(pair % 2 == 1 && this->hasSubTrait == true){
            painter->drawLine(cos(qDegreesToRadians(-angleB+val))*(width/2-5)+ width/2,
                              sin(qDegreesToRadians(-angleB+val))*(height/2-5) + height/2,
                              cos(qDegreesToRadians(-angleB+val))*(width/2-7)+ width/2,
                              sin(qDegreesToRadians(-angleB+val))*(height/2-7) + height/2);
        }
        else{
            painter->drawLine(cos(qDegreesToRadians(-angleB+val))*(width/2-5)+ width/2,
                          sin(qDegreesToRadians(-angleB+val))*(height/2-5) + height/2,
                          cos(qDegreesToRadians(-angleB+val))*(width/2-10)+ width/2,
                          sin(qDegreesToRadians(-angleB+val))*(height/2-10) + height/2);
        }
        if(hasText == 1 && pair % 2 == 0){
            painter->drawText(cos(qDegreesToRadians(-angleB+val))*(width/2-20)+ width/2-6,
                              sin(qDegreesToRadians(-angleB+val))*(height/2-20) + height/2+2, QString("%1").arg(i));
        }
        pair++;
    }
}
float CadrantFlorian::generateAngle()
{
    float angle = 0.0f;
    angle = (float)value/valueMax * angleE;
    //qDebug() << value << " " << angle;
    return angle;
}
