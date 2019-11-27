#ifndef HUGO_SCENE_H
#define HUGO_SCENE_H
#include <QGraphicsScene>
#include "Hugo/hugo_aiguille.h"
#include "hugo_mygraphicsitem.h"
#include "hugo_voyant.h"
#include "hugo_clignotants.h"



class hugo_scene : public QGraphicsScene
{
public:
    hugo_scene();
    hugo_MyGraphicsitem *CompteurKm;
    hugo_Aiguille *vitesse, *CompteTours, *Essence;
    hugo_voyant *VoyantBatterie, *VoyantClignotantDroit;
    hugo_clignotants *Clignotant;

private slots:

};

#endif // HUGO_SCENE_H
