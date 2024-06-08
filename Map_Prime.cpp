#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Vertex {
    int val;
    Vertex(int value) : val(value) {}
};

// 使用邻接表表示图的类
class GraphAdjList {
private:
    // 邻接表：将每个顶点映射到一个邻居和权重的对的列表
    unordered_map<Vertex*, vector<pair<Vertex*, int>>> adjList;

public:
    // 构造函数，用给定的边初始化图
    GraphAdjList(vector<tuple<Vertex*, Vertex*, int>> &edges) {
        for (auto &edge : edges) {
            addVertex(get<0>(edge));
            addVertex(get<1>(edge));
            addEdges(get<0>(edge), get<1>(edge), get<2>(edge));
        }
    }

    // 添加顶点到邻接表
    void addVertex(Vertex* vet) {
        if (adjList.count(vet)) return;
        adjList[vet] = vector<pair<Vertex*, int>>();
    }

    // 添加带权重的边到两个顶点之间
    void addEdges(Vertex* vet1, Vertex* vet2, int weight) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2) return;
        adjList[vet1].emplace_back(vet2, weight);
        adjList[vet2].emplace_back(vet1, weight);
    }

    // 使用Prim算法找到最小生成树
    void graphPrime() {
        // 假设图是连通且无向的
        // 定义了一个最小堆（优先队列），用于存储顶点及其对应的key值，优先处理key值最小的顶点
        priority_queue<pair<int, Vertex*>, vector<pair<int, Vertex*>>, greater<pair<int, Vertex*>>> minHeap;
        // 用于跟踪已经包含在最小生成树中的顶点
        unordered_set<Vertex*> inMST;
        // 用于记录每个顶点在最小生成树中的父节点
        unordered_map<Vertex*, Vertex*> parent;
        // 用于记录每个顶点的最小权重边值（key值），初始设置为无穷大（INT_MAX）
        unordered_map<Vertex*, int> key;

        // 初始化每个顶点的key值为最大
        for (auto &entry : adjList) {
            key[entry.first] = INT_MAX;
        }

        // 选择起始顶点
        Vertex* start = adjList.begin()->first;
        key[start] = 0;
        minHeap.emplace(0, start);

        // Prim算法的核心部分
        while (!minHeap.empty()) {
            Vertex* u = minHeap.top().second;
            minHeap.pop();

            inMST.insert(u);

            for (auto &neighbor : adjList[u]) {
                Vertex* v = neighbor.first;
                int weight = neighbor.second;
                if (inMST.find(v) == inMST.end() && key[v] > weight) {
                    key[v] = weight;
                    parent[v] = u;
                    minHeap.emplace(key[v], v);
                }
            }
        }

        // 打印最小生成树
        for (auto &entry : parent) {
            cout << "Edge: " << entry.second->val << " - " << entry.first->val << " with weight " << key[entry.first] << endl;
        }
    }
};

int main() {
    // 创建顶点
    Vertex* v0 = new Vertex(0);
    Vertex* v1 = new Vertex(1);
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);

    // 创建带权重的边
    vector<tuple<Vertex*, Vertex*, int>> edges = {
            {v0, v1, 2},
            {v0, v3, 6},
            {v1, v2, 3},
            {v1, v3, 8},
            {v1, v4, 5},
            {v2, v4, 7},
            {v3, v4, 9}
    };

    // 创建图并调用Prim算法
    GraphAdjList graph(edges);
    graph.graphPrime();

    return 0;
}
