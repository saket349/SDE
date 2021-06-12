#### Dijkstra algorithm is used to find minimum distance from any node to all other nodes, it works in O(n^2) time complexity but can be reduced to O(n + mlog(n)) using priority queue or multiset
#### PS: this algo fails with negative distances, for negative weights, algorithm get Runtime time error as it get trapped into infinite loop
#### requirements: 
- vector pair, for graph, stores adjascent node and its edge length
- distance array, which will contain minimum distance length, at the end of program, initialized with some big random value
- visited bool array, to keep account of node visited 
- priority queue to store node and weight(current distance of that node from source), min heap priority queue 

```cpp
//******Jai Hanuman*****************
//******Saket Kumaer*****************
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define pi pair<int,int>
#define mp make_pair
#define f first
#define s second
#define fo(i,n) for(int i=0;i<n;i++)

void dijsktra(vector<pi> v[],int n){     // dijkstra function
    vector<int> dis(n+1,1e9);            // we initialise the distance array to inifinity, here 1e9
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    dis[0] = 0;
    priority_queue <pi, vector<pi>, greater<pi>> q; // min heap priority queue
    q.push(mp(0,0));                                // distance of source from source is zero
    while(!q.empty()){
        pi p = q.top();                             // pop the node with minimum distance
        q.pop();
        int x = p.f;
        if(vis[x]) continue;                        // check if poped node is visited or not 
        vis[x]=true;
        for(auto i:v[x]){
            int w = i.s;
            int y = i.f;
            if(dis[x]+w<dis[y]){                       // check if the next vertex distance could be minimized
                dis[y]=dis[x]+w;
                q.push(mp(dis[y],y));                  // insert the next vertex with the updated distance
            }
        }
    }
    fo(i,n)
    cout<<dis[i]<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    vector<pi> v[n+1];
    for(int i=0;i<m;i++){                                 //  graph preparation
        cin>>x>>y>>w;
        v[x].push_back(mp(y,w));
        v[y].push_back(mp(x,w));
    }
    dijsktra(v,n);
    
    return 0;
}
```
