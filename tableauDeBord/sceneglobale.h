#ifndef SCENEGLOBALE_H
#define SCENEGLOBALE_H
#include <QMainWindow>
#include "cadranthenri.h"
#include "jaugeessencehenri.h"
#include "scenedefondhenri.h"
#include "jaugetoursminutehenri.h"


class sceneGlobale : public QGraphicsScene
{
public:
    sceneGlobale(QGraphicsScene *parent=nullptr);

    sceneDeFond *fond;
    cadrantVirtuel *cadrant;
    jaugeVirtuel *jaugeEssence;
    jaugeVirtuel *jaugeToursMin;
};

#endif // SCENEGLOBALE_H
