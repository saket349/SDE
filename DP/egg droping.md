- [question link](https://leetcode.com/problems/super-egg-drop/)

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
