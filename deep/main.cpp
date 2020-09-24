#include <iostream>

using namespace std;

typedef struct Node {
    char data;
    struct Node *firstChild;
    struct Node *nextSibling;
} NODE, *PNODE;

typedef struct value {
    int val = 0;
    struct value *left = nullptr;
    struct value *right = nullptr;
} VALUE, *PVAL;

void sort(PVAL value){
    if(value){
        sort(value->right);
        cout << value->val << endl;
        sort(value->left);
    }
}

int TreeDegree(PNODE T) /* 统计树中度为1的结点数*/
{
    int h1, h2;
    if (!T)
        return 0;
    else {
        h1 = TreeDegree(T->firstChild);
        h2 = TreeDegree(T->nextSibling);
        if (T->firstChild && !T->firstChild->nextSibling)
            return (h1 + h2 + 1);
        else
            return (h1 + h2);
    }
}

int main() {
//    auto root = new NODE;
//    auto n1 = new NODE;
//    auto n2 = new NODE;
//    auto n3 = new NODE;
//    auto n4 = new NODE;
//    root->data = 'A';
//    root->firstChild = n1;
//    root->nextSibling = nullptr;
//    n1->data = 'B';
//    n1->nextSibling = n2;
//    n1->firstChild = n4;
//    n4->firstChild = nullptr;
//    n4->nextSibling = nullptr;
//    n2->data = 'C';
//    n2->nextSibling = n3;
//    n2->firstChild = nullptr;
//    n3->data = 'D';
//    n3->firstChild = nullptr;
//    n3->nextSibling = nullptr;
//    cout << TreeDegree(root) << endl;

    PVAL root = new VALUE;
    root->val = 2;
    PVAL l = new VALUE ;
    l->val = 1;
    PVAL r = new VALUE ;
    r->val = 3;
    root->left = l;
    root->right = r;
    sort(root);

    return 0;
}