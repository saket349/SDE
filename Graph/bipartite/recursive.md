### idea is if any loop inside the graph is odd membered then loop can not be bipartite
### odd membered loop means cycle in a graph formed from odd no of nodes
<p>we do dfs and during traversal if child of any node is not visited then we assign its height as height of  node + 1</p>
<b>note:</b> we assign height only to only unvisited node and we are doing dfs so it is possible that child of any node was child of any other node too was already visited, so its height may not be its curent parent node height + 1 <br>

##### so if any child of node is already visited then there is cycle then we compare the visited child node height with parent node height is diff is even then cycle is odd membered and we return false.

```
class Solution {
public:
    vector<bool> vis;
    vector<int> h;
    bool solve(int x, vector<vector<int>>& graph){
            vis[x]=true;
            bool ans = true;
            for(auto i: graph[x]){
                if(!vis[i]){
                    h[i]=h[x]+1;
                    ans = solve(i,graph);
                }else{
                    if(abs(h[i]-h[x])%2==0)
                        return false;
                }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n+1,false);
        h.resize(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                h[i]=1;
                if(!solve(i,graph))
                    return false;
            }
        }
        return true;
    }
};

```
