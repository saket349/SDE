- TC: O(V+E) , SC: O(V+E)
- we do toposort , i.e. dfs with stack
- stack will contain our answer in reverse order
- we use two visited arrays, one for the general perpose to know which all nodes are visited
- other for that perticular traversal in graph, which help us to find cycle

```
bool topoSort(stack<int> &s, int x, vector<int> adj[], bool vis[], bool vis_curr[]){
    vis[x] = true;
    vis_curr[x] = true;
    bool ans = true;
    for(auto i:adj[x]){
        if(vis_curr[i]) return false;
        if(!vis[i]) ans = ans & topoSort(s, i, adj, vis, vis_curr);
        if(!ans) return false;
    }
    vis_curr[x] = false;
    s.push(x);
    return ans;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = prerequisites.size();
    vector<int>  adj[numCourses+1], ans;
    bool vis[numCourses+1], vis_curr[numCourses+1];
    bool flag = true;
    stack<int> s;
    memset(vis, false, sizeof(vis));

    for(int i=0;i<n;i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for(int i=0;i<numCourses;i++){
        if(!vis[i]){
            memset(vis_curr, false, sizeof(vis_curr));
            flag = flag & topoSort(s, i, adj, vis, vis_curr);
        }
        if(!flag) return ans;
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
```
