vector<vector<int>> dp;
    int solve(string x, string y, int m, int n){
        if(m<0 || n<0) return 0;
        if(m==0 || n==0){
            return n + m;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        if(x[m-1]==y[n-1]) {
            dp[m][n] = 1 + solve(x, y, m-1, n-1);
        }else{
            dp[m][n] = 1 + min(solve(x, y, m-1, n), solve(x, y, m, n-1));
        }
        return dp[m][n];
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        dp = vector<vector<int>> (m+1, vector<int> (n+1, -1));
        return solve(x, y, m, n);
        //code here
    }
