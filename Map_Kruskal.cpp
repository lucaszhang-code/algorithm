#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>

using namespace std;

struct Vertex {
    int val;
    Vertex(int value) : val(value) {}
};

class DisjointSet {
private:
    unordered_map<Vertex*, Vertex*> parent;
    unordered_map<Vertex*, int> rank;

public:
    void makeSet(vector<Vertex*>& vertices) {
        for (auto v : vertices) {
            parent[v] = v;
            rank[v] = 0;
        }
    }

    Vertex* find(Vertex* v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    void unionSets(Vertex* v1, Vertex* v2) {
        Vertex* root1 = find(v1);
        Vertex* root2 = find(v2);

        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};

class GraphAdjList {
private:
    unordered_map<Vertex*, vector<pair<Vertex*, int>>> adjList;
    vector<Vertex*> vertices;

public:
    GraphAdjList(vector<tuple<Vertex*, Vertex*, int>> &edges) {
        for (auto &edge : edges) {
            addVertex(get<0>(edge));
            addVertex(get<1>(edge));
            addEdges(get<0>(edge), get<1>(edge), get<2>(edge));
        }
    }

    void addVertex(Vertex* vet) {
        if (adjList.count(vet)) return;
        adjList[vet] = vector<pair<Vertex*, int>>();
        vertices.push_back(vet);
    }

    void addEdges(Vertex* vet1, Vertex* vet2, int weight) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2) return;
        adjList[vet1].emplace_back(vet2, weight);
        adjList[vet2].emplace_back(vet1, weight);
    }

    void kruskalMST() {
        vector<tuple<int, Vertex*, Vertex*>> edges;

        for (auto &entry : adjList) {
            Vertex* u = entry.first;
            for (auto &neighbor : entry.second) {
                Vertex* v = neighbor.first;
                int weight = neighbor.second;
                edges.emplace_back(weight, u, v);
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds;
        ds.makeSet(vertices);

        vector<tuple<int, Vertex*, Vertex*>> mst;

        for (auto &edge : edges) {
            int weight = get<0>(edge);
            Vertex* u = get<1>(edge);
            Vertex* v = get<2>(edge);

            if (ds.find(u) != ds.find(v)) {
                mst.push_back(edge);
                ds.unionSets(u, v);
            }
        }

        // 打印最小生成树
        cout << "Edge \tWeight\n";
        for (auto &edge : mst) {
            cout << get<1>(edge)->val << " - " << get<2>(edge)->val << " \t" << get<0>(edge) << " \n";
        }
    }
};

int main() {
    Vertex* v0 = new Vertex(0);
    Vertex* v1 = new Vertex(1);
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);

    vector<tuple<Vertex*, Vertex*, int>> edges = {
            {v0, v1, 2},
            {v0, v3, 6},
            {v1, v2, 3},
            {v1, v3, 8},
            {v1, v4, 5},
            {v2, v4, 7},
            {v3, v4, 9}
    };

    GraphAdjList graph(edges);
    graph.kruskalMST();

    return 0;
}
