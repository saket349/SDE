#### ercursive solution
- either we include the number or we dont
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
        // Write Your Code here
    }
}
```

#### iterative method, uses powerset for calculation
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
        // Write Your Code here
    }
```
