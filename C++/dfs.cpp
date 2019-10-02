// this is my favourite code snippet because it used to solve almost all Competetive programming questions related to graphs.

class Graph 
{ 
    int V;   
    list<int> *adj; 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);   // Constructor 

    void addEdge(int v, int w); 

    void DFS(int v); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 

    visited[v] = true; 
    cout << v << " "; 
  
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 

void Graph::DFS(int v) 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

    DFSUtil(v, visited); 
} 
