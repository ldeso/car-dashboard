#ifndef LOTO_SCENE_H
#define LOTO_SCENE_H

#include "scene_globale.h"
#include <QGraphicsScene>
#include "scene_globale.h"
#include "QGraphicsItem"
#include "loto_dashboard.h"
#include "fuel_guage.h"
#include "tachometre.h"
#include "tempgauge.h"
#include "leds.h"
#include "objet_virtuel.h"
#include "QString"
#include "blinkingleds.h"

class loto_scene : public scene_globale
{
public:
    loto_scene(scene_globale *parent=nullptr);

};

#endif // LOTO_SCENE_H
