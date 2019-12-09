#ifndef YOUCEF_SCENE_H
#define YOUCEF_SCENE_H
#include "cardialerprototype.h"
#include "carspeeddial.h"
#include "tachometer.h"
#include "fuelgauge.h"
#include "engineheatgauge.h"
#include "flashinglight_youss.h"
#include "warning_youss.h"
#include "maindisplay_youcef.h"

#include "scene_globale.h"

class Youcef_Scene : public scene_globale
{
public:
    Youcef_Scene(scene_globale* parent = nullptr);
};
#endif // YOUCEF_SCENE_H
