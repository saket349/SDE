### approach: prefix sum + hashmap
- Using extra space of O(N) for hash table we can reduce time complexity from O(N^2) in brute force to O(N).
- We use a hash table to store frequencies of prefix sum in hash table.
- The number of times we have encountered (sum-k), that many more solutions we have till that index.

```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;  //hash table to store the frequencies of prefix sum
        
        int sum,c; sum =  c = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];  //calculating the prefix sum
            if(sum == k) c++;     //if prefix sum has become k means we have a subarray from 0->i
            if(mp[sum-k]>0) c = c + mp[sum-k];  //if prefix sum has already encountered (sum-k) than we have sol from there till i'th index
            mp[sum]++;
        }
        return c;
    }
};
```
