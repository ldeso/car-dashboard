#include "leo_label.h"

Leo_label::Leo_label(QGraphicsItem* parent)
    : QGraphicsSimpleTextItem(parent)
{
    SetFontSizePx(mFontSizePx);
}

Leo_label::Leo_label(const QString &text, QGraphicsItem* parent)
    : QGraphicsSimpleTextItem(text, parent)
{
    SetFontSizePx(mFontSizePx);
}

void Leo_label::SetFontSizePx(const int fontSizePx)
{
    mFontSizePx = fontSizePx;
    QFont new_font = font();
    new_font.setPixelSize(mFontSizePx);
    setFont(new_font);
    moveBy(
        0.25*font().pixelSize() + 1.25*parentItem()->boundingRect().width(),
        0.5 * (-font().pixelSize()+parentItem()->boundingRect().height())
    );
}
