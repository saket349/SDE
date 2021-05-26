### x+y+z = sum, so x + y = sum - z, here sum is 0
### we sort our nums array
### as indices of all three, i.e. x,y,z, should be diff , so we assume x( nums[i] ) to be one with smallest index, then comes y and then comes z, thus x<=y<=z, as nums array is sorted

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i+1;
        }
        
        for(int i=0;i<nums.size();i++){  // we fix x here 
            if(i>0 && nums[i-1]==nums[i]){ // for one particular x we already gonna consider all posibilty so we avoid repetation
                continue;
            }
            int c = -nums[i];
            for(int j=i+1;j<nums.size();j++){ // we find y so to fix it
                if(j>i+1 && nums[j-1]==nums[j]) // similar argument as of x
                    continue;
                if(mp[c - nums[j]]!=0 && (mp[c-nums[j]]>(j+1)))
                {
                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[j]);
                    a.push_back(c-nums[j]);
                    v.push_back(a);
                }
            }
        }
        
        return v;
    }
};
```
