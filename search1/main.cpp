#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} NODE, *PNODE;

PNODE createNode(int data) {
    auto p = new NODE;
    p->value = data;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

bool addNode(PNODE *r, int data) {
    if (nullptr == *r) {
        *r = createNode(data);
        cout << "NO" << endl;
        return false;//不存在顶点
    } else if ((*r)->value == data) {
        cout << "YES" << endl;
        return true;//存在
    } else if ((*r)->value < data) {
        return addNode(&(*r)->right, data);
    } else {
        return addNode(&(*r)->left, data);
    }
}

int main() {
    int n;
    cin >> n;
    PNODE root = nullptr;
    while (n--) {
        int data;
        cin >> data;
        addNode(&root, data);
    }
    return 0;
}
