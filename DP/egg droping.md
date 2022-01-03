- [question link](https://leetcode.com/problems/super-egg-drop/)

```
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.
```

```
Input: k = 2, n = 6
Output: 3
```
```cpp
vector<vector<int>> dp;
    int solve(int f, int e){
        if(f==0 || f==1) return f;
        if(e==1) return f;
        if(dp[f][e]!=-1) return dp[f][e];
        int mn = INT_MAX;
        for(int k=1; k<=f;k++){
            int temp = 1 + max(solve(k-1, e-1), solve(f-k, e));
            mn = min(mn, temp);
        }
        return dp[f][e] = mn;
    }
    int eggDrop(int n, int k) 
    {
        dp = vector<vector<int>> (k+1, vector<int> (n+1, -1));
        // your code here
        return solve(k, n);
    }
```
