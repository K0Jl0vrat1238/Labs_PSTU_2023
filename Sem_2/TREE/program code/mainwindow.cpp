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
