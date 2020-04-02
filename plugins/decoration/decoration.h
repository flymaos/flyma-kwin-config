/*
 * Copyright (C) 2020 PandaOS Team.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

// KDecoration
#include <KDecoration2/Decoration>
#include <KDecoration2/DecorationButtonGroup>

// Qt
#include <QVariant>
#include <QIcon>

namespace Panda
{

class CloseButton;
class MaximizeButton;
class MinimizeButton;

class Decoration : public KDecoration2::Decoration
{
    Q_OBJECT

public:
    Decoration(QObject *parent = nullptr, const QVariantList &args = QVariantList());
    ~Decoration() override;

    void paint(QPainter *painter, const QRect &repaintRegion) override;

    QIcon closeIcon() { return m_closeIcon; };
    QIcon minimizeIcon() { return m_minimizeIcon; };
    QIcon maximizeIcon() { return m_maximizeIcon; };
    QIcon restoreIcon() { return m_restoreIcon; };

public slots:
    void init() override;

private:
    void updateBorders();
    void updateResizeBorders();
    void updateTitleBar();
    void updateButtonsGeometry();
    void updateShadow();

    int titleBarHeight() const;

    QColor titleBarBackgroundColor() const;
    QColor titleBarForegroundColor() const;

    bool radiusAvailable() const;

    void paintFrameBackground(QPainter *painter, const QRect &repaintRegion) const;
    void paintTitleBarBackground(QPainter *painter, const QRect &repaintRegion) const;
    void paintCaption(QPainter *painter, const QRect &repaintRegion) const;
    void paintButtons(QPainter *painter, const QRect &repaintRegion) const;

    KDecoration2::DecorationButtonGroup *m_leftButtons;
    KDecoration2::DecorationButtonGroup *m_rightButtons;

    friend class CloseButton;
    friend class MaximizeButton;
    friend class MinimizeButton;

private:
    int m_titleBarHeight = 30;
    QColor m_titleBarBgColor = QColor(255, 255, 255);
    QColor m_titleBarFgColor = QColor(51, 51, 51);

    QIcon m_closeIcon;
    QIcon m_minimizeIcon;
    QIcon m_maximizeIcon;
    QIcon m_restoreIcon;
};

}
