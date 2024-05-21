
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "tree.h"
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
    Tree tree;
    QGraphicsScene *scene;
    QGraphicsView *graphicsView;
private slots:
    void Forming_tree();
    void Print_tree(tnode* root);
    void Print_Binary();
    void Print_MAX();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
