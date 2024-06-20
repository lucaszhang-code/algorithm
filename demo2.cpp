#include <vector>
#include <climits>
#include <queue>
#include <iostream>
using namespace std;

#define INFINITY  INT_MAX

// 表示最小生成树中的一条边，包含两个顶点vex1和vex2以及边的权重weight
struct MSTEdge {
    int vex1, vex2;
    int weight;
};

// 图的邻接矩阵，包含顶点数量vexnum和邻接矩阵adj，邻接矩阵是一个二维向量，每个元素表示两个顶点之间的边的权重
struct AdjGraph {
    int vexnum;
    vector<vector<int>> adj;
};

// 结构体表示图中的一条边，包含目标顶点to、起始顶点from和边的权重weight

struct Edge {
    int to;
    int from;
    int weight;
    // 重载>运算符，使得优先队列可以根据边的权重从小到大排序
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

MSTEdge* Prim_MST(AdjGraph *G, int start) {
    MSTEdge* TE = new MSTEdge[G->vexnum - 1];
    // 创建一个向量minCost，大小为vexnum，并初始化为INFINITY，用于存储每个顶点到当前生成树的最小边的权重
    vector<int> minCost(G->vexnum, INFINITY);
    // 创建一个向量inMST，大小为vexnum，并初始化为false，用于标记每个顶点是否已包含在生成树中
    vector<bool> inMST(G->vexnum, false);
    // 创建一个优先队列pq，用于存储边，并根据边的权重从小到大排序
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    minCost[start] = 0; // 将起始顶点的最小边权重设为0
    pq.push({start, -1, 0}); // 将起始顶点入队，起始顶点的from设为-1，表示无来源顶点

    int edgeCount = 0;

    while (!pq.empty() && edgeCount < G->vexnum - 1) {
        // 取出优先队列中的最小边
        Edge minEdge = pq.top();
        pq.pop();

        // 获取当前边的目标顶点
        int u = minEdge.to;

        // 如果目标顶点已包含在生成树中，则跳过该边
        if (inMST[u]) continue;
        // 将目标顶点标记为已包含在生成树中
        inMST[u] = true;

        // 如果当前边不是起始边，则将该边加入最小生成树的边数组
        if (minEdge.from != -1) { // 跳过初始节点的自身连接
            TE[edgeCount++] = {minEdge.from, u, minEdge.weight};
        }

        // 新邻接顶点的最小边权重
        for (int v = 0; v < G->vexnum; ++v) {
            if (!inMST[v] && G->adj[u][v] < minCost[v]) {
                minCost[v] = G->adj[u][v];
                pq.push({v, u, G->adj[u][v]});
            }
        }
    }

    return TE;
}

int main() {
    // 示例图初始化
    AdjGraph *graph = new AdjGraph;
    graph->vexnum = 4;
    graph->adj = {
            {0, 10, 6, 5},
            {10, 0, INFINITY, 15},
            {6, INFINITY, 0, 4},
            {5, 15, 4, 0}
    };

    // 调用Prim_MST函数
    MSTEdge* mst = Prim_MST(graph, 0);

    // 打印MST的边
    for (int i = 0; i < graph->vexnum - 1; ++i) {
        cout << "Edge: " << mst[i].vex1 << " - " << mst[i].vex2 << " Weight: " << mst[i].weight << endl;
    }

    // 释放动态分配的内存
    delete[] mst;

    return 0;
}
