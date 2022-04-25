#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsView>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QEvent>

#include "graphicscene.h"
#include "gtriangle.h"
#include "gellipse.h"
#include "figure.h"


class QtWidgetsApplication : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget *parent = Q_NULLPTR);

    graphicScene* scene;
    QGraphicsView* view;

    QPushButton* rectangleButton;
    QPushButton* ellipseButton;
    QPushButton* triangleButton;
    QPushButton* lineButton;
    QPushButton* handButton;

    QVBoxLayout* vLayout;
    QHBoxLayout* hLayout;
    QGroupBox* group;


protected slots:
    void on_rectangleButton_clicked();
    void on_triangleButton_clicked();
    void on_ellipseButton_clicked();
    void on_lineButton_clicked();
    void on_handButton_clicked();

private:
    int figureSize = 30;
    int rndFactor = 250;
    int rando(int low, int high);
};
