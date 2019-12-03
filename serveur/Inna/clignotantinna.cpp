#include "clignotantinna.h"
#include "Inna/iconinna.h"
#include <QPainter>
#include <QDebug>
#include <QTest>

clignotantInna::clignotantInna(IconInna *parent) : IconInna (parent)
{   mode = 0;
    cligno = 0;
    this->setZValue(5.0);
}

QRectF clignotantInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void clignotantInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{  painter->setRenderHint(QPainter::Antialiasing);
    mode = qRound(value);
    if  (mode != 0)
    {if (mode == -1)
        {painter->setOpacity(cligno);
        painter->drawPixmap(500,120,50,50, QPixmap(":/I_turnLeft.gif"));
        }

     if (mode == 1)
        {painter->setOpacity(cligno);
        painter->drawPixmap(840,120,50,50, QPixmap(":/I_turnRight.gif"));
        }

    if (mode == 2)
        {painter->setOpacity(cligno);
         painter->drawPixmap(500,120,50,50, QPixmap(":/I_turnLeft.gif"));
         painter->drawPixmap(840,120,50,50, QPixmap(":/I_turnRight.gif"));
         }
    MAJ();
    }

   else
    {   painter->setPen(Qt::transparent);
        painter->setBrush(QBrush(Qt::transparent));
        painter->drawRect(500,120,50,50);
    }


}

void clignotantInna::MAJ()
{cligno = !cligno;
 QTest::qWait(500);//
 update();
}
