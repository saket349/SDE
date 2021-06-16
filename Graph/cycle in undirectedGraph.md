- If for any node, if node in its adjoint set is already visisted and it is not the parent node then there is a cycle
```cpp
bool solve(vector<int> adj[], bool vis[], int x, int p){
        vis[x] = true;
        for(auto i : adj[x]){
         if(vis[i]){
             if(i!=p) return true;
         }else{
             if(solve(adj,vis,i,x)) return true;
         }   
        }
        return false;
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    bool vis[V+1];
	    memset(vis,false, sizeof(vis));
	    for(int i=0;i<V;i++)
	    if(!vis[i] && solve(adj, vis, i, -1)) return true;
	    
	    return false;
	    // Code here
	}
```
