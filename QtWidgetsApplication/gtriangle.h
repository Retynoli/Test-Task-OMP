#pragma once

#include <QObject>
#include <QGraphicsPolygonItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QDebug>


class gTriangle : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT

public:
    enum { Type = UserType + 1 };
    int type() const
    {
        return Type;
    }

    explicit gTriangle(QObject* parent = 0);

    QList<QGraphicsLineItem*> lines;
    void adjustLines();
    void redrawLines();
    bool checkLines(QLineF testLine);
    QGraphicsLineItem* lineTo(gTriangle* targetItem);
};