/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};*/
/*You are required to complete this method*/

bool dfs(bool vis[], list<int> *adj, int node, int prev_node){
    vis[node] = true;
    
    list<int>::iterator i;
    for(i = adj[node].begin();i!=adj[node].end();i++){
        bool result = false;
        int present_node = *i;
        if(vis[*i] && present_node!=prev_node){
            return true;
        }
        
        if(!vis[*i]){
            result = dfs(vis,adj,present_node,node);
        }
        
        if(result){
            return true;
        }
    }
    
    return false;
}

bool Graph :: isCyclic()
{
//Your code here

    bool *vis = new bool[V]; //vis[100]
    for(int i=0;i<V;i++){
        vis[i] = false;
    }
    bool isCyclic = false;
    
    for(int i=0;i<V;i++){
        
        if(!vis[i]){
        isCyclic = dfs(vis, adj, i, -1);
        }
        if(isCyclic){
            return true;
            break;
        }
    }
    
    return false;
    
}