- In Prim’s Algorithm, we will start with an arbitrary node (it doesn’t matter which one) and mark it
-  In each iteration we will mark a new vertex that is adjacent to the one that we have already marked
-   As a greedy algorithm, Prim’s algorithm will select the cheapest edge and mark the vertex

![Fig-11](https://user-images.githubusercontent.com/62437314/130318068-9de5d5cc-85aa-4e2d-9cf3-8413f47b9888.jpg)

```cpp
#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}
```
Time Complexity:
The time complexity of the Prim’s Algorithm is O((V+E)logV)  because each vertex is inserted in the priority queue only once and insertion in priority queue take logarithmic time.
