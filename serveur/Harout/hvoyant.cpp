/// \brief hvoyant::hvoyant. Constructeur permettant de paramétrer la position et le halo des voyants
/// \param param_x position horizontale
/// \param param_y position verticale
/// \param param_chemin Nom de la ressource
/// \param red Paramètre optionnel pour gérer la couleur du halo donnant l'effet de brillance
/// \param green
/// \param blue
/// \param param_size Paramètre optionnel pour gérer la taille du voyant

#include "hvoyant.h"

hvoyant::hvoyant(int param_x, int param_y, QString param_chemin, int red, int green,
                 int blue, int param_size)
{
    value=1;
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    couleur=QColor(red,green,blue,160);
    size=param_size;
}

QRectF hvoyant::boundingRect() const
{
    return QRect(-200,-200,400,400);
}


void hvoyant::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHints(QPainter::Antialiasing);
    ///Va chercher la valeur de la variable "valeur" de la classe mère. Si ==1, le voyant doit être affiché.
    if (getValue()==1){
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

