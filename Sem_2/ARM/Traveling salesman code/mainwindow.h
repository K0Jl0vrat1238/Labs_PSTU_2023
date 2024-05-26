
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Graph graph;
    QGraphicsScene *scene;
    QGraphicsView *graphicsView;
    std::vector<QGraphicsEllipseItem*> ellipses = {0};
    std::vector<QGraphicsItemGroup*> arrows = {0};
public slots:
    void Add_edge();
    void Add_node();
    void Print_edge(int,int,int);
    void Delete_edge();
    void Delete_node();
    void Change_weight();
    void Commis();
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
