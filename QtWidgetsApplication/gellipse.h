#pragma once

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QDebug>

class gEllipse : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    enum { Type = UserType + 1 };
    int type() const
    {
        return Type;
    }

    explicit gEllipse(QObject* parent = 0);

    QList<QGraphicsLineItem*> lines;
    void adjustLines();
    void redrawLines();
    bool checkLines(QLineF testLine);
    QGraphicsLineItem* lineTo(gEllipse* targetItem);
};
