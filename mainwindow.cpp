#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "point.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    Point *pp = new Point(event->x(), event->y());
    if (n<10)
    {
        p[n] = pp;
        repaint();
        n++;
    }
    qDebug("x=%d, y=%d", pp->getX(), pp->getY());
}
void MainWindow::paintEvent(QPaintEvent *event){
        QPainter painter (this);
        Point *pp = p[n];
        QPen pen(Qt::black);
        pen.setWidth(3);
        painter.setPen(pen);
        if (pp){
            for (int i=0; i<=n; i++) {
                painter.drawLine(pp->getX(),pp->getY()-1, pp->getX(),pp->getY()+1);
                painter.drawLine(pp->getX()-1,pp->getY(), pp->getX()+1,pp->getY());
            }
        }
}
MainWindow::~MainWindow()
{
    delete ui;
}
