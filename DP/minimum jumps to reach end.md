- method one is using recursion solution, that will take total time complexity of O(n^n) 
- method two is optimal solution using dp, to store min number of jumps to reach any index i
```cpp
long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for(int i=0;i<n;i++){
            q.push(arr[i]);
        }
        long long sum = 0;
        while(q.size()>1){
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            sum += x+y;
            q.push(x+y);
        }
        return sum;
    }
```

- method 3: is O(n) time complexity, here we calculate steps we have now, if steps == 0 , then we have to make a jump, else we calculate max position we can reach in between
-  so when never we make a jump, we take total steps as max as possible i.e. maxReach - current position

```cpp
int minJumps(int a[], int n){
        if(n==1) return 0;
        if(a[0] == 0) return -1;
        int maxReach  = a[0];
        int step = a[0];
        int jump = 1;
        for(int i=1;i<n;i++){
            if(i==n-1) return jump;
            maxReach  = max(maxReach, i + a[i]);
            step--;
            if(step == 0){
                jump++;
                if(maxReach <= i) return -1;
                step  = maxReach - i;
            }
        }
        return -1;
    }
```
