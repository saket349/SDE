- Almost same as part 1
- only difference if we initialy intake all elements of array in right to left, so first element is last element pushed

```cpp
 vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
         s.push(nums[i]);   
        }
        vector<int> v(n);
        for(int i=n-1;i>=0;i--){
         while(!s.empty() && s.top()<=nums[i]){
             s.pop();
         }   
            if(!s.empty())
            v[i] = s.top();
            else v[i] = -1;
            s.push(nums[i]);
        }
        return v;
    }
```
