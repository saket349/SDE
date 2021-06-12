### The Algorithm Steps:
for graph with N vertices
- Initialize the shortest path between any two vertices with infinity
- Find all pair shortest paths that uses 0 intermidiate vertices, then find the shortest paths that use 1 intermediate vertex and so on.. until using all N vertices as intermediate nodes
- Minimize the shortest paths between any two pairs in the previous opertation.
- For any two vertices (i,j), one should actully minimize the distance between this pair using the first K nodes, so the shortest path will be: min(dist\[i]\[k] + dist\[k]\[j], dist\[i]\[j]). 
```cpp
for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
        }
    }
}
```
