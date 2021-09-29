#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRectF>
#include <iomanip>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene * scene;
    Ui::MainWindow *ui;
    void keyPressEvent( QKeyEvent * event );
    void drawRect(QGraphicsScene * scene_now, int x1, int y1, int hight, int left, QBrush def = QColor(255, 255, 255));
};

#endif // MAINWINDOW_H
