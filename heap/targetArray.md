[Question link](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)

```
You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :
- let x be the sum of all elements currently in your array.
- choose index i, such that 0 <= i < n and set the value of arr at index i to x.
- You may repeat this procedure as many times as needed.

Return true if it is possible to construct the target array from arr, otherwise, return false.
```

Solution
```
We can store the elements of target array in a priority queue (pq) to always get the greatest element at the top.

Calculate the total sum along with it.

Exclude top element of pq from sum.

Now minus the sum from the top element to get the previous element. 
If multiple operations were done on same element we have to do this same operation multiple times.
Insted we can just return pq.top() % sum.
```



~~~cpp

bool isPossible(vector<int>& target) {
        long long int sum = 0;
        priority_queue<int> pq;
        for(auto i : target) { 
            sum = sum + i;
            pq.push(i);
        }

        while(pq.top()!=1){
            int x = pq.top();
            pq.pop();
            sum = sum - x;
            cout<<sum<<" ";
            if(sum==0 || x<sum) return false;
            if(sum!=1 && (x%sum==0)) return false;
            x = x%sum;
            pq.push(x);
            sum = sum + x;
        }
        
        return true;
    }

~~~
