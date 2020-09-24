#include <iostream>
#include <cstring>

using namespace std;

int n, m;//顶点数和边数
int matrix[500][500];//邻接矩阵
int isVisited[500];//记录顶点是否被访问

int prim(int v) {
    int res = 0;
    isVisited[v] = 1;
    int h1 = -1;//记录最短路径起点下标，可以用来输出（本题为梁山的军师）
    int h2 = -1;//记录最短路径终点下标
    int minWeight = 10000;//最小权值，默认501亦可
    for (int i = 1; i < n; ++i) {//总共 n - 1 条边
        //找到子图中已访问的顶点与其邻接顶点（未访问）中距离最小的
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (isVisited[j] == 1 && isVisited[k] == 0 && matrix[j][k] < minWeight) {
                    minWeight = matrix[j][k];//更新最小权值
                    h1 = j;//更新下标
                    h2 = k;
                }
            }
        }
        isVisited[h2] = 1;
        res += minWeight;
        minWeight = 10000;
    }
    return res;
}

int main() {
    cin >> n >> m;

    for (auto & j : matrix) {
        for (int & i : j) {
            i = 10000;
        }
    }

    for (int & k : isVisited) {
        k = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u - 1][v - 1] = matrix[v - 1][u - 1] = w;//创建邻接矩阵
    }

    cout << prim(0) << endl;
    return 0;
}
