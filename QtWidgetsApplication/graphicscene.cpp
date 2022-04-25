#include "graphicscene.h"


graphicScene::graphicScene(QObject* parent) : QGraphicsScene(parent)
{
    markerRect = new Figure;
    markerRect->setRect(0, 0, 10, 10);
    markerRect->setData(1, "marker");
    markerRect->hide();
    addItem(markerRect);

    markerLine = new QGraphicsLineItem;
    markerLine->hide();
    addItem(markerLine);
}


void graphicScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {

    pressedItem = static_cast<Figure*> (this->itemAt(event->scenePos().x(),
        event->scenePos().y(),
        QTransform()));
    
    if (pressedItem->data(1) != "figure")
        pressedItem = nullptr;

    targetItem = nullptr;

    if (pressedItem && !isLineButtonPressed) {

        isFigurePressed = true;
        m_shiftMouseCoords = pressedItem->pos() - event->scenePos();

    }
    else if (pressedItem && isLineButtonPressed && !isLineDrawing) {
        isFigurePressed = true;
        isLineDrawing = true;
        m_shiftMouseCoords = pressedItem->pos() - event->scenePos();
    }
}


void graphicScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {

    if (isLineDrawing && !targetItem) {
        isFigurePressed = false;
        isLineDrawing = false;
        markerRect->hide();
        markerLine->hide();
        targetItem = nullptr;
    }
    else if (isLineDrawing && targetItem != nullptr && pressedItem != nullptr) {

        isFigurePressed = false;
        isLineDrawing = false;
        markerRect->hide();
        markerLine->hide();

        QGraphicsLineItem* line;
        if (line = pressedItem->lineTo(targetItem)) {
            addItem(line);
        }
    }
    Q_UNUSED(event)
}


void graphicScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {

    if (pressedItem && isFigurePressed && !isLineDrawing) {

        if (pressedItem->lines.isEmpty() == false) {

            pressedItem->adjustLines();
            pressedItem->setPos(event->scenePos() + m_shiftMouseCoords);
            pressedItem->redrawLines();

        }
        else {
            pressedItem->setPos(event->scenePos() + m_shiftMouseCoords);
        }
    }
    else if (pressedItem && isFigurePressed && isLineDrawing) {
        markerRect->setPos(event->scenePos() + m_shiftMouseCoords);
        markerRect->show();

        QPointF dp1 = pressedItem->boundingRect().center();
        QPointF dp2 = markerRect->boundingRect().center();

        QPointF p1 = pressedItem->scenePos() + dp1;
        QPointF p2 = markerRect->scenePos() + dp2;

        if (markerRect->contains(p1) == false) {

            markerLine->setLine(QLineF(p1, p2));
            markerLine->show();
        }

        if (markerRect->collidingItems().at(0)->type() == Figure{}.type()
            && markerRect->collidingItems().at(0) != pressedItem
            && isLineDrawing)
        {
            targetItem = static_cast<Figure*>(markerRect->collidingItems().at(0));
        }
    }
}