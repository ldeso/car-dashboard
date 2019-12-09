#include "objet_virtuel.h"

#include "Cadran_Kodjo.h"
#include "mainwindow.h"
//#include <QGraphicsItem>
#include "scene_globale.h"
#include <QPainter>
#include <QDebug>
#include <math.h>
#include <QTest>
#include <QTimer>

Cadran_Kodjo::Cadran_Kodjo(QString type_cadre, QString texte_cadre, int val_vitesse_min, int val_vitesse_max, int increment_viesse, int cpt_vitesse_texte)
{
    qDebug()<<getValueMax();
    valueMax = 240;
    qDebug()<<getValueMax();

    if(type_cadre == "V")
    {
        valueMax = 240;
        qDebug()<<getValueMax();
    }

    if(type_cadre == "M")
    {
        valueMax = 12000;
        qDebug()<<getValueMax();
    }

    if(type_cadre == "E")
    {
        valueMax = 100;
        qDebug()<<getValueMax();
    }

    if(type_cadre == "H")
    {
        valueMax = 150;
        qDebug()<<getValueMax();
    }

    //qDebug()<<"vitesse_cadran_kodjo"<< getValue();

    type_cadran = type_cadre;
    texte_cadran_global = texte_cadre;

    valeur_vitesse_min_globale = val_vitesse_min;
    valeur_vitesse_max_globale = val_vitesse_max;
    increment_vitesse_globale = increment_viesse;

    condition_moteur_ou_vitesse = cpt_vitesse_texte;
    condition_essence_ou_huile = type_cadre;

    setValue(0);  // Initialise la vitesse à 0


}

void Cadran_Kodjo::Dessiner_Cercle_Fille(QPainter *cercle_painter)
{
    //couleur_cercle.setNamedColor("red");
    couleur_cercle.setNamedColor("blue");
    pen->setWidth(6);
    pen->setColor(couleur_cercle);
    cercle_painter->setPen(couleur_cercle);
    cercle_painter->setPen(*pen);

    couleur_pinceau->setNamedColor("black");
    pinceau->setColor(*couleur_pinceau);

    cercle_painter->setBrush(*couleur_pinceau);


    cercle_painter->drawEllipse(centre_cercle_x, centre_cercle_y, longueur_rectangle, largeur_rectangle);

}

void Cadran_Kodjo::Dessiner_Aiguille_Fille(QPainter *aiguille_painter)
{
    //couleur_aiguille.setNamedColor("blue");
    couleur_aiguille.setNamedColor("orange");
    pen_aiguille->setWidth(3);
    pen_aiguille->setColor(couleur_aiguille);

    aiguille_painter->setPen(couleur_aiguille);
    aiguille_painter->setPen(*pen_aiguille);
    //aiguille_painter->drawLine(200,200, 400, 200);
    aiguille_painter->drawLine(200,200, 400, 200);

}

void Cadran_Kodjo::Variation_Vitesse_aiguille_Fille(QPainter *aiguille_vitesse_painter, float degres_aiguille)
{
    //for(int i = 0; i <= 360; i++ )
    if(type_cadran == "V")
    {

    couleur_aiguille.setNamedColor("red");

    pen_aiguille->setWidth(3);
    pen_aiguille->setColor(couleur_aiguille);
    aiguille_vitesse_painter->setPen(*pen_aiguille);

    //aiguille_mobile_fille->setLine(200,200, 355, 200);
    aiguille_mobile_fille->setLine(ligne_origine_x,ligne_origine_y, ligne_fin_x, ligne_fin_y);
    //aiguille_mobile_fille->setAngle(180-Degres_Fille);
    aiguille_mobile_fille->setAngle(210-degres_aiguille);

    aiguille_vitesse_painter->drawLine(*aiguille_mobile_fille);

    }

    if(type_cadran == "M")
    {

    couleur_aiguille.setNamedColor("red");

    pen_aiguille->setWidth(3);
    pen_aiguille->setColor(couleur_aiguille);
    aiguille_vitesse_painter->setPen(*pen_aiguille);

    //aiguille_mobile_fille->setLine(200,200, 355, 200);
    aiguille_mobile_moteur->setLine(ligne_origine_x,ligne_origine_y, ligne_fin_x, ligne_fin_y);

    aiguille_mobile_moteur->setAngle(210-degres_aiguille*2/100);

    aiguille_vitesse_painter->drawLine(*aiguille_mobile_moteur);
    //aiguille_vitesse_painter->drawLine(250,degres_aiguille, 400, 200);
    }




}

