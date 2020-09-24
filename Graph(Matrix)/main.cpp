/**
 * Author : 陈海扬
 * Date : 2020/5/6 WED
 * Email : 18281003@bjtu.edu.cn
 */

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m;//顶点数和边数
int vertexList[500];//记录顶点的列表： 1、2、3...n
int edges[500][500];//邻接矩阵
bool isVisited1[500];//记录顶点是否被访问（dfs）
bool isVisited2[500];//记录顶点是否被访问（bfs）

/**
 * 为相邻的两个顶点v1、v2添加边
 * @param v1
 * @param v2
 * @param weight 权值
 */
void insertEdge(int v1, int v2, int weight) {
    edges[v1][v2] = weight;
    edges[v2][v1] = weight;
}

/**
 * 返回 index下标对应顶点的第一个邻接顶点
 * @param index 需要查找其第一个邻接顶点的顶点下标
 * @return 如果存在即返回第一个邻接顶点下标，否则返回-1
 */
int getFirstNeighbor(int index) {
    for (int i = 0; i < n; ++i) {
        if (edges[index][i] > 0) {
            return i;
        }
    }
    return -1;
}

/**
 * 已经找到 v1 的一个邻接顶点 v2 ，继续查找 v1 的下一个邻接顶点（顺序在 v2 之后）
 * @param v1
 * @param v2
 * @return 存在即返回下一个的下标，否则返回-1
 */
int getNextNeighbor(int v1, int v2) {
    for (int i = v2 + 1; i < n; ++i) {
        if (edges[v1][i] > 0) {
            return i;
        }
    }
    return -1;
}

/**
 * 深度优先搜索算法（只针对某个未被访问的顶点）
 * @param i 对该顶点dfs
 */
void dfs(int i) {
    cout << vertexList[i] << " ";
    isVisited1[i] = true;
    int w = getFirstNeighbor(i);
    while (w != -1) {
        if (!isVisited1[w]) {
            dfs(w);
        }
        w = getNextNeighbor(i, w);//w已经被访问
    }
}

/**
 * 重载dfs，遍历所有顶点（确保对每个顶点都dfs）
 */
void dfs() {
    for (int i = 0; i < n; ++i) {
        if (!isVisited1[i]) {
            dfs(i);
        }
    }
    cout << endl;
}

/**
 * 广度优先搜索算法（只针对某个未被访问的顶点）
 * @param i 对该顶点bfs
 * @return
 */
void bfs(int i) {
    int u;//队列头结点下标
    int w;//邻接顶点下标
    queue<int> queue;//记录顶点访问顺序的队列
    cout << vertexList[i] << " ";
    isVisited2[i] = true;//标记 i 被访问了
    queue.push(i);
    while (!queue.empty()) {
        u = queue.front();//从队列头开始
        queue.pop();//出队列
        w = getFirstNeighbor(u);//得到 u 的第一个邻接顶点
        while (w != -1) {//邻接顶点 w 存在
            if (!isVisited2[w]) {// w 还没被访问
                cout << vertexList[w] << " ";
                isVisited2[w] = true;//标记 w 被访问了
                queue.push(w);
            }
            w = getNextNeighbor(u, w);//找到 u 这个顶点在 w 之后的下一个邻接顶点
        }
    }
}

/**
 * 重载bfs，遍历所有顶点（确保对每个顶点都bfs）
 */
void bfs(){
    for (int i = 0; i < n; ++i) {
        if (!isVisited2[i]){
            bfs(i);
        }
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    memset(vertexList, 0, n);
    memset(edges, 0, sizeof(edges));

    for (int j = 0; j < n; ++j) {
        vertexList[j] = j + 1;//初始化顶点列表
    }

    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        insertEdge(v1 - 1, v2 - 1, 1);
    }
    bfs();
    dfs();
    return 0;
}
