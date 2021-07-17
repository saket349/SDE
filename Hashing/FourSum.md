### code same as tree sum, just here we go three nested loop instead of two

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
           
            mp[nums[i]]=i+1;
        }
        int n = nums.size();
        cout<<n<<endl;
        for(int i=0;i<(n-3);i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int c = target - nums[i];
            for(int j=i+1;j<(n-2);j++){
                if(j>(i+1) && nums[j]==nums[j-1])
                    continue;
                
                int ck = c - nums[j];
                
                for(int k=j+1;k<(n-1);k++){
                    if(k>(j+1) && nums[k]==nums[k-1])
                        continue;
                    
                    if(mp[ck-nums[k]]!=0 && mp[ck-nums[k]]>(k+1)){
                        vector<int> a;
                        a.push_back(nums[i]);
                        a.push_back(nums[j]);
                        a.push_back(nums[k]);
                        a.push_back(ck-nums[k]);
                        v.push_back(a);
                    }
                }
            }
        }
        
        return v;
        
        
    }
};
```
