- Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG
- The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges)
- **DIFFERENCE BETWEEN DFS AND TOPO SORT**: In DFS, we print a vertex and then recursively call DFS for its adjacent vertices. In topological sorting, we need to print a vertex before its adjacent vertices. 
- Where our DFS will to get topo is when we move from one parent node to its leaf node printing all the node sequencially, but that leaf node is also a leaf of some other parent node, but we already had printed it,
- so to get rid of this, we use stack to store the node, we store the node once all its child node are already visited, in this way we will have all node in sequencial  mnner in stack, then we just pop and print from stack

```cpp
void dfs(vector<int> adj[], stack<int> &s,bool vis[], int x){
	    vis[x]=true;
	    for(auto i:adj[x]){
	        if(!vis[i]){
	            dfs(adj,s,vis,i);
	        }
	    }
	    s.push(x);
	}
	vector<int> reverse(stack<int> &s, vector<int> &v){  // we return the reverse of stack as our answer
	    while(!s.empty()){
	        int t = s.top();
	        s.pop();
	        v.push_back(t);
	    }
	    return v;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> s;
	    bool vis[V+1];
	    memset(vis, false, sizeof(vis));
	    for(int i=0;i<V;i++)
	        if(!vis[i]) dfs(adj,s,vis,i);
	    vector<int> v;
	    return reverse(s,v);
	    // code here
	}
```