void Cadran_Kodjo::Affiche_Graduation_Vitesse_Fille(QPainter *graduation_painter)
{
    //for(int i = -30; i <= 210; i= i+10)
    for(int i = valeur_vitesse_min_globale; i <= valeur_vitesse_max_globale; i= i+increment_vitesse_globale)
    {

    couleur_aiguille.setRgb(165, 136, 207);
    pen_aiguille->setWidth(3);
    pen_aiguille->setColor(couleur_aiguille);

    graduation_fille->setLine(200,200, 400, 200);
    graduation_fille->setAngle(i);
    //graduation_fille->setLength(25);
    graduation_fille->setLength(15);

    graduation_fille->translate(180*cos(i *Pi/180),-180*sin(i*Pi/180));

    graduation_painter->setPen(couleur_aiguille);
    graduation_painter->setPen(*pen_aiguille);
    graduation_painter->drawLine(*graduation_fille);

    couleur_valeur_vitesse_texte.setNamedColor("white");
    graduation_painter->setPen(couleur_valeur_vitesse_texte);

    //graduation_painter->drawText(190 + 160*cos(i *Pi/180), 200 -160*sin(i*Pi/180), valeur_vitesse_string.setNum(180-i, 10));

    if(compteur_vitesse_texte <= valeur_vitesse_max_globale && condition_moteur_ou_vitesse == 0)
    {
        graduation_painter->drawText(190 + 160*cos(compteur_vitesse_texte *Pi/180), 200 -160*sin(compteur_vitesse_texte*Pi/180), valeur_vitesse_string.setNum(valeur_vitesse_max_globale-compteur_vitesse_texte, 10));
    }

    if(compteur_vitesse_texte <= valeur_vitesse_max_globale && condition_moteur_ou_vitesse == 1)
    {
        graduation_painter->drawText(190 + 160*cos(compteur_vitesse_texte *Pi/180), 200 -160*sin(compteur_vitesse_texte*Pi/180), valeur_vitesse_string.setNum((valeur_vitesse_max_globale-compteur_vitesse_texte)/20, 10));

        couleur_arc_moteur.setNamedColor("red");
        pen_arc_moteur->setColor(couleur_arc_moteur);
        pen_arc_moteur->setWidth(6);
        graduation_painter->setPen(couleur_arc_moteur);
        graduation_painter->setPen(*pen_arc_moteur);
        graduation_painter->drawArc(0,0,400,400,-30*16 ,60*16);
    }


    compteur_vitesse_texte = compteur_vitesse_texte + 20;
    }

    compteur_vitesse_texte = -30;  //Angle initiale de la position de l'aiguille

}

void Cadran_Kodjo::Setteur_Vitesse_Aiguille(int val_vitesse)
{
    Degres_Fille = val_vitesse;

    //qDebug() << "Degres_Principale" <<Degres_Fille;
}

void Cadran_Kodjo::Affichage_Texte_Km_h(QPainter *kilometre_h_painter)
{
    couleur_kilometre_h->setRgb(138, 244, 239);

    pen_kilometre_h->setColor(*couleur_kilometre_h);

    kilometre_h_painter->setPen(*pen_kilometre_h);
    //kilometre_h_painter->drawText(190, 225, "Km/h");
    kilometre_h_painter->drawText(190, 225, texte_cadran_global);

}

void Cadran_Kodjo::Setteur_Graduation_Moteur_Vitesse(int valeur_vitesse_min, int valeur_vitesse_max, int increment_vitesse, int condition_m_v)
{
    valeur_vitesse_min_globale = valeur_vitesse_min;
    valeur_vitesse_max_globale = valeur_vitesse_max;
    increment_vitesse_globale  = increment_vitesse;
    condition_moteur_ou_vitesse = condition_m_v;
}

void Cadran_Kodjo::Affiche_Graduation_Rotation_Moteur()
{

}

void Cadran_Kodjo::Affichage_Texte_Cadran_General(QString texte_cadran)
{
    texte_cadran_global = texte_cadran;
}

void Cadran_Kodjo::Limite_Tours_Moteur()
{
    couleur_arc_moteur.setNamedColor("red");
    pen_arc_moteur->setColor(couleur_arc_moteur);
    pen_arc_moteur->setWidth(3);
}

void Cadran_Kodjo::Choix_Type_Cadran(QString type)
{
    type_cadran = type;
}

