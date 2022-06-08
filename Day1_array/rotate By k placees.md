~~~
Given an array, rotate the array to the right by k steps, where k is non-negative.
in O(n) time ,and O(1) extra space
~~~

```cpp
 void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(k==0 || len==1) return;
        k = k %len;
        // {1,2,3,4, 5,6,7} => {4,3,2,1, 5,6,7}
        reverse(nums.begin(), nums.end() - k);
        // {4,3,2,1, 5,6,7} => {4,3,2,1, 7,6,5}
        reverse(nums.end() - k, nums.end());
        // {4,3,2,1, 7,6,5} => {5,6,7, 1,2,3,4}
        reverse(nums.begin(), nums.end());
    }
```
