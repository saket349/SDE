# simple implementation of unbounded knapsack

```
class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        int t[n+1][sum + 1];
        
        // base case;
        for(int i=0;i<=sum;i++) t[0][i] = INT_MAX;
        for(int i=0;i<=n;i++) t[i][0] = 0;
        
        // additional base condition
        for(int i=1;i<=sum;i++) {
            if(i%coins[0] == 0) t[1][i] = (i/coins[0]);
            else t[1][i] = INT_MAX - 1;
        }
        // condition tree
        for(int i=2;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i-1]<=j)
                    t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j]);
                else t[i][j] = t[i-1][j];
            }
        }
        if(t[n][sum]>=(INT_MAX-1)) return -1;
        return t[n][sum];
    }
};
```
