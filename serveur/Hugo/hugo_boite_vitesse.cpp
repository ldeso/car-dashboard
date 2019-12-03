#include "hugo_boite_vitesse.h"

hugo_boite_vitesse::hugo_boite_vitesse()
{
    value=1;
}

QRectF hugo_boite_vitesse::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

///
/// \brief hugo_ecran::paint
/// \param painter
///\details La fonction paint va permettre de réaliser un affichage pour le compteur kilometrique et l'heure. Dans un premier temps, affichage des objets fixes, puis on récupère et affiche les différentes variables.
void hugo_boite_vitesse::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setFont(QFont("Arial", 8, -1,false));
    painter->setPen(QPen(QColor(Qt::darkGray), 1, Qt::SolidLine,Qt::FlatCap));
    QStringList Regimes;
    Regimes<<"P"<<"R"<<"N"<<"D"<<"3"<<"2"<<"L";
    float teta=-30*3.14159/180;
    int i=0;
    while (i<7){
        teta+=10*3.14159/180;
        if (i==getValue()-1){
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
