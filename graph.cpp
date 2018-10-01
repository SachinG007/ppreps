#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    
    public:
    void DFSrec(int node, bool visited[]); 
    void DFS(int start);
    void addEdge(int v,int w);
    Graph(int j);
};

Graph::Graph(int j){
    V = j;
    adj = new list<int>[j];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSrec(int node, bool visited[]){
    visited[node] = true;
    cout << node << " ";
    
    list<int>::iterator i;
    for(i = adj[node].begin(); i != adj[node].end(); i++){
        if(!visited[*i]){
            DFSrec(*i,visited);
        }
    }
}

void Graph::DFS(int start){
    
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    
    DFSrec(start,visited);
}


int main() {
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}