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
    mCreateRow(QPointF(0, 0), green);
    mCreateRow(QPointF(300, 0), yellow, Qt::darkYellow, Qt::yellow);
}

void Leo_scene::mCreateRow(QPointF pos, indicators_t indicators, QColor colorOff, QColor colorOn)
{
    for (auto pair : indicators) {
        *pair.first = new Leo_indicator(colorOff, colorOn);
        new Leo_label(pair.second, *pair.first);
        (*pair.first)->setPos(pos);
        pos += QPointF(0, mRowSpacingPx);
        addItem(*pair.first);
    }
}
