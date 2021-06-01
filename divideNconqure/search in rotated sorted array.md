## For array with distinct values

#### to find pivot
```
int find(vector<int> v,int l,int r){
        if(l>r) return -1;
        if(l==r) return l;
        int mid = (r-l)/2 + l;
        if(v[mid]<v[v.size()-1]) return find(v,l,mid);
        else return find(v,mid+1,r);   
    }
```
##### so when we have pivot we know that we have two sorted array, First and Second, so we can then use binary search in both of them to see if our value lie in any of them or not, or just compare target value with arr[0] so if target > arr[0] then target will lie in First array, else in Second one
##### Binary search

```
int findval(vector<int> v,int l,int r,int x){
    if(l>r) return -1;
    int mid = (r-l)/2 + l;
    if(v[mid]==x) return mid;
    else if(v[mid]<x) return findval(v,mid+1,r,x);
    return findval(v,l,mid,x);
}
```

