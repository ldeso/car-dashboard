#include "leo_limit.h"

namespace {
    QPainterPath Outline(const QRectF rect)
    {
        QPainterPath path;
        path.addEllipse(rect.center(), rect.width()/2, rect.height()/2);
        return path;
    }

    bool ShowSign(int limit, QList<int> valid_limits, int blinks)
    {
        static int last_limit;
        static int blink_cnt;
        static std::chrono::time_point<std::chrono::high_resolution_clock> start;
        static bool is_started;
        static bool is_shown;

        is_shown = false;
        if (valid_limits.contains(limit) && (limit != last_limit)) {
            is_shown = true;
            if (!is_started) {
                start = std::chrono::high_resolution_clock::now();
                is_started = true;
            }
            auto now = std::chrono::high_resolution_clock::now();
            if (now - start > std::chrono::milliseconds(500)) {
                if (blink_cnt < blinks) {
                    blink_cnt++;
                    is_shown = !is_shown;
                } else {
                    blink_cnt = 0;
                    is_shown = true;
                    last_limit = limit;
                }
                is_started = false;
            }
        }
        return is_shown;
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
