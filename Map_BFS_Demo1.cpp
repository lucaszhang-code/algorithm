#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Vertex{
    int val;
    Vertex(int value):val(value){}
};

class GraphAdjList{
private:
    unordered_map<Vertex*, vector<Vertex*>> adjList;

public:
    GraphAdjList(vector<vector<Vertex*>> &edges){
        for(vector<Vertex*> vec : edges){
            addVertex(vec[0]);
            addVertex(vec[1]);
            addEdges(vec[0], vec[1]);
        }
    }

    void addVertex(Vertex* vets){
        if(adjList.count(vets)) return;
        adjList[vets] = vector<Vertex*>();
    }

    void addEdges(Vertex* vet1, Vertex* vet2){
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2) return;
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

   vector<Vertex*> graphBFS(GraphAdjList &graph, Vertex* startVet){
        vector<Vertex*> res;
        unordered_set<Vertex*> visited = {startVet};
        queue<Vertex*> que;
        que.push(startVet);
        while(!que.empty()){
            Vertex* vets = que.front();
            que.pop();
            res.push_back(vets);
            for(Vertex* v : graph.adjList[vets]){
                if(visited.count(v)) continue;
                que.push(v);
                visited.emplace(v);
            }
        }
        return res;
    }

    void printVec(vector<Vertex *> vec){
        for(Vertex *vet : vec){
            cout<< vet -> val <<" ";
        }
        cout<<endl;
    }
};

int main(){

    Vertex* v0 = new Vertex(0);
    Vertex* v1 = new Vertex(1);
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);

    vector<vector<Vertex*>> edges = {{v0, v1}, {v0, v2}, {v1, v2}, {v2, v3}, {v3, v4}};

    GraphAdjList graph(edges);

    graph.printVec(graph.graphBFS(graph, v0));


    return 0;
}