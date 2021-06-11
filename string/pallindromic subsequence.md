##### First approach:  brute force approach is to start with index i, i from 0 to n-1, and then for each i we take j, last index , and then find if s[i] to s[j]  is pallindrome or not, time complexity: O(n^3)

##### second is DP:
- if you want to get just length, then it is easy
 ```cpp
 int  l = INT_MIN; vector<vector<int>> v(n+1,vector<int> (m,-1));
  int solve(string s, int n,int m){   // n starts with 0, and m with size - 1
      if(n>m) return 0;
      if(t[n][m] != -1)
      return t[n][m];
      if(n==m){
          l = max(l,1);
          return t[n][m] = 1;
      }
      if(n==(m-1)){
          l = max(l,2);
          return t[n][m] = 1;
      }
      if(s[n]==s[m]){
        t[n][m] = solve(s,n+1,m-1)'
          if(t[n][m])
              l = max(l,m-n+1);
          return t[n][m];
      }else{
          solve(s,n+1,m);
          solve(s,n,m-1);
          return t[n][m] = 0;
      }
  }
 ```
 
 - for returning string, which pallindrome, we have
 ```cpp
 
 ```
