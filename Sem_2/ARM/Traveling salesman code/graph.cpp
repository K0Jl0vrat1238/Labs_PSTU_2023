
#include "graph.h"
#include<stack>
#include<set>
#include<cmath>
#include<map>
#include <algorithm>

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
int Graph::Comi(){//FIX
    int s = 1;
    std::vector<int> vertex = {0};
    for (int i = 1; i < vertices.size(); i++){
        if (i != s){
             vertex.push_back(i);
        }
    }
    int sum = 99999999;
    do {
        int current_pathweight = 0;
        int k = s   ;
        for (int i = 1; i < vertex.size(); i++) {
            if(k!=0){
                current_pathweight += Matrix[k][vertex[i]];
                k = vertex[i];
            }
        }
        if (k!=0){
            current_pathweight += Matrix[k][s];
            if(sum > current_pathweight){
                sum = current_pathweight;
            }
        }


    } while (next_permutation(vertex.begin(), vertex.end()));

    return sum;
}
