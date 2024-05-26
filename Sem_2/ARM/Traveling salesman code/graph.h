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
    int Comi();
};

#endif // GRAPH_H
