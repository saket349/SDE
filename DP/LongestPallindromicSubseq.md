## Again the parent question is LCS 
- we consider same string as two different string, one is the original one, and the other is inverted one, so we take two pointers i,j  for index 
- note (i-1) {index of first partition, string} can not be greater then (n-j) {index of second partition}

```cpp
int longestPalindromeSubseq(string s) {
    int n = s.size();

    // base condition
    if(n==0) return 0;

    int t[n+1][n+1];
    memset(t,0,sizeof(t));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i-1)>(n-j)) t[i][j] = max({t[i-1][j], t[i][j-1],t[i-1][j-1]});  // overflow
            else if((i-1)==(n-j)) t[i][j] = 1 + t[i-1][j-1];                    // when we land to same index from both start and end
            else if(s[i-1] == s[(n-j)]) t[i][j] = 2 + t[i-1][j-1];              // match condition
            else t[i][j] = max(t[i-1][j], t[i][j-1]);                           // else statement
        }
    }

    return t[n][n];
}
```
```cpp
vector<vector<int>> dp;
    int solve(string &s, int n, int m){
        // base case
        if(n>m) return 0;
        if(n==m) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        
        // condition to recur
        if(s[n]==s[m])  dp[n][m] = (2 + solve(s, n+1, m-1));
        else  dp[n][m] = max(solve(s,n+1,m), solve(s,n,m-1));
        return dp[n][m];
    }
    int minInsertions(string s) {
        int n = s.length();
        dp = vector<vector<int>> (n, vector<int>(n, - 1));
        return abs(n - solve(s,0,n-1));
    }
```
