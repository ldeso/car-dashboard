#include "Inna/prnd.h"
#include "Inna/iconinna.h"
#include <QPainter>

PRND::PRND(IconInna *parent) : IconInna (parent)
{
value = 1;
}

QRectF PRND::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void PRND::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{ position=QPoint(700,320);
  size = QSize(70,70);
    switch (value) {
    case 1:
      {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/myicons/auto_P_blue.gif"));break;}
    case 2:
      {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/myicons/auto_R_blue.gif"));break;}
    case 3:
       {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/myicons/auto_N_blue.gif"));break;}
    case 4:
       {painter->drawPixmap(position.x(),position.y(),size.width(),size.height(), QPixmap(":/myicons/auto_D_blue.gif"));break;}
    default:
    {painter->setPen(Qt::transparent);
     painter->setBrush(QBrush(Qt::transparent));
     painter->drawRect(position.x(),position.y(),size.width(),size.height());
     break;}
    }
}
