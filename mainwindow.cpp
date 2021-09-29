#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

int clicks = 0;
bool rainbow = false;
QPen border(Qt::black);
QPen edge(Qt::cyan, 3);
QBrush fillMe(Qt::yellow);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->showMeWhatYouGot->setScene(scene);
}

void MainWindow::keyPressEvent( QKeyEvent * event )
{
    if( event->key() == Qt::Key_D)
    {
        std::cout << "pressed" << std::endl;
        --clicks;
        clicks = std::max(1, clicks);
    } else if (event->key() == Qt::Key_A){
        std::cout << "easy, broo" << std::endl;
        ++clicks;
        clicks = std::min(7, clicks);
    } else if (event->key() == Qt::Key_R) {
        rainbow = !rainbow;
    }
    drawRect(scene, 0,0, 729, clicks);
}

void MainWindow::drawRect(QGraphicsScene * scene_now, int x1, int y1, int hight, int left, QBrush def) {
    if (left == 0) return;
    QRectF rect = QRectF(x1, y1, hight, hight);
    QRectF center = QRectF(x1+hight/ 3, y1+hight/ 3, hight/ 3, hight /3);
    int r = 0, g = 0, b = 0;
    if (rainbow) {
        r = std::rand() % 255;
        g = std::rand() % 255;
        b = std::rand() % 255;
    }
    QBrush fillMe(QColor(r, g, b));

    if (left == 1) {
        QPen bordernow(fillMe.color());
        QPen whitePen(QColor(255, 255, 255));
        scene_now->addRect(rect, bordernow, fillMe);
        scene_now->addRect(center, whitePen, def);
    }

    drawRect(scene_now, x1, y1+hight / 3, hight / 3, left - 1);
    drawRect(scene_now, x1+hight / 3, y1, hight / 3, left - 1);
    drawRect(scene_now, x1+2*hight / 3, y1+2*hight / 3, hight / 3, left - 1);
    drawRect(scene_now, x1+2*hight / 3, y1+hight/3, hight / 3, left - 1);
    drawRect(scene_now, x1+2*hight / 3, y1, hight / 3, left - 1);
    drawRect(scene_now, x1, y1+2*hight / 3, hight / 3, left - 1);
    drawRect(scene_now, x1, y1, hight / 3, left - 1);
    drawRect(scene_now, x1+hight / 3, y1+2*hight / 3, hight / 3, left - 1);
}


MainWindow::~MainWindow()
{

    delete ui;
}

