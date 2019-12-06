#include "harout_scene.h"
#include <QStringList>
#include "cadran.h"
#include "harc.h"

harout_scene::harout_scene()
{
    QStringList gradVitesse;
    gradVitesse<<"  220"<<" 200"<<" 180"<<" 160"<<" 140"<<"120"<<"100"<<"80"<<"60"<<"40"<<"20"<<"0";
    QString Vtext = "Km/h";
    float angledVitesse = 0;

    QString Essencetext1 = "";
    int spanAngle0Essence = 10 *16;
    Vitesse = new cadran(gradVitesse,Vtext, "",angledVitesse,220);
    this->addItem(Vitesse);

    QStringList gradRPM;
    gradRPM<<"8"<<"7"<<"6"<<"5"<<"4"<<"3"<<"2"<<"1"<<"0";
    QString RPMtext {"x1000 RPM"};
    QString Temptext1 = "T°C";
    //angledVitesse.clear;
    //float angledRPM ;
    int spanAngle0Temp = 40 *16;
    float valueRPM = 6;
    CompteTours= new cadran(gradRPM, RPMtext, Temptext1,valueRPM,8000);
    this->addItem(CompteTours);
    CompteTours->setPos(271,0);

    Essence =new Harc(spanAngle0Essence);
    this->addItem(Essence);

    jaugeTemperature =new Harc(spanAngle0Temp);
    this->addItem(jaugeTemperature);
    jaugeTemperature->setPos(271,0);

}
