#ifndef YOUCEF_SCENE_H
#define YOUCEF_SCENE_H
#include "cardialerprototype.h"
#include "carspeeddial.h"
#include "tachometer.h"
#include "fuelgauge.h"
#include "engineheatgauge.h"

#include "scene_globale.h"

class Youcef_Scene : public scene_globale
{
public:
    Youcef_Scene(scene_globale* parent = nullptr);
    ~Youcef_Scene();

    CarDialerPrototype *MainDial = new CarDialerPrototype();
    CarSpeedDial *Speed = new CarSpeedDial();
    Tachometer *tacho = new Tachometer();
    FuelGauge *fuel = new FuelGauge();
    EngineHeatGauge *heat = new EngineHeatGauge();
};
#endif // YOUCEF_SCENE_H
