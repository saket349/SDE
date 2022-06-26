[question link](https://leetcode.com/problems/132-pattern/)
```
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k]
such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false
```
```
Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
```
- use stack moving from back, and a pointer (third) to store max of all previous values lesser then current value
```cpp
bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int len = nums.size();
        int third = INT_MIN;
        for(int i = len-1;i>=0;i--){
            if(nums[i] < third) return true;
            while(!s.empty() && nums[i]>s.top()){
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
```
