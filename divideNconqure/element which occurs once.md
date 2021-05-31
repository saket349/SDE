#### divide and conqure, range: 0 - (n-1)
##### All elements before the required have the first occurrence at even index (0, 2, ..) and the next occurrence at odd index (1, 3, …). And all elements after the required elements have the first occurrence at an odd index and the next occurrence at an even index
- Find the middle index, say ‘mid’.
- If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are the same, then the required element after ‘mid’ and else before mid
- If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are the same, then the required element after ‘mid’ and else before mid

```
int findOnce(int arr[], int n)
    {
        //code here.
        int r = n - 1;
        int l = 0;
        while(l<r){
            int mid = (r-l)/2 + l;
            if(mid%2==0){
                if(arr[mid]==arr[mid+1])
                    l = mid+1;
                else r = mid;
            }else{
                if(arr[mid]==arr[mid+1])
                    r = mid;
                else l = mid+1;
            }
        }
        return arr[l];
    }
```
