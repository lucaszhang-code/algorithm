#include <iostream>
#include <vector>
#include <list>

using namespace std;

void printGraph(const vector<list<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        cout << i;
        for (int neighbor : graph[i]) {
            cout << "->" << neighbor;
        }
        cout << endl;
    }
}

int main() {
    int type, vCount, sCount;
    cin >> type >> vCount >> sCount;

    vector<int> arr(sCount * 2);
    for (int &num : arr) {
        cin >> num;
    }

    vector<list<int>> graph(vCount);

    for (int i = 0; i < arr.size(); i += 2) {
        int u = arr[i];
        int v = arr[i + 1];
        graph[u].push_front(v);
        if (type == 0) {
            graph[v].push_front(u);
        }
    }

    printGraph(graph);

    return 0;
}
