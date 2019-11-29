#ifndef HUGO_SCENE_H
#define HUGO_SCENE_H
#include <QGraphicsScene>
#include "hugo_mygraphicsitem.h"
#include "hugo_voyants_clignotant.h"
#include "hugo_voyants_simples.h"
#include "hugo_compteur.h"
#include "scene_globale.h"



class hugo_scene : public scene_globale
{
public:
    hugo_scene(scene_globale *parent=nullptr);

private slots:

};

#endif // HUGO_SCENE_H
