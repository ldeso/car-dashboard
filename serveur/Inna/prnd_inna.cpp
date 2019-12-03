#include "Inna/prnd_inna.h"
#include "Inna/iconinna.h"
#include <QPainter>
#include <QtMath>

PRND_Inna::PRND_Inna(IconInna *parent) : IconInna (parent)
{
value = 1;
}

QRectF PRND_Inna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void PRND_Inna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{ position=QPoint(700,320);
  val = qRound(value);
    size = QSize(70,70);
    switch (val) {
    case 1:
      {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/I_auto_P_blue.gif"));break;}
    case 2:
      {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/I_auto_R_blue.gif"));break;}
    case 3:
       {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/I_auto_N_blue.gif"));break;}
    case 4:
       {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/I_auto_D_blue.gif"));break;}
    default:
    {painter->setPen(Qt::transparent);
     painter->setBrush(QBrush(Qt::transparent));
     painter->drawRect(position.x(),position.y(),size.width(),size.height());
     break;}
    }
}
