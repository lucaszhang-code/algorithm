#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Vertex{
    int val;
    Vertex(int value):val(value){}
};

class GraphAdList{
private:
    unordered_map<Vertex*, vector<Vertex*>>adList;
public:
    void removeEdge(vector<Vertex*> &vec, Vertex* vets){
        for(int i = 0; i< vec.size(); i++){
            if(vec[i] == vets){
                vec.erase(vec.begin() + i);
            }
        }
    }

    GraphAdList(vector<vector<Vertex*>> &edges){
        for(vector<Vertex*> &vec: edges){
            adVertex(vec[0]);
            adVertex(vec[1]);
            adEdges(vec[0], vec[1]);
        }
    }

    void adVertex(Vertex* v){
        if(adList.count(v)) return;
        adList[v] = vector<Vertex*>();
    }

    void adEdges(Vertex* v1, Vertex* v2){
        if(!adList.count(v1) || !adList.count(v2) || v1 == v2) return;
        adList[v1].push_back(v2);
        adList[v2].push_back(v1);
    }

    void removeVertex(Vertex* v){
        if(!adList.count(v)) return;
        adList.erase(v);
        for(auto pair : adList){
            removeEdge(pair.second, v);
        }
    }

    void removeEdge(Vertex* v1, Vertex* v2){
        if (!adList.count(v1) || !adList.count(v2) || v1 == v2) return;
        removeEdge(adList[v1], v2);
        removeEdge(adList[v2], v1);
    }

    vector<int> VerToVal(vector<Vertex*> &vec){
        vector<int> result;
        for(int i = 0; i < vec.size(); i++){
            result.push_back(vec[i] -> val);
        }
        sort(result.begin(), result.end());
        return result;
    }

    void printVec(vector<int> vec){
        for(int i : vec){
            cout << i << " ";
        }
        cout<<endl;
    }

    void printGraph(){
        for(const auto pair : adList){
            int val = pair.first -> val;
            vector<Vertex*> vec = pair.second;
            cout<< val << " : ";
            printVec(VerToVal(vec));
        }
    }
};

int main(){

    Vertex *v0 = new Vertex(0);
    Vertex *v1 = new Vertex(1);
    Vertex *v2 = new Vertex(2);
    Vertex *v3 = new Vertex(3);

    vector<vector<Vertex*>> edges = {{v0,v1},{v1, v2}, {v1, v3}, {v2, v3}};
    GraphAdList graph(edges);
    graph.removeVertex(v3);
    graph.adEdges(v0, v2);
    graph.printGraph();

    return 0;
}