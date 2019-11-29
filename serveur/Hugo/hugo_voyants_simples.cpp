///
///Classe permettant l'affichage de voyants simples i.e. dont l'état est allumé ou éteint
///
#include "hugo_voyants_simples.h"

///
/// \brief hugo_voyants_simples::hugo_voyants_simples. Constructeur permettant de paramétrer la position et le halo des voyants
/// \param param_x position horizontale
/// \param param_y position verticale
/// \param param_chemin Nom de la ressource
/// \param red Paramètre optionnel pour gérer la couleur du halo donnant l'effet de brillance
/// \param green
/// \param blue
/// \param param_size Paramètre optionnel pour gérer la taille du voyant
///
hugo_voyants_simples::hugo_voyants_simples(int param_x, int param_y, QString param_chemin,int red,int green,int blue,int param_size)
{
    value=0;
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    couleur=QColor(red,green,blue,160);
    size=param_size;
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
        QPixmap image2=image.scaled(size,size);
        QRadialGradient radialGrad(QPointF(x+size/2, y+size/2), size/2);
        radialGrad.setColorAt(0, couleur);
        radialGrad.setColorAt(1, QColor(0,0,0,120));

        QBrush brush(radialGrad);
        painter->setBrush(brush);
        painter->drawPixmap(x,y,size,size,image2);
        painter->drawEllipse(x,y,size,size);
    }
}

