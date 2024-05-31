#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &graph) {
    for(vector<int>arr : graph){
        for(int num : arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    int type, vCount, sCount;
    cin >> type >> vCount >> sCount;

    int arrLen = sCount * 2;
    vector<int> arr(arrLen);

    for (int i = 0; i < arrLen; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> graph(vCount, vector<int>(vCount, 0));

    for (int i = 0; i < arrLen; i += 2) {
        int u = arr[i];
        int v = arr[i + 1];
        graph[u][v] = 1;
        if (type == 0) {
            graph[v][u] = 1;
        }
    }

   print(graph);

    return 0;
}
