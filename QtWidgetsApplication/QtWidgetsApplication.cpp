#include "QtWidgetsApplication.h"

QtWidgetsApplication::QtWidgetsApplication(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1000, 650);

    scene = new graphicScene(this);
    view = new QGraphicsView(scene);

    group = new QGroupBox;
    vLayout = new QVBoxLayout;
    hLayout = new QHBoxLayout;
    
    rectangleButton = new QPushButton("Rectangle");
    connect(rectangleButton, &QPushButton::clicked,
        this, &QtWidgetsApplication::on_rectangleButton_clicked);

    ellipseButton = new QPushButton("Ellipse");
    connect(ellipseButton, &QPushButton::clicked,
        this, &QtWidgetsApplication::on_ellipseButton_clicked);

    triangleButton = new QPushButton("Triangle");
    connect(triangleButton, &QPushButton::clicked,
        this, &QtWidgetsApplication::on_triangleButton_clicked);

    lineButton = new QPushButton("Line");
    connect(lineButton, &QPushButton::clicked,
        this, &QtWidgetsApplication::on_lineButton_clicked);

    handButton = new QPushButton("Hand");
    connect(handButton, &QPushButton::clicked,
        this, &QtWidgetsApplication::on_handButton_clicked);

    hLayout->addWidget(rectangleButton);
    hLayout->addWidget(ellipseButton);
    hLayout->addWidget(triangleButton);
    hLayout->addSpacing(250);

    hLayout->addWidget(lineButton);
    hLayout->addWidget(handButton);
    hLayout->addSpacing(100);

    vLayout->addLayout(hLayout);
    vLayout->addWidget(view);
    group->setLayout(vLayout);
    setCentralWidget(group);
}

int QtWidgetsApplication::rando(int low, int high) {
    return (rand() % ((high + 1) - low) + low);
}

void QtWidgetsApplication::on_rectangleButton_clicked() {
    Figure* rect = new Figure;
    rect->setRect(0, 0, figureSize * 2, figureSize);

    int x = rando(0, rndFactor);
    int y = rando(0, rndFactor);

    for (int i = 0; i < 200; i++) {
        
        rect->moveBy(x, y);
        QList<QGraphicsItem*> collidingList = scene->collidingItems(rect);
        
        if (collidingList.size() == 0)
            break;
    }

    scene->addItem(rect);
    centralWidget()->setFocus();
}

void QtWidgetsApplication::on_ellipseButton_clicked() {
    gEllipse* ellipse = new gEllipse;
    ellipse->setRect(0, 0, figureSize * 2, figureSize);

    int x = rando(0, rndFactor);
    int y = rando(0, rndFactor);

    for (int i = 0; i < 200; i++) {

        ellipse->moveBy(x, y);
        QList<QGraphicsItem*> collidingList = scene->collidingItems(ellipse);

        if (collidingList.size() == 0)
            break;
    }

    scene->addItem(ellipse);
    centralWidget()->setFocus();
}

void QtWidgetsApplication::on_triangleButton_clicked() {
    QPolygon polygon;   
    gTriangle* triangle = new gTriangle;

    polygon << QPoint(0, -15) << QPoint(15, 15) << QPoint(-15, 15);
    triangle->setPolygon(polygon);

    int x = rando(0, rndFactor);
    int y = rando(0, rndFactor);

    for (int i = 0; i < 200; i++) {

        triangle->moveBy(x, y);
        QList<QGraphicsItem*> collidingList = scene->collidingItems(triangle);

        if (collidingList.size() == 0)
            break;
    }

    scene->addItem(triangle);
    centralWidget()->setFocus();
}

void QtWidgetsApplication::on_lineButton_clicked() {
    scene->isLineButtonPressed = true;
}

void QtWidgetsApplication::on_handButton_clicked() {
    scene->isLineButtonPressed = false;
}
