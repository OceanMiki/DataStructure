#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
    int data;//节点编号
    int level;//结点的度
    struct Node *left;
    struct Node *right;
} NODE, *PNODE;

PNODE create_node(int data, int level) {
    PNODE p = new NODE;
    p->data = data;
    p->level = level;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

int depth(PNODE p) {
    if (p) {
        return max(depth(p->left) + 1, depth(p->right));
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    PNODE *node = new PNODE[n];//结点数组，方便遍历和查找
    int *levels = new int[n];//度数组，对应结点数组
//    queue<PNODE> queue;
    for (int i = 0; i < n; ++i) {
        int data, level;
        cin >> data >> level;
        PNODE p = create_node(data, level);
        node[i] = p;
        levels[i] = level;
    }
    int index = 0;//双亲节点下标
    int cnt = 0;//记录为某个双亲找了cnt个孩子（判断孩子是否找完了）
    int j = 1;//遍历每个结点
    while (j < n) {
        if (levels[index] == 0 || cnt == levels[index]) {//双亲没有孩子（度为0）
            cnt = 0;//计数器清零，为下一个双亲找孩子准备
            index++;//定位下一个还没链接的双亲
            continue;//下面的是链接孩子链表，你都没孩子还链接个毛线
        }
        cnt++;//每链接1个孩子，就++
        if (cnt == 1) {//第一个孩子
            node[index]->left = node[j];
        } else {//其他孩子，即第一个孩子的兄弟，node[j - 1]就是第一个孩子结点
            node[j - 1]->right = node[j];
        }
        j++;
    }
    cout << depth(node[0]) - 1 << endl;//题目说根结点深度是0

    return 0;
}
