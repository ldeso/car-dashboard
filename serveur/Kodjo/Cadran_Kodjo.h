#ifndef CADRAN_KODJO_H
#define CADRAN_KODJO_H

#include "objet_virtuel.h"
#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QPixmap>

class Cadran_Kodjo : public objet_virtuel
{
public:
    Cadran_Kodjo(QString type_cadre, QString texte_cadre, int val_vitesse_min, int val_vitesse_max, int increment_viesse, int cpt_vitesse_texte);

public:
    void Dessiner_Cercle_Fille(QPainter *cercle_painter);
    void Dessiner_Aiguille_Fille(QPainter *aiguille_painter);
    void Variation_Vitesse_aiguille_Fille(QPainter *aiguille_vitesse_painter, float degres_aiguille);
    void Affiche_Graduation_Vitesse_Fille(QPainter *graduation_painter);
    void Affiche_Graduation_Vitesse(void);
    void Setteur_Vitesse_Aiguille(int val_vitesse);
    void Affichage_Texte_Km_h(QPainter *kilometre_h_painter);
    void Setteur_Graduation_Moteur_Vitesse(int valeur_vitesse_min, int valeur_vitesse_max, int increment_vitesse, int cpt_vitesse_texte);
    void Affiche_Graduation_Rotation_Moteur(void);
    void Affichage_Texte_Cadran_General(QString texte_cadran);
    void Limite_Tours_Moteur(void);
    void Choix_Type_Cadran(QString type);
    void Arc_Cercle_Essence_Huile(QPainter *essence_huile_painter);
    void Affiche_Graduation_Essence_Huile(QPainter *graduation_essence_huile_painter);
    void Variation_Aiguille_Essence_Huile(QPainter *aiguille_huile_essence_painter, int degres_aiguille_huile_essence);
    void Setteur_Degre_Aiguille_Essence_Huile(int val_degres);
    void Setteur_Graduation_Essence_Huile(QString val_choix);
    void Clignotant(QPainter *clignotants_painter);
    void Setteur_Clignotant(int cpt_clignotant);
    void Voyant_Batterie(QPainter *batterie_painter, float etat_batterie);
    void Voyant_Porte_Ouverte(QPainter *porte_painter, float etat_porte);
    void Voyant_Ceinture_De_Securite(QPainter *ceinture_painter, float etat_ceinture_de_securite);


public slots :
    void Variation_Vitesse_Fille(void);

public:
    QColor couleur_cercle;
    QPen *pen = new QPen;
    QPainter *cercle_painter = new QPainter;

    QColor couleur_aiguille;
    QPen *pen_aiguille = new QPen;

    QPointF point_origine;
    QPointF point_mobile;
    QLineF *aiguille_fille;
    QLineF *graduation_fille = new QLineF(200,350, 400, 200);

    QPointF *valeur_vitesse = new QPointF(300,300);
    QString valeur_vitesse_string;
    float Pi= 3.14;
    int Degres_Fille = 0;

    QLineF *aiguille_mobile_fille = new  QLineF (200,200, 400, 200);
    QLineF *aiguille_mobile_moteur = new  QLineF (200,200, 400, 200);
    QBrush *pinceau = new QBrush;
    QColor *couleur_pinceau = new QColor;

    QPen *pen_kilometre_h = new QPen;
    QColor *couleur_kilometre_h = new QColor;
    QRectF rectangle_cercle;

    QRectF rectangle_cercle_moteur;

    QColor couleur_valeur_vitesse_texte;

    int compteur_vitesse_texte = -30; //Angle initiale de la position de l'aiguille

    int  centre_cercle_x = 0;
    //int  centre_cercle_x = -100;
    int  centre_cercle_y = 0;
    int  longueur_rectangle = 400;
    int  largeur_rectangle = 400;

    int  ligne_origine_x = 200;
    //int  ligne_origine_x = 100;
    int  ligne_origine_y = 200;
    int  ligne_fin_x = 355;
    //int  ligne_fin_x = 255;
    int  ligne_fin_y = 200;

    QString texte_cadran_global;
    int val_grad_moteur_global;

    int valeur_vitesse_min_globale;
    int valeur_vitesse_max_globale;
    int increment_vitesse_globale;
    int compteur_vitesse_texte_globale;
    int condition_moteur_ou_vitesse = 0;

    QColor couleur_arc_moteur;
    QPen *pen_arc_moteur = new QPen;

    QString type_cadran;

