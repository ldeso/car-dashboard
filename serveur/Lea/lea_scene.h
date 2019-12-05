#ifndef LEA_SCENE_H
#define LEA_SCENE_H
#include <QGraphicsItem>
#include <QRectF>
#include <QMainWindow>
#include "scene_globale.h"
#include "objet_virtuel.h"
#include "speedometer_lea.h"
#include "tachometergauge_lea.h"
#include "voyant_lea.h"
#include "fuelgauge_lea.h"
#include "lea_clignottants.h"
#include "lea_scenedefond.h"
#include "warning_lea.h"
#include "compteur_kilometre_lea.h"

class Lea_scene : public scene_globale
{
public:
    Lea_scene(scene_globale *parent = nullptr);
    lea_SceneDeFond *fond;


};

#endif // LEA_SCENE_H
