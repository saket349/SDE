#### using mapping, we use sorting to avoid repetation of  triple 

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        
        unordered_map<int,int> mp; // Mapping the entries of nums
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i+1;
        }
        
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i-1]==nums[i]){
                continue;
            } // for unique triple
            int c = -nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j-1]==nums[j])
                    continue; // for unique triple
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