    QColor couleur_arc_enssence_huile;
    QPen *pen_arc_enssence_huile = new QPen;
    //QLineF *ligne_inf_arc_cercle= new  QLineF (100,100, 200,100);
    QLineF *ligne_inf_arc_cercle= new  QLineF (75,75, 150,75);
    //QLineF *ligne_sup_arc_cercle= new  QLineF (100,100, 200,100);
    QLineF *ligne_sup_arc_cercle= new  QLineF (75,75, 150,75);


    QPen *pen_enssence_huile = new QPen;
    QBrush *pinceau_enssence_huile = new QBrush;
    QColor *couleur_pinceau_enssence_huile = new QColor;

    QLineF *aiguille_enssence_huile = new  QLineF (75,75, 225,75);
    QColor couleur_aiguille_enssence_huile;
    QPen *pen_aiguille_enssence_huile = new QPen;
    //int Degres_aiguille_enssence_huile = 0;
    float Degres_aiguille_enssence_huile = 50;

    QLineF *graduation_huile_essence= new QLineF(200,350, 400, 200);
    QColor couleur_graduation_enssence_huile;
    QPen *pen_graduation_enssence_huile = new QPen;

    QString condition_essence_ou_huile;
    int compteur_essence_huile = -30;
    int compteur_huile_seule = 50;

    //QPixmap *image_essence = new QPixmap("essence.png",Q_NULLPTR, Qt::AutoColor ) ;
    //QPixmap *image_essence = new QPixmap("/home/utilisateur/Bureau/Tableau_De_Bord_Kodjo/essence.png",Q_NULLPTR, Qt::AutoColor);
    //QPixmap *image_essence = new QPixmap("/home/utilisateur/Bureau/Tableau_De_Bord_Kodjo/essence_2.png",Q_NULLPTR, Qt::AutoColor);

    //QPixmap *image_essence = new QPixmap("/home/houndjago/Bureau/car-dashboard/serveur/Kodjo/essence_2.png",Q_NULLPTR, Qt::AutoColor);
    QPixmap *image_essence = new QPixmap(":/new/prefix1/essence_2.png",Q_NULLPTR, Qt::AutoColor);
    //QPixmap *image_huile = new QPixmap("/home/utilisateur/Bureau/Tableau_De_Bord_Kodjo/huile_moteur.png",Q_NULLPTR, Qt::AutoColor);
    //QPixmap *image_huile = new QPixmap("/home/houndjago/Bureau/car-dashboard/serveur/Kodjo/huile_moteur.png",Q_NULLPTR, Qt::AutoColor);
    QPixmap *image_huile = new QPixmap(":/new/prefix1/huile_moteur.png",Q_NULLPTR, Qt::AutoColor);
    //QPixmap image("fichier.png");
    QPixmap *image_clignotant_gauche = new QPixmap("/home/utilisateur/Bureau/Tableau_De_Bord_Kodjo/clignotants_gauche.png",Q_NULLPTR, Qt::AutoColor);

    //QPixmap *image_voyant_batterie = new QPixmap("/home/houndjago/Bureau/car-dashboard/serveur/Kodjo/voyant_batterie.png",Q_NULLPTR, Qt::AutoColor);
    QPixmap *image_voyant_batterie = new QPixmap(":/new/prefix1/voyant_batterie.png",Q_NULLPTR, Qt::AutoColor);

    //QPixmap *image_voyant_porte_ouverte = new QPixmap("/home/houndjago/Bureau/car-dashboard/serveur/Kodjo/voyant_porte_ouverte.png",Q_NULLPTR, Qt::AutoColor);
    QPixmap *image_voyant_porte_ouverte = new QPixmap(":/new/prefix1/voyant_porte_ouverte.png",Q_NULLPTR, Qt::AutoColor);

    //QPixmap *image_voyant_ceinture_de_securite = new QPixmap("/home/houndjago/Bureau/car-dashboard/serveur/Kodjo/voyant_ceinture_de_securite.png",Q_NULLPTR, Qt::AutoColor);
    QPixmap *image_voyant_ceinture_de_securite = new QPixmap(":/new/prefix1/voyant_ceinture_de_securite.png",Q_NULLPTR, Qt::AutoColor);

    int compteur_clignotant = 0;
    float vitesse_vehicule;
    float etat_batterie_globale;
    float etat_porte_globale;
    float etat_ceinture_de_securite_globale;

    int i;



    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CADRAN_KODJO_H
