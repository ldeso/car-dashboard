#include "leo_gauge.h"

namespace {
    struct Shape {
        QRectF rect;
        qreal startAngle;
        qreal arcLength;
    };

    QPainterPath Outline(const Shape shape)
    {
        QPainterPath path;
        path.arcMoveTo(shape.rect, shape.startAngle);
        path.arcTo(shape.rect, shape.startAngle, shape.arcLength);
        return path;
    }

    QPainterPath Ticks(const Shape shape, const int divisions, const  int subdivisions)
    {
        QPainterPath path;
        qreal len = 5;
        QRectF big = shape.rect.adjusted(len, len, -len, -len);
        QRectF small = shape.rect.adjusted(len/2, len/2, -len/2, -len/2);
        for (int i = 0; i <= subdivisions; ++i) {
            qreal angle = i*(shape.arcLength)/subdivisions + shape.startAngle;
            path.arcMoveTo(shape.rect, angle);
            if (i % (subdivisions/divisions))
                path.arcTo(small, angle, 0);
            else
                path.arcTo(big, angle, 0);
        }
        return path;
    }

    void DrawScale(QPainter* painter, const Shape shape, const int max, const int step)
    {
        qreal distance = 0.47 * shape.rect.width() - 15;
        for (int val = 0; val <= max; val += step) {
            qreal angle = qDegreesToRadians(val*shape.arcLength/max+shape.startAngle);
            QPointF pos(distance*qCos(angle), -distance*qSin(angle));
            pos += shape.rect.center();
            QRectF rect(pos - QPointF(30, 30), pos + QPointF(30, 30));
            painter->drawText(rect, QString::number(val), Qt::AlignCenter | Qt::AlignVCenter);
        }
    }

    QPainterPath Needle(const Shape shape, const qreal val, const int max)
    {
        qreal len = 0.50 * shape.rect.width() - 10;
        QPainterPath path(shape.rect.center());
        qreal angle = qDegreesToRadians(
            val*shape.arcLength/max+shape.startAngle
        );
        QPointF pos(len*qCos(angle), -len*qSin(angle));
        path.lineTo(pos + shape.rect.center());
        return path;
    }
}

Leo_gauge::Leo_gauge(const QRectF boundingRect, QGraphicsItem *parent)
    : Leo_object(boundingRect, parent)
{
    setData(MAX, 100);
    setData(DIVS, 10);
    setData(SUBDIVS, 20);
    setData(STARTANGLE, -145);
    setData(ARCLENGTH, -250);
    setData(WIDTH, 2);
    setData(FONT, 10);
    valueMax = data(MAX).toInt();
}

void Leo_gauge::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    Shape shape {
        mBoundingRect.adjusted(
            data(WIDTH).toReal() / 2,
            data(WIDTH).toReal() / 2,
            -data(WIDTH).toReal() / 2,
            -data(WIDTH).toReal() / 2
        ),
        data(STARTANGLE).toReal(),
        data(ARCLENGTH).toReal()
    };
    QFont font = painter->font();
    font.setPixelSize(data(FONT).toInt());
    painter->setFont(font);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::white, data(WIDTH).toReal()));
    painter->drawPath(Outline(shape));
    painter->drawPath(Ticks(shape, data(DIVS).toInt(), data(SUBDIVS).toInt()));
    DrawScale(painter, shape, valueMax, valueMax/data(DIVS).toInt());
    painter->setPen(QPen(Qt::red, data(WIDTH).toReal()));
    painter->drawPath(Needle(shape, static_cast<qreal>(value), valueMax));
}
