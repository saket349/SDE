int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> q;
        int cnt = 0;
        for(int i=l;i<=r;i++){
            cnt++;
            q.push(arr[i]);
            if(cnt>k) q.pop();
        }
        
        return q.top();
        
    }
