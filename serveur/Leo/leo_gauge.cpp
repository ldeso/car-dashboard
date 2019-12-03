#include "leo_gauge.h"

Leo_gauge::Leo_gauge(int maxValue, int spacing, objet_virtuel *parent)
    : objet_virtuel(parent)
{
    valueMax = maxValue;
    mSpacing = spacing;
}

void Leo_gauge::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QRectF arc_rect = mBoundingRect.adjusted(
        0.5 * mPenWidthPx,
        0.5 * mPenWidthPx,
        -0.5 * mPenWidthPx,
        -0.5 * mPenWidthPx
    );
    QPointF bottom(arc_rect.center() + QPointF(0, 0.5 * arc_rect.height()));
    QPainterPath path(bottom);
    path.arcMoveTo(arc_rect, 0.5*mBottomAngle - 90);
    path.arcTo(arc_rect, 0.5*mBottomAngle - 90, 360 - mBottomAngle);
    path.closeSubpath();
    painter->fillPath(path, mColor);
    painter->setPen(QPen(Qt::black, mPenWidthPx));
    painter->drawPath(path);
    QFont new_font = painter->font();
    new_font.setPixelSize(mFontSizePx);
    painter->setFont(new_font);
    painter->drawText(
        static_cast<int>(-0.28 * mSizePx),
        static_cast<int>(0.28 * mSizePx),
        "0"
    );
    painter->drawText(
        static_cast<int>(0.1 * mSizePx),
        static_cast<int>(0.28 * mSizePx),
        QString::number(valueMax)
    );
    painter->rotate(0.5 * mBottomAngle);
    painter->rotate(static_cast<qreal>(
        value * static_cast<float>((360-mBottomAngle) / valueMax)
    ));
    painter->drawLine(arc_rect.center(), arc_rect.center() + QPointF(0, mNeedleSizePx));
    painter->rotate(-static_cast<qreal>(
        value * static_cast<float>((360-mBottomAngle) / valueMax)
    ));
    for (int value = 0; value <= valueMax; value += mSpacing) {
        painter->drawLine(bottom, bottom - QPointF(0, mTickSizePx));
        painter->rotate(mSpacing * (360-mBottomAngle) / valueMax);
    }
}
