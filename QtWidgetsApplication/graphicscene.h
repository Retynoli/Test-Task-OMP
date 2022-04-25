#pragma once

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "figure.h"


class graphicScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit graphicScene( QObject* parent = nullptr);
    Figure* pressedItem = nullptr;
    Figure* targetItem = nullptr;
    Figure* markerRect = nullptr;

    QGraphicsLineItem* markerLine;

    bool isLineButtonPressed = false;
    bool isFigurePressed = false;
    bool isLineDrawing = false;

    QPointF m_shiftMouseCoords;


private:

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};
