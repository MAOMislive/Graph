#include<iostream>
#include<vector>
using namespace std;

class node{
public:
    int vertex;
    int weight;

    node(int v, int w){
        vertex = v;
        weight = w;
    }
};

class Graph{
private:
    int vertex;
    int edge;
    vector<node>*adjList;

public:
    Graph(int vertex){
        this->vertex = vertex;

        this->adjList = new vector<node> [vertex];
    }

    bool addEdge(int u,int v,int weight)
    {
        if(u >= this->vertex || v >= this->vertex){
            return false;
        }
        adjList[u].push_back(node(v,weight));
        adjList[v].push_back(node(u,weight));
        this->edge++;

        return true;
    }

    void printGraph()
    {
        for(int i = 0; i< vertex; i++){
            for(node element : adjList[i]){
            cout << "(" << element.vertex << "," << element.weight << ")";
            }

            cout << "\n";
        }

    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,5);
    g.addEdge(1,3,2);
    g.addEdge(0,2,1);
    g.addEdge(2,3,5);
    //g.removeEdge(2,3);
    g.printGraph();
    return 0;
}
