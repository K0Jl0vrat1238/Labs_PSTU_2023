Давыдов Андрей Юрьевич

Ивт-23-1Б

# 1 Вариант задания

Лабораторная работа - Дерево, вариант 9

Тип информационного поля double. Найти максимальный элемент в дереве.

# 2.1 Код програмы

## Заголовочные
```cpp

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

```
```cpp

#ifndef TREE_H
#define TREE_H
#include <QString>
#include <iostream>
#include <vector>

struct tnode {
    double data = 0;
    tnode* left = nullptr;
    tnode* right = nullptr;
    int x = 640;
    int y = 0;
    int num = 0;
};


class Tree{
    double max = 0;
    tnode* root = nullptr;
    std::vector<double> vector;
    int count = 0;
public:
    Tree() {}
    ~Tree() {}
    tnode* Add_node(double d, tnode* tree, int x, int y, int h);
    double MAX();
    void Create_tree(int cnt);
    tnode* get_root();
    int get_count();
    void Destroy_tree(tnode*);
    tnode* Balanced_tree(int, tnode*, int x, int y, int h);
    void set_count(int);
    void set_root(tnode*);
};

#endif // TREE_H

```
## Исходники

```cpp

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

```
```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QGraphicsTextItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Form_tree, SIGNAL(clicked()), this, SLOT(Forming_tree()));
    connect(ui->Binary_Btn, SIGNAL(clicked()), this, SLOT(Print_Binary()));
    connect(ui->Average_Btn, SIGNAL(clicked()), this, SLOT(Print_MAX()));

    graphicsView = ui -> graphicsView;
    scene = new QGraphicsScene;
    graphicsView -> setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Forming_tree(){
    int cnt_nodes = (ui->Count_nodes->text()).toInt();
    if (cnt_nodes < 2){
        qDebug() << "Количество узлов должно быть больше единицы";
        return;
    }
    tree.Create_tree(cnt_nodes);
    scene->clear();
    tnode* root = tree.get_root();
    Print_tree(root);
    ui->graphicsView->update();
}
void MainWindow::Print_tree(tnode* root){
    if (root != nullptr)
       {
           Print_tree(root->left);

           QString node = QString("%1").arg(root->data); //значние элемента узла
           QGraphicsEllipseItem *ellipse = scene->addEllipse(root->x, root->y, 46, 46, QPen(Qt::black), QBrush(Qt::lightGray)); // кружок
           QGraphicsTextItem *textItem = scene->addText(node);
           textItem->setPos(ellipse->boundingRect().center().x() - textItem->boundingRect().width() / 2,
                            ellipse->boundingRect().center().y() - textItem->boundingRect().height() / 2);

           if (root->left != nullptr)
           {
               int leftX = root->left->x;
               int leftY = root->left->y;

               int currentNodeX = root->x;
               int currentNodeY = root->y;

               QPointF leftCenter(leftX + 23, leftY + 23);//центр левого узла
               QPointF currentNodeCenter(currentNodeX + 23, currentNodeY + 23); //центр текущего узла

               scene->addLine(leftCenter.x(), leftCenter.y(), currentNodeCenter.x(), currentNodeCenter.y(), QPen(Qt::black)); //линия между узлами
               if(root->right != 0){
                   int rightX = root->right->x;
                   int rightY = root->right->y;
                   int currentNodeX = root->x;
                   int currentNodeY = root->y;

                   QPointF rightCenter(rightX + 23, rightY + 23);
                   QPointF currentNodeCenter(currentNodeX + 23, currentNodeY + 23);

                   scene->addLine(rightCenter.x(), rightCenter.y(), currentNodeCenter.x(), currentNodeCenter.y(), QPen(Qt::black));
               }
           }
           else if(root->right != 0){
               int rightX = root->right->x;
               int rightY = root->right->y;
               int currentNodeX = root->x;
               int currentNodeY = root->y;

               QPointF rightCenter(rightX + 23, rightY + 23);
               QPointF currentNodeCenter(currentNodeX + 23, currentNodeY + 23);

               scene->addLine(rightCenter.x(), rightCenter.y(), currentNodeCenter.x(), currentNodeCenter.y(), QPen(Qt::black));
           }
           ui->graphicsView->update();

           Print_tree(root->right);
       }
}

void MainWindow::Print_Binary(){
    int n = tree.get_count();
    tnode* r = tree.get_root();
    scene->clear();
    tree.Destroy_tree(r);
    r = tree.Balanced_tree(n, r, 640, 10, 250);
    tree.set_count(n);
    tree.set_root(r);
    Print_tree(r);
    ui->graphicsView->update();
}

void MainWindow::Print_MAX(){ // вывод максимального значения дерева
    double a = tree.MAX();
    QString node = QString("%1").arg(a);
    QString av = QString("Максимальное значение");
    QGraphicsTextItem *textItem2 = scene->addText(av);
    textItem2->setPos(580, -80);
    QGraphicsTextItem *textItem = scene->addText(node);
    textItem->setPos(640, -50);
}


```
```cpp
#include "tree.h"
#include <ctime>

tnode* Tree::Add_node(double d, tnode* tree, int x, int y, int h) {
    if (tree == nullptr) {
        tree = new tnode;
        tree->data = d;
        tree->x = x;
        tree->y = y;
        tree->num = ++count;
        if (root == nullptr) root = tree;
        if (max<d) max=d;
    }
    else if (tree->data > d) {
        tree->left = Add_node(d, tree->left, x - h, y + 50,h/2);
    }
    else {
        tree->right = Add_node(d, tree->right, x + h, y + 50,h/2);
    }
    return(tree);
}

double Tree::MAX() {
    return max;
}

void Tree::Create_tree(int cnt) { // создание дерева поиска
    srand(time(0));
    for (int i = 0; i < cnt; i++) {
        double d = (rand() % 1000 + 1);
        double d2 = (rand() % 100 + 1);
        double r = d / d2;
        vector.push_back(r);
        Add_node(r, root, 640, 10, 250);
    }
}
tnode* Tree::get_root(){
    return root;
}

void Tree::Destroy_tree(tnode*tree){
    if (tree->left != nullptr)   Destroy_tree(tree->left);
      if (tree->right != nullptr)  Destroy_tree(tree->right);
      delete tree;
}
tnode* Tree::Balanced_tree(int n, tnode* r, int x, int y, int h){ //преобразование в идеально сбалансированное
    tnode* new_root;
    int nl, nr;
    if(n == 0){
        r = nullptr;
        return r;
    }
    new_root = new tnode;
    new_root->data = vector[--count];
    new_root->x = x;
    new_root->y = y;
    nl = n/2;
    nr = n-nl-1;
    new_root->left = Balanced_tree(nl, new_root->left, x-h, y+50, h/2);
    new_root->right = Balanced_tree(nr, new_root->right, x+h, y+50, h/2);
    r = new_root;
    return r;
}
int Tree::get_count(){
    return count;
}
void Tree::set_count(int c){
    count = c;
}
void Tree::set_root(tnode* r){
    root = r;
}

```
# 2.2 UML
![](https://github.com/K0Jl0vrat1238/Labs_PSTU_2023/blob/main/Sem_2/TREE/img/Дерево.png?raw=true)

# 3 Видео работы