#### For two nmumbers to sum upto a given no, presence of both is required, say " x + y = n " , then "x & n-x" both should be present
#### when we encounter x, we mark n-x so, if we encounter n-x in the list we can say both are present
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]!=0 && (i+1)!=mp[nums[i]])
            {
                v.push_back(i);
                v.push_back(mp[nums[i]]-1);
                break;
            }
            mp[target-nums[i]]=i+1;
        }
        return v;
        
    }
};

```
