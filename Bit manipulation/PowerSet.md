### Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
- total number of subset can be 2^size (or 1<<size)  
- so those are just filling options for each blank _ _ _ _ .... _ (total size of array) either 0 or 1
- thus if any index is set, that index value is picked, else continue
- thus we get all possible subsets

```cpp
vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int subsetnum = (1<<size);
        vector<vector<int>> x;
        for(int s = 0;s<subsetnum;s++){
            vector<int> v;
            for(int i=0;i<size;i++){
                if((s&(1<<i))!=0){
                    v.push_back(nums[i]);
                }
            }
            x.push_back(v);
        }
        return x;
    }

```

#### qn link: <a href="https://leetcode.com/problems/subsets-ii/"> here </a>
