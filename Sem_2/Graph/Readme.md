Давыдов Андрей Юрьевич

Ивт-23-1Б

# 1 Вариант задания

Лабораторная работа - Графы, вариант 9

Реализовать граф, а также алгоритм обхода графа в ширину (выполнение с вершины 3)

# 2.1 Код программы

### Заголовочные
```cpp
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

public slots:
    void Add_edge();
    void Add_node();
    void Print_edge(int,int,int);
    void Delete_edge();
    void Delete_node();
    void Change_weight();
    void Width_traversal();
    void Deep_crawl();
    void Dijkstra_algorithm();
private:
    Ui::MainWindow *ui;
    Graph graph;
    QGraphicsScene *scene;
    QGraphicsView *graphicsView;
    std::vector<QGraphicsEllipseItem*> ellipses = {0};
    std::vector<QGraphicsItemGroup*> arrows = {0};
};
#endif // MAINWINDOW_H
```
```cpp
#ifndef GRAPH_H
#define GRAPH_H

#include<vector>
#include <queue>
#include<iostream>

class Graph{
std::vector<int> vertices{0};
int** Matrix;
int Matrix_size = 1;
public:
    Graph();
    void Add_Vertice();
    void Add_Edge(int,int,int);
    void Delete_Vertice(int);
    void Delete_Edge(int,int);
    int Get_matrix_size();
    int** Get_matrix();
    std::vector<int> BFS(int);
    std::vector<int> DFS(int);
    std::vector<int> Dijkstra(int, int);
};

#endif // GRAPH_H
```
### Исходники
```cpp
#include "graph.h"
#include<stack>
#include<set>
#include<cmath>
#include<map>

Graph::Graph(){

}
void Graph::Add_Vertice(){
    vertices.push_back(vertices.size());
    int c = vertices.size();
    int** Matrix_temp = new int* [c];
    for (int i = 0; i < c; i++) {
        Matrix_temp[i] = new int[c];
        for (int j = 0; j < c; j++) {
            if (i < Matrix_size and j < Matrix_size and c >2) {
                Matrix_temp[i][j] = Matrix[i][j];
            }
            else {
                Matrix_temp[0][j] = j;
                Matrix_temp[i][0] = i;
                Matrix_temp[i][j] = 0;
            }
        }
    }
    Matrix = Matrix_temp;
    Matrix_size++;
}
void Graph::Add_Edge(int name_1,int name_2,int weight){
    Matrix[name_1][name_2] = weight;
}
void Graph::Delete_Vertice(int name){
    vertices[name] = 0;
    for(int i = 0; i<Matrix_size;i++){
         Matrix[name][i] = 0;
         Matrix[i][name] = 0;
    }
}
void Graph::Delete_Edge(int name_1,int name_2){
     Matrix[name_1][name_2] = 0;
}
int Graph::Get_matrix_size(){
    return Matrix_size;
}
int** Graph::Get_matrix(){
    return Matrix;
}
std::vector<int> Graph::BFS(int start_vertex) {
    if (start_vertex > vertices.size() or start_vertex <= 0){
        return {};
    }
    std::vector<int> enter_order;
    std::vector<short> visited(vertices.size());
    std::queue<int> q;

    // Функция принимает вершину, нумерация которой начинается с 1
    // Для удобства уменьшаем ее значение на 1, чтобы нумерация начиналась с 0
    visited[start_vertex] = true;
    q.push(start_vertex);
    enter_order.emplace_back(start_vertex);

    while (!q.empty()) {
        auto from = q.front();
        q.pop();

        for (int to = 1, size = vertices.size(); to < size; to++) {
            if (!visited[to] and Matrix[from][to] != 0) {
                visited[to] = true;
                q.push(to);
                enter_order.emplace_back(to);
            }
        }
    }
    return enter_order;
}
std::vector<int> Graph::DFS(int start_vertex){
    if (start_vertex > vertices.size() or start_vertex <= 0){
        return {};
    }
    std::vector<int> enter_order;
    std::vector<short> visited(vertices.size());
    std::stack<int> s;


    visited[start_vertex] = true;
    s.push(start_vertex);
    enter_order.emplace_back(start_vertex);

    while (!s.empty()) {
        auto from = s.top();
        bool is_found = false;

        for (int to = 1, size = vertices.size(); to < size; to++) {
            if (!visited[to] and Matrix[from][to] != 0) {
                visited[to] = true;
                is_found = true;
                s.push(to);
                enter_order.emplace_back(to);
                from = to;
            }
        }
        if(!is_found){
            s.pop();
        }
    }
    return enter_order;
}
std::vector<int> Graph::Dijkstra(int start, int finish){
    if (start <= 0 or finish <= 0 or start > vertices.size() or finish > vertices.size()){
        return{};
    }
    int big = 9999999;
    std::vector<int> enter_order(vertices.size());
    std::vector<int> distance(vertices.size(), big);
    distance[start] = 0;

    std::set<std::pair<int, int>> q;
    q.insert({distance[start], start});

    while (!q.empty()) {
        auto from = q.begin()->second;
        q.erase(q.begin());

        for (int to = 1; to < vertices.size(); to++) {
            bool edge_is_exists = Matrix[from][to] != 0;
            bool new_edge_is_shorter = distance[to] > distance[from] + Matrix[from][to];

            if (edge_is_exists and new_edge_is_shorter) {
                q.erase({distance[to], to});
                distance[to] = distance[from] + Matrix[from][to];
                q.insert({distance[to], to});
            }
        }
    }

    int end =vertices.size()-1;
    enter_order[1]=end+1;
    int weight = distance[finish];
    int k = 1;
    while(end!=start){
        for(int i = 1; i < vertices.size(); i++){
            int temp = weight - Matrix[i][end];
            if(temp == distance[i]){
                weight = temp;
                end = i;
                enter_order[k] = i;
                k++;
            }
        }
    }
    enter_order.push_back(distance[finish]);

    return enter_order;
}
```
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
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <qmath.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Add_Node_Btn, SIGNAL(clicked()),this,SLOT(Add_node()));
    connect(ui->Add_Edge_Btn, SIGNAL(clicked()), this,SLOT(Add_edge()));
    connect(ui->Delete_Edge_Btn, SIGNAL(clicked()), this, SLOT(Delete_edge()));
    connect(ui->Delete_Node_Btn, SIGNAL(clicked()), this, SLOT(Delete_node()));
    connect(ui->Change_weight_Btn, SIGNAL(clicked()), this, SLOT(Change_weight()));
    connect(ui->Width_traversal_Btn, SIGNAL(clicked()), this, SLOT(Width_traversal()));
    connect(ui->Deep_crawl_Btn, SIGNAL(clicked()), this, SLOT(Deep_crawl()));
    connect(ui->Dijkstra_Btn, SIGNAL(clicked()), this, SLOT(Dijkstra_algorithm()));

    graphicsView = ui -> graphicsView;
    scene = new QGraphicsScene;
    graphicsView -> setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Add_node(){
    graph.Add_Vertice();
    QString node = QString("%1").arg(graph.Get_matrix_size()-1);
    QGraphicsEllipseItem *ellipse = scene->addEllipse(640, 275, 50, 50, QPen(Qt::black), QBrush(Qt::lightGray));
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    QGraphicsTextItem *textItem = scene->addText(node);
    textItem->setPos(ellipse->boundingRect().center().x() - textItem->boundingRect().width() / 2,
                     ellipse->boundingRect().center().y() - textItem->boundingRect().height() / 2);
    textItem->setParentItem(ellipse);
    scene->installEventFilter(this);
    ellipses.push_back(ellipse);
}
void MainWindow::Add_edge(){
    if((ui->Output_lineEdit->text() == "") or (ui->Input_lineEdit->text() == "") or (ui->weight_lineEdit->text() =="")){
        qDebug() << "Не все поля заполнены";
        return;
    }
    int out = (ui->Output_lineEdit->text()).toInt();
    int in = (ui->Input_lineEdit->text()).toInt();
    int weight = (ui->weight_lineEdit->text()).toInt();
    if(out < 1 or in < 1 or weight < 1){
        qDebug() << "ни какое из значений не может быть меньше единицы";
        return;
    }
    if(graph.Get_matrix_size()-1 < out or graph.Get_matrix_size()-1 < in){
        qDebug() << "Таких(ой) вершин(ы) нет";
        return;
    }
    graph.Add_Edge(out, in, weight);
    Print_edge(out, in, weight);
}
void MainWindow::Print_edge(int ou, int inn, int we){
    if(we == 0){
        return;
    }
    int out = ou;
    int in = inn;
    int weight = we;


    if(in != out){                        //стрелка
        QGraphicsEllipseItem *out_ellipse = ellipses[out];
        QGraphicsEllipseItem *in_ellipse = ellipses[in];

        QPointF center1 = out_ellipse->mapToScene(out_ellipse->boundingRect().center());
        QPointF center2 = in_ellipse->mapToScene(in_ellipse->boundingRect().center());


        qreal angle = qAtan2(center2.y() - center1.y(), center2.x() - center1.x());

        QPointF new_out(center1.x() + 25 * qCos(angle), center1.y() + 25 * qSin(angle));
        QPointF new_in(center2.x() + 25 * qCos(angle + M_PI), center2.y() + 25 * qSin(angle + M_PI));

        QGraphicsLineItem *line1 = new QGraphicsLineItem();
        line1->setLine(QLineF(new_out, new_in));
        scene->addItem(line1);

        QPolygonF arrowHead;

        qreal angle_arrow = qAtan2(new_in.y() - new_out.y(), new_in.x() - new_out.x());
        qreal arrowLength = 10.0;

        qreal arrowAngle = M_PI / 6.0;

        QPointF arrowP1 = new_in - QPointF(arrowLength * std::cos(angle_arrow + arrowAngle), arrowLength * std::sin(angle_arrow + arrowAngle));
        QPointF arrowP2 = new_in - QPointF(arrowLength * std::cos(angle_arrow - arrowAngle), arrowLength * std::sin(angle_arrow - arrowAngle));

        arrowHead << new_in << arrowP1 << arrowP2;

        QGraphicsPolygonItem *arrow1 = new QGraphicsPolygonItem(arrowHead);
        arrow1->setBrush(Qt::black);
        arrow1->setPen(Qt::NoPen);
        scene->addItem(arrow1);

        QPointF textPos2 = arrowP2;
        QGraphicsTextItem* textItem2 = scene->addText(QString::number(weight));
        textItem2->setPos(textPos2);

        QList<QGraphicsItem*> items;
        items << arrow1 << textItem2 <<line1;
        QGraphicsItemGroup *group = scene->createItemGroup(items);
        arrows.push_back(group);

        out_ellipse->setFlag(QGraphicsItem::ItemIsMovable, false);
        in_ellipse->setFlag(QGraphicsItem::ItemIsMovable, false);
    }

    if(in == out){                                      //петля
         QGraphicsEllipseItem *ellipse = ellipses[out];

         QPointF center = ellipse->mapToScene(ellipse->boundingRect().center());

         qreal radius = ellipse->boundingRect().width() / 2.0;

         qreal angle_loop = 45 * M_PI / 180;

         QPointF start(center.x() + radius * qCos(angle_loop), center.y() + radius * qSin(angle_loop));
         QPointF end(center.x() + radius * qCos(angle_loop + M_PI), center.y() + radius * qSin(angle_loop + M_PI));

         radius *= 4;

         QPointF controlPoint1(center.x() + radius * qCos(angle_loop - M_PI / 4), center.y() + radius * qSin(angle_loop - M_PI / 4));
         QPointF controlPoint2(center.x() + radius * qCos(angle_loop + M_PI + M_PI / 4), center.y() + radius * qSin(angle_loop + M_PI + M_PI / 4));

         QPainterPath loopPath;
         loopPath.moveTo(start);
         loopPath.cubicTo(controlPoint1, controlPoint2, end);
         scene->addPath(loopPath);


         QPointF textPos2(center.x() + radius * qCos(angle_loop + M_PI + M_PI / 4), center.y() + 25 + radius * qSin(angle_loop + M_PI + M_PI / 4));
         QGraphicsTextItem* textItem2 = scene->addText(QString::number(weight));
         textItem2->setPos(textPos2);

         QGraphicsPathItem *loopItem = new QGraphicsPathItem(loopPath);

         QList<QGraphicsItem*> items;
         items << loopItem << textItem2;
         QGraphicsItemGroup *group = scene->createItemGroup(items);
         arrows.push_back(group);


         ellipse->setFlag(QGraphicsItem::ItemIsMovable, false);
    }
}
void MainWindow::Delete_edge(){
    if(ui->Output_Delete_lineEdit->text() == "" or ui->Input_Delete_lineEdit->text() == ""){
        qDebug() <<"Заполните все поля";
        return;
    }
    int out = (ui->Output_Delete_lineEdit->text()).toInt();
    int in = (ui->Input_Delete_lineEdit->text()).toInt();
    if(graph.Get_matrix_size()-1 < out or graph.Get_matrix_size()-1 < in){
        qDebug() << "Таких(ой) вершин(ы) нет";
        return;
    }
    int** matrix = graph.Get_matrix();
    if(matrix[out][in] == 0){
        qDebug() << "Такого ребра нет";
        return;
    }
    graph.Delete_Edge(out, in);
    matrix = graph.Get_matrix();
    for (unsigned long long int i = 0; i < arrows.size(); i++){
        scene->removeItem(arrows[i]);
        delete arrows[i];
    }
    arrows.clear();
    for(int i = 1; i< graph.Get_matrix_size(); i++){
        for(int j = 1; j < graph.Get_matrix_size(); j++){
                Print_edge(i, j, matrix[i][j]);
        }
    }
}
void MainWindow::Delete_node(){
    if(ui->Delete_node_lineEdit->text() == ""){
        qDebug() <<"Заполните все поля";
        return;
    }
    int node = (ui->Delete_node_lineEdit->text()).toInt();
    if(node > graph.Get_matrix_size()){
        qDebug() << "Такой вершины нет";
        return;
    }
    for (unsigned long long int i = 0; i < ellipses.size(); i++){
        if(node == i){
            scene->removeItem(ellipses[i]);
            ellipses[i] = 0;
        }
    }
    for (int i = 1; i < graph.Get_matrix_size(); i++) {
        for (int j = 1; j < graph.Get_matrix_size(); j++) {
            if(i == node or j == node){
                graph.Delete_Edge(i, j);
            }
        }
    }
    for (unsigned long long int i = 0; i < arrows.size(); i++){
        scene->removeItem(arrows[i]);
        delete arrows[i];
    }
    arrows.clear();
    int** matrix = graph.Get_matrix();
    for(int i = 1; i< graph.Get_matrix_size(); i++){
        for(int j = 1; j < graph.Get_matrix_size(); j++){
                Print_edge(i, j, matrix[i][j]);
        }
    }
}
void MainWindow::Change_weight(){
    if((ui->Output_lineEdit->text() == "") or (ui->Input_lineEdit->text() == "") or (ui->weight_lineEdit->text() =="")){
        qDebug() << "Не все поля заполнены";
        return;
    }
    int out = (ui->Output_lineEdit->text()).toInt();
    int in = (ui->Input_lineEdit->text()).toInt();
    int weight = (ui->weight_lineEdit->text()).toInt();
    if(out < 1 or in < 1 or weight < 1){
        qDebug() << "ни какое из значений не может быть меньше единицы";
        return;
    }
    if(graph.Get_matrix_size()-1 < out or graph.Get_matrix_size()-1 < in){
        qDebug() << "Таких(ой) вершин(ы) нет";
        return;
    }
    graph.Add_Edge(out, in, weight);
    for (unsigned long long int i = 0; i < arrows.size(); i++){
        scene->removeItem(arrows[i]);
        delete arrows[i];
    }
    arrows.clear();
    int** matrix = graph.Get_matrix();
    for(int i = 1; i< graph.Get_matrix_size(); i++){
        for(int j = 1; j < graph.Get_matrix_size(); j++){
                Print_edge(i, j, matrix[i][j]);
        }
    }
}
void MainWindow::Width_traversal(){
    ui->Output_algoritms->clear();
    int start = (ui->Wide_lineEdit->text()).toInt();
    std::vector<int> BFS;
    BFS = graph.BFS(start);
    QString result;
    for(int i = 0; i < BFS.size();i++){
        result.append(QString::number(BFS[i]));
        if (i < BFS.size()){
            result.append(", ");
        }
    }
    ui->Output_algoritms->setText(result);
}
void MainWindow::Deep_crawl(){
    ui->Output_algoritms->clear();
    int start = (ui->Deep_lineEdit->text()).toInt();
    std::vector<int> DFS;
    DFS = graph.DFS(start);
    QString result;
    for(int i = 0; i < DFS.size();i++){
        result.append(QString::number(DFS[i]));
        if (i < DFS.size()){
            result.append(", ");
        }
    }
    ui->Output_algoritms->setText(result);
}
void MainWindow::Dijkstra_algorithm(){
    ui->Output_algoritms->clear();
    int start = (ui->Dijkstra_start_lineEdit->text()).toInt();
    int end = (ui->Dijkstra_end_lineEdit->text()).toInt();
    std::vector<int> D;
    D = graph.Dijkstra(start, end);
    QString result;
    for(int i = D.size()-2; i > 0; i--){
        if(D[i]!=0){
            result.append(QString::number(D[i]));
            if (i > 0 + 1){
                result.append("->");
            }
        }
    }
    result.append("  Кратчайший маршрут = ");
    result.append(QString::number(D[D.size()-1]));
    ui->Output_algoritms->setText(result);
}

```
# 2.2 UML
![](https://github.com/K0Jl0vrat1238/Labs_PSTU_2023/blob/main/Sem_2/Graph/img/Граффы.png?raw=True)
# 3 Демонстрация работы
https://www.youtube.com/watch?v=lJYsiGKaZJY