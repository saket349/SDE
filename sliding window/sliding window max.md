- for [ 2, 3 , 1, -1, -2], k = 3
- if implement concept of queue (doubly)  here
- we see that for our current window, any value smaller then max and to left of it is of no use, as  in next step we move our window to right, so even then those smaller values will be of no use
- but smaller value right ot max value may be considered in next iteration, as when max is removed, and we want new max value
- then that max will be max of existing max value and new value we insert into, for our example intial max value was 3, after two interation window beacam [1 -1  -2]
- so new max will be max [1 -1] and new value [-2] so max is 1, so u see less (1) value in right of max value (3) is considered in this step, but 2, which was on left of 3, will never be considered
```cpp
 vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int>  q;
        int n = a.size();
        vector<int> v;
        for(int i=0;i<k;i++){
            while(!q.empty() && a[q.back()] < a[i])
                q.pop_back();
            q.push_back(i);
        }
        for(int i=k;i<n;i++){
            v.push_back(a[q.front()]);
            while(!q.empty() && q.front()<=(i-k))
                q.pop_front();
            while(!q.empty() && a[q.back()] < a[i])
                q.pop_back();
            q.push_back(i);
        }
        v.push_back(a[q.front()]);
        return v;
    }
```
