#include "leo_gauge.h"

namespace {
    struct Params {
        QRectF rect;
        qreal startAngle;
        qreal arcLength;
        int max;
        int divs;
        int subdivs;
        int step;
    };

    QPainterPath Outline(const Params params)
    {
        QPainterPath path;
        path.arcMoveTo(params.rect, params.startAngle);
        path.arcTo(params.rect, params.startAngle, params.arcLength);
        return path;
    }

    QPainterPath Ticks(const Params params)
    {
        QPainterPath path;
        qreal len = 5;
        QRectF big_rect = params.rect.adjusted(len, len, -len, -len);
        QRectF small_rect = params.rect.adjusted(len/2, len/2, -len/2, -len/2);
        for (int i = 0; i <= params.subdivs; ++i) {
            qreal angle = i*params.arcLength/params.subdivs + params.startAngle;
            path.arcMoveTo(params.rect, angle);
            if (i % (params.subdivs/params.divs))
                path.arcTo(small_rect, angle, 0);
            else
                path.arcTo(big_rect, angle, 0);
        }
        return path;
    }

    void DrawScale(QPainter* painter, const Params params)
    {
        qreal distance = 0.47 * params.rect.width() - 15;
        for (int val = 0; val <= params.max; val += params.step) {
            qreal angle = qDegreesToRadians(
                val*params.arcLength/params.max + params.startAngle
            );
            QPointF pos(distance*qCos(angle), -distance*qSin(angle));
            pos += params.rect.center();
            QRectF rect(pos - QPointF(30, 30), pos + QPointF(30, 30));
            painter->drawText(
                rect, QString::number(val), Qt::AlignCenter | Qt::AlignVCenter
            );
        }
    }

    QPainterPath Needle(const Params params, qreal val)
    {
        qreal len = 0.50*params.rect.width() - 10;
        QPainterPath path(params.rect.center());
        qreal angle = qDegreesToRadians(
            val*params.arcLength/params.max+params.startAngle
        );
        QPointF pos(len*qCos(angle), -len*qSin(angle));
        path.lineTo(pos + params.rect.center());
        return path;
    }
}

Leo_gauge::Leo_gauge(const QRectF boundingRect, QGraphicsItem *parent)
    : Leo_object(boundingRect, parent)
{
    setData(MAX, 100);
    setData(DIVS, 2);
    setData(SUBDIVS, 4);
    setData(STARTANGLE, -145);
    setData(ARCLENGTH, -250);
    setData(WIDTH, 2);
    setData(FONT, 10);
}

void Leo_gauge::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    Params params {
        mBoundingRect.adjusted(
            data(WIDTH).toReal()/2,
            data(WIDTH).toReal()/2,
            -data(WIDTH).toReal()/2,
            -data(WIDTH).toReal()/2
        ),
        data(STARTANGLE).toReal(),
        data(ARCLENGTH).toReal(),
        data(MAX).toInt(),
        data(DIVS).toInt(),
        data(SUBDIVS).toInt(),
        data(MAX).toInt() / data(DIVS).toInt()
    };
    QFont font = painter->font();
    font.setPixelSize(data(FONT).toInt());
    painter->setFont(font);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::white, data(WIDTH).toReal()));
    painter->drawPath(Outline(params));
    painter->drawPath(Ticks(params));
    DrawScale(painter, params);
    painter->setPen(QPen(Qt::red, data(WIDTH).toReal()));
    painter->drawPath(Needle(params, static_cast<qreal>(value)));
    valueMax = data(MAX).toInt();
}
