///
///Classe permettant l'affichage de voyants simples i.e. dont l'état est allumé ou éteint
///
#include "hugo_voyants_simples.h"

///
/// \brief hugo_voyants_simples::hugo_voyants_simples. Constructeur avec initialisation des paramètres de la classe.
///
hugo_voyants_simples::hugo_voyants_simples()
{
    value=0;
}


QRectF hugo_voyants_simples::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}


void hugo_voyants_simples::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHints(QPainter::Antialiasing);
    if (getValue()==1){///< Va chercher la valeur de la variable "valeur" de la classe mère. Si ==1, le voyant doit être affiché
        QPixmap image(chemin);
        QPixmap image2=image.scaled(30,30);
        QRadialGradient radialGrad(QPointF(x+15, y+15), 15);
        radialGrad.setColorAt(0, couleur);
        radialGrad.setColorAt(1, QColor(0,0,0,120));

        QBrush brush(radialGrad);
        painter->setBrush(brush);
        painter->drawPixmap(x,y,30,30,image2);
        painter->drawEllipse(x,y,30,30);
    }
}

///
/// \brief hugo_voyants_simples::parametrage Fonction permettant de paramétrer le voyant
/// \param param_x Position horizontale du voyant
/// \param param_y position verticale du voyant
/// \param param_chemin Donne le chemin ou est stockée l'image
/// \param red Paramètres optionnels pour créer un halo de couleur autour du voyant. La couleur par défault est rouge
/// \param green
/// \param blue
///
void hugo_voyants_simples::parametrage(int param_x, int param_y, QString param_chemin,int red,int green,int blue)
{
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    couleur=QColor(red,green,blue,160);
}