void Cadran_Kodjo::Arc_Cercle_Essence_Huile(QPainter *essence_huile_painter)
{
    couleur_arc_enssence_huile.setRgb( 94, 20, 223 ,255);
    pen_arc_enssence_huile->setColor(couleur_arc_enssence_huile);
    pen_arc_enssence_huile->setWidth(3);
    essence_huile_painter->setPen(*pen_arc_enssence_huile);

    ligne_inf_arc_cercle->setAngle(-30);
    essence_huile_painter->drawLine(*ligne_inf_arc_cercle);

    ligne_sup_arc_cercle->setAngle(90);
    essence_huile_painter->drawLine(*ligne_sup_arc_cercle);

    //essence_huile_painter->setPen(QPen(QBrush(QColor("blue")),200,Qt::SolidLine,Qt::FlatCap)); //Henri
    couleur_pinceau_enssence_huile->setNamedColor("black");
    pinceau_enssence_huile->setColor(*couleur_pinceau_enssence_huile);
    pen_arc_enssence_huile->setColor("black");
    pen_arc_enssence_huile->setCapStyle(Qt::FlatCap); //Dédinit la forme des lignes
    pen_arc_enssence_huile->setWidth(150);
    //pen_arc_enssence_huile->set
    essence_huile_painter->setPen(*pen_arc_enssence_huile);
    essence_huile_painter->drawArc(0,0,150,150,-30*16 ,120*16 );

    couleur_pinceau_enssence_huile->setNamedColor("blue");
    //pinceau_enssence_huile->setColor(*couleur_pinceau_enssence_huile);
    pen_arc_enssence_huile->setColor(*couleur_pinceau_enssence_huile);
    pen_arc_enssence_huile->setWidth(6);
    essence_huile_painter->setPen(*pen_arc_enssence_huile);
    essence_huile_painter->drawArc(-75,-75,300,300,-30*16 ,120*16 );
}

void Cadran_Kodjo::Affiche_Graduation_Essence_Huile(QPainter *graduation_essence_huile_painter)
{
    if(condition_essence_ou_huile == "E")
    {

    for(int i = -30; i <= 90; i= i+30)
    {
    couleur_graduation_enssence_huile.setNamedColor("blue");
    pen_graduation_enssence_huile->setWidth(3);
    pen_graduation_enssence_huile->setColor(couleur_graduation_enssence_huile);

    graduation_huile_essence->setLine(75,75, 225,75);
    graduation_huile_essence->setAngle(i);
    graduation_huile_essence->setLength(15);
    //graduation_huile_essence->translate(75*cos(i *Pi/180),-75*sin(i*Pi/180));
    graduation_huile_essence->translate(135*cos(i *Pi/180),-135*sin(i*Pi/180));


    graduation_essence_huile_painter->setPen(couleur_graduation_enssence_huile);
    graduation_essence_huile_painter->setPen(*pen_graduation_enssence_huile);
    graduation_essence_huile_painter->drawLine(*graduation_huile_essence);

    //if(condition_essence_ou_huile == "E")
    {
    couleur_graduation_enssence_huile.setNamedColor("white");
    graduation_essence_huile_painter->setPen(couleur_graduation_enssence_huile);
    //graduation_essence_huile_painter->drawText(75 + 115*cos(i *Pi/180), 75 -115*sin(i*Pi/180), valeur_vitesse_string.setNum((90-i)/120.0,'g', 2)+" L");
    graduation_essence_huile_painter->drawText(75 + 115*cos(i *Pi/180), 75 -115*sin(i*Pi/180), valeur_vitesse_string.setNum((90-i)/120.0,'g', 2));

    couleur_graduation_enssence_huile.setNamedColor("red");
    pen_graduation_enssence_huile->setWidth(6);
    pen_graduation_enssence_huile->setColor("red");

    graduation_essence_huile_painter->setPen(couleur_graduation_enssence_huile);
    graduation_essence_huile_painter->setPen(*pen_graduation_enssence_huile);

    graduation_essence_huile_painter->drawArc(-75,-75,300,300,75*16 ,15*16 );
    }

    }

    }

    if(condition_essence_ou_huile == "H")
    {
        for(int i = -30; i <= 90; i= i+10)
        {
        couleur_graduation_enssence_huile.setNamedColor("blue");
        pen_graduation_enssence_huile->setWidth(3);
        pen_graduation_enssence_huile->setColor(couleur_graduation_enssence_huile);

        graduation_huile_essence->setLine(75,75, 225,75);
        graduation_huile_essence->setAngle(i);
        graduation_huile_essence->setLength(15);
        //graduation_huile_essence->translate(75*cos(i *Pi/180),-75*sin(i*Pi/180));
        graduation_huile_essence->translate(135*cos(i *Pi/180),-135*sin(i*Pi/180));

        graduation_essence_huile_painter->setPen(couleur_graduation_enssence_huile);
        graduation_essence_huile_painter->setPen(*pen_graduation_enssence_huile);
        graduation_essence_huile_painter->drawLine(*graduation_huile_essence);


        couleur_graduation_enssence_huile.setNamedColor("white");
        graduation_essence_huile_painter->setPen(couleur_graduation_enssence_huile);
        //graduation_essence_huile_painter->drawText(75 + 115*cos(i *Pi/180), 75 -115*sin(i*Pi/180), valeur_vitesse_string.setNum((90-i)/120.0,'g', 2)+" L");
        if(compteur_essence_huile <= 90)
        {
        graduation_essence_huile_painter->drawText(75 + 115*cos(compteur_essence_huile *Pi/180), 75 -115*sin(compteur_essence_huile*Pi/180), valeur_vitesse_string.setNum((200-compteur_huile_seule), 10));
        }

        couleur_graduation_enssence_huile.setNamedColor("red");
        pen_graduation_enssence_huile->setWidth(6);
        pen_graduation_enssence_huile->setColor("red");

        graduation_essence_huile_painter->setPen(couleur_graduation_enssence_huile);
        graduation_essence_huile_painter->setPen(*pen_graduation_enssence_huile);

        //graduation_essence_huile_painter->drawArc(-75,-75,300,300,75*16 ,15*16 );

        compteur_essence_huile = compteur_essence_huile + 30;
        compteur_huile_seule = compteur_huile_seule + 25;
        }


    }
    compteur_huile_seule = 50;
    compteur_essence_huile = -30;

}

