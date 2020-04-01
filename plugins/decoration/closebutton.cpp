/*
 * Copyright (C) 2018 Vlad Zagorodniy <vladzzag@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// own
#include "closebutton.h"
#include "decoration.h"

// KDecoration
#include <KDecoration2/DecoratedClient>

// Qt
#include <QPainter>

namespace Panda
{

CloseButton::CloseButton(Decoration *decoration, QObject *parent)
    : DecorationButton(KDecoration2::DecorationButtonType::Close, decoration, parent)
{
    auto *decoratedClient = decoration->client().data();
    connect(decoratedClient, &KDecoration2::DecoratedClient::closeableChanged,
            this, &CloseButton::setVisible);

    connect(this, &CloseButton::hoveredChanged, this,
        [this] {
            update();
        });

    const int titleBarHeight = decoration->titleBarHeight();
    const QSize size(qRound(titleBarHeight * 1.33), titleBarHeight);
    setGeometry(QRect(QPoint(0, 0), size));
    setVisible(decoratedClient->isCloseable());
}

CloseButton::~CloseButton()
{
}

void CloseButton::paint(QPainter *painter, const QRect &repaintRegion)
{
    Q_UNUSED(repaintRegion)

    const QRectF buttonRect = geometry();
    QRectF crossRect = QRectF(0, 0, 10, 10);
    crossRect.moveCenter(buttonRect.center().toPoint());

    painter->save();
    painter->setRenderHints(QPainter::Antialiasing, true);

    // Background.
    QRectF bgRect = QRectF(0, 0, 27, 27);
    bgRect.moveCenter(buttonRect.center().toPoint());
    const qreal radius = bgRect.width() / 2;

    painter->setPen(Qt::NoPen);
    painter->setBrush(backgroundColor());
    // painter->drawRect(buttonRect);
    painter->drawRoundedRect(bgRect, radius, radius);

    // Foreground.
    painter->setPen(foregroundColor());
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHints(QPainter::Antialiasing, false);
    painter->drawLine(crossRect.topLeft(), crossRect.bottomRight());
    painter->drawLine(crossRect.topRight(), crossRect.bottomLeft());

    painter->restore();
}

QColor CloseButton::backgroundColor() const
{
    const auto *deco = qobject_cast<Decoration *>(decoration());
    if (!deco) {
        return {};
    }

    if (isPressed()) {
        return QColor(255, 91, 77);
    }

    if (isHovered()) {
        return QColor(255, 105, 89);
    }

    return Qt::transparent;
}

QColor CloseButton::foregroundColor() const
{
    const auto *deco = qobject_cast<Decoration *>(decoration());
    if (!deco) {
        return {};
    }

    return deco->titleBarForegroundColor();
}

} // namespace Panda
