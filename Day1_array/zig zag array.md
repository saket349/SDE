- TC: O(N), SC: O(1)
```
Input:
N = 7
Arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 3 7 4 8 2 6 1
Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1
```
```cpp
void zigZag(int a[], int n) {
	    // code here
	    bool m = true;
	    for(int i=0;i<n-1;i++){
	        if(m){
	            if(a[i]>a[i+1]) swap(a[i], a[i+1]);
	        }else{
	            if(a[i]<a[i+1]) swap(a[i], a[i+1]);
	        }
	        m ^= true;
	    }
	}
```
