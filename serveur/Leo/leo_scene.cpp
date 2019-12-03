#include "leo_gauge.h"
#include "leo_scene.h"

Leo_scene::Leo_scene(scene_globale *parent) :
    scene_globale(parent)
{
    indicators_t green = {
        {&position, "Position Lamps"},
        {&croisement, "Dipped Beam"},
        {&route, "Main Beam"},
        {&FrontAntifog, "Front Antifog Lamps"},
        {&RearAntifog, "Rear Antifog Lamps"},
        {&AdaptiveSuspensionDampers, "ASD"},
    };
    indicators_t yellow = {
        {&VoyantBatterie, "Battery"},
        {&warning, "Hazard Warning Lights"},
    };
    mAddGauge(125, 125, Vitesse, 300);
    mAddIndicators(300, 0, green);
    mAddIndicators(600, 0, yellow, Qt::darkYellow, Qt::yellow);
}

void Leo_scene::mAddIndicators(qreal ax, qreal ay, indicators_t indicators, QColor colorOff, QColor colorOn)
{
    for (auto pair : indicators) {
        *pair.first = new Leo_indicator(colorOff, colorOn);
        new Leo_label(pair.second, *pair.first);
        (*pair.first)->setPos(ax, ay);
        ay += mRowSpacingPx;
        addItem(*pair.first);
    }
}

void Leo_scene::mAddGauge(qreal ax, qreal ay, objet_virtuel*& gauge, int maxValue, int spacing)
{
    gauge = new Leo_gauge(maxValue, spacing);
    gauge->setPos(ax, ay);
    addItem(gauge);
}
