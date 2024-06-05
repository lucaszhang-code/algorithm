#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Vertex {
public:
    int val;
    Vertex(int value) : val(value) {}
};

class GraphAdjList {
private:
    unordered_map<Vertex *, vector<Vertex *>> adjList;
public:
    /* 构造函数，接受边列表来初始化图 */
    GraphAdjList(const vector<vector<Vertex *>> &edges) {
        for (const auto &edge : edges) {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    /* 添加顶点 */
    void addVertex(Vertex *vet) {
        if (adjList.find(vet) == adjList.end()) {
            adjList[vet] = vector<Vertex *>();
        }
    }

    /* 添加边 */
    void addEdge(Vertex *vet1, Vertex *vet2) {
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    /* 广度优先遍历 */
    vector<Vertex *> graphBFS(Vertex *startVet) {
        // 顶点遍历序列
        vector<Vertex *> res;
        // 哈希集合，用于记录已被访问过的顶点
        unordered_set<Vertex *> visited = {startVet};
        // 队列用于实现 BFS
        queue<Vertex *> que;
        que.push(startVet);
        // 以顶点 vet 为起点，循环直至访问完所有顶点
        while (!que.empty()) {
            Vertex *vet = que.front();
            que.pop();              // 队首顶点出队
            res.push_back(vet);     // 记录访问顶点
            for (auto adjVet : adjList[vet]) {
                if (visited.count(adjVet))
                    continue;              // 跳过已被访问的顶点
                que.push(adjVet);       // 只入队未访问的顶点
                visited.emplace(adjVet);  // 标记该顶点已被访问
            }
        }
        // 返回顶点遍历序列
        return res;
    }


    /* 打印顶点序列 */
    void printVertices(const vector<Vertex *> &vertices) const {
        for (const auto &vertex : vertices) {
            cout << vertex->val << " ";
        }
        cout << endl;
    }
};

int main() {
    Vertex *v0 = new Vertex(0);
    Vertex *v1 = new Vertex(1);
    Vertex *v2 = new Vertex(2);
    Vertex *v3 = new Vertex(3);

    vector<vector<Vertex *>> edges = {{v0, v1}, {v1, v2}, {v2, v3}, {v3, v0}, {v0, v2}};
    GraphAdjList graph(edges);

    vector<Vertex *> bfsResult = graph.graphBFS(v0);
    cout << "BFS Traversal starting from vertex 0: ";
    graph.printVertices(bfsResult);

    delete v0;
    delete v1;
    delete v2;
    delete v3;

    return 0;
}
