- same as finding subset only change is we donot consider all subset instead use the condition of sum == 0, to consider slot
- either we consider a element or we don't
- for any subset to be considered total sum should be equal to target, or in other words, target should be become zero
```cpp
// recursive function 
void solve(vector<int> &v, int ind, vector<vector<int>> &x, vector<int> s, int n, int sum){
        if(sum==0)      // condition for considering that subset
        {  x.push_back(s); return;}
        if(ind>=n) return;
        if(v[ind]<=sum){
            s.push_back(v[ind]);      // we consider that element 
            solve(v,ind,x,s,n,sum-v[ind]);    // and move on
            s.pop_back();             // we donot consider that element
        }
            solve(v,ind+1,x,s,n,sum);    // and we move on
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> x;     // output vector
        vector<int> s;                   // temp vector to store subset
        int n = candidates.size();
        solve(candidates,0,x,s,n,target);    // function call
        return x;
    }
```
