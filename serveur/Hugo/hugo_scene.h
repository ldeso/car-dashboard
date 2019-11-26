#ifndef HUGO_SCENE_H
#define HUGO_SCENE_H
#include <QGraphicsScene>
#include "Hugo/hugo_aiguille.h"
#include "hugo_mygraphicsitem.h"
#include "hugo_voyant.h"



class hugo_scene : public QGraphicsScene
{
public:
    hugo_scene();
    hugo_MyGraphicsitem *background;
    hugo_Aiguille *vitesse, *CompteTours;
    hugo_voyant *VoyantBatterie;

};

#endif // HUGO_SCENE_H
