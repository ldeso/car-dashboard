#ifndef HUGO_SCENE_H
#define HUGO_SCENE_H
#include <QGraphicsScene>
#include "Hugo/hugo_aiguille.h"
#include "hugo_mygraphicsitem.h"
#include "hugo_voyants_clignotant.h"
#include "hugo_voyants_simples.h"



class hugo_scene : public QGraphicsScene
{
public:
    hugo_scene();
    hugo_MyGraphicsitem *CompteurKm;
    hugo_Aiguille *vitesse, *CompteTours, *Essence;
    //hugo_voyant *VoyantBatterie, *VoyantClignotantDroit;
    hugo_voyants_clignotant *Clignotant;
    hugo_voyants_simples *VoyantBatterie,*ABS,*liq_refroidissement,*liq_frein,*plaquettes,*portieres,*ceinture,*airbag,*huile;


private slots:

};

#endif // HUGO_SCENE_H
