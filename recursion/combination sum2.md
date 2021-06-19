##### there is only slight variation from combination sum, changes are that we need to consider only one occurence of any number and there should not be any duplicate subset
- only while loop is added which is used when we are not considering any value, so all other with same value should also be skipped as if considered then they will produce ntng but condiration of previous number
```cpp
void solve(vector<int> v, int i, vector<vector<int>> &x, vector<int> s, int n, int sum){
        if(sum==0){
            x.push_back(s);
            return;
        }
        if(i>=n) return;
        if(v[i]<=sum){
            s.push_back(v[i]);
            solve(v,i+1,x,s,n,sum-v[i]);
            s.pop_back();
        }
        i++;
        while(i<n){     // extra considitional statetement
            if(v[i]==v[i-1]) i++;
            else break;
        }
        solve(v,i,x,s,n,sum);   // i is passed not i+1, as we have already changed i 
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> x;     // output vector
        vector<int> s;                   // temp vector to store subset
        int n = candidates.size();
        solve(candidates,0,x,s,n,target);    // function call
        return x;
    }
```
