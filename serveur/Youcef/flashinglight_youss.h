#ifndef FLASHINGLIGHT_YOUSS_H
#define FLASHINGLIGHT_YOUSS_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "objet_virtuel.h"
#include <QTest>

class FlashingLight_Youss: public objet_virtuel
{
public:
  FlashingLight_Youss();

  QRectF boundingRect() const ;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
  void flashing();

int clignotant;
};

#endif // FLASHINGLIGHT_YOUSS_H


