```cpp
class Solution {
public:
    int solve(vector<vector<char>> &v, int r,int c, int i, int j, vector<vector<bool>> &vis){
        vis[i][j] = true;
        if(v[i][j]=='0') return 0;
        for(int a = i-1;a<=i+1;a=a+2){
            if(a>=0 && a<r)
                if(!vis[a][j])
                    solve(v,r,c,a,j,vis);
        }
        for(int a = j-1;a<=j+1;a=a+2){
            if(a>=0 && a<c)
                if(!vis[i][a])
                    solve(v,r,c,i,a,vis);
        }
        return 1;
    }
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        int r = grid.size();
        if(r==0) return 0;
        int c = grid[0].size();
        vector<vector<bool>> vis(r+2,vector<bool> (c+2, false));
       
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i>=0 && i<r && j>=0 && j<c)
                    if(!vis[i][j])
                        count += solve(grid,r,c,i,j,vis);
            }
        }
        return count;
        // Code here
    }
};
```
