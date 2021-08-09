[qn link](https://leetcode.com/problems/unique-paths-ii/discuss/1393658/RECURSIVE-CPP-CODE-oror-DP)
- So idea is  very simple for any cel let's say (i, j)  we have only two option either we move down (i+1, j), or right (i, j+1). 
- So  recursion solution of this will be quite simple, move to left  if not blocked, similarly down if not blocked. 
But time complexity will be factorial time complexity. 
- So we do little edit, we add dp array which keep track of cell visited, so when we revisit that cell, we need not calculate ans for it again, rather simply return dp[i][j]
```cpp
vector<vector<int>> dp;
    int solve(vector<vector<int>> &v, int i, int j, int m , int n){
        if(i==m && j==n && v[i-1][j-1]==0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(v[i-1][j-1] == 1) return 0;
        int ans = 0;
        if(i!=m)
            ans += solve(v, i+1, j, m, n);    
        if(j!=n)
            ans += solve(v, i, j+1, m, n);
        dp[i][j] = ans;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        dp = vector<vector<int>> (m+1, vector<int> (n + 1, -1));
        return solve(v, 1, 1, m, n);
        
    }
```
#### Hope you find it helpful, please write in comment if you find something incorrect or hard to understand
### Also please give this upvote if you like it
