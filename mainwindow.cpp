#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include "point.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseReleaseEvent (QMouseEvent *event)
{
    int size = arr.size();
    for(int i = 0; i < size; i++)
    {
        Point *point = arr.at(i);
        if(point->getisdragg())
        {
            point->setisdragg(false);
        }
    }
    repaint();
}
void MainWindow::mouseMoveEvent (QMouseEvent *event)
{
    int size = arr.size();
    bool existsDragged = false;
    for(int i = 0; i < size; i++)
    {
        Point *point = arr.at(i);
        if(point->getisdragg())
        {
            point->setX(point->getX()+(event->x()-x));
            point->setY(point->getY()+(event->y()-y));
            existsDragged = true;
        }
    }
    if(existsDragged){
        x = event->x();
        y = event->y();
    }
    repaint();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(arr.size())
         for(int i = 0; i <(int)arr.size();i++)
         {
             Point *point = arr.at(i);
             point->draw(&painter);
             if(i)
             {
                 point->connectPoints(&painter,arr.at(i - 1));
             }
         }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    int size = arr.size();
    QPoint clickPoint;
    clickPoint.setX(event->x());
    clickPoint.setY(event->y());
    bool doNotCreate = false;
    for(int i = 0; i < size; i++)
    {
        Point *point = arr.at(i);
       if(point->distance2(clickPoint) <= 5)
       {
          point->setisdragg(true);
          x = event->x();
          y = event->y();
          doNotCreate = true;
          break;
        }
     }
        if(!doNotCreate)
        {
            Point *point = new Point(event->x(),event->y());
            arr.push_back(point);
        }
        repaint();
    }
