```
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) return kthElement(arr2,arr1,m,n,k);
        int low = 0;int high = n;
        while(low<=high) {
            int mid1 = (low + high)/2;
            if(mid1 > k) {
                high = mid1 - 1;
                continue;
            }
            int mid2 = k - mid1;
            if(mid2 >= m){
                low = mid1 + 1;
                continue;
            }
            int left1  = (mid1-1 < 0) ? INT_MIN : arr1[mid1 - 1];
            int left2  = (mid2-1 < 0) ? INT_MIN : arr2[mid2 - 1];
            int right1 = (mid1 >= n) ? INT_MAX : arr1[mid1];
            int right2 = (mid2 >= m) ? INT_MAX : arr2[mid2];
            if(left1<=right2 && left2<=right1){
                return max(left1,left2);
            }
            if(left1 > right2){
                high = mid1-1;
            }
            if(left2 > right1){
                low = mid1+1;
            }
        }
        return 0;
    }
```
