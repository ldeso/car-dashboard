#include "leo_display.h"

Leo_display::Leo_display(objet_virtuel *parent)
    : objet_virtuel(parent)
{
    value = 0;
    valueMax = 130;
}

void Leo_display::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addRect(
        0.5 * mPenWidthPx,
        0.5 * mPenWidthPx,
        mBoundingRect.width() - 0.5*mPenWidthPx,
        mBoundingRect.height() - 0.5*mPenWidthPx
    );
    painter->fillPath(path, Qt::white);
    painter->setPen(QPen(Qt::black, mPenWidthPx));
    painter->drawPath(path);
    QFont new_font = painter->font();
    new_font.setPixelSize(mFontSizePx);
    painter->setFont(new_font);
    QString num = QString::number(static_cast<int>(value));
    painter->drawText(
        static_cast<int>(0.5*mBoundingRect.width() - 0.25*num.size()*mFontSizePx),
        static_cast<int>(0.5*mBoundingRect.height() + 0.35*mFontSizePx),
        num
    );
}
