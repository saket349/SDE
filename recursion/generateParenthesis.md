- [question link](https://leetcode.com/problems/generate-parentheses/)

```
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
```

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

```cpp
void solve(vector<string> &res, string temp, int n, int k){
        if(n==0){
            res.push_back(temp);
            return;
        }
        if(k==0 || k<n){
            temp.push_back('(');
            solve(res, temp, n, k+1);
            temp.pop_back();
        }
        if(k!=0){
            temp.push_back(')');
            solve(res, temp, n-1, k-1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(res, "", n, 0);
        return res;
    }
```
