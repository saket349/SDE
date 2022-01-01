- [question link](https://leetcode.com/problems/burst-balloons/)
- It is simple MCM , with changed statement

```
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

```cpp
int solve(vector<vector<int>> &dp, vector<int> &nums, int i, int j){
        if(j<=i) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0, temp = 0;
        for(int k=i;k<j;k++){
            temp = solve(dp, nums, i, k) + solve(dp, nums, k+1, j) + nums[i-1]*nums[k]*nums[j];
            ans = max(ans, temp);
        }
        // cout<<i<<" "<<j<<" "<<ans<<endl;
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(dp, nums, 1, n-1);
    }
```
