#include "sceneflorian.h"
#include <QResource>
SceneFlorian::SceneFlorian(QGraphicsScene *parent):sceneGlobale(parent)
{
    this->position = new Voyant(QPixmap(QString(":/voyant/voyant/position.jpeg")));
    this->addItem(this->position);
    this->position->setPos(40, 70);
    this->croisement = new Voyant(QPixmap(QString(":/voyant/voyant/croisement.jpg")));
    this->addItem(this->croisement);
    this->croisement->setPos(60, 40);
    this->route = new Voyant(QPixmap(QString(":/voyant/voyant/route.jpg")));
    this->addItem(this->route);
    this->route->setPos(110, 40);
    this->brouillardAvant = new Voyant(QPixmap(QString(":/voyant/voyant/brouillardAvant.jpg")));
    this->addItem(this->brouillardAvant);
    this->brouillardAvant->setPos(130, 70);
    this->brouillardArriere = new Voyant(QPixmap(QString(":/voyant/voyant/brouillardArriere.jpg")));
    this->addItem(this->brouillardArriere);
    this->brouillardArriere->setPos(130, 100);
    this->noEssence = new Voyant(QPixmap(QString(":/voyant/voyant/noEssence.jpg")));
    this->addItem(this->noEssence);
    this->noEssence->setPos(-60, 75);
    this->noEssence->setScale(0.8);
    this->noHuile = new Voyant(QPixmap(QString(":/voyant/voyant/noHuile.jpg")));
    this->addItem(this->noHuile);
    this->noHuile->setPos(-60, 155);
    this->noHuile->setScale(0.8);
    this->noEssence->setScale(0.8);
    this->clignotantGauche = new Voyant(QPixmap(QString(":/voyant/voyant/clignotantGauche.jpg")));
    this->addItem(this->clignotantGauche);
    this->clignotantGauche->setPos(-300, -20);
    this->clignotantGauche->setScale(0.9);
    this->clignotantDroite = new Voyant(QPixmap(QString(":/voyant/voyant/clignotantDroite.jpg")));
    this->addItem(this->clignotantDroite);
    this->clignotantDroite->setPos(180, -20);
    this->clignotantDroite->setScale(0.9);
    this->refroidissement = new Voyant(QPixmap(QString(":/voyant/voyant/refroidissement.jpg")));
    this->addItem(this->refroidissement);
    this->refroidissement->setPos(-260, 100);
    this->batterie = new Voyant(QPixmap(QString(":/voyant/voyant/batterie.jpg")));
    this->addItem(this->batterie);
    this->batterie->setPos(-260, 70);
    this->warning = new Voyant(QPixmap(QString(":/voyant/voyant/warning.jpg")));
    this->addItem(this->warning);
    this->warning->setPos(-70, -30);
    this->warning->setScale(1.4);
    this->ceinture = new Voyant(QPixmap(QString(":/voyant/voyant/ceinture.jpg")));
    this->addItem(this->ceinture);
    this->ceinture->setPos(-230, 40);
    this->noCeinture = new Voyant(QPixmap(QString(":/voyant/voyant/noCeinture.jpg")));
    this->addItem(this->noCeinture);
    this->noCeinture->setPos(-190, 40);

    this->vitesse = new CadrantFlorian();
    this->addItem(this->vitesse);
    this->essence = new CadrantFlorian(false,true,-1,25, 120,60, 100);
    this->essence->setScale(0.4);
    this->essence->setPos(-90,40);
    this->huile = new CadrantFlorian(false,true,1, 25, 120,60,100);
    this->huile->setScale(0.4);
    this->huile->setPos(-90,120);
    this->addItem(this->essence);
    this->addItem(this->huile);
    this->setBackgroundBrush(QBrush(QColor(Qt::black)));
    this->toursMinute = new CadrantFlorian(true,true,1,500,220,260,8000);
    this->toursMinute->setPos(-300,0);
    this->addItem(toursMinute);
    //this->vitesse->update();
}
