#include "leo_limit.h"

namespace {
    struct Params {
        const QRectF rect;
        const QList<int> limits;
        const int blinks;
        const int period;
    };

    QPainterPath Outline(const Params params)
    {
        QPainterPath path;
        path.addEllipse(
            params.rect.center(), params.rect.width()/2, params.rect.height()/2
        );
        return path;
    }

    bool ShowSign(float &value, int &current_limit, const Params params)
    {

        int new_limit = qRound(value);
        value = 0;
        static std::chrono::high_resolution_clock::time_point start;
        if (params.limits.contains(new_limit) && (new_limit != current_limit)) {
            current_limit = new_limit;
            start = std::chrono::high_resolution_clock::now();
            return true;
        }
        if (current_limit == 0)
            return false;
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        if (elapsed > params.blinks*std::chrono::milliseconds(params.period)) {
            current_limit = 0;
            return false;
        }
        return !((2*elapsed/std::chrono::milliseconds(params.period)) % 2);
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
    setData(PERIOD, 3000);
    value = 90;
}

void Leo_limit::paint(QPainter* p, const QStyleOptionGraphicsItem*, QWidget*)
{
    static int current_limit;
    const struct Params params {
        mBoundingRect.adjusted(
            data(WIDTH).toReal()/2,
            data(WIDTH).toReal()/2,
            -data(WIDTH).toReal()/2,
            -data(WIDTH).toReal()/2
        ),
        data(LIMITS).value<QList<int>>(),
        data(BLINKS).toInt(),
        data(PERIOD).toInt()
    };
    if (ShowSign(value, current_limit, params)) {
        QFont font = p->font();
        font.setPixelSize(data(FONT).toInt());
        font.setBold(true);
        p->setFont(font);
        p->setRenderHint(QPainter::Antialiasing);
        p->fillPath(Outline(params), Qt::white);
        p->setPen(QPen(Qt::red, data(WIDTH).toReal()));
        p->drawPath(Outline(params));
        p->setPen(QPen(Qt::black, data(WIDTH).toReal()));
        p->drawText(
            mBoundingRect,
            QString::number(current_limit),
            Qt::AlignCenter | Qt::AlignVCenter
        );
    }
}
