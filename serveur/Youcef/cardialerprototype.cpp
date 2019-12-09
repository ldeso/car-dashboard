#include "cardialerprototype.h"

#include <QtMath>
#include <QGraphicsTextItem>


CarDialerPrototype::CarDialerPrototype(QGraphicsItem *)
{

}

QRectF CarDialerPrototype::boundingRect() const
{
 return QRectF(-600, -400, 1200, 800);
}

void CarDialerPrototype::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
painter->setRenderHint(QPainter::Antialiasing);


//    /* For test: line to define the middle of main rectangle*/
//     painter->setPen(QPen(QBrush("dark") ,2, Qt::SolidLine,Qt::FlatCap));
//     painter->drawLine(QLine (0,-400,0,300));
//    /*end of the line draw*/




    /*Color gradient of the main scene*/

    {QLinearGradient gradient(QPoint(-800,-500),QPoint(-800,500));/* coordinates gradient ((x,y),(x1,y1)) are cooresponding to line where starting the color variation*/
    gradient.setColorAt(1, QColor("#dark blue"));
    gradient.setColorAt(0.5, QColor("#D4CAC7"));
    gradient.setColorAt(0, QColor("#white"));
    QBrush brush(gradient);
    painter->setBrush(brush);
    painter->drawRect(-800,-500,1600,1000);}



//     /* For test: line to define the middle of main rectangle*/
//      painter->setPen(QPen(QBrush("dark") ,2, Qt::SolidLine,Qt::FlatCap));
//      painter->drawLine(QLine (0,-400,0,300));
//     /*end of the line draw*/



/* contour principal*/
      {

          QPolygonF polygon;

         QRect rec1(47,-355,507,507);
         QRect rec2(-554,-355,507,507);

         painter->setPen(QPen(QBrush("dark blue"),3,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));

          QPainterPath rectPath;
          rectPath.moveTo(-290,-320);
          rectPath.lineTo(290,-320);
          rectPath.arcTo(rec1,90, -180);
          rectPath.lineTo(290,115);
          rectPath.lineTo(-290,115);
          rectPath.arcTo(rec2,270, -180);
          rectPath.closeSubpath();
          rectPath.addPolygon(polygon);

/*remplissage contour principal*/

          QRadialGradient gradient(0, -70, 700);
          gradient.setColorAt(0, QColor("0,204,255"));
          gradient.setColorAt(0.2, QColor("dark blue"));
          gradient.setColorAt(1, QColor("dark"));

          QBrush brush(gradient);
          painter->setBrush(brush);
          painter->drawPath(rectPath);
      }

/*creation contour cadrant*/

      {

          QPolygonF polygon;

         QRect rec1(97,-305,407,407);
         QRect rec2(-504,-305,407,407);

         painter->setPen(QPen(QBrush("dark blue"),3,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));

          QPainterPath rectPath;
          rectPath.moveTo(-300,-305);
          rectPath.lineTo(300,-305);
          rectPath.arcTo(rec1,90, -180);
          rectPath.lineTo(302,102);
          rectPath.lineTo(-300,102);
          rectPath.arcTo(rec2,270, -180);
          rectPath.closeSubpath();
          rectPath.addPolygon(polygon);

      }

/*creation second contour cadrant*/


      {
          QPolygonF polygon;

         QRect rec1(103,-300,398,398);
         QRect rec2(-499,-300,398,398);

         painter->setPen(QPen(QBrush("red"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));

          QPainterPath rectPath;
          rectPath.moveTo(-300,-300);
          rectPath.lineTo(300,-300);
          rectPath.arcTo(rec1, 90, -180);
          rectPath.lineTo(302,98);
          rectPath.lineTo(-300,98);
          rectPath.arcTo(rec2,270, -180);
          rectPath.closeSubpath();
          rectPath.addPolygon(polygon);

/* remplissage second contour cadrant*/

          QLinearGradient gradient(-300, -300,-300,0 );
          gradient.setColorAt(0, QColor(0,204,255));
          gradient.setColorAt(0, QColor("gray"));
           gradient.setColorAt(1, QColor("gray"));


           QBrush brush(gradient);
          painter->setBrush(brush);
          painter->drawPath(rectPath);
      }
/*creation contour ecran supérieur */



{
QRect RectSpeed3 (100,-300, 405, 405);
QRect RectSpeed4 (-500,-300, 405, 405);
painter->setPen(QPen(QBrush("red"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));

QPolygonF polygon2;
 QPainterPath rectPath1;
 rectPath1.moveTo(-300,-300);
 rectPath1.lineTo(300,-300);
 rectPath1.arcTo(RectSpeed3,90, 49);
 rectPath1.lineTo(150,-230);
 rectPath1.lineTo(-145,-230);
 rectPath1.arcTo(RectSpeed4,42, 49);
 rectPath1.closeSubpath();
 rectPath1.addPolygon(polygon2);


 painter->drawPath(rectPath1);
}

{
QRect RectSpeed1 (93,-303, 411, 411);
QRect RectSpeed2 (-505,-305, 415, 415);
painter->setPen(QPen(QBrush("white"),4,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));

QPolygonF polygon;
 QPainterPath rectPath;
 rectPath.moveTo(-251,-298);
 rectPath.lineTo(257,-298);
 rectPath.arcTo(RectSpeed1,105, 30);
 rectPath.lineTo(145,-235);
 rectPath.lineTo(-140,-235);
 rectPath.arcTo(RectSpeed2,45, 30);
 rectPath.closeSubpath();
 rectPath.addPolygon(polygon);

 QRadialGradient gradient(0, -270, 200);
 gradient.setColorAt(0.5, QColor("dark blue"));
 gradient.setColorAt(1, QColor("dark"));
 QBrush brush(gradient);
 painter->setBrush(brush);

  painter->drawPath(rectPath);
}


}
