### Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
- total number of subset can be 2^size (or 1<<size)
- so those are just filling options for each blank _ _ _ _ .... _ (total size of array) either 0 or 1
- thus if any index is set, that index value is picked, else continue
- thus we get all possible subsets

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = nums.size();
        int subsetnum = (1<<size);
        set<vector<int>> st;
        for(int s = 0;s<subsetnum;s++){
            vector<int> v;
            for(int i=0;i<size;i++){
                if((s&(1<<i))!=0){
                    v.push_back(nums[i]);
                }
            }
            sort(v.begin(),v.end());
            st.insert(v);
        }
        vector<vector<int>> x;
        for(auto i:st){
            x.push_back(i);
        }
        return x;
    }
};

```

#### qn link: <a href="https://leetcode.com/problems/subsets-ii/"> here </a>
