```cpp
vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<1) return {-1, -1};
        vector<int> ans(2, -1);
        
        // initial range, complete array
        int l = 0, r = n-1;
        // we get the start index of the target value 
        while(l+1<r){
            int mid = l + (r-l)/2;
            if(nums[mid]<target) l = mid;
            else r = mid;
        }
        
        ans[0] = (target==nums[l])?l:r;
        if(nums[ans[0]]!=target) return {-1, -1};
        
        // re-declaration with new range
        l = r - 1; r = n - 1;
        // we get the end index of the target value
        while(l+1<r){
            int mid = l + (r-l)/2;
            if(nums[mid]>target) r = mid;
            else l = mid;
        }
        
        ans[1] = (target==nums[r])?r:l;
        if(nums[ans[1]]!=target) return {-1, -1};
        return ans;
    }
```
