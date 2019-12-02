#include <QDebug>
#include <QtMath>
#include <QLinearGradient>
#include <QRadialGradient>
#include "jonas_compteur.h"

Jonas_compteur::Jonas_compteur()
{
    valueMax = 220;
    alpha = -50;
    beta = 230;
    gaugeSize = 150;
    textLabel = "km/h";
    graduations = 23;
    mod = 2;
    hLine = 1;
    for (int i=0; i<=valueMax/10; i++) {
        textAround << (QString::number(10*i));
    }
}

Jonas_compteur::Jonas_compteur(int max, QStringList gradList, float startAngle, float endAngle, QString textCenter,int ngrad, bool line, int modulo, int size)
{
    if (endAngle > startAngle) {
        alpha = startAngle;
        beta = endAngle;
    }
    else if (endAngle < startAngle) {
        alpha = endAngle;
        beta = startAngle;
    }
    else
        qDebug() << "erreur startAngle = endAngle";

    valueMax = max;
    gaugeSize = size;
    textAround = gradList;
    textLabel = textCenter;
    graduations = ngrad;
    hLine = line;
    mod = modulo;
}

QRectF Jonas_compteur::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void Jonas_compteur::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    // Definition des constantes
    const float spanAngle = beta - alpha;
    const float needleSize = gaugeSize*120/150;
    const float diffAngle = (spanAngle+2)/(graduations-1);

    // Active l'antialiasing pour les formes géométriques
    painter->setRenderHints(QPainter::Antialiasing);

    //////////////////////////////////////////////////////////////////////////////////////////

    // Définition des différentes options graphiques
    QPen gaugePen(QColor(Qt::black), gaugeSize*15/150, Qt::SolidLine, Qt::FlatCap);
    QPen needlePen(QColor(Qt::red), gaugeSize*8/150, Qt::SolidLine, Qt::RoundCap);
    QLineF needle(0,0,-90,0);
    QRectF needleCenter(-10, -10, 20, 20);
    //////////////////////////////////////////////////////////////////////////////////////////

    // Définition des gradients
    QRadialGradient radialGradient;
    QLinearGradient linearGradient;
    linearGradient.setColorAt(0.0, Qt::white);
    linearGradient.setColorAt(0.3, QColor(172, 154, 154));
    radialGradient.setColorAt(0.0, Qt::black);
    radialGradient.setColorAt(1.0, Qt::white);
    linearGradient.setSpread(QGradient::ReflectSpread);
    radialGradient.setSpread(QGradient::ReflectSpread);
    //////////////////////////////////////////////////////////////////////////////////////////

    // Dessine les carrés qui vont contenir les différents élements du cadrant
    QRect rect[50];
    int space = gaugeSize*5/150;
    for (int i=0;i<50;i++)
    {
        rect[i]=QRect(-gaugeSize+i*space,-gaugeSize+i*space,(gaugeSize-i*space)*2,(gaugeSize-i*space)*2);
//        painter->setPen(QPen(Qt::white));
//        painter->drawRect(rect[i]);
    }
    painter->setPen(Qt::white);
    //////////////////////////////////////////////////////////////////////////////////////////

    // Dessine les graduations du cadrant
    int k = 0;
    float delta = beta;
    for (int i=0; i<graduations; i++)
    {
        if  (k%2 == 0) {
            painter->setPen(QPen(QBrush(QColor(38, 10, 178)), gaugeSize*24/150, Qt::SolidLine, Qt::FlatCap));
            painter->drawArc(rect[3],delta*16, gaugeSize*28/150);
        }
        else {
            painter->setPen(QPen(QBrush(Qt::white), gaugeSize*15/150, Qt::SolidLine,Qt::FlatCap));
                painter->drawArc(rect[3],delta*16, gaugeSize*12/150);
            }
            delta -= diffAngle;
        k++;
    }
    //////////////////////////////////////////////////////////////////////////////////////////

    // Dessine le cadrant intérieur
    painter->setPen(QPen(QBrush(QColor(38, 10, 178)), 8));
    painter->drawArc(rect[1],(alpha)*16, (spanAngle-1)*16);
    //////////////////////////////////////////////////////////////////////////////////////////

    // Dessine le cadrant extérieur
    QPointF p1(qCos(qDegreesToRadians(beta+15))*rect[0].height()/2, -qSin(qDegreesToRadians(beta+15))*rect[0].height()/2);
    QPointF p2(qCos(qDegreesToRadians(alpha-15))*rect[0].height()/2, -qSin(qDegreesToRadians(alpha-15))*rect[0].height()/2);
    painter->setPen(QPen(QBrush(linearGradient), 7, Qt::SolidLine,Qt::RoundCap));
    painter->drawArc(rect[0],(alpha-15)*16, (spanAngle+30)*16);
    if (hLine)
    painter->drawLine(p1, p2);
    //////////////////////////////////////////////////////////////////////////////////////////


    // Dessine le texte autour du cadrant
    painter->setPen(QPen(QBrush(QColor(Qt::white)) , gaugeSize*15/150 , Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Ubuntu", gaugeSize*11/150, -1,false));
    float gamma = beta;
    int j = 0;

    for (int i=0; i<textAround.size(); i++)
    {
        if (j%mod == 0) {
        painter->drawText(qCos(qDegreesToRadians((gamma)))*rect[8].height()/2-gaugeSize*10/150,
                -qSin(qDegreesToRadians(gamma))*rect[8].height()/2 +gaugeSize*5/150,
                textAround[i]);
        }
        j++;
        gamma -= (spanAngle)/(float)(textAround.size()-1);
    }

    painter->setFont(QFont("Helvetica", gaugeSize*12/150, QFont::Bold));
    painter->setPen(QPen(QBrush(QColor(Qt::white)), gaugeSize*4/150));
    painter->drawText(qCos(qDegreesToRadians(90.0))*rect[21].height()/2-gaugeSize*20/150,
            -qSin(qDegreesToRadians(90.0))*rect[21].height()/2,
            textLabel);

    //////////////////////////////////////////////////////////////////////////////////////////


    // Dessine l'aiguille et met à jour sa position
    needle.setP1(QPointF(0, 0));
    needle.setP2(QPointF(qCos(speedToAngle(value)), -qSin(speedToAngle(value)))); // Positionne l'aiguille selon la vitesse en entrée
    needle.setLength(needleSize);
    painter->setPen(needlePen);
    painter->drawLine(needle);
    painter->setPen(QPen(QBrush(QColor(172, 154, 154)), 4, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QBrush(Qt::black));
    painter->drawEllipse(needleCenter);
    ////////////////////////////////////////////////////////////////////////////////////////
}

float Jonas_compteur::speedToAngle(float speed)
{
    if (speed != 0)
        return qDegreesToRadians(((alpha-beta)/(valueMax))*speed+beta);
    else
        return qDegreesToRadians(beta);
}








