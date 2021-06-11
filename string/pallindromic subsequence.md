##### First approach:  brute force approach is to start with index i, i from 0 to n-1, and then for each i we take j, last index , and then find if s[i] to s[j]  is pallindrome or not, time complexity: O(n^3)

##### second is DP:
- DP1, for small length
 ```cpp
 int l = INT_MIN; string a="";
    int solve(string s,int n,int m, vector<vector<int>> &t){
        if(n>m) return 0;
        if(t[n][m]!=-1) return t[n][m];
        if(n==m) {
            t[n][m]=1;
            l=max(l,1);
            if(l>a.size()) a = s.substr(n,l);
            return 1;
        }
        if(n==(m-1)){
            if(s[n]!=s[m]) {
                t[n][m]=0;
                solve(s,n+1,m,t);
                solve(s,n,m-1,t);
                return 0;
            }
            t[n][m]=1;
            l = max(l,2);
            if(l>a.size()) a = s.substr(n,l);
            return 1;
        }
        if(s[n]==s[m]){
            if(solve(s,n+1,m-1,t)){
                t[n][m]=1;
                l = max(l,m-n+1);
                if(l>a.size()) a = s.substr(n,l);
                return 1;
            }
            else{
                t[n][m]=0;
                solve(s,n+1,m,t);
                solve(s,n,m-1,t);
                return 0;
            }
        }else{
            t[n][m]=0;
            solve(s,n+1,m,t);
            solve(s,n,m-1,t);
            return 0;
        }
        
    }
 ```
 
 - DP2
 ```cpp
 
 ```
