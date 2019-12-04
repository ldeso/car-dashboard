#include "leo_gauge.h"
#include "leo_scene.h"

Leo_scene::Leo_scene(scene_globale *parent) :
    scene_globale(parent)
{
    mAddGauges(
        150,
        150,
        {
            {&Vitesse, 220, 20, "Speed"},
            {&CompteTours, 8000, 500, "RPM"}
        }
    );
    mAddGauges(
        725,
        150,
        {
            {&Essence, 100, 10, "Gas"},
            {&OilTemp, 200, 20, "Oil"},
            {&jaugeTemperature, 200, 20, "Engine"},
        },
        150,
        175
    );
    mAddIndicators(
        50,
        340,
        {
            {&CheckEngine, "Engine Problem"},
            {&OpenDoorDriver, "Hazard Warning Lights"},
            {&SeatBelt, "Seat Belt"},
            {&AirbagOn, "Airbag Problem"},
            {&warning, "Hazard Warning Lights"},
            {&warning, "Hazard Warning Lights"},
            {&warning, "Hazard Warning Lights"},
            {&warning, "Hazard Warning Lights"},
        },
        Qt::darkRed,
        Qt::red
    );
    mAddIndicators(
        450,
        340,
        {
            {&VoyantBatterie, "Battery"},
            {&warning, "Hazard Warning Lights"},
            {&SeatBelt, "Seat Belt"},
            {&OpenDoorDriver, "Driver Door Open"},
            {&OpenDoorFrontPassenger, "Front Door Open"},
            {&OpenDoorBackRightPassenger, "Back Right Door Open"},
            {&OpenDoorBackLeftPassenger, "Back Left Door Open"},
            {&CruiseControlOn, "Cruise Control"}
        },
        Qt::darkYellow,
        Qt::yellow
    );
    mAddIndicators(
        850,
        300,
        {
            {&position, "Position Lamps"},
            {&croisement, "Dipped Beam"},
            {&route, "Main Beam"},
            {&FrontAntifog, "Front Antifog Lamps"},
            {&RearAntifog, "Rear Antifog Lamps"},
            {&AdaptiveSuspensionDampers, "ASD"},
            {&RearWindowHeating, "Rear Window Heat"},
            {&BonnetOpen, "Bonnet Open"},
            {&BootOpen, "Boot Open"},
            {&AdaptiveCruiseControl, "Cruise Control On"}
        }
    );
}

void Leo_scene::mAddGauges(qreal ax, qreal ay, Leo_scene::gauges_t gauges, qreal sizePx, qreal spacingPx)
{
    for (auto tuple : gauges) {
        objet_virtuel** p_gauge = std::get<0>(tuple);
        QString description = std::get<3>(tuple);
        *p_gauge = new Leo_gauge(
            std::get<1>(tuple), std::get<2>(tuple), sizePx
        );
        new Leo_label(
            std::get<3>(tuple),
            QPointF(
                -8*description.size(), 0.4*(*p_gauge)->boundingRect().height()
            ),
            *p_gauge
        );
        (*p_gauge)->setPos(ax, ay);
        ax += spacingPx;
        addItem(*p_gauge);
    }
}

void Leo_scene::mAddIndicators(qreal ax, qreal ay, indicators_t indicators, QColor colorOff, QColor colorOn, qreal spacingPx)
{
    for (auto pair : indicators) {
        *pair.first = new Leo_indicator(colorOff, colorOn);
        new Leo_label(pair.second, QPointF(32, -2), *pair.first);
        (*pair.first)->setPos(ax, ay);
        ay += spacingPx;
        addItem(*pair.first);
    }
}
