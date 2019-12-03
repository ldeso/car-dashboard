#include <QDial>

#include "leo_gauge.h"
#include "leo_scene.h"

Leo_scene::Leo_scene(scene_globale *parent) :
    scene_globale(parent)
{
    position = new Leo_indicator;
    croisement = new Leo_indicator;
    route = new Leo_indicator;
    FrontAntifog = new Leo_indicator;
    RearAntifog = new Leo_indicator;
    AdaptiveSuspensionDampers = new Leo_indicator;
    VoyantBatterie = new Leo_indicator(Qt::darkYellow, Qt::yellow);
    warning = new Leo_indicator(Qt::darkYellow, Qt::yellow);

    new Leo_label("Position Lamps", position);
    new Leo_label("Dipped Beam", croisement);
    new Leo_label("Main Beam", route);
    new Leo_label("Front Antifog Lamps", FrontAntifog);
    new Leo_label("Rear Antifog Lamps", RearAntifog);
    new Leo_label("Adaptive Suspension Dampers", AdaptiveSuspensionDampers);
    new Leo_label("Battery", VoyantBatterie);
    new Leo_label("Hazard Warning Lights", warning);

    QPointF current_pos;
    const qreal spacing_px = 35;

    position->setPos(current_pos += QPointF(0, spacing_px));
    croisement->setPos(current_pos += QPointF(0, spacing_px));
    route->setPos(current_pos += QPointF(0, spacing_px));
    FrontAntifog->setPos(current_pos += QPointF(0, spacing_px));
    RearAntifog->setPos(current_pos += QPointF(0, spacing_px));
    AdaptiveSuspensionDampers->setPos(current_pos += QPointF(0, spacing_px));
    VoyantBatterie->setPos(current_pos += QPointF(0, spacing_px));
    warning->setPos(current_pos += QPointF(0, spacing_px));

    addItem(position);
    addItem(croisement);
    addItem(route);
    addItem(FrontAntifog);
    addItem(RearAntifog);
    addItem(AdaptiveSuspensionDampers);
    addItem(VoyantBatterie);
    addItem(warning);
}

