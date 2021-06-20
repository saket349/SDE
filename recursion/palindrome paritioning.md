
#### Approach 1
- it is simple backtracking approach 
- consider first parition of length 1 -> recur ->backtrack and increase length length 2 and so
- in recur do same for smaller string and recur and recur
- once paritioning done, add it to result(res) only when all partioned strings are pallindrome  
```cpp
 bool ispalindrome(vector<string> x){
        for(auto s:x){
            int n = s.size();
            for(int i=0;2*i<n-1;i++)
                if(s[i]!=s[n-i-1]) 
                    return 0;
        }
        return 1;
    }
    void solve(string s, int ind, vector<vector<string>> &res, vector<string> temp, int n){
        if(ind>=n){
            if(ispalindrome(temp))
                res.push_back(temp);
            return;
        }
        for(int i=1;i+ind <= n;i++){
            string t = s.substr(ind,i);
            temp.push_back(t);
            solve(s,ind+i,res,temp,n);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int n = s.size();
        solve(s,0,res,temp,n);
        return res;
    }
```
- in the above problem there is overlaping, insteading of storing the result we check for substring again and again

#### optimised solution => DP plus Backtracking
- we further optimize the approach by using dynamic programming to determine if a string is a palindrome in constant time
- we do this using dp matrix: dp[x][y] : string starting at x and ends at y; if pallindrome then dp[x][y] true

```cpp
```