void Cadran_Kodjo::Variation_Aiguille_Essence_Huile(QPainter *aiguille_huile_essence_painter, int degres_aiguille_huile_essence =50)
{
    if(type_cadran == "H" && (degres_aiguille_huile_essence == 0 || degres_aiguille_huile_essence < 50))
        degres_aiguille_huile_essence = 50;


    if(type_cadran == "E")
    {
    couleur_aiguille_enssence_huile.setNamedColor("red");
    pen_aiguille_enssence_huile->setWidth(3);
    pen_aiguille_enssence_huile->setColor(couleur_aiguille_enssence_huile);

    aiguille_enssence_huile->setAngle((90 -(degres_aiguille_huile_essence*1.2)));

    //qDebug() << "Degres_Fille_Essence "<< Degres_Fille;
    //qDebug() << "Degres_Fille_Essence "<< Degres_aiguille_enssence_huile;

    aiguille_huile_essence_painter->drawPixmap(100,25,100,100, *image_essence); //Affiche l'icone essence
    }

    if(type_cadran == "H")
    {
        couleur_aiguille_enssence_huile.setNamedColor("red");
        pen_aiguille_enssence_huile->setWidth(3);
        pen_aiguille_enssence_huile->setColor(couleur_aiguille_enssence_huile);

        aiguille_enssence_huile->setAngle(150-degres_aiguille_huile_essence*1.2);

        //qDebug() << "Degres_Fille_Essence "<< Degres_Fille;
        //qDebug() << "Degres_Huile "<< Degres_aiguille_enssence_huile;

        aiguille_huile_essence_painter->drawPixmap(100,25,100,100, *image_huile); //Affiche l'icone huile
    }


    aiguille_huile_essence_painter->setPen(*pen_aiguille_enssence_huile);
    //aiguille_vitesse_painter->drawLine(*aiguille_enssence_huile);
    aiguille_huile_essence_painter->drawLine(*aiguille_enssence_huile);

}

void Cadran_Kodjo::Setteur_Degre_Aiguille_Essence_Huile(int val_degres)
{
    Degres_aiguille_enssence_huile = val_degres;
}

void Cadran_Kodjo::Setteur_Graduation_Essence_Huile(QString val_choix)
{
    condition_essence_ou_huile = val_choix;
}

