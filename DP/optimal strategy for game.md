- [question link](https://leetcode.com/problems/predict-the-winner/)

```
Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.
```

```
Input: nums = [1,5,233,7]
Output: true
```

- recursive solution is based on turns, for each player turn, chose either of the options

```
bool solve(vector<int> &nums, int i, int j, int xsum, int ysum, int turn){
        // cout<<i<<" "<<j<<" "<<xsum<<" "<<ysum<<endl;
        if(i>j) {
            if(xsum >= ysum)  return true;
            return false;
        }
        if(turn%2)
        return solve(nums, i+1, j, xsum + nums[i], ysum, turn+1) | solve(nums, i, j-1, xsum+nums[j], ysum, turn + 1);
        else return solve(nums, i+1, j, xsum, nums[i] + ysum, turn+1) & solve(nums, i, j-1, xsum, nums[j] + ysum, turn + 1);
    }
    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1, 0, 0, 1);
    }
```

-  dp solution : for each turn return max value we get while playing optimally


```cpp
int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i==j) return nums[i];
        if(dp[i][j]!=NULL) return dp[i][j]; 
        int a = nums[i] - solve(nums, i+1, j, dp);
        int b = nums[j] - solve(nums, i, j-1, dp);
        dp[i][j] = max(a, b);
        return dp[i][j];
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size()));
        return solve(nums, 0, nums.size()-1, dp)>=0;
    }
```
