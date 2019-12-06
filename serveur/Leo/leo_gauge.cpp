#include "leo_gauge.h"

namespace {
    struct Shape {
        QRectF rect;
        qreal startAngle;
        qreal arcLength;
    };

    QPainterPath Outline(Shape shape)
    {
        QPainterPath path;
        path.arcMoveTo(shape.rect, shape.startAngle);
        path.arcTo(shape.rect, shape.startAngle, shape.arcLength);
        return path;
    }

    QPainterPath Ticks(Shape shape, int bigSteps, int smallSteps)
    {
        QPainterPath path;
        qreal len = 5;
        QRectF big = shape.rect.adjusted(len, len, -len, -len);
        QRectF small = shape.rect.adjusted(len/2, len/2, -len/2, -len/2);
        for (int i = 0; i <= smallSteps; ++i) {
            qreal angle = i*(shape.arcLength)/smallSteps + shape.startAngle;
            path.arcMoveTo(shape.rect, angle);
            if (i % (smallSteps/bigSteps))
                path.arcTo(small, angle, 0);
            else
                path.arcTo(big, angle, 0);
        }
        return path;
    }

    void DrawScale(QPainter* painter, Shape shape, int max, int step)
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

    QPainterPath Needle(Shape shape, float val, int max)
    {
        qreal len = 0.50 * shape.rect.width() - 10;
        QPainterPath path(shape.rect.center());
        qreal angle = qDegreesToRadians(
            static_cast<qreal>(val)*shape.arcLength/max+shape.startAngle
        );
        QPointF pos(len*qCos(angle), -len*qSin(angle));
        path.lineTo(pos + shape.rect.center());
        return path;
    }
}

Leo_gauge::Leo_gauge(QRectF boundingRect, int max, int bigStep, int smallStep, QGraphicsItem* parent)
    : Leo_object(boundingRect, parent)
    , mBigStep(bigStep)
    , mSmallStep(smallStep)
{
    valueMax = max;
}

void Leo_gauge::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    Shape shape {
        mBoundingRect.adjusted(
            mPenWidth/2,
            mPenWidth/2,
            -mPenWidth/2,
            -mPenWidth/2
        ),
        mStartAngle,
        mArcLength
    };
    QFont font = painter->font();
    font.setPixelSize(10);
    painter->setFont(font);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::white, mPenWidth));
    painter->drawPath(Outline(shape));
    painter->drawPath(Ticks(shape, valueMax/mBigStep, valueMax/mSmallStep));
    DrawScale(painter, shape, valueMax, mBigStep);
    painter->setPen(QPen(Qt::red, mPenWidth));
    painter->drawPath(Needle(shape, value, valueMax));
}
