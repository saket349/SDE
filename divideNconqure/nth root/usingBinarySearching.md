##### with the help of binay searching, time complexity: O(log(n)), space complexity: O(1)

```
public:
	int NthRoot(int n, int m)
	{
	    int low, mid, high;
	    long long mm;
	    low = 1;
	    high = m;
	    while(low <= high){
	        mid = low + (high-low)/2;
	        mm= pow(mid, n);
	        if(mm < 0){
	            high = mid;
	            continue;
	        }
	        if(mm == m){
	            return mid;
	        }
	        else if(mm < m){
	            low=mid+1;
	        }
	        else {
	            high = mid - 1;
	        }
	       // cout<<mid<<" "<<mm<<endl;
	    }
	    return -1;
	}  
```
