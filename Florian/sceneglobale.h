#ifndef SCENEGLOBALE_H
#define SCENEGLOBALE_H
#include <QMainWindow>
#include "cadrantvirtuel.h"
#include "jaugevirtuel.h"
#include "scenedefond.h"

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
