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
