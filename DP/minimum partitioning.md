- first approach or say naive approach is using backtracking, Time complexity: O(N\*2^N), space complexity: O(1);
```cpp
bool isPalindrome(string s, int i, int j){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        return isPalindrome(s, i+1, j-1);
    }
    void solve(string s, int i, int n, int & temp, int &ans){
        if(i==n) temp--;
        if(i>=n-1){
            ans = min(ans, temp);
            return;
        }
        for(int k=i;k<n;k++){
            if(isPalindrome(s, i, k)){
                temp++;
                solve(s, k+1, n, temp, ans);
                temp--;
            }
        }
    }
```

- second approach is using memoized DP or bottom up DP

```cpp
vector<vector<int>> dp;
    bool isPalindrome(string s, int i, int j){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        return isPalindrome(s, i+1, j-1);
    }
    int solve(string s, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==j) return dp[i][j] = 0;
        if(isPalindrome(s, i, j)) return dp[i][j] = 0;
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            int temp = solve(s, i, k) + solve(s, k+1, j) + 1;
            ans = min(ans, temp);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minCut(string s) {
        dp = vector<vector<int>> (s.size(), vector<int> (s.size(), -1));
        return solve(s, 0, s.size()-1);
    }
```
