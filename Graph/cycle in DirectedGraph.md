- same as finding graph in undirected graph, only change is that not all circle is cycle

```cpp
bool solve(vector<int> adj[], bool vis[], bool incycle[], int x, int p){
        vis[x] = true;
        incycle[x] = true;
        for(auto i:adj[x]){
            if(!vis[i]){
                if(solve(adj,vis,incycle,i,x)) return true;
            }else {
                if(incycle[i]) return true;   // extra condition
            }
        }
        incycle[x]=false;
        return false;
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    bool vis[V+1], incycle[V+1];
	    memset(vis, false, sizeof(vis));
	    memset(incycle, false, sizeof(incycle));
	    for(int i=0;i<V;i++)
	    if(!vis[i] && solve(adj, vis, incycle, i, -1)) return true;
	    return false;
	   	// code here
	}
```
