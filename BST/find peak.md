### [question link](https://leetcode.com/problems/find-peak-element/) 

#### Four possible conditions
- if a value at current index is smaller then its right neighbour and bigger then left neighbour, then its a part of increasing sequence, search on right to get peak
- similarly for index which is bigger then right neighbour and smaller then left, search on left part to get peak
- for one who is smaller then both neighbour, we may search in left or right, both side atleast one peak for each will exist
- and if bigger then both, then its a peak

```cpp
int solve(vector<int> &nums, int l,int h,int &n){
        if(l>h) return -1;
        int mid = (h-l)/2 + l;
        
        //end case1
        if(mid==0 && nums[mid]>nums[mid+1]) return mid;
        else if(mid==0) return solve(nums,mid+1,h,n);
       
        //end case2
        if(mid==(n-1) && nums[mid]>nums[mid-1]) return mid;
        else if(mid==(n-1)) return solve(nums,l,mid-1,n);
       
        // conditions 
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;  // perfect index
        else if(nums[mid]>nums[mid-1]) return solve(nums,mid+1,h,n);    // index left to peak
        else return solve(nums,l,mid-1,n);                              // index right to peak
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;      // special casse
        return solve(nums,0,n,n);
    }
```
