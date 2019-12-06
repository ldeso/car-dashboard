#ifndef VOYANTSYOUCEF_H
#define VOYANTSYOUCEF_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "objet_virtuel.h"
#include <QTest>

class voyantsYoucef : public objet_virtuel
{
public:
  voyantsYoucef();

  QRectF boundingRect() const ;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
  void flashing();

int clignotant;
};

#endif // VOYANTSYOUCEF_H


