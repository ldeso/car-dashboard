#include "cadrantcontour.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>
#include <QDateTime>

cadrantcontour::cadrantcontour(QGraphicsItem *parent)
{

}
QRectF cadrantcontour::boundingRect() const
{
    QRectF rectf(-800,-500,1600,1000);
    return rectf;
}

void cadrantcontour::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ///la fonction antialiasing permet d'activer le mode haute définition
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen;


  ///création du rectangle avec arriére plan dégradé en noir et bleu
  {QRadialGradient gradient(0,700,800);
  gradient.setColorAt(1, QColor("black"));
  gradient.setColorAt(0, QColor("#0B2F3A"));
  QBrush brush(gradient);
  painter->setBrush(brush);
  painter->drawRect(-800,-500,1600,1000);}

  ///création du cadrant vitesse
  {painter->setPen(QPen(QBrush("dark"), 40, Qt::SolidLine));
  QRect rect4 (-530,-340,420,420);
  painter->drawEllipse(rect4);
  QRect rect5 (110,-350,420,420);
  painter->drawEllipse(rect5);}

 ///création des graduations de deux gauges a cotés pour le tour minute, l'essence et la température moteur
  {QPen pen;
  QRadialGradient gradient(0,0,1200);
  gradient.setColorAt(1,"blue");
  gradient.setColorAt(0.3,QColor(0,0,0,0));
  pen.setColor("dark");
  painter->setPen(pen);
  painter->setBrush(gradient);
  painter->setPen(QPen(QBrush(QColor(0,0,0,0)), 6, Qt::SolidLine));
  QRect rectTmin (-520,-330,400,400);
  painter->drawEllipse(rectTmin);
  QRect rectEss (100,-330,400,400);
  painter->drawEllipse(rectEss);}


  ///création contours arc pour la gauge vitesse
  {painter->setPen(QPen(QBrush("blue"), 15, Qt::SolidLine));
   QRect rect3 (-265,-300,550,550);
   painter->drawEllipse(rect3);}

  {painter->setPen(QPen(QBrush("red"), 15, Qt::SolidLine));
     QRect rect3 (-265,-225,550,550);
     painter->drawEllipse(rect3);}

  ///création de gradient transparent

  {QPen pen;
  QRadialGradient gradient(0,0,1000);
  gradient.setColorAt(0.3,"dark");
  gradient.setColorAt(1, "blue");
  pen.setColor("dark");
  painter->setPen(pen);
  painter->setBrush(gradient);
  QRect rect (-300,-300,620,620);
  painter->drawEllipse(rect);}

{   QRadialGradient gradient(0,0,300);
  gradient.setColorAt(0.2,"blue");
  gradient.setColorAt(0.9,QColor(0,0,0,0));
  gradient.setColorAt(1,QColor(0,0,0,0));
  QPen pen;
  pen.setColor(QColor(0,0,0,0));
  painter->setPen(pen);
  QBrush brushContour(gradient);
  painter->setBrush(brushContour);
  painter->drawEllipse(-300,-300,600,600);}

  {QRadialGradient gradient(0,0,300);
  gradient.setColorAt(0.4,"dark");
  gradient.setColorAt(0.9,QColor(0,0,0,0));
  gradient.setColorAt(1,QColor(0,0,0,0));
  QPen pen;
  pen.setColor(QColor(0,0,0,0));
  painter->setPen(pen);
  QBrush brushContour(gradient);
  painter->setBrush(brushContour);
  painter->drawEllipse(-300,-300,600,600);}

}
