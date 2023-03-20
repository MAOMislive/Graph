#include<iostream>

using namespace std;

class Graph
{

private:
    int vertex;
    int edge;
    int **graph;


public:

    Graph(int v)
    {
        this->edge=0;
        this->vertex=v;
        this->graph=new int*[v];
        for(int i=0; i<v; i++)
        {
            graph[i]=new int[v];
        }
        for(int i=0; i<this->vertex; i++)
        {
            for(int j=0; j<this->vertex; j++)
            {
                this->graph[i][j]=0;
            }

        }
    }

    bool addEdge(int u,int v,int weight)
    {
        if(u >= this->vertex || v >= this->vertex){
            return false;
        }
        graph[u][v]=weight;
        graph[v][u]=weight;
        this->edge++;

        return true;
    }
    bool removeEdge(int u,int v)
    {
        if(u >= this->vertex || v >= this->vertex){
            return false;
        }
        graph[u][v]=0;
        graph[v][u]=0;

        return true;
    }

    void printGraph()
    {
        printf("The number of vertex used: %d\n",this->edge);
        for(int i=0; i<this->vertex; i++)
        {
            for(int j=0; j<this->vertex; j++)
            {
                cout<<this->graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph g(4);
    g.addEdge(0,1,5);
    g.addEdge(1,3,2);
    g.addEdge(0,2,1);
    g.addEdge(2,3,5);
    g.removeEdge(2,3);
    g.printGraph();
    return 0;
}