void Cadran_Kodjo::Clignotant(QPainter *clignotants_painter)
{

    if(type_cadran == "V" )
    {
        int i = 0;

        //qDebug() << " compteur_clignotant = " <<compteur_clignotant;

        //for(i = 0; i <10; i++)
        //int i = 1;
        {
            //if(i == 1 || i == 3 || i ==5 || i ==7 || i ==9)
            //if(i == 0 || i == 2 || i ==4 || i ==6 || i ==8)
            //if(compteur_clignotant == 0 || compteur_clignotant == 2 || compteur_clignotant ==4 || compteur_clignotant ==6 || compteur_clignotant ==8)
            if(compteur_clignotant == 0)
            {
            //QPixmap *image_clignotant_gauche = new QPixmap("/home/utilisateur/Bureau/Tableau_De_Bord_Kodjo/clignotants_gauche.png",Q_NULLPTR, Qt::AutoColor);
            clignotants_painter->drawPixmap(300, 400, 50, 50,*image_clignotant_gauche);
            //QTest::qWait(500);
            //clignotants_painter->end();
            //if(clignotants_painter->isActive())
                //QTest::qWait(500);

                qDebug() << " compteur_clignotant = " <<compteur_clignotant;
            //return;
            //break;
            //timer->start(500);

                //qDebug() << " i = " <<i;
            }
            else
            if(compteur_clignotant == 1)
            {

                qDebug() << " compteur_clignotant = " <<compteur_clignotant;
            //clignotants_painter->end();
            //QTest::qWait(500);
                //if(!clignotants_painter->isActive())
                    //QTest::qWait(500);

            //return;
            //break;

            }


        }
    }


}

void Cadran_Kodjo::Setteur_Clignotant(int cpt_clignotant)
{
    compteur_clignotant = cpt_clignotant;
}

void Cadran_Kodjo::Voyant_Batterie(QPainter *batterie_painter, float etat_batterie)
{
    if(etat_batterie == 1)
    {
        batterie_painter->drawPixmap(600, 250, 50, 50,*image_voyant_batterie);
    }
    else
    {

    }

}

void Cadran_Kodjo::Voyant_Porte_Ouverte(QPainter *porte_painter, float etat_porte)
{
    if(etat_porte == 1)
    {
        porte_painter->drawPixmap(650, 250, 50, 50,*image_voyant_porte_ouverte);
    }
    else
    {

    }
}

void Cadran_Kodjo::Voyant_Ceinture_De_Securite(QPainter *ceinture_painter, float etat_ceinture_de_securite)
{
    if(etat_ceinture_de_securite == 1)
    {
        ceinture_painter->drawPixmap(650, 250, 50, 50,*image_voyant_ceinture_de_securite);
    }
    else
    {

    }
}

void Cadran_Kodjo::Variation_Vitesse_Fille()  // C'est un SLOT
{

}

QRectF Cadran_Kodjo::boundingRect() const
{
    qreal penWidth = 1;

    return QRectF(0,0,400,400);
}

///Dans la fonction paint, nous affichons : la vitesse, le tour moteur, le niveau d'essence, la température de l'huile
/// et les voyants

void Cadran_Kodjo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    rectangle_cercle = boundingRect();

   //qDebug() << "Degres_Principale" << pointeur_main->Degres;
    //qDebug() << "Degres_Principale" << pointeur_main->Valeur_Degres();

    if(type_cadran == "V" || type_cadran == "M")
    {
    Dessiner_Cercle_Fille(painter);

    Affiche_Graduation_Vitesse_Fille(painter);

    vitesse_vehicule = getValue();
    //qDebug()<<"youpi"<<getValue();
    //qDebug()<<"youpi"<<vitesse_vehicule;

    Variation_Vitesse_aiguille_Fille(painter,vitesse_vehicule);

    Affichage_Texte_Km_h(painter);

    }


    if(type_cadran == "E" || type_cadran == "H")
    {
        Arc_Cercle_Essence_Huile(painter);

        //vitesse_vehicule = getValue();
        Degres_aiguille_enssence_huile = getValue();

        Variation_Aiguille_Essence_Huile(painter, Degres_aiguille_enssence_huile);

        //qDebug()<<"valeur_essence_huile ="<<vitesse_vehicule;
        //qDebug()<<"valeur_essence_huile ="<<Degres_aiguille_enssence_huile;

        Affiche_Graduation_Essence_Huile(painter);

    }


    if(type_cadran == "B")
    {

        etat_batterie_globale = getValue();

        Voyant_Batterie(painter, etat_batterie_globale);

    }

    if(type_cadran == "P")
    {
        etat_porte_globale = getValue();

        Voyant_Porte_Ouverte(painter, etat_porte_globale);

    }


    if(type_cadran == "C")
    {
        etat_ceinture_de_securite_globale = getValue();

        Voyant_Ceinture_De_Securite(painter, etat_ceinture_de_securite_globale);

    }

    //qDebug() << " compteur_clignotant = " <<compteur_clignotant;

}
