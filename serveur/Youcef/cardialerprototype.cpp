#include "cardialerprototype.h"

#include <QtMath>
#include <QGraphicsTextItem>


CarDialerPrototype::CarDialerPrototype(QGraphicsItem *parent)
{

}

QRectF CarDialerPrototype::boundingRect() const
{
 return QRectF(-600, -400, 1200, 800);
}

void CarDialerPrototype::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
painter->setRenderHint(QPainter::Antialiasing);
    /* For test: line to define the middle of main rectangle*/

     painter->setPen(QPen(QBrush("dark") ,2, Qt::SolidLine,Qt::FlatCap));
     painter->drawLine(QLine (0,-400,0,300));
    /*end of the line draw*/

    /*Color gradient of the main scene*/

    {QLinearGradient gradient(QPoint(-800,-500),QPoint(-800,500));/* coordinates gradient ((x,y),(x1,y1)) are cooresponding to line where starting the color variation*/
    gradient.setColorAt(1, QColor("#dark blue"));
    gradient.setColorAt(0.5, QColor("#D4CAC7"));
    gradient.setColorAt(0, QColor("#white"));
    QBrush brush(gradient);
    painter->setBrush(brush);
    painter->drawRect(-800,-500,1600,1000);}

     /* For test: line to define the middle of main rectangle*/

      painter->setPen(QPen(QBrush("dark") ,2, Qt::SolidLine,Qt::FlatCap));
      painter->drawLine(QLine (0,-400,0,300));


     /*end of the line draw*/

      {

          QPolygonF polygon;

         QRect rec1(47,-355,507,507);
         QRect rec2(-554,-355,507,507);

         painter->setPen(QPen(QBrush("dark blue"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));

          QPainterPath rectPath;
          rectPath.moveTo(-290,-320);
          rectPath.lineTo(290,-320);
          rectPath.arcTo(rec1,90, -180);
          rectPath.lineTo(290,115);
          rectPath.lineTo(-290,115);
          rectPath.arcTo(rec2,270, -180);
          rectPath.closeSubpath();
          rectPath.addPolygon(polygon);

          QRadialGradient gradient(119, -4.5, 1000);
          gradient.setColorAt(0, QColor("white"));
          gradient.setColorAt(0.2, QColor(0,0,0,0));
          gradient.setColorAt(0.5, QColor("dark"));
          gradient.setColorAt(0.8, QColor(0,0,0,0));
          gradient.setColorAt(1, QColor("blue"));
          QBrush brush(gradient);
          painter->setBrush(brush);

          painter->drawPath(rectPath);
      }
      {

          QPolygonF polygon;

         QRect rec1(97,-305,407,407);
         QRect rec2(-504,-305,407,407);

         painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));

          QPainterPath rectPath;
          rectPath.moveTo(-300,-305);
          rectPath.lineTo(300,-305);
          rectPath.arcTo(rec1,90, -180);
          rectPath.lineTo(302,102);
          rectPath.lineTo(-300,102);
          rectPath.arcTo(rec2,270, -180);
          rectPath.closeSubpath();
          rectPath.addPolygon(polygon);

//          QRadialGradient gradient(119, -4.5, 200);
//          gradient.setColorAt(0, QColor(0,0,0,0));
//          gradient.setColorAt(0.5, QColor("yellow"));
//          gradient.setColorAt(1, QColor("dark"));
//          QBrush brush(gradient);
//          painter->setBrush(brush);
          painter->drawPath(rectPath);
      }
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

