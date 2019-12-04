#include "leo_display.h"
#include "leo_gauge.h"
#include "leo_scene.h"

Leo_scene::Leo_scene(scene_globale *parent) :
    scene_globale(parent)
{
    setBackgroundBrush(Qt::black);
    mAddGauges(
        175,
        150,
        {
            {&Vitesse, 220, 20, "Speed"},
            {&CompteTours, 8000, 500, "RPM"}
        }
    );
    mAddGauges(
        75,
        375,
        {
            {&Essence, 100, 10, "Fuel"},
            {&jaugeTemperature, 200, 20, "T° Engine"},
            {&CompteurKm, 1000, 100, "km"},
            {&OilTemp, 200, 20, "T° Oil"}
        },
        150,
        175
    );
    mAddIndicators(
        725,
        25,
        {
            {&Clignotant, "Turn"},
            {&position, "Position Lamps"},
            {&croisement, "Dipped Beam"},
            {&route, "Main Beam"},
            {&AdaptiveSuspensionDampers, "ASD"},
            {&AutomaticTransmissionMode, "Automatic Transmission"},
            {&FrontAntifog, "Front Antifog Lamps"},
            {&RearAntifog, "Rear Antifog Lamps"},
            {&RearWindowHeating, "Rear Window Heat"},
            {&AdaptiveCruiseControl, "Cruise Control On"},
            {&BonnetOpen, "Bonnet Open"},
            {&BootOpen, "Boot Open"}
        }
    );
    mAddIndicators(
        1050,
        25,
        {
            {&VoyantBatterie, "Battery"},
            {&warning, "Hazard Warning Lights"},
            {&SeatBelt, "Seat Belt"},
            {&OpenDoorDriver, "Driver Door Open"},
            {&OpenDoorFrontPassenger, "Front Door Open"},
            {&OpenDoorBackLeftPassenger, "Back Left Door Open"},
            {&OpenDoorBackRightPassenger, "Back Right Door Open"},
            {&CruiseControlOn, "Cruise Control"}
        },
        Qt::darkYellow,
        Qt::yellow
    );
    mAddIndicators(
        1050,
        345,
        {
            {&CheckEngine, "Engine Problem"},
            {&SeatBelt, "Seat Belt"},
            {&AirbagOn, "Airbag Problem"},
        },
        Qt::darkRed,
        Qt::red
    );
    // Clignotant
    SpeedLimit = new Leo_display();
    SpeedLimit->setPos(150, 195);
    addItem(SpeedLimit);
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
