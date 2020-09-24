/**
 * Author : 陈海扬
 * Date : 2020/5/10 SUN
 * Email : 18281003@bjtu.edu.cn
 * 参考书籍 ： 《大话数据结构》
 */

#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
    int data;//邻接顶点编号
    struct Node *next;//下一个邻接顶点
} NODE, *PNODE;

typedef struct List {
    int vertex;//邻接表头顶点编号 1、2...n
    PNODE firstNode;//表头顶点的第一个邻接顶点
} LIST, *PLIST;

typedef struct Graph {
    LIST list[505];//邻接表数组
    int n, m;//顶点、边
    bool isVisited1[505];//dfs标志是否访问
    bool isVisited2[505];//bfs标志是否访问
} GRAPH, *PGRAPH;

void InitGraph(PGRAPH G) {
    cin >> G->n >> G->m;
    for (int i = 1; i <= G->n; ++i) {//题目给的编号是从 1 开始的。。。
        G->list[i].vertex = i;
        G->list[i].firstNode = nullptr;
    }
}

void CreateGraph(PGRAPH G) {
    PNODE p, q;
    for (int i = 0; i < G->m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        if (G->list[v1].firstNode == nullptr) {//v1的表还没有第一个邻接顶点
            q = new NODE;
            q->data = v2;
            q->next = nullptr;
            G->list[v1].firstNode = q;//v2 作 v1 的第一个邻接顶点
        } else if (v2 < G->list[v1].firstNode->data) {//处理一下 v2比第一个结点小的情况
            q = new NODE;
            q->data = v2;
            q->next = G->list[v1].firstNode;
            G->list[v1].firstNode = q;
        } else {
            p = G->list[v1].firstNode;
            while (p->next && v2 > p->next->data) {//链接新顶点(注意顺序，从小到大)
                p = p->next;
            }
            q = new NODE;
            q->data = v2;
            q->next = p->next;
            p->next = q;
        }
        //牛顿第三定律
        if (G->list[v2].firstNode == nullptr) {//v2的表还没有第一个邻接顶点
            q = new NODE;
            q->data = v1;
            q->next = nullptr;
            G->list[v2].firstNode = q;//v1 作 v2 的第一个邻接顶点
        }
        else if (v1 < G->list[v2].firstNode->data){//处理一下 v1比第一个结点小的情况
            q = new NODE;
            q->data = v1;
            q->next = G->list[v2].firstNode;
            G->list[v2].firstNode = q;
        }
        else {
            p = G->list[v2].firstNode;
            while (p->next && v1 > p->next->data) {//链接新顶点(注意顺序，从小到大)
                p = p->next;
            }
            q = new NODE;
            q->data = v1;
            q->next = p->next;
            p->next = q;
        }
    }
}

/**
 * 深度优先搜索算法（只针对某个未被访问的顶点）
 * @param G 图
 * @param i 顶点编号
 */
void dfs(PGRAPH G, int i) {
    cout << G->list[i].vertex << " ";
    G->isVisited1[i] = true;
    PNODE p = G->list[i].firstNode;
    while (p) {
        if (!G->isVisited1[p->data]) {
            dfs(G, p->data);
        }
        p = p->next;
    }
}

/**
 * 重载dfs，遍历所有顶点（确保对每个顶点都dfs）
 */
void dfs(PGRAPH G) {
    for (int i = 1; i <= G->n; ++i) {//编号从 1 开始
        if (!G->isVisited1[i]) {
            dfs(G, i);
        }
    }
    cout << endl;
}

/**
 * 广度优先搜索算法（只针对某个未被访问的顶点）
 * @param G
 * @param i
 */
void bfs(PGRAPH G, int i) {
    PNODE p;
    queue<int> queue;//记录访问顺序的队列
    cout << G->list[i].vertex << " ";
    G->isVisited2[i] = true;
    queue.push(i);
    while (!queue.empty()) {
        int tmp = queue.front();//得到队列头
        queue.pop();//出队
        p = G->list[tmp].firstNode;
        while (p) {
            if (!G->isVisited2[p->data]) {
                cout << G->list[p->data].vertex << " ";
                G->isVisited2[p->data] = true;
                queue.push(p->data);//每访问一个后就将这个顶点入队
            }
            p = p->next;
        }
    }
}

/**
 * 重载 bfs，遍历所有顶点（确保对每个顶点都 bfs）
 * @param G
 */
void bfs(PGRAPH G) {
    for (int i = 1; i <= G->n; ++i) {
        if (!G->isVisited2[i]) {
            bfs(G, i);
        }
    }
    cout << endl;
}

int main() {
    auto graph = new GRAPH;
    InitGraph(graph);
    CreateGraph(graph);
    bfs(graph);
    dfs(graph);
    return 0;
}
