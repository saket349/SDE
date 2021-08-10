// at any point merge two ropes with min lengths

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
