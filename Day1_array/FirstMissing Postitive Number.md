- given an array of number find first missing poisitve number (1 or above)
```
Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
```

```
Example 
Input: nums = [3,4,-1,1]
Output: 2
```
- makee everything positive
- negative index for visited
```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<min && nums[i]>0) min = nums[i];
            if(nums[i]<=0) nums[i] = 0;
        }
        if(min!=1) {
            return 1;
        }
        
        for(int i=0;i<n;i++){
            nums[i] = nums[i] - min + 1;
            if(nums[i]==0) nums[i] = n + 1;
        }
        
        for(int i=0;i<n;i++){
            int ind = abs(nums[i]) - 1;
            if(ind<n && nums[ind]>0) nums[ind] = -nums[ind];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) return (min + i);
        }
        return min + n;
        
        
    }
};
```
