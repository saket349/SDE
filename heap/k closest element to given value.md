- So idea is similar of that of finding k smallest element in given unsorted array
- eg: [10 8 7 6 9], x = 7;  we will find k smallest element using transformed arr => [3 1 0 1 2] obtain by subtracting array values with 'x' 
- We store pair in heap, { transformed value, actual value}

```cpp
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int> > q;
        int cnt = 0;
        for(int i=0;i<arr.size();i++){
            cnt++;
            q.push({abs(arr[i]-x), arr[i]});
            if(cnt>k){
                q.pop();
                cnt--;
            }
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(q.top().second); 
            q.pop();
        }
        sort(res.begin(), res.end());
        return res;
        
    }
```
