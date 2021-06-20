- backtracking
- we consider any position for current queen, that position should pass our validation condition => must not be in horizontal, vertical or diagonal of any existing queen 
- we do this by using col, diag and antiDiag set, which stores the position (rows, column and diagonals)
- we know that each row will have eactly one queen, so we define our function likewise thus we reduce number of checks
- also we need not to check any position right or down of current position because those aren't covered yet
- after covering all rows we finally insert that permutation in respose vector
```cpp
    unordered_set<int> col;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;
    void solve(int n, vector<vector<string>> &res, vector<string> &x, int row){
        if(row>=n){       
            res.push_back(x);
            return;
        }
        for(int c=0;c<n;c++){
            if (!col.count(c) && !diag.count(row+c) && !antiDiag.count(row-c)){
                // do
                col.insert(c); diag.insert(row+c); antiDiag.insert(row-c);
                x[row][c]='Q';
                // recur
                solve(n, res, x, row+1);
                // undo
                col.erase(c); diag.erase(row+c); antiDiag.erase(row-c);
                x[row][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> x(n, string(n, '.'));
        solve(n, res, x, 0);
        return res;
    }
```
