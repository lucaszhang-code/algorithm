#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Vertex {
    int val;
    Vertex(int value) : val(value) {}
};

/* 基于邻接表实现的无向图类 */
class GraphAdjList {
public:
    // 邻接表，key：顶点，value：该顶点的所有邻接顶点
    unordered_map<Vertex *, vector<Vertex *>> adjList;

    /* 在 vector 中删除指定节点 */
    void remove(vector<Vertex *> &vec, Vertex *vet) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == vet) {
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }

    /* 构造方法 */
    GraphAdjList(const vector<vector<Vertex *>> &edges) {
        // 添加所有顶点和边
        for (const vector<Vertex *> &edge : edges) {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    /* 获取顶点数量 */
    int size() {
        return adjList.size();
    }

    /* 添加边 */
    void addEdge(Vertex *vet1, Vertex *vet2) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点");
        // 添加边 vet1 - vet2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    /* 删除边 */
    void removeEdge(Vertex *vet1, Vertex *vet2) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点");
        // 删除边 vet1 - vet2
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }

    /* 添加顶点 */
    void addVertex(Vertex *vet) {
        if (adjList.count(vet))
            return;
        // 在邻接表中添加一个新链表
        adjList[vet] = vector<Vertex *>();
    }

    /* 删除顶点 */
    void removeVertex(Vertex *vet) {
        if (!adjList.count(vet))
            throw invalid_argument("不存在顶点");
        // 在邻接表中删除顶点 vet 对应的链表
        adjList.erase(vet);
        // 遍历其他顶点的链表，删除所有包含 vet 的边
        for (auto &adj : adjList) {
            remove(adj.second, vet);
        }
    }

    /* 将顶点的指针列表转换为顶点的值列表 */
    vector<int> vetsToVals(const vector<Vertex *> &vec) const {
        vector<int> vals;
        for (const Vertex *vet : vec) {
            vals.push_back(vet->val);
        }
        sort(vals.begin(), vals.end());
        return vals;
    }

    /* 打印 vector<int> */
    void printVector(const vector<int> &vec) const {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    /* 打印邻接表 */
    void print() const {
        cout << "邻接表 =" << endl;
        for (const auto &adj : adjList) {
            Vertex *key = adj.first;
            vector<Vertex *> vec = adj.second;
            cout << key->val << ": ";
            printVector(vetsToVals(vec));
        }
    }
};

int main() {
    Vertex *v0 = new Vertex(0);
    Vertex *v1 = new Vertex(1);
    Vertex *v2 = new Vertex(2);
    Vertex *v3 = new Vertex(3);

    vector<vector<Vertex *>> edges = {{v0, v1}, {v1, v2}, {v2, v3}, {v3, v0}, {v0, v2}};

    GraphAdjList graph(edges);
    graph.print();

    delete v0;
    delete v1;
    delete v2;
    delete v3;

    return 0;
}
