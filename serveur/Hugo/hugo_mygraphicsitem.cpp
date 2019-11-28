#include "hugo_mygraphicsitem.h"
#include <QtMath>
#include <QDebug>
#define pi 3.14159265
#include <QString>
#include <QTime>

hugo_MyGraphicsitem::hugo_MyGraphicsitem()
{
}



QRectF hugo_MyGraphicsitem::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void hugo_MyGraphicsitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing);///<Antialiasing//

    ///Création du fond (gradient ou image)
    QLinearGradient linearGrad(QPointF(-450, -200), QPointF(-450, -150));
    linearGrad.setColorAt(0, QColor(0,26,77));
    linearGrad.setColorAt(1, Qt::black);
    QBrush black_brush(QColor(Qt::black));
    painter->setBrush(linearGrad);
    QRect rect_fond(-450,-300,900,600);
     painter->drawRect(rect_fond);
    QPixmap image("/home/utilisateur/Images/bois.jpg");
    QPixmap image2=image.scaled(900,600);
   //painter->drawPixmap(-450,-300,900,600,image2); ///<A Decommenter pour avoir une image en fond

    ///Création des arcs de cercles gris, et d'un fond noir pour poser les objects
    painter->setPen(QPen( QColor(150,150,150,100) ,6, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(QRect(-450,-150,900,300),0,180*16);
    painter->drawArc(QRect(-450,120,900,300),0,180*16);
    painter->setPen(QPen( QColor(5,5,5) ,6, Qt::SolidLine,Qt::FlatCap));
    for (int i=-153;i<121;i++){
        painter->drawArc(QRect(-450,i,900,300),0,180*16);
        painter->drawArc(QRect(-450,i,900,300),0,180*16);
    }

    for (int i=1;i<20;i++){
        painter->setPen(QPen( QColor(65,65,65,5*i) ,6, Qt::SolidLine,Qt::FlatCap));
        painter->drawArc(QRect(-450,-130-i,900,300),0,180*16);
    }
    for (int i=1;i<20;i++){
        painter->setPen(QPen( QColor(40,40,40,5*i) ,6, Qt::SolidLine,Qt::FlatCap));
        painter->drawArc(QRect(-450,100+i,900,300),0,180*16);
    }

    /// Création de l'arc de cercle fermé bleu qui entoure le compteur de vitesse
    QRect carre(-100,-100,200,200);
    painter->setPen(QPen( QColor(51,102,153) ,2, Qt::SolidLine,Qt::FlatCap));
    painter->drawChord(carre,-60*16,300*16);
    painter->setPen(QPen(QColor(51,102,153,40) ,5, Qt::SolidLine,Qt::FlatCap));
    for (int i=1;i<5;i++){
        QRect carre_grad(0-(100-i),0-(100-i),2*(100-i),2*(100-i));
        painter->drawChord(carre_grad,-60*16,300*16);
    }

    ///Affichage de texte dans les différents compteurs
    painter->setPen(QPen(QColor(Qt::darkGray) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Arial", 9, -1,false));
    painter->drawText(-12,-30,"km/h");
    painter->drawText(-190,-10,"x1000rpm");

    ///Création d'un afficheur. Affiche le temps réel, aisi que la distance parcourue depuis le départ
    painter->setPen(QPen(QColor(0,0,0,0) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor(0,128,255,15));
    painter->drawRect(-45,25,90,40);
    QRadialGradient radialGrad(QPointF(0, 45), 50);
    radialGrad.setColorAt(0, QColor(0,204,255));
    radialGrad.setColorAt(1, QColor(0, 128, 255));
    painter->setPen(QPen(QColor(0,204,255) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(radialGrad);
    painter->drawRect(-40,30,80,30);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Arial", 5, -1,false));
    painter->drawText(-38,40,"TIME");
    painter->drawText(-38,55,"TRIP");


    QTime time=QTime::currentTime();
    time.currentTime();
    painter->setFont(QFont("Arial", 9, -1,false));
    painter->drawText(0,45,time.toString("hh.mm")); ///< Conversion pour avoir l'affichage sous forme heure.minutes
    painter->drawText(0,60, QString::number(km, 'f', 1));


    painter->setPen(QPen(QColor( 26, 13, 0), 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor( 26,13,0));

    ///Afficheur pour les stations de radios
    painter->setFont(QFont("Arial", 8, -1,false));
    painter->setPen(QPen(QColor(255, 153, 51), 1, Qt::SolidLine,Qt::FlatCap));
    painter->drawText(-38,110,station);
    QRect carre_rpm(115,-100,80,80);
    painter->setBrush(black_brush);
    painter->setPen(QPen(QColor(25,25,25) ,1, Qt::SolidLine,Qt::FlatCap));
    painter->drawEllipse(carre_rpm);
    QRect carre_rpm2(120,-10,80,80);
    painter->drawEllipse(carre_rpm2);

    ///Affichage régime moteur
    painter->setFont(QFont("Arial", 8, -1,false));
    painter->setPen(QPen(QColor(Qt::darkGray), 1, Qt::SolidLine,Qt::FlatCap));
    QStringList Regimes;
    Regimes<<"P"<<"R"<<"N"<<"D"<<"3"<<"2"<<"L";
    float teta=-30*3.14159/180;
    int i=0;
    while (i<7){
        teta+=10*3.14159/180;
        if (i==3){
            QRadialGradient radialGrad(QPointF(110*(qCos(teta))+4,110*(qSin(teta))-3), 12);
            radialGrad.setColorAt(0, QColor(0,255,0,80));
            radialGrad.setColorAt(1, QColor(0,0,0,0));
            painter->setPen(QPen(QColor(0,0,0,0) , 1, Qt::SolidLine,Qt::FlatCap));
            painter->setBrush(radialGrad);
            painter->drawEllipse(QPointF(110*(qCos(teta))+4,110*(qSin(teta))-3),20,20);
            painter->setPen(QPen(QColor(Qt::green), 1, Qt::SolidLine,Qt::FlatCap));
        }
        else{
            painter->setPen(QPen(QColor(Qt::darkGray), 1, Qt::SolidLine,Qt::FlatCap));
        }
        painter->drawText(110*(qCos(teta)),110*(qSin(teta)),Regimes[i]);
        i++;
    }

}

void hugo_MyGraphicsitem::setValue(float a)
{
    km=a;
}
