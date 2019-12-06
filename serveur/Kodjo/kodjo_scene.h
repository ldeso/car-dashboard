#ifndef KODJO_SCENE_H
#define KODJO_SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "Kodjo/Cadran_Kodjo.h"

#include "scene_globale.h"

class kodjo_scene : public scene_globale
{
public:
    kodjo_scene(scene_globale *parent=nullptr);

    //kodjo_scene *scene;

//    Cadran_Kodjo *Rotation_Moteur = new Cadran_Kodjo;
//    Cadran_Kodjo *Niveau_Essence  = new Cadran_Kodjo;
//    Cadran_Kodjo *Niveau_Huile  = new Cadran_Kodjo;
};

#endif // KODJO_SCENE_H
