int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                q.push({i,j});
            }
        }
        int count = 0;
        int a,b;
        while(!q.empty()){
            int x = q.size();
            bool flag = true;
            for(int i=0;i<x;i++){
                pair<int,int> p;
                p = q.front();
                q.pop();
                if(p.first>0){
                    a = p.first - 1;
                    b = p.second;
                    if(grid[a][b]==1){
                        // cout<<a<<" "<<b<<endl;
                        grid[a][b] = 2;
                        q.push({a,b});
                        flag = false;
                    }
                }
                if(p.first<n-1){
                    a = p.first + 1;
                    b = p.second;
                    if(grid[a][b]==1){
                        // cout<<a<<" "<<b<<endl;
                        grid[a][b] = 2;
                        q.push({a,b});
                        flag = false;
                    }
                }
                if(p.second > 0){
                    a = p.first;
                    b = p.second - 1;
                    if(grid[a][b]==1){
                        // cout<<a<<" "<<b<<endl;
                        grid[a][b] = 2;
                        q.push({a,b});
                        flag = false;
                    }
                }
                if(p.second < m-1){
                    a = p.first;
                    b = p.second + 1;
                    if(grid[a][b]==1){
                        // cout<<a<<" "<<b<<endl;
                        grid[a][b] = 2;
                        q.push({a,b});
                        flag = false;
                    }
                }
                // cout<<count<<endl;
                
            }
            if(flag) break;
            count++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
        return count;
    }
