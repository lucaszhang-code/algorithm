#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

/* ��ӡ���� */
void printVector(const vector<int> &vec) {
    cout << "[ ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

/* ��ӡ��ά�������� */
void printVectorMatrix(const vector<vector<int>> &matrix) {
    for (const vector<int> &row : matrix) {
        printVector(row);
    }
}

/* �����ڽӾ���ʵ�ֵ�����ͼ�� */
class GraphAdjMat {
    vector<int> vertices;       // �����б�Ԫ�ش�������ֵ����������������������
    vector<vector<int>> adjMat; // �ڽӾ�������������Ӧ������������

public:
    /* ���췽�� */
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges) {
        // ��Ӷ���
        for (int val : vertices) {
            addVertex(val);
        }
        // ��ӱ�
        // ��ע�⣬edges Ԫ�ش���������������Ӧ vertices Ԫ������
        for (const vector<int> &edge : edges) {
            addEdge(edge[0], edge[1]);
        }
    }

    /* ��ȡ�������� */
    int size() const {
        return vertices.size();
    }

    /* ��Ӷ��� */
    void addVertex(int val) {
        int n = size();
        // �򶥵��б�������¶����ֵ
        vertices.push_back(val);
        // ���ڽӾ��������һ��
        adjMat.emplace_back(vector<int>(n, 0));
        // ���ڽӾ��������һ��
        for (vector<int> &row : adjMat) {
            row.push_back(0);
        }
    }

    /* ɾ������ */
    void removeVertex(int index) {
        if (index >= size()) {
            throw out_of_range("���㲻����");
        }
        // �ڶ����б����Ƴ����� index �Ķ���
        vertices.erase(vertices.begin() + index);
        // ���ڽӾ�����ɾ������ index ����
        adjMat.erase(adjMat.begin() + index);
        // ���ڽӾ�����ɾ������ index ����
        for (vector<int> &row : adjMat) {
            row.erase(row.begin() + index);
        }
    }

    /* ��ӱ� */
    // ���� i, j ��Ӧ vertices Ԫ������
    void addEdge(int i, int j) {
        // ����Խ������ȴ���
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw out_of_range("���㲻����");
        }
        // ������ͼ�У��ڽӾ���������Խ��߶Գƣ������� (i, j) == (j, i)
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    /* ɾ���� */
    // ���� i, j ��Ӧ vertices Ԫ������
    void removeEdge(int i, int j) {
        // ����Խ������ȴ���
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw out_of_range("���㲻����");
        }
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    /* ��ӡ�ڽӾ��� */
    void print() {
        cout << "�����б� = ";
        printVector(vertices);
        cout << "�ڽӾ��� =" << endl;
        printVectorMatrix(adjMat);
    }
};

int main() {
    vector<int> vertices = {0, 1, 2, 3};
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
    GraphAdjMat graph(vertices, edges);
    graph.print();

    return 0;
}
