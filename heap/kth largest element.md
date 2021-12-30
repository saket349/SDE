- use min heap
- TC : O(nlogK), SC: O(K)
```cpp
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt++;
            pq.push(nums[i]);
            if(cnt>k) { pq.pop(); cnt--;}
        }
        
        return pq.top();
    }
```