//          QRadialGradient gradient(119, -4.5, 200);
//          gradient.setColorAt(0, QColor(0,0,0,0));
//          gradient.setColorAt(0.5, QColor("yellow"));
//          gradient.setColorAt(1, QColor("dark"));
//          QBrush brush(gradient);
//          painter->setBrush(brush);
          painter->drawPath(rectPath);
      }
      {
      QRect RectSpeed1 (100,-305, 415, 415);
      QRect RectSpeed2 (-505,-305, 415, 415);
      painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));

      QPolygonF polygon;
       QPainterPath rectPath;
       rectPath.moveTo(-250,-295);
       rectPath.lineTo(250,-295);
       rectPath.arcTo(RectSpeed1,90, 30);
       rectPath.lineTo(145,-235);
       rectPath.lineTo(-140,-235);
       rectPath.arcTo(RectSpeed2,42, 31);
       rectPath.closeSubpath();
       rectPath.addPolygon(polygon);

       QRadialGradient gradient(0, -270, 200);
       gradient.setColorAt(0, QColor(0,0,0,0));
       gradient.setColorAt(0.5, QColor("dark blue"));
       gradient.setColorAt(1, QColor("dark"));
       QBrush brush(gradient);
       painter->setBrush(brush);

        painter->drawPath(rectPath);
   }
      {
      QRect RectSpeed1 (100,-300, 405, 405);
      QRect RectSpeed2 (-500,-300, 405, 405);
      painter->setPen(QPen(QBrush("red"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));

      QPolygonF polygon;
       QPainterPath rectPath;
       rectPath.moveTo(-300,-300);
       rectPath.lineTo(300,-300);
       rectPath.arcTo(RectSpeed1,90, 49);
       rectPath.lineTo(150,-230);
       rectPath.lineTo(-145,-230);
       rectPath.arcTo(RectSpeed2,42, 49);
       rectPath.closeSubpath();
       rectPath.addPolygon(polygon);


       painter->drawPath(rectPath);
   }


    /*Build the left Arc of the main dial */
    /*A.  Main Cirle*/
//    {
//      QRectF rectangle(-500,-300, 398, 398);
//      int startAngle = 25 * 16;
//      int spanAngle =  245* 16;

//      painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//      painter->drawArc(rectangle,startAngle,spanAngle);

//     }
    /*B.  OverCicle*/
//    {
//      QRectF rectangle(-504,-304, 408, 408);
//      int startAngle = 25 * 16;
//      int spanAngle =  245* 16;

//      painter->setPen(QPen(QBrush("dark"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//      painter->drawArc(rectangle,startAngle,spanAngle);

//     }

    /*Build the right Arc of the main dial */
    /*A.  Main Cirle*/
//    {
//      QRectF rectangle(100,-300, 400, 400);
//        int startAngle = (-90) * 16;
//        int spanAngle = (245) * 16;

//        painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//        painter->drawArc(rectangle,startAngle,spanAngle);

//    }
       /*B.  OverCicle*/
//    {
//      QRectF rectangle(97,-305, 406, 408);
//        int startAngle = (-90) * 16;
//        int spanAngle = (245) * 16;

//        painter->setPen(QPen(QBrush("dark"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//        painter->drawArc(rectangle,startAngle,spanAngle);

//     }

    /*Build the top line of the main dial */
    /*A.  Main line*/
//    {
//    QLine line(-300,-300,300,-300);
//    painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//    painter->drawLine(line);
//    }
    /*B.  Above line */
//    {
//    QLine line(-300,-305,300,-305);
//    painter->setPen(QPen(QBrush("dark"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//    painter->drawLine(line);
//    }
    /*C.  bottom line*/
//    {
//    QLine line(-242,-295,242,-295);
//    painter->setPen(QPen(QBrush("dark"),5,Qt::SolidLine,Qt::RoundCap,Qt::BevelJoin));
//    painter->drawLine(line);
//    }

    /*Build the middle line of the main dial */
    /*A.  Main line*/
//    {
//     QLine line(-120,-187,120,-187);
//     painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//     painter->drawLine(line);
//    }
    /*B.  above line*/
//    {
//     QLine line(-118,-192,118,-192);
//     painter->setPen(QPen(QBrush("dark"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//     painter->drawLine(line);
//    }

    /*Build the bottom line of the main dial */
    /*A.  Main line*/
//    {
//     QLine line(-300,99,300,99);
//     painter->setPen(QPen(QBrush("white"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//     painter->drawLine(line);
//    }
     /*B.  Bottom line*/
//    {
//     QLine line(-302,103,302,103);
//     painter->setPen(QPen(QBrush("dark"),5,Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
//     painter->drawLine(line);
//    }








}
