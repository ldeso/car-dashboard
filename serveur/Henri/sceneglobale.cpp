#include "sceneglobale.h"


sceneGlobale::sceneGlobale(QGraphicsScene *parent):QGraphicsScene(parent)
{

    fond = new sceneDeFondHenri();
    addItem(fond);

    vitesse=new cadrantHenri();
    addItem(vitesse);

    jaugeEssence=new jaugeEssenceHenri();
    addItem(jaugeEssence);

    CompteTours=new jaugeToursMinuteHenri();
    addItem(CompteTours);

    jaugeTemperature=new jaugeTemperatureHenri();
    addItem(jaugeTemperature);

    jaugeCligno=new jaugeClignotant();
    addItem(jaugeCligno);
}
