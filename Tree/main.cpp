#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE, *PNODE;

typedef struct tree {
    struct node *root;
} TREE, *PTREE;

void init_tree(PTREE tree, int root) {
    tree->root = new NODE;
    tree->root->data = root;
    tree->root->left = nullptr;
    tree->root->right = nullptr;
}

void create_node(PNODE node, int child) {
    if (node->left) {//已经有了第一个孩子
        PNODE tmp = new NODE;
        tmp = node->left;//找到第一个孩子
        while (tmp->right) {
            tmp = tmp->right;
        }
        tmp->right = new NODE;
        tmp->right->data = child;
        tmp->right->left = nullptr;
        tmp->right->right = nullptr;
    } else {//还没有第一个孩子
        node->left = new NODE;
        node->left->data = child;
        node->left->left = nullptr;
        node->left->right = nullptr;
    }
}

PNODE find_parent(PNODE pnode, int parent) {
    if (pnode->data == parent) {
        return pnode;
    }
    PNODE res = new NODE;
    if (pnode->left) {
        res = find_parent(pnode->left, parent);
    }
    if (res->data == parent) {
        return res;
    }
    if (pnode->right) {
        res = find_parent(pnode->right, parent);
    }
    return res;
}

//void preOrder_traverse(PNODE node) {//先序遍历，妈的被第一个测试用例骗了
//    if (node) {
//        if (node->left) {
//            cout << node->left->data;
//        } else {
//            cout << 0;
//        }
//        cout << " ";
//        if (node->right) {
//            cout << node->right->data;
//        } else {
//            cout << 0;
//        }
//        cout << endl;
//    }
//    if (node->left) {
//        preOrder_traverse(node->left);
//    }
//    if (node->right) {
//        preOrder_traverse(node->right);
//    }
//}

void show(PNODE node){
    if (node) {
        if (node->left) {
            cout << node->left->data;
        } else {
            cout << 0;
        }
        cout << " ";
        if (node->right) {
            cout << node->right->data;
        } else {
            cout << 0;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    PTREE tree = new TREE;
    init_tree(tree, 1);
    for (int i = 0; i < n - 1; ++i) {
        int parent, child;
        cin >> parent >> child;
        PNODE p = find_parent(tree->root, parent);
        create_node(p, child);
    }
    for (int j = 1; j <= n; ++j) {
        PNODE node = find_parent(tree->root,j);
        show(node);
    }
    return 0;
}
