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
