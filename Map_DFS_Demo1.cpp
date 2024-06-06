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

    void dfs(GraphAdjList &graph, unordered_set<Vertex*> &visited, vector<Vertex*> &res, Vertex* vet){
        res.push_back(vet);
        visited.emplace(vet);
        for(Vertex* adjVet : graph.adjList[vet]){
            if(visited.count(adjVet)) continue;
            dfs(graph, visited, res, adjVet);
        }
    }

    vector<Vertex*> graphDFS(GraphAdjList &graph, Vertex* startVets){
        vector<Vertex*> res;
        unordered_set<Vertex*> visited;
        dfs(graph, visited, res, startVets);
        return res;
    }


    void printVec(vector<Vertex *> vec){
        for(Vertex *vet : vec){
            cout<< vet -> val <<"  ";
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
    Vertex* v5 = new Vertex(5);
    Vertex* v6 = new Vertex(6);

    vector<vector<Vertex*>> edges = {{v0, v1}, {v0, v3}, {v1, v2}, {v2, v5}, {v4, v5},{v5, v6}};

    GraphAdjList graph(edges);

    graph.printVec(graph.graphDFS(graph, v0));


    return 0;
}