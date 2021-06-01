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

## For array with duplicates

##### for extra condition we just reduce the size of consideration from both side

```
int searchx(vector<int> &v, int l,int r,int x){
    if(l>r) return -1;
    
    int mid = (l+r)/2;
    if(v[mid]==x) return mid;
    
    
    if(v[l]==v[mid] && v[mid]==v[r]) return searchx(v,l+1,r-1,x);  // this one extra condition applied, 
    
    // if array is sorted from l...mid     
    if(v[l]<=v[mid]) {
        if(x>=v[l] && x<=v[mid]) return searchx(v,l,mid-1,x);
        
        return searchx(v,mid+1,r,x);
    }
    
    if(x>=v[mid] && x<=v[r])
        return searchx(v,mid+1,r,x);
    
    return searchx(v,l,mid-1,x);
}
```
 
```
bool search(vector<int>& nums, int target) {
        int x = searchx(nums,0,nums.size()-1,target);
        if(x>=0 && nums[x]==target) return true;
        return false;
    }
```

