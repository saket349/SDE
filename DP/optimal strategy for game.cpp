/*
The user chooses the ‘ith’ coin with value ‘Vi’: The opponent either chooses (i+1)th coin or jth coin. The opponent intends to choose the coin which leaves the user with minimum value. 
i.e. The user can collect the value Vi + min(F(i+2, j), F(i+1, j-1) ). 
*/
vector<vector<int>> dp;
int solve(int arr[], int i, int j){
    if(i>j) return 0;
    if(i==j) return arr[i];
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j] = max(arr[i] + min(solve(arr, i+2, j), solve(arr, i+1, j-1)), arr[j] + min(solve(arr, i, j-2), solve(arr, i+1, j-1)));

    return dp[i][j];
}
//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n) 
{
    dp = vector<vector<int>> (n+1, vector<int> (n+1, -1));
    return solve(arr, 0, n-1);
    // Your code here
}
