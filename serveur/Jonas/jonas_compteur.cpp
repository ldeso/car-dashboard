#include <QDebug>
#include <QtMath>
#include <QLinearGradient>
#include <QRadialGradient>
#include "jonas_compteur.h"

/**
 * @brief Jonas_compteur::Jonas_compteur
 * @details constructeur par défaut
 */
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
    critical = valueMax;
    for (int i=0; i<=valueMax/10; i++) {
        textAround << (QString::number(10*i));
    }
}

/**
 * @brief Jonas_compteur::Jonas_compteur
 * @details constructeur surchargé
 * @param max
 * @param gradList
 * @param startAngle
 * @param endAngle
 * @param critic
 * @param textCenter
 * @param ngrad
 * @param line
 * @param modulo
 * @param size
 */
Jonas_compteur::Jonas_compteur(int max, QStringList gradList, float startAngle, float endAngle, int critic, QString textCenter,int ngrad, bool line, int modulo, int size)
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
    if (critic >=0 && critic <=valueMax) {
        critical = critic;
    }
}

/**
 * @brief Jonas_compteur::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF Jonas_compteur::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

/**
 * @brief Jonas_compteur::paint
 * @param painter
 * @details dessine les différents élements du compteur
 */
void Jonas_compteur::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    /// Definition des constantes
    const float spanAngle = beta - alpha;
    const float diffAngle = (spanAngle+2)/(graduations-1);

    /// Active l'antialiasing pour les formes géométriques
    painter->setRenderHints(QPainter::Antialiasing);

    //////////////////////////////////////////////////////////////////////////////////////////

    /// Définition des différentes options graphiques
    QPen gaugePen(QColor(Qt::black), gaugeSize*15/150, Qt::SolidLine, Qt::FlatCap);
    QPen needlePen(QColor(Qt::red), gaugeSize*8/150, Qt::SolidLine, Qt::RoundCap);

    //////////////////////////////////////////////////////////////////////////////////////////


    /// Dessine les carrés qui vont contenir les différents élements du cadrant
    QRect rect[50];
    int space = gaugeSize*5/150;
    for (int i=0;i<50;i++)
    {
        rect[i]=QRect(-gaugeSize+i*space,-gaugeSize+i*space,(gaugeSize-i*space)*2,(gaugeSize-i*space)*2);
    }
    painter->setPen(Qt::white);
    //////////////////////////////////////////////////////////////////////////////////////////

    /// Définition des gradients
    QRadialGradient radialGrad1(QPointF(0,0), rect[2].height()/2);
    QLinearGradient linearGrad1(rect[0].topLeft(), rect[0].bottomRight());
    QLinearGradient linearGrad2(rect[2].topLeft(), rect[2].bottomRight());
    linearGrad1.setColorAt(1.0, Qt::white);
    linearGrad1.setColorAt(0.0, QColor(169, 165, 166));
    linearGrad2.setColorAt(0.0, Qt::white);
    linearGrad2.setColorAt(1.0, Qt::black);
    radialGrad1.setColorAt(1.0, Qt::black);
    radialGrad1.setColorAt(0.0, Qt::white);
    linearGrad1.setSpread(QGradient::ReflectSpread);
    linearGrad2.setSpread((QGradient::ReflectSpread));
    radialGrad1.setSpread(QGradient::ReflectSpread);

    /// Dessine les gradients en arrière plan
