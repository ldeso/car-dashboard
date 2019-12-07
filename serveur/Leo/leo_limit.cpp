#include "leo_limit.h"

namespace {
    QPainterPath Outline(const QRectF rect)
    {
        QPainterPath path;
        path.addEllipse(rect.center(), rect.width()/2, rect.height()/2);
        return path;
    }

    bool ShowSign(int limit, QList<int> limits, int blinks, int time_ms = 4000)
    {
        static int last_limit;
        static bool is_blinking;
        static std::chrono::time_point<std::chrono::high_resolution_clock> start;
        if (!is_blinking && (!limits.contains(limit) || (limit == last_limit)))
            return false;
        if (!is_blinking) {
            start = std::chrono::high_resolution_clock::now();
            is_blinking = true;
            return true;
        }
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        if (elapsed > std::chrono::milliseconds(time_ms)) {
            last_limit = limit;
            is_blinking = false;
            return false;
        }
        return !((elapsed/std::chrono::milliseconds(time_ms/(2*blinks))) % 2);
    }
}

Leo_limit::Leo_limit(const QRectF boundingRect, QGraphicsItem *parent)
    : Leo_object(boundingRect, parent)
{
    setData(LIMITS, QVariant::fromValue<QList<int>>(
        { 30, 50, 70, 90, 110, 130 }
    ));
    setData(FONT, 16);
    setData(WIDTH, 6);
    setData(BLINKS, 3);
}

void Leo_limit::paint(QPainter* p, const QStyleOptionGraphicsItem*, QWidget*)
{
    QList<int> valid_limits = data(LIMITS).value<QList<int>>();
    if (ShowSign(qRound(value), valid_limits, data(BLINKS).toInt())) {
        int limit = qRound(value);

        QRectF rect = mBoundingRect.adjusted(
            data(WIDTH).toReal()/2,
            data(WIDTH).toReal()/2,
            -data(WIDTH).toReal()/2,
            -data(WIDTH).toReal()/2
        );
        QFont font = p->font();
        font.setPixelSize(data(FONT).toInt());
        font.setBold(true);
        p->setFont(font);
        p->setRenderHint(QPainter::Antialiasing);
        p->fillPath(Outline(rect), Qt::white);
        p->setPen(QPen(Qt::red, data(WIDTH).toReal()));
        p->drawPath(Outline(rect));
        p->setPen(QPen(Qt::black, data(WIDTH).toReal()));
        p->drawText(
            mBoundingRect,
            QString::number(limit),
            Qt::AlignCenter | Qt::AlignVCenter
        );
    }
}
