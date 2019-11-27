#ifndef SCENEGLOBALE_H
#define SCENEGLOBALE_H
#include <QMainWindow>
#include "cadranthenri.h"
#include "jaugeessencehenri.h"
#include "scenedefondhenri.h"
#include "jaugetoursminutehenri.h"
#include "jaugetemperaturehenri.h"
#include "jaugeclignotant.h"


class sceneGlobale : public QGraphicsScene
{
public:
    sceneGlobale(QGraphicsScene *parent=nullptr);

    sceneDeFond *fond;
    cadrantVirtuel *vitesse;
    jaugeVirtuel *Essence;
    jaugeVirtuel *CompteTours;
    jaugeVirtuel *jaugeTemperature;
    jaugeClignotant *Clignotant;
    jaugeVirtuel *VoyantBatterie;
};

#endif // SCENEGLOBALE_H
