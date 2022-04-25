#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QDebug>


class Figure : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    enum { Type = UserType + 1 };
    int type() const
    {
        return Type;
    }

    explicit Figure(QObject* parent = 0);

    QList<QGraphicsLineItem*> lines;
    void adjustLines();
    void redrawLines();
    bool checkLines(QLineF testLine);
    QGraphicsLineItem* lineTo(Figure* targetItem);
};
