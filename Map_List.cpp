#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Vertex {
    int val;
    Vertex(int value) : val(value) {}
};

/* �����ڽӱ�ʵ�ֵ�����ͼ�� */
class GraphAdjList {
public:
    // �ڽӱ�key�����㣬value���ö���������ڽӶ���
    unordered_map<Vertex *, vector<Vertex *>> adjList;

    /* �� vector ��ɾ��ָ���ڵ� */
    void remove(vector<Vertex *> &vec, Vertex *vet) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == vet) {
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }

    /* ���췽�� */
    GraphAdjList(const vector<vector<Vertex *>> &edges) {
        // ������ж���ͱ�
        for (const vector<Vertex *> &edge : edges) {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    /* ��ȡ�������� */
    int size() {
        return adjList.size();
    }

    /* ��ӱ� */
    void addEdge(Vertex *vet1, Vertex *vet2) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("�����ڶ���");
        // ��ӱ� vet1 - vet2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    /* ɾ���� */
    void removeEdge(Vertex *vet1, Vertex *vet2) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("�����ڶ���");
        // ɾ���� vet1 - vet2
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }

    /* ��Ӷ��� */
    void addVertex(Vertex *vet) {
        if (adjList.count(vet))
            return;
        // ���ڽӱ������һ��������
        adjList[vet] = vector<Vertex *>();
    }

    /* ɾ������ */
    void removeVertex(Vertex *vet) {
        if (!adjList.count(vet))
            throw invalid_argument("�����ڶ���");
        // ���ڽӱ���ɾ������ vet ��Ӧ������
        adjList.erase(vet);
        // �����������������ɾ�����а��� vet �ı�
        for (auto &adj : adjList) {
            remove(adj.second, vet);
        }
    }

    /* �������ָ���б�ת��Ϊ�����ֵ�б� */
    vector<int> vetsToVals(const vector<Vertex *> &vec) const {
        vector<int> vals;
        for (const Vertex *vet : vec) {
            vals.push_back(vet->val);
        }
        sort(vals.begin(), vals.end());
        return vals;
    }

    /* ��ӡ vector<int> */
    void printVector(const vector<int> &vec) const {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    /* ��ӡ�ڽӱ� */
    void print() const {
        cout << "�ڽӱ� =" << endl;
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
