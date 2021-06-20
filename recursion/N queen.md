
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
