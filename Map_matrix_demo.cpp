#include <iostream>
using namespace std;
#include <vector>

class Matrix {
private:
    vector<int>vertices = {0, 1, 2, 3};
    int size = vertices.size();
    vector<vector<int>> finalMatrix;
public:
    Matrix(vector<vector<int>> matrix) : finalMatrix(size, vector<int>(size, 0)){
        for(auto &vec : matrix){
            finalMatrix[vec[0]][vec[1]] = 1;
            finalMatrix[vec[1]][vec[0]] = 1;
        }
    }

    void addVertex(int x){
        vertices.push_back(x);
        size++;
        finalMatrix.emplace_back(size, 0);
        for(auto &vec : finalMatrix){
            vec.push_back(0);
        }
    }

    void deleteVertex(int x){
        vertices.erase(vertices.begin()+x);
        size--;
        finalMatrix.erase(finalMatrix.begin()+x);
        for(auto &vec : finalMatrix){
            vec.erase(vec.begin()+x);
        }
    }

    void addEdge(int x, int y){
        finalMatrix[x][y] = 1;
        finalMatrix[y][x] = 1;
    }

    void deleteEdge(int x, int y){
        finalMatrix[x][y] = 0;
        finalMatrix[y][x] = 0;
    }

    void printMatrix(){
        for(const auto& vec : finalMatrix){
            for(int num : vec){
                cout<<num<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{0,1},{1,1},{1,3},{2,3}};

    Matrix m(matrix);
    m.addEdge(2,2);
    m.deleteEdge(0,1);
    m.printMatrix();

    return 0;
}