//    painter->setBrush(QBrush(radialGrad1));
//    painter->setPen(Qt::NoPen);
//    painter->drawEllipse(QPoint(0,0), rect[2].height()/2, rect[2].height()/2);
    //////////////////////////////////////////////////////////////////////////////////////////

    /// Dessine les graduations du cadrant
    int k = 0;
    float delta = beta;
    for (int i=0; i<graduations; i++)
    {
        if (critical == valueMax || delta > qRadiansToDegrees(speedToAngle(critical))) {
            if  (k%2 == 0) {
                painter->setPen(QPen(QBrush(QColor(38, 10, 178)), gaugeSize*24/150, Qt::SolidLine, Qt::FlatCap));
                painter->drawArc(rect[3],delta*16, gaugeSize*28/150);
            }
            else {
                painter->setPen(QPen(QBrush(Qt::white), gaugeSize*15/150, Qt::SolidLine,Qt::FlatCap));
                painter->drawArc(rect[3],delta*16, gaugeSize*12/150);
            }
        }
        else {
            if  (k%2 == 0) {
                painter->setPen(QPen(QBrush(QColor(252, 3, 11)), gaugeSize*24/150, Qt::SolidLine, Qt::FlatCap));
                painter->drawArc(rect[3],delta*16, gaugeSize*28/150);
            }
            else {
                painter->setPen(QPen(QBrush(QColor(252, 3, 11)), gaugeSize*15/150, Qt::SolidLine,Qt::FlatCap));
                painter->drawArc(rect[3],delta*16, gaugeSize*12/150);
            }
        }
            delta -= diffAngle;
        k++;
    }
    //////////////////////////////////////////////////////////////////////////////////////////

    /// Dessine le cadrant intérieur
    if (critical == valueMax) {
        painter->setPen(QPen(QBrush(QColor("dark blue")), 8));
        painter->drawArc(rect[1],(alpha+1)*16, (spanAngle-2)*16);
    }

    else {
        painter->setPen(QPen(QBrush(QColor(38, 10, 178)), 8));
        painter->drawArc(rect[1],(alpha)*16, (spanAngle-1)*16);
        painter->setPen(QPen(QBrush(QColor(252, 3, 11)), 8));
        painter->drawArc(rect[1],(alpha)*16, (qAbs(qRadiansToDegrees(speedToAngle(critical))-alpha-2.5))*16);
    }

    //////////////////////////////////////////////////////////////////////////////////////////

    /// Dessine le cadrant extérieur
    QPointF p1(qCos(qDegreesToRadians(beta+15))*rect[0].height()/2, -qSin(qDegreesToRadians(beta+15))*rect[0].height()/2);
    QPointF p2(qCos(qDegreesToRadians(alpha-15))*rect[0].height()/2, -qSin(qDegreesToRadians(alpha-15))*rect[0].height()/2);
    painter->setPen(QPen(QBrush(linearGrad1), 7, Qt::SolidLine,Qt::RoundCap));
    painter->drawArc(rect[0],(alpha-15)*16, (spanAngle+30)*16);
    if (hLine)
    painter->drawLine(p1, p2);
    //////////////////////////////////////////////////////////////////////////////////////////


    /// Dessine le texte autour du cadrant
    painter->setPen(QPen(QBrush(QColor(Qt::white)) , gaugeSize*15/150 , Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Ubuntu", gaugeSize*12/150, -1,false));
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


    /// Dessine l'aiguille et met à jour sa position à chaque update
    painter->setPen(QPen(QBrush(Qt::white), 1));
    painter->setBrush(Qt::red);
    QPointF c(qCos(speedToAngle(value))*rect[6].height()/4, -qSin(speedToAngle(value))*rect[6].height()/4);
    QPointF v1(qCos(speedToAngle(value))*rect[6].height()/2, -qSin(speedToAngle(value))*rect[6].height()/2);
    double n = qSqrt(qPow(v1.x(),2)+qPow(v1.y(),2));
    double d = 6.0*gaugeSize/150;
    QPointF n1 = v1/n;
    QPointF n2(n1.y(), -n1.x());
    QPointF P[4];
    P[0].setX(0);
    P[0].setY(0);
    P[1].setX(c.x()+d*n2.x());
    P[1].setY(c.y()+d*n2.y());
    P[3].setX(c.x()-d*n2.x());
    P[3].setY(c.y()-d*n2.y());
    P[2].setX(qCos(speedToAngle(value))*rect[6].height()/2);
    P[2].setY(-qSin(speedToAngle(value))*rect[6].height()/2);

    QLinearGradient linearGradNeedle(P[0], P[3]);
    linearGradNeedle.setColorAt(0, QColor(Qt::darkRed));
    linearGradNeedle.setColorAt(0.5, QColor(230, 46, 0));
    linearGradNeedle.setColorAt(1, QColor(Qt::darkRed));

    painter->setBrush(QBrush(linearGradNeedle));
    painter->setPen(QPen(QColor(Qt::darkRed), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawPolygon(P,4);

    /// Dessine le cercle à la base de l'aiguille
    QRectF needleCenter(-10, -10, 20, 20);
    QLinearGradient linearGrad(needleCenter.topLeft(), needleCenter.bottomRight());
    linearGrad.setColorAt(0, QColor(200,200,200));
    linearGrad.setColorAt(1, QColor(0,0,0));
    painter->setBrush(QBrush(linearGrad));
    painter->setPen(QPen(QBrush(QColor(172, 154, 154)), 1, Qt::SolidLine,Qt::FlatCap));
    painter->drawEllipse(needleCenter);

    ////////////////////////////////////////////////////////////////////////////////////////
}

/**
 * @brief Jonas_compteur::speedToAngle
 * @param speed
 * @return retourne l'angle (en radians) correspondant à la vitesse en entrée
 */
float Jonas_compteur::speedToAngle(float speed)
{
    if (speed != 0)
        return qDegreesToRadians(((alpha-beta)/(valueMax))*speed+beta);
    else
        return qDegreesToRadians(beta);
}








