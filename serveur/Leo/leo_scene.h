#ifndef LEO_SCENE_H
#define LEO_SCENE_H

#include "leo_indicator.h"
#include "leo_label.h"
#include "scene_globale.h"

class Leo_scene : public scene_globale
{
public:
    Leo_scene(scene_globale* parent = nullptr);
};

#endif // LEO_SCENE_H
