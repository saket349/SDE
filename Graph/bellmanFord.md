#### Used to find the sortest path from the source node to all other vertices in a weigted graph,
#### A very important application of Bellman Ford is to **check if there is a negative cycle** in the graph, time complexity of the algorithm is relatively high O(n^v) if v=n^2 then complexity becomes O(n^3)
#### Bellman ford donot works for directed graph with neagtive edges, and for directed grsph it fails when graph has negative cycle
- in this algorithm we perform n-1 (one less then total no of nodes) time relaxation for worst case possiblities
- reason is, we know before doing anything we already have one node with min path length, which is source node itself, path length = 0
- then in one move we can in worst case scenario we can find optimal path for nodes, which are directly linked to source node, worst case:  one node only directly connected
- then in other consider all optimsed node as seperate source node, then we can optimised rest node by repeating the process, so even in worst case we will require to do n-1 interations  
~~~cpp

~~~
