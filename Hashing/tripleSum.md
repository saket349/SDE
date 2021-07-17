#### using mapping, we use sorting to avoid repetation of  triple 

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // sorrting 
        sort(nums.begin(),nums.end());
        
        // vector which we will return
        vector<vector<int>> v;
        
        unordered_map<int,int> mp; // Mapping the entries of nums
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i+1;
        }
        
        // main code
        for(int i=0;i<nums.size();i++){
        
            if(i>0 && nums[i-1]==nums[i]){
                continue;
            } // for unique triple
            
            // if nums[i] is one element then remainig sum will be 0 - (nums[i])
            int c = -nums[i];
            
            for(int j=i+1;j<nums.size();j++){
            
                if(j>i+1 && nums[j-1]==nums[j])
                    continue; // for unique triple
                    
                 // conditions are that element (C - nums[j]) should be present and,
                 // index must be greater then j otherwise we had already considered it
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
