#include "porteshenri.h"

portesHenri::portesHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
    DD = new onoff();
    DG=new onoff();
    PG=new onoff();
    PD=new onoff();
    C=new onoff();
    PD->setValue(1);
}

QRectF portesHenri::boundingRect() const
{
    return QRect(-500,-300,1000,600);
}

void portesHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if ( (DD->getValue()==1) | (DG->getValue()==1) | (PG->getValue()==1) | (PD->getValue()==1) | (PD->getValue()==1) | (C->getValue()==1) )
    {
        QPixmap *voiture=new QPixmap(":/new/prefix1/icones/iconeVoitureSansPortes.png");
        QPixmap *dd=new QPixmap(":/new/prefix1/icones/porteAD.png");
        QPixmap *dg=new QPixmap(":/new/prefix1/icones/porteAG.png");
        QPixmap *pg=new QPixmap(":/new/prefix1/icones/porteArrG.png");
        QPixmap *pd=new QPixmap(":/new/prefix1/icones/porteArrD.png");
        painter->drawPixmap(0,0,200,200,*voiture);
        if (DD->getValue()==0)
            painter->drawPixmap(20,-49,200,200,*dd);
        if (DD->getValue()==1)
        {
            painter->rotate(-45);
            painter->drawPixmap(-42,-10,200,200,*dd);
            painter->rotate(45);
        }

        if (PD->getValue()==0)
            painter->drawPixmap(52,-37,200,200,*pd);
        if (PD->getValue()==1)
        {
            painter->rotate(-45);
            painter->drawPixmap(-25,36,198,200,*pd);
            painter->rotate(45);
        }

        if (PG->getValue()==0)
            painter->drawPixmap(52,30,200,200,*pg);
        if (PG->getValue()==1)
        {
            painter->rotate(45);
            painter->drawPixmap(110,-100,200,200,*pg);
            painter->rotate(-45);
        }

        if (DG->getValue()==0)
            painter->drawPixmap(20,43,200,200,*dg);
        if (DG->getValue()==1)
        {
            painter->rotate(45);
            painter->drawPixmap(95,-50,200,200,*dg);
            painter->rotate(-45);
        }
    }
}
