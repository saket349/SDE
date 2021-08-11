int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int ans = 0;
        unordered_map<long long, int> mp;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += a[i];
            if(mp.find(sum)==mp.end())
                mp[sum] = i;
            if(sum==k) ans = i + 1;
            if(mp.find(sum-k)!=mp.end()) ans = max(ans, i-mp[sum-k]);
        }
        return ans;
        
        // Complete the function
    } 
