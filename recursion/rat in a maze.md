```cpp
void solve(vector<vector<int>> &m, 
       vector<string> &res, string temp, vector<vector<bool>> &vis, int row, int col){
        int n = vis.size();
        // if we reached the end and that is not blocked
        if(row==n-1 && col==n-1){
          if(m[row][col])
           res.push_back(temp);
          return;
        }
        // for each down, left, up and right we do => recur => undo
        // check if we can move down
        if(row<n-1 && m[row+1][col] && !vis[row+1][col]){
            vis[row+1][col] = true;
            temp = temp + 'D';
            solve(m, res, temp, vis, row+1, col);
            vis[row+1][col] = false;
            temp.pop_back();
        }
        // check if we can move left
        if(col>0 && m[row][col-1] && !vis[row][col-1]){
           vis[row][col-1] = true;
           temp = temp + 'L';
           solve(m, res, temp, vis, row, col-1);
           vis[row][col-1] = false;
           temp.pop_back();
        }
        // check if we can move right
        if(col<n-1 && m[row][col+1] && !vis[row][col+1]){
            vis[row][col+1] = true;
            temp = temp + 'R';
            solve(m, res, temp, vis, row, col+1);
            vis[row][col+1] = false;
            temp.pop_back();
        }
        // check if we can move up
        if(row>0 && m[row-1][col] && !vis[row-1][col]){
           vis[row-1][col] = true;
           temp = temp + 'U';
           solve(m, res, temp, vis, row-1, col);
           vis[row-1][col] = false;
           temp.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vector<string> res;
        if(m[0][0]==0) return res;    // if start is blocked then result dose not exist
        string temp;
        vis[0][0] = true;
        solve(m, res, temp, vis, 0, 0);
        return res;
        // Your code goes here
    }
```
