### approach is using prefix sum(XOR here) and mapping 
```
int Solution::solve(vector<int> &a, int m) {
    int n = a.size();
    
    std::vector<long long> ps(n+1,0);
     for(int i=0;i<n;i++)
         ps[i+1] = ps[i]^a[i];
        
        int c = 0; long long x;  
        std::map<long long, int> mp;
     for(int i=0;i<n;i++){
         if(ps[i+1]==m)
             c++;
            
         x = ps[i+1]^m;
         if(mp[x]!=0) 
             c=c+mp[x];
            
         mp[ps[i+1]]++;
     }
    return c;
     
}
```
