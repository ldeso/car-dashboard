#ifndef HUGO_SCENE_H
#define HUGO_SCENE_H
#include <QGraphicsScene>
#include <Hugo/hugo_aiguille.h>



class hugo_scene : public QGraphicsScene
{
public:
    hugo_scene();
    hugo_Aiguille *vitesse, *rpm;
};

#endif // HUGO_SCENE_H
