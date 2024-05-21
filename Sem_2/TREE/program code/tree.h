
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
