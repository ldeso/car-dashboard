#ifndef INNA_SCENE_H
#define INNA_SCENE_H
#include "scene_globale.h"
#include "objet_virtuel.h"
#include "Inna/speedometerinna.h"
#include "Inna/arrowspeedometerinna.h"
#include "Inna/tachometerinna.h"
#include "Inna/arrowtachometerinna.h"
#include "Inna/oilgaugeinna.h"
#include "Inna/arrowoiltinna.h"
#include "Inna/infowindowinna.h"
#include "Inna/fuelengineinna.h"
#include "Inna/iconinna.h"
#include "Inna/arrowoillinna.h"
#include "Inna/fuellevelinna.h"
#include "Inna/enginetinna.h"
#include "Inna/prnd_inna.h"
#include "Inna/icononoffinna.h"
#include "Inna/clignotantinna.h"

class inna_scene : public scene_globale
{
public:
    inna_scene(scene_globale *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    SpeedometerInna *speedometerInna ;
    TachometerInna *tachometerInna;
    OilGaugeInna *oilgaugeInna;
    InfoWindowInna *infoInna;
    FuelEngineInna *fuel_engineInna;

};

#endif // INNA_SCENE_H
