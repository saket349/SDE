##### time complexity : O(n), space complexity: O(n)
```
int NthRoot(int n, int m)
	{
	    long long ans = 1;
	    unordered_map<int,int> mp;
	    bool flag = false;
	    while(m%2==0){   // counting factor of two
	        m = m/2;
	        mp[2]++;
	        if(mp[2]%n == 0) ans = ans*2;    // multipling number when ever count becomes multiple of n
	    }
    
	    if(mp[2]%n!=0) return -1;
	    int i = 3;
	    while(m>1){
	        flag = false;
	        while(m%i==0) {
	            m = m/i;
	            mp[i]++;
	            if(mp[i]%n == 0) ans = ans*i; // same counting when count becomes multiple of n
	        }
	        if(mp[i]%n!=0) return -1;       // that factor must me in multiple of n-count
	        i++;
	    }
	    if(ans == 1 && m!=1)
	    return -1;
	    
	    return ans;
	}  
```
