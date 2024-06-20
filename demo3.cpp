#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Edge表示图的一条边，有两个顶点vex1和vex2及其权重weight
struct Edge {
    int vex1, vex2;
    int weight;
};

// ELGraph表示边列表图，有顶点数量vexnum和边数量edgenum，以及边的列表edgelist
struct ELGraph {
    int vexnum; // 顶点数量
    int edgenum; // 边数量
    vector<Edge> edgelist; // 边列表
};

// MSTEdge表示最小生成树中的一条边
struct MSTEdge {
    int vex1, vex2;
    int weight;
};

// 定义了一个比较函数，用于按边的权重进行排序
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

MSTEdge* Kruskal_MST(ELGraph* G) {
    MSTEdge* TE = new MSTEdge[G->vexnum - 1];   // TE：用于存放最小生成树的边
    vector<int> Vset(G->vexnum);    // 使用vector初始化为0到vexnum-1，表示每个顶点所属的集合
    iota(Vset.begin(), Vset.end(), 0);     // 初始化Vset数组，使得Vset[i] = i

    sort(G->edgelist.begin(), G->edgelist.end(), compareEdges); // 对表按权值从小到大排序

    int j = 0;
    int k = 0;

    /*
     * 找到当前权值最小的边的两个顶点所属的集合s1和s2。
     * 如果s1和s2不同，说明加入这条边不会形成环，将这条边加入到最小生成树中。
     * 更新Vset，将所有属于s2集合的顶点的集合编号改为s1。
     */
    while (k < G->vexnum - 1 && j < G->edgelist.size()) {
        int s1 = Vset[G->edgelist[j].vex1];
        int s2 = Vset[G->edgelist[j].vex2];

        // 若边的两个顶点的连通分量编号不同, 边加入到TE中
        if (s1 != s2) {
            TE[k].vex1 = G->edgelist[j].vex1;
            TE[k].vex2 = G->edgelist[j].vex2;
            TE[k].weight = G->edgelist[j].weight;
            k++;
            for (int v = 0; v < G->vexnum; v++) {
                if (Vset[v] == s2) Vset[v] = s1;
            }
        }
        j++;
    }

    return TE;
}
