- [question link](https://leetcode.com/problems/koko-eating-bananas/)

```
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
```
```
Input: piles = [3,6,7,11], h = 8
Output: 4
```

```cpp
int solve(vector<int> &piles, int x){
        int ans = 0;
        for(auto i : piles) ans = ans + (i + x - 1)/x;
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l<r){
            int mid = (l+r)/2;
            int val = solve(piles, mid);
            if(val <= h) r = mid;
            else l = mid + 1;
        }
        return r;
    }
```
