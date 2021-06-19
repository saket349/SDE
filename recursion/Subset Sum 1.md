#### Recursive solution
- Either we include the element or we don't
```cpp
void solve(vector<int> v,int l,int r, int sum, vector<int> &x){
        if(l>r)
        {
            x.push_back(sum);
            return;
        }
        
        solve(v,l+1,r,sum+v[l],x);
        solve(v,l+1,r,sum,x);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> x;
        solve(arr,0,n-1,0,x);
        sort(x.begin(),x.end());
        return x;
    }
}
```

#### Iterative method, uses powerset for calculation 
```cpp
vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> x;
        long long s = 0;
        long long l = (1<<n);
        for(int i=0;i<l;i++){
            s = 0;
            for(int k = 0;k<n;k++){
                if(i&(1<<k))
                s=s+arr[k];
            }
            x.push_back(s);
        }
        sort(x.begin(),x.end());
        return x;
    }
```

#### if we have to store all subset and return that, for iterative approach it is just the same question as power set, but for recursion we have to use backtracking method
```cpp
void solve(vector<int> &v, vector<int> &s, int ind, vector<vector<int>> &x){
        x.push_back(s);   // we insert the subset s into our output vector x
        int n = v.size();
        for(int i=ind;i<n;i++)
        {
            s.push_back(v[i]);      // include the A[i] in subset
            solve(v,s,ind+1,x);     // move onto the next element
            s.pop_back();           // exclude the A[i] from subset and triggers backtracking
        
        }
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<vector<int>> x;    // out put vector
        vector<int> s;            // subset vector
        solve(arr,s,0,x);     // function call
        return x;
    }
}
```
