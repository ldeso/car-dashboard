#include "sceneglobale.h"


sceneGlobale::sceneGlobale(QGraphicsScene *parent):QGraphicsScene(parent)
{

    fond = new sceneDeFondHenri();
    addItem(fond);

    vitesse=new cadrantHenri();
    addItem(vitesse);

    Essence=new jaugeEssenceHenri();
    addItem(Essence);

    CompteTours=new jaugeToursMinuteHenri();
    addItem(CompteTours);

    jaugeTemperature=new jaugeTemperatureHenri();
    addItem(jaugeTemperature);

    jaugeCligno=new jaugeClignotant();
    addItem(jaugeCligno);
}
