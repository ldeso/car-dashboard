#include "sceneflorian.h"
#include <QResource>
SceneFlorian::SceneFlorian(QGraphicsScene *parent):scene_globale(parent)
{
    // ajout icone feu de position
    this->position = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/position.jpeg")));
    this->addItem(this->position);
    this->position->setPos(40, 70);

    // ajout icone feu de croisement
    this->croisement = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/croisement.jpg")));
    this->addItem(this->croisement);
    this->croisement->setPos(60, 40);

    // ajout icone feu de route
    this->route = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/route.jpg")));
    this->addItem(this->route);
    this->route->setPos(110, 40);

    //ajout icone feu de brouillard avant
    this->brouillardAvant = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/brouillardAvant.jpg")));
    this->addItem(this->brouillardAvant);
    this->brouillardAvant->setPos(130, 70);

    //ajout icone feu de brouillard arriere
    this->RearAntifog = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/brouillardArriere.jpg")));
    this->addItem(this->RearAntifog);
    this->RearAntifog->setPos(130, 100);

    //ajout icone no essence
    this->noEssence = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/noEssence.jpg")));
    this->addItem(this->noEssence);
    this->noEssence->setPos(-60, 75);
    this->noEssence->setScale(0.8);

    //ajout icone no huile
    this->noHuile = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/noHuile.jpg")));
    this->addItem(this->noHuile);
    this->noHuile->setPos(-60, 155);
    this->noHuile->setScale(0.8);

    //ajout des clignotant
    this->Clignotant = new FlorianClignotant();
    this->addItem(this->Clignotant);


    //ajout icone refroidissement
    this->refroidissement = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/refroidissement.jpg")));
    this->addItem(this->refroidissement);
    this->refroidissement->setPos(-260, 100);

    //ajout icone batteie
    this->batterie = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/batterie.jpg")));
    this->addItem(this->batterie);
    this->batterie->setPos(-260, 70);

    //ajout icone warning
    this->warning = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/warning.jpg")));
    this->addItem(this->warning);
    this->warning->setPos(-70, -30);
    this->warning->setScale(1.4);

    //ajout icone ceinture
    this->ceinture = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/ceinture.jpg")));
    this->addItem(this->ceinture);
    this->ceinture->setPos(-230, 40);

    //ajout icone ceinture manquante
    this->noCeinture = new FlorianVoyant(QPixmap(QString(":/new/prefix1/voyant/noCeinture.jpg")));
    this->addItem(this->noCeinture);
    this->noCeinture->setPos(-190, 40);

    //ajout compteur vitesse
    this->Vitesse = new CadrantFlorian();
    this->addItem(this->Vitesse);

    //ajout jauge essence
    this->Essence = new CadrantFlorian(false,true,-1,25, 120,60, 100,false);
    this->Essence->setScale(0.4);
    this->Essence->setPos(-90,40);
    this->addItem(this->Essence);

    //ajout jauge huile temperature
    this->OilTemp = new CadrantFlorian(false,true,1, 25, 120,60,100,false);
    this->OilTemp->setScale(0.4);
    this->OilTemp->setPos(-90,120);
    this->addItem(this->OilTemp);


    this->setBackgroundBrush(QBrush(QColor(Qt::black)));

    //ajout compteur tours minutes
    this->CompteTours = new CadrantFlorian(true,true,1,500,220,260,8000);
    this->CompteTours->setPos(-300,0);
    this->addItem(CompteTours);

    //ajout cadrant kilometrique
    this->CompteurKm = new FlorianCompteurKm();
    this->addItem(CompteurKm);
    this->CompteurKm->setPos(60 ,150);
}